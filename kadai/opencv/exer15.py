#  exer15.py
#  Seam Carving を自作する
#
#  > python exer19.py img.png
#  img.png : 入力画像

import numpy as np
import sys
import cv2

#重要度画像を計算する関数
def calc_importance(img) :
    img_gray = np.float64( cv2.cvtColor(img  , cv2.COLOR_RGB2GRAY) )
    # 縦横方向に購買を計算
    dx = cv2.Sobel(img_gray, cv2.CV_64F, 1, 0, ksize=3)
    dy = cv2.Sobel(img_gray, cv2.CV_64F, 0, 1, ksize=3)
    # 重要度を計算
    img_importance = np.abs( dx ) + np.abs( dy )
    return img_importance


#seam carving関数
def seam_carving(img, img_importance) :
    #img は入力画像
    #img_importanceは重要度画像
    #2枚とも縮める必要がある

    #TODO ここを書き換える
    # DPで最小コスト表を作成
    dp = np.zeros(img_importance.shape)
    dp[0] = img_importance[0]
    for i in range(1, img_importance.shape[0]):
        for j in range(img_importance.shape[1]):
            dp[i][j] = img_importance[i][j]
            dp[i][j] += min(
                dp[i-1][max(j-1, 0)], 
                dp[i-1][j], 
                dp[i-1][min(j+1, img_importance.shape[1]-1)])
    # 最小コストのシームを逆順に辿る
    seam = [np.argmin(dp[-1])]
    for i in range(len(dp)-2, -1, -1):
        j = seam[-1]
        seam.append(j + np.argmin(dp[i][max(0, j-1):min(img_importance.shape[1], j+2)]) - 1)

    seam.reverse()
    seam = np.array(seam)
    print(seam[:50])
    # シームを削除
    
    # imgをチャネルごとに分割
    r, g, b = img[:, :, 0], img[:, :, 1], img[:, :, 2]

    # 各チャネルでseamに対応する要素を削除
    r_new = np.array([np.delete(row, seam[i]) for i, row in enumerate(r)])
    g_new = np.array([np.delete(row, seam[i]) for i, row in enumerate(g)])
    b_new = np.array([np.delete(row, seam[i]) for i, row in enumerate(b)])

    # チャネルを再結合して新しい画像を作成
    img_new = np.stack([r_new, g_new, b_new], axis=-1)
    img_importance = calc_importance(img_new)
    return img_new, img_importance


fname_in  = sys.argv[1]
img = cv2.imread(fname_in)

#TODO gray scale画像を作成し，重要度画像を作成する
img_importance = calc_importance(img)

while(1) :
    cv2.imshow("img", img)
    k = cv2.waitKey(0)
    if(k == ord('a')) :
        print("横方向にseam carvingして，imgとimg_importanceを縮める")
        img, img_importance = seam_carving(img, img_importance)
        print("done")
    if(k == ord('b')) :
        cv2.imwrite("out.png", img)
