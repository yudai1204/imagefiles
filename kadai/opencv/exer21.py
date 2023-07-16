# exer21.py cv2023
# MNISTのトレーニングデータ と ラベル値の不明な画像3枚 を読み込み、
# kNNによりラベルの値を推定せよ。
#
# python exer21.py k img1.png img2.png img3.png
# k          : kNNの近傍数
# img1.png   : 推定対象の画像ファイル名1
# img2.png   : 推定対象の画像ファイル名2
# img3.png   : 推定対象の画像ファイル名3
# output.txt : 推定結果を出力するファイル

import numpy as np
import sys
import cv2
import gzip
from sklearn.neighbors import KNeighborsClassifier

k         = int(sys.argv[1])
img1      = np.uint8( cv2.imread( sys.argv[2], 0 ))
img2      = np.uint8( cv2.imread( sys.argv[3], 0 ))
img3      = np.uint8( cv2.imread( sys.argv[4], 0 ))

#-----------------------
# ここを編集（MNISTのLoad部分には前課題を利用してください）
# ヒント : 2次元配列の画像データは v = img.flatten() で 1次元配列へ変換できます

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

# KNeighborsClassifierのインスタンスを作成
knn = KNeighborsClassifier(n_neighbors=k)

# KNeighborsClassifierにトレーニングデータを渡す
knn.fit(x_train[0:5000], t_train[0:5000])

# ラベルを推定
estim = knn.predict(test_images)

print(' '.join(map(str, estim)))

#------------------------------------------------------------------------------
