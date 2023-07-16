#  excer17.py    2023 cv
#  画像を読み込み、グレースケール画像に変換後、Otsu法により画像を二値化せよ。
#
#  $python exer17.py input.png output.png
#  input.png  : 入力画像のファイル名
#  output.png : 出力画像のファイル名

import numpy as np
import sys
import cv2

# calcPixnumMeanVari関数 : ヒストグラム数列から画素数、平均、分散を計算する
#（必用なら利用してください）
# valueは、[0,1,2,3,4,...,255]という数列です（ヒストグラムの横軸の画素値を表します）
# histoは、頻度が入った配列です
def calcPixnumMeanVari( histo, value ) :
    num  = np.sum(histo)
    if num == 0 :
        return 0, 0, 0
    mean = np.sum(histo * value) / num
    vari = np.sum(histo * ( (value - mean)**2) ) / num
    return num, mean, vari

fname_in  = sys.argv[1]
fname_out = sys.argv[2]

#画像を読み込み輝度画像へ変換
img = cv2.imread(fname_in)
img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

#---------------------------------------
#ここを編集

#TODO ヒストグラムを計算
histo, _ = np.histogram(img.flatten(), bins=256, range=[0,256])

value = np.arange(256)
num_total, mean_total, _ = calcPixnumMeanVari(histo, value)

#TODO Otsu法により閾値threshを計算
#ヒント : スライスを使うときれいに書けます
max_var_class = 0
thresh = 0

for t in range(256):
    # 背景の計算
    num_b, mean_b, _ = calcPixnumMeanVari(histo[:t], value[:t])

    # 前景の計算
    num_f, mean_f, _ = calcPixnumMeanVari(histo[t:], value[t:])

    # クラス間分散を計算
    var_class = num_b * num_f * (mean_b - mean_f) ** 2

    # 最大クラス間分散と閾値を更新
    if var_class > max_var_class:
        max_var_class = var_class
        thresh = t

#画像の二値化（pythonでは以下の表記が可能, boolean array indexingという記法です）
img[img >= thresh] = 255
img[img <  thresh] = 0
#---------------------------------------



cv2.imwrite( fname_out, img )
