# exer13.py 2023 cv
# 入力画像を読み込み、前課題で作成したHough変換画像を利用して直線を検出し、
# 検出した直線を入力画像に描画せよ。
#
# 1. 前課題の手順でHough変換画像を作成（Hough変換画像は正規化しない）
# 2. 投票数が閾値以上の(ρ, θ) の組に対する直線を描く
#  - 直線は，色(B=255, G=0, R=0)，線幅1とする
# 3. 直線を描画した画像を出力する
#
# $python exer13.py input.png output.png
#  input.png  : 入力画像のファイル名
#  output.png : 出力画像のファイル名

import numpy as np
import math
import sys
import cv2

fname_in  = sys.argv[1]
fname_out = sys.argv[2]

#画像を読み込み輝度画像へ変換
img = cv2.imread(fname_in)
img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

#勾配強度画像の計算
img_gradmag = np.zeros(img.shape, dtype = np.float64)
for y in range( 1, img.shape[0]-1 ) :
    for x in range( 1, img.shape[1]-1 ) :
        fx = -1.0 * img[y-1,x-1] + 0.0 * img[y-1,x ] + 1.0 * img[y-1,x+1] + \
             -2.0 * img[y  ,x-1] + 0.0 * img[y  ,x ] + 2.0 * img[y  ,x+1] + \
             -1.0 * img[y+1,x-1] + 0.0 * img[y+1,x ] + 1.0 * img[y+1,x+1]

        fy = -1.0 * img[y-1,x-1] - 2.0 * img[y-1,x ] - 1.0 * img[y-1,x+1] + \
              0.0 * img[y  ,x-1] + 0.0 * img[y  ,x ] + 0.0 * img[y  ,x+1] + \
              1.0 * img[y+1,x-1] + 2.0 * img[y+1,x ] + 1.0 * img[y+1,x+1]
        fx /= 4
        fy /= 4
        img_gradmag[y,x] = math.sqrt(fx*fx + fy*fy )

img_gradmag = img_gradmag / np.max(img_gradmag)

#hough変換
A = int( math.sqrt( img.shape[0] ** 2 + img.shape[1] ** 2) )
img_hough = np.zeros((A,360), float)

#-------------------------------------
#ここを編集
#TODO 1 投票（Hough変換画像を生成する）
#前課題を利用する


#TODO 2 開票（投票数が閾値以上の直線を描画）
# imgは一度グレースケールにしてしまったのでカラーの直線を書き込めない
# 再読み込みすると良い
# img = cv2.imread(fname_in)

#-------------------------------------

cv2.imwrite( fname_out, np.uint8( img ) )
