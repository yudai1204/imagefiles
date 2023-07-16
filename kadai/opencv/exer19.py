# exer19.py
#  画像内の種の個数を数え標準出⼒に書き出すプログラムを作成せよ
#
#  $python exer19.py img.png
#  img.png  : 入力画像のファイル名

import numpy as np
import sys
import cv2

#load image
fname_in  = sys.argv[1]
img = cv2.imread(fname_in)


# 画像をBGRからRGBに変換
image = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# 画像をグレースケールに変換
gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)

# 画像を適切な方法で二値化
_, binary = cv2.threshold(gray, 90, 255, cv2.THRESH_BINARY_INV)

# オブジェクトのエッジ間のギャップを閉じるために、膨張と収縮を実行
dilated = cv2.dilate(binary, None, iterations=2)
eroded = cv2.erode(dilated, None, iterations=1)

dilated = cv2.dilate(binary, None, iterations=3)
eroded = cv2.erode(dilated, None, iterations=2)


# 円を検出するためのHough変換を実行
circles = cv2.HoughCircles(eroded, cv2.HOUGH_GRADIENT, dp=1.5, minDist=10, param1=30, param2=12, minRadius=5, maxRadius=12)

# 円が検出された場合
if circles is not None:
    circles = np.round(circles[0, :])



####### 以下デバッグ用 #######
# import matplotlib.pyplot as plt
# # 円を描画するための画像のコピーを作成
# output = image.copy()

# # 円を描画
# if circles is not None:
#     for (x, y, r) in circles:
#         cv2.circle(output, (x, y), r, (0, 255, 0), 2)

# # 画像を表示
# plt.imshow(output)
# plt.axis('off')
# plt.show()
####### ここまで #######


print(len(circles))
