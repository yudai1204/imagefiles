# exer10.py     2023 cv
# 画像と画素位置(x,y)を読み込み、その画素位置におけるHarris行列を計算し出力せよ。
#
# > python exer10.py fname_in.png x_in  y_in output.txt
# fname_in.png : 入力画像のファイル名
# x_in,  y_in  : 画素位置
# output.txt   : 出力テキストファイル名

import numpy as np
import sys
import cv2

fname_in  = sys.argv[1]
x_in      = int(sys.argv[2])
y_in      = int(sys.argv[3])
fname_out = sys.argv[4]

#画像を読み込み輝度画像へ変換
img = cv2.imread(fname_in)
img = np.float64( cv2.cvtColor(img, cv2.COLOR_RGB2GRAY) )


#画像全体のSobelフィルタ結果は以下の通り
#この課題では一部のみ利用 (ヒントを与え過ぎかもしれないですが活用して下さい。）
img_sobel_x = np.zeros_like( img)
img_sobel_y = np.zeros_like( img)

for y in range( 1, img.shape[0]-1 ) :
    for x in range( 1, img.shape[1]-1 ) :
        img_sobel_x[y,x] = -1.0 * img[y-1,x-1] + 0.0 * img[y-1,x ] + 1.0 * img[y-1,x+1] + \
                           -2.0 * img[y  ,x-1] + 0.0 * img[y  ,x ] + 2.0 * img[y  ,x+1] + \
                           -1.0 * img[y+1,x-1] + 0.0 * img[y+1,x ] + 1.0 * img[y+1,x+1]
        img_sobel_y[y,x] = -1.0 * img[y-1,x-1] - 2.0 * img[y-1,x ] - 1.0 * img[y-1,x+1] + \
                            0.0 * img[y  ,x-1] + 0.0 * img[y  ,x ] + 0.0 * img[y  ,x+1] + \
                            1.0 * img[y+1,x-1] + 2.0 * img[y+1,x ] + 1.0 * img[y+1,x+1]
img_sobel_x = img_sobel_x / 4
img_sobel_y = img_sobel_y / 4

#5x5 ガウシアンの重みは以下の通り
gauss = np.array([[1, 4, 6, 4,1],
                  [4,16,24,16,4],
                  [6,24,36,24,6],
                  [4,16,24,16,4],
                  [1, 4, 6, 4,1] ])
gauss = gauss / 256.0


#----------------------------
#ここを編集してHarris行列（harris_mat）を計算
Ixx = img_sobel_x[y_in-2:y_in+3, x_in-2:x_in+3]**2
Iyy = img_sobel_y[y_in-2:y_in+3, x_in-2:x_in+3]**2
Ixy = img_sobel_x[y_in-2:y_in+3, x_in-2:x_in+3] * img_sobel_y[y_in-2:y_in+3, x_in-2:x_in+3]

Sxx = np.sum(Ixx * gauss)
Syy = np.sum(Iyy * gauss)
Sxy = np.sum(Ixy * gauss)

harris_mat = np.array([[Sxx, Sxy], [Sxy, Syy]])

#----------------------------

fp = open(fname_out, "w")
fp.write(str(harris_mat[0,0]) + " " + str(harris_mat[0,1]) + "\n")
fp.write(str(harris_mat[1,0]) + " " + str(harris_mat[1,1]) + "\n")
fp.close()
