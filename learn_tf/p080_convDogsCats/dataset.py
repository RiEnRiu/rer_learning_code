#-*-coding:utf-8-*-
# book: <Neural Network Programming with Tensorflow>
# authors: Manpreet Singh Ghotra, Rajdeep Dua


import cv2
import numpy as np
import glob
import os
import tqdm
from easydict import EasyDict

def load_img(img_dir,hw,classes):
    imgs = []
    labels = []
    ids = []
    clses = []
    for i,cls in enumerate(classes):
        files = glob.glob(os.path.join(img_dir,cls,'*.jpg'))
        for f in files:
            img = cv2.imread(f)
            if img is not None:
                img = cv2.resize(img,hw)
                imgs.append(img)
                ids.append(i)
                clses.append(cls)
                t = np.zeros(len(classes),dtype=np.float32)
                t[i] = 1
                labels.append(t)
    return imgs,labels,ids,clses

      

class DataSet:

    def __init__(self, imgs,labels,ids,clses,shuffle=True):
        self._images = np.array(imgs,np.float32)
        self._images = self._images / 255
        self._labels = np.array(labels,dtype=np.float32)
        self._ids = np.array(ids)
        self._clses = np.array(clses)

        self._num_examples = len(self._images)
        self._epochs_completed = 0
        self._index_in_epoch = 0
        self._shuffle = shuffle
        if self._shuffle:
            self._shuffer_images()

    @property
    def images(self):
        return self._images

    @property
    def labels(self):
        return self._labels

    @property
    def ids(self):
        return self._ids

    @property
    def clses(self):
        return self._clses

    @property
    def num_examples(self):
        return self._num_examples

    def _shuffer_images(self):
        sid = np.arange(self._num_examples)
        np.random.shuffle(sid)
        self._images = self._images[sid]
        self._labels = self._labels[sid]
        self._ids = self._ids[sid]
        self._clses = self._clses[sid]
        return

    def next_batch(self, batch_size):
        start = self._index_in_epoch
        self._index_in_epoch += batch_size
        if self._index_in_epoch > self._num_examples:
            self._epochs_completed+=1
            self._shuffer_images()
            start = 0
            self._index_in_epoch = batch_size
        end = self._index_in_epoch
        return self._images[start:end], self._labels[start:end],\
                self._ids[start:end], self._clses[start:end]

def read_data_sets(train_path, hw, classes, validation_size=None, test_path=None):    
    imgs,labels,ids,clses = load_img(train_path,(hw),classes)
    sid = np.arange(len(imgs))
    np.random.shuffle(sid)
    vstart = len(imgs)
    if validation_size is not None:
        vstart = int(min(max((1-validation_size),0),1)*len(imgs))
    timgs,tlabels,tids,tclses = [],[],[],[]
    vimgs,vlabels,vids,vclses = [],[],[],[]
    for i in range(vstart):
        timgs.append(imgs[sid[i]])
        tlabels.append(labels[sid[i]])
        tids.append(ids[sid[i]])
        tclses.append(clses[sid[i]])
    for i in range(vstart,len(imgs)):
        vimgs.append(imgs[sid[i]])
        vlabels.append(labels[sid[i]])
        vids.append(ids[sid[i]])
        vclses.append(clses[sid[i]])
    data_sets = EasyDict()
    data_sets.train = DataSet(timgs,tlabels,tids,tclses)
    data_sets.valid = DataSet(vimgs,vlabels,vids,vclses)
    if test_path is not None:
        data_sets.test = DataSet(*(load_img(test_path,hw,classes)))
    return data_sets

