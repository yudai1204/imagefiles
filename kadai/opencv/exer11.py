#  exer11.py 2023cv
#  Harrisのコーナー検出法により入力画像からコーナーを検出し、コーナーに円を描画した画像を出力せよ。 
#
#  >python exer11.py input.png  output.ong
#  input.png  : 入力画像のファイル名
#  output.png : 出力画像のファイル名


import numpy as np
import sys
import cv2

fname_in  = sys.argv[1]
fname_out = sys.argv[2]

#画像を読み込み輝度画像へ変換
img_color = cv2.imread(fname_in)
img_gray  = np.float64( cv2.cvtColor(img_color, cv2.COLOR_RGB2GRAY) )

#画像全体のsobel filter
img_sobel_x = np.zeros_like( img_gray)
img_sobel_y = np.zeros_like( img_gray)

for y in range( 1, img_gray.shape[0]-1 ) :
    for x in range( 1, img_gray.shape[1]-1 ) :
        img_sobel_x[y,x] = -1.0 * img_gray[y-1,x-1] + 0.0 * img_gray[y-1,x ] + 1.0 * img_gray[y-1,x+1] + \
                           -2.0 * img_gray[y  ,x-1] + 0.0 * img_gray[y  ,x ] + 2.0 * img_gray[y  ,x+1] + \
                           -1.0 * img_gray[y+1,x-1] + 0.0 * img_gray[y+1,x ] + 1.0 * img_gray[y+1,x+1]
        img_sobel_y[y,x] = -1.0 * img_gray[y-1,x-1] - 2.0 * img_gray[y-1,x ] - 1.0 * img_gray[y-1,x+1] + \
                            0.0 * img_gray[y  ,x-1] + 0.0 * img_gray[y  ,x ] + 0.0 * img_gray[y  ,x+1] + \
                            1.0 * img_gray[y+1,x-1] + 2.0 * img_gray[y+1,x ] + 1.0 * img_gray[y+1,x+1]
img_sobel_x = img_sobel_x / 4
img_sobel_y = img_sobel_y / 4

gauss = np.array([[1, 4, 6, 4,1],
                  [4,16,24,16,4],
                  [6,24,36,24,6],
                  [4,16,24,16,4],
                  [1, 4, 6, 4,1] ])
gauss = gauss / 256.0


#------------------------------------
#ここを編集
#検出位置に円（半径3・色(255,0, 0)・線幅1）を描画する

h, w = img_gray.shape
for y in range(2, h-2):
    for x in range(2, w-2):
        Ixx = img_sobel_x[y-2:y+3, x-2:x+3]**2
        Iyy = img_sobel_y[y-2:y+3, x-2:x+3]**2
        Ixy = img_sobel_x[y-2:y+3, x-2:x+3] * img_sobel_y[y-2:y+3, x-2:x+3]

        Sxx = np.sum(Ixx * gauss)
        Syy = np.sum(Iyy * gauss)
        Sxy = np.sum(Ixy * gauss)

        det = Sxx * Syy - Sxy**2
        trace = Sxx + Syy
        r = det - 0.15 * trace**2

        # 最小固有値が閾値を超えたらコーナーとみなす
        if r >= 260000:
            cv2.circle(img_color, (x, y), 3, (255,0,0), 1)
#------------------------------------


cv2.imwrite(fname_out, img_color)
