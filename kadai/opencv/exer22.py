# exer22.py
# MNISTのトレーニングデータ と ラベル値の不明な画像3枚 を読み込み、
# SVMによりラベルの値を推定せよ。
#
# python exer22.py k img1.png img2.png img3.png
# k          : kNNの近傍数
# img1.png   : 推定対象の画像ファイル名1
# img2.png   : 推定対象の画像ファイル名2
# img3.png   : 推定対象の画像ファイル名3
# output.txt : 推定結果を出力するファイル

import numpy as np
import sys
import cv2
import gzip
from sklearn import svm

img1      = np.uint8( cv2.imread( sys.argv[1], 0 ))
img2      = np.uint8( cv2.imread( sys.argv[2], 0 ))
img3      = np.uint8( cv2.imread( sys.argv[3], 0 ))

#-----------------------
# ここを編集（MNISTのLoad部分には前課題を利用してください）
# todo1 mnist読み込み関数をコピー
def open_mnist_image(fname) :
    f = gzip.open(fname, 'rb')
    data = np.frombuffer( f.read(), np.uint8, offset=16)
    f.close()
    return data.reshape((-1, 784)) # (n, 784)の行列に整形, nは自動で決定

def open_mnist_label(fname):
    f = gzip.open(fname, 'rb')
    data = np.frombuffer( f.read(), np.uint8, offset=8 )
    f.close()
    return data.flatten() # (n, 1)の行列に整形, nは自動で決定
# todo2 mnistを読み込む
fname_train_img   = "../mnist/train-images-idx3-ubyte.gz"
fname_train_label = "../mnist/train-labels-idx1-ubyte.gz"
x_train = open_mnist_image( fname_train_img   )
t_train = open_mnist_label( fname_train_label )

# kNNを利用してimg1 img2 img3のラベルを推定
# 入力画像を1次元配列に変換
test_images = np.array([img1.flatten(), img2.flatten(), img3.flatten()])

# SVMインスタンスを作成
svc = svm.SVC()

# SVMにトレーニングデータを渡す
svc.fit(x_train[0:5000], t_train[0:5000])

# ラベルを推定
estim = svc.predict(test_images)

print(' '.join(map(str, estim)))
#----------------------
