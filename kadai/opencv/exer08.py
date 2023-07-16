# exer08.py 2023cv
# ランダムに選択された30%の画素が黒く塗りつぶされた劣化画像を入力とし、なるべく元画像に近い画像を復元せよ。
#
# > python exer08.py input.png output.png
# input.png  : 入力画像ファイル名
# output.png : 出力画像ファイル名
#

# 下記を編集（全体を書いてみてください）

import numpy as np
import sys
import cv2

input = sys.argv[1]
output = sys.argv[2]

# 画像をRGBで読み込む
image = cv2.imread(input)

# 黒色のピクセルを探して、それぞれの周囲のピクセルの平均値で置換する
for i in range(0, image.shape[0]):
    for j in range(0, image.shape[1]):
        if np.array_equal(image[i, j], [0, 0, 0]): # ピクセルが黒色の場合
            # 周囲のピクセルの四分位範囲の平均値を計算
            for k in range(image.shape[2]):
                sub_image = image[max(0, i-1):min(image.shape[0], i+2), 
                                max(0, j-1):min(image.shape[1], j+2), 
                                k] # 周囲3x3の領域を取得
                non_zero_elems = sub_image[sub_image != 0] # 黒以外のピクセルを取得
                if non_zero_elems.size != 0: # 黒以外のピクセルが存在するときのみ計算
                    # # 外れ値を除くために四分位範囲を計算する
                    # q1 = np.percentile(non_zero_elems, 25)
                    # q3 = np.percentile(non_zero_elems, 75)
                    # iqr = q3 - q1
                    # non_zero_elems2 = non_zero_elems[non_zero_elems < q3 + 1.5 * iqr]
                    # tmp = non_zero_elems2 if non_zero_elems2.size != 0 else non_zero_elems
                    tmp = non_zero_elems
                    image[i, j, k] = np.mean(tmp)


# 画像を保存
cv2.imwrite(output, image)
