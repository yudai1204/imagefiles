# exer01.py 2023cv
# 1枚の画像を読み込みグレースケール化後，その平均値と中央値を出力せよ
#
#  $python exer1.py img.png
#
#  img.png : 入力画像1のファイル名
#

import numpy as np
import sys
import cv2

#load image
fname_in  = sys.argv[1]
img = cv2.imread(fname_in)

#輝度画像へ変換（平均値がオーバーフローしないようfloat64にキャスト）
img = np.float64( cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) )

#---------------------------
#ここを編集して，mean_value, median_valueを計算
#最初の問題なのでとても簡単です．for文を使ったり、numpyを使ったり色々やってみてください
mean_value = np.mean(img)
median_value = np.median(img)
#---------------------------


#値を標準出力 (1行目が平均, 2行目が中央値)
print(mean_value)
print(median_value)
