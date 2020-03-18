#-*-coding:utf-8-*-
# book: <Neural Network Programming with Tensorflow>
# authors: Manpreet Singh Ghotra, Rajdeep Dua


import tensorflow as tf
import numpy as np
import cv2
from easydict import EasyDict
import dataset
import os

GPU_CONFIG = tf.ConfigProto()
GPU_CONFIG.gpu_options.allow_growth=True


# Convolutional Layer 1.
filter_size1 = 3 
num_filters1 = 32

# Convolutional Layer 2.
filter_size2 = 3
num_filters2 = 32

# Convolutional Layer 3.
filter_size3 = 3
num_filters3 = 64

# Fully-connected layer.
# Number of neurons in fully-connected layer.
fc_size = 128

# Number of color channels for the images: 1 channel for gray-scale.
num_channels = 3

# image dimensions (only squares for now)
img_size = 128

# Size of image when flattened to a single dimension
img_size_flat = img_size * img_size * num_channels

# Tuple with height and width of images used to reshape arrays.
img_shape = (img_size, img_size)

# class info
classes = ['dog', 'cat']
num_classes = len(classes)

# batch size
batch_size = 5

# validation split
validation_size = 0.1

# path
train_path = r'dogs_vs_cats\train-cat-dog-100'
test_path = r'dogs_vs_cats\test-cat-dog-100'
checkpint_dir = r'dogs_vs_cats\model'

# train config
lr = 0.0001
loss_iter = 1000
save_epoch = 1
val_epoch = 1
total_epoch = 100





def new_weights(shape):
    return tf.Variable(tf.truncated_normal(shape,stddev=0.05))

def new_biases(length):
    return tf.Variable(tf.constant(0.05,shape=[length]))

def flatten_layer(layer):
    layer_shape = layer.get_shape()# tensor
    num_features = layer_shape[1:4].num_elements() # constant
    layer_flat = tf.reshape(layer,[-1,num_features])
    return layer_flat,num_features
    
def new_conv_block(input, i_channel, filter_size, o_channel, use_pooling=True):
    # input -> conv -> max_pool -> relu

    # tf API requirement
    shape = [filter_size, filter_size, i_channel, o_channel]
    filters = new_weights(shape)
    biases = new_biases(o_channel)
    layer = tf.nn.conv2d(input=input,\
                        filter=filters,\
                        strides=[1,1,1,1],\
                        padding='SAME')    
    layer += biases
    if use_pooling:
        # 2*2 max pool format
        layer = tf.nn.max_pool(value=layer,\
                            ksize=[1,2,2,1],\
                            strides=[1,2,2,1],\
                            padding='SAME')
    layer = tf.nn.relu(layer)
    return layer,filters

def new_fc_layer(input,i_num,o_num,use_relu=True):
    # input -> fc -> relu
    weights = new_weights([i_num,o_num])
    biases = new_biases(o_num)
    layer = tf.matmul(input,weights)+biases
    if use_relu:
        layer = tf.nn.relu(layer)
    return layer

def build_net():
    # net
    x = tf.placeholder(dtype=tf.float32,shape=[None,img_size,img_size,num_channels])
    conv1,ker1 = new_conv_block(x,num_channels,filter_size1,num_filters1,use_pooling=True)
    print(conv1)
    conv2,ker2 = new_conv_block(conv1,num_filters1,filter_size2,num_filters2,use_pooling=True)
    print(conv2)
    conv3,ker3 = new_conv_block(conv2,num_filters2,filter_size3,num_filters3,use_pooling=True)    
    print(conv3)
    flat1,num_flat = flatten_layer(conv3)
    print(flat1)
    print(num_flat)
    fc1 = new_fc_layer(flat1,num_flat,fc_size,use_relu=True)
    print(fc1)
    fc2 = new_fc_layer(fc1,fc_size,num_classes,use_relu=False)
    print(fc2)
    y_pred = tf.nn.softmax(fc2)
    
    # loss
    y_true = tf.placeholder(dtype=tf.float32,shape=[None,num_classes])
    cross_entropy = tf.nn.softmax_cross_entropy_with_logits_v2(labels=y_true,logits=fc2,dim=1)
    loss = tf.reduce_mean(cross_entropy)
    
    # opt
    opt = tf.train.AdamOptimizer(learning_rate=lr).minimize(loss)
    
    # acc
    y_true_cls = tf.arg_max(y_true,dimension=1)
    y_pred_cls = tf.arg_max(y_pred,dimension=1)
    eq = tf.equal(y_true_cls,y_pred_cls)
    acc = tf.reduce_mean(tf.cast(eq,tf.float32))
    return x,y_true,y_pred,opt,loss,acc


if __name__=='__main__':
    data_sets = dataset.read_data_sets(train_path,(img_size,img_size),classes,validation_size,test_path)
    print("Size of:")
    print("- Training-set  : {0}".format(len(data_sets.train.labels)))
    print("- Test-set      : {0}".format(len(data_sets.test.labels)))
    print("- Validation-set: {0}".format(len(data_sets.valid.labels)))

    x,y_true,y_pred,opt,loss,acc = build_net()
    sess = tf.Session(config=GPU_CONFIG)
    sess.run(tf.global_variables_initializer())
    
    for i in range(total_epoch):
        train_set = data_sets.train
        #val_set = dataset.DataSet()################
        for j in range(len(train_set.images)//batch_size):   
            imgs,labels,_,_ = train_set.next_batch(batch_size)
            sess.run(opt,feed_dict={x:imgs,y_true:labels})
            # if j%loss_iter==0:
            #     l = sess.run(loss,feed_dict={x:imgs,y_true:labels})
            #     print('epoch({0}).iter({1}).loss = {2}'.format(i,j,l))
        if i%val_epoch ==0:
            val_set = data_sets.valid
            ta = sess.run(acc,feed_dict={x:train_set.images,y_true:train_set.labels})
            va = sess.run(acc,feed_dict={x:val_set.images,y_true:val_set.labels})
            print('epoch({0}) valid_acc = {1}  train_acc = {2}'.format(i,va,ta))
        # if i%save_epoch ==0:
        #     print('epoch({0}) saved'.format(i))

    a = sess.run(acc,feed_dict={x:data_sets.test.images,y_true:data_sets.test.labels})
    print('test_acc = {0}'.format(a))
    sess.close()



