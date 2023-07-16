# excer18.py
# 画像・シード画素位置・閾値を読み込み、画像をグレースケール化後，
# シードより領域成⻑を⾏い画像を⼆値化せよ
#
# > python exer18.py img.png seed_x seed_y t output.png
# img.png    : 入力画像のファイル名
# seed_x     : seed画素のx座標
# seed_y     : seed画素のy座標
# t          : 閾値
# output.png : 出力画像のファイル名

import numpy as np
import sys
import cv2

fname_in  = sys.argv[1]
seed_x    = int(sys.argv[2])
seed_y    = int(sys.argv[3])
thresh    = int(sys.argv[4])
fname_out = sys.argv[5]

#画像を読み込み輝度画像へ変換
img = cv2.imread(fname_in)
img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)


#---------------------------------------
#ここ以降を編集  　   　
# バイナリ画像を全て0（背景）で初期化
bin_img = np.zeros_like(img)

# 領域成長アルゴリズムのためのスタックを作り、シードピクセルを追加
stack = [(seed_x, seed_y)]

# スタックが空でない限り続ける
while len(stack) > 0:
    # スタックからピクセルを取り出す
    x, y = stack.pop()

    # ピクセルが画像の境界を越えていたらスキップ
    if x < 0 or y < 0 or x >= img.shape[1] or y >= img.shape[0]:
        continue

    # ピクセルがすでに前景ならスキップ
    if bin_img[y, x] == 255:
        continue

    # ピクセルの値が閾値未満ならスキップ
    if img[y, x] < thresh:
        continue

    # それ以外の場合、ピクセルを前景に追加
    bin_img[y, x] = 255

    # ピクセルの近傍をスタックに追加
    stack.append((x - 1, y))  # 左
    stack.append((x + 1, y))  # 右
    stack.append((x, y - 1))  # 上
    stack.append((x, y + 1))  # 下

cv2.imwrite(fname_out, bin_img)
#---------------------------------------
