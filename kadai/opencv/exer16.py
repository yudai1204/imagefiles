# exer16.py
# 画像を読み込み、グレースケール化した後、そのヒストグラムを出力せよ。
#
# >python exer16.py input.png output.txt
# input.png  : 入力画像ファイル名
# output.txt : 出力ファイル名

import numpy as np
import sys
import cv2

fname_in  = sys.argv[1]
fname_out = sys.argv[2]

#画像を読み込み輝度画像へ変換
img = cv2.imread(fname_in)
img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)


#---------------------------------------------
hist, bins = np.histogram(img.flatten(), bins=256, range=[0,256])

with open(fname_out, 'w') as f:
    for i in range(256):
        f.write(str(i) + " " + str(hist[i]) + "\n")
#---------------------------------------------
