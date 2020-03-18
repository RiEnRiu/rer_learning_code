#-*-coding:utf-8-*-
# book: <Neural Network Programming with Tensorflow>
# authors: Manpreet Singh Ghotra, Rajdeep Dua

import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt

GPU_CONFIG = tf.ConfigProto()
GPU_CONFIG.gpu_options.allow_growth=True
sess = tf.Session(config=GPU_CONFIG)

# input data
xData = np.arange(100,step=0.1)
yData = xData + 20 * np.sin(xData / 10)
nSamples = xData.size
xData = xData.reshape((nSamples,1))
yData = yData.reshape((nSamples,1))

batchSize = 100


# net
with tf.variable_scope('linear-regression-pipeline'):
    X = tf.placeholder(tf.float32,(batchSize,1))
    y = tf.placeholder(tf.float32,(batchSize,1))
    W = tf.get_variable('weights',(1,1),initializer=tf.random_normal_initializer())
    b = tf.get_variable('bias',(1,1),initializer=tf.constant_initializer(0.0))
    yPred = X * W + b
    loss = tf.reduce_sum((y - yPred) ** 2 / nSamples)

#optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.001).minimize(loss)
#optimizer = tf.train.AdamOptimizer(learning_rate=0.001).minimize(loss)
#optimizer = tf.train.AdadeltaOptimizer(learning_rate=0.001).minimize(loss)
#optimizer = tf.train.AdagradDAOptimizer(learning_rate=0.001).minimize(loss)
#optimizer = tf.train.MomentumOptimizer(learning_rate=0.001,momentum=0.9).minimize(loss)
#optimizer = tf.train.FtrlOptimizer(learning_rate=0.001).minimize(loss)
optimizer = tf.train.RMSPropOptimizer(learning_rate=0.001).minimize(loss)

sess.run(tf.global_variables_initializer())
errors = []
for _ in range(1000):
    indices = np.random.choice(nSamples,batchSize)
    xBatch,yBatch = xData[indices],yData[indices]
    _,lossVal = sess.run([optimizer,loss],feed_dict={X:xBatch,y:yBatch})
    errors.append(lossVal)

plt.plot([np.mean(errors[i-50:i]) for i in range(len(errors))])
plt.grid()
plt.show()
    
sess.close()
