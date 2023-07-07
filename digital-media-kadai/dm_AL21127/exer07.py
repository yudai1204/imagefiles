#dm 2022 template
# 画像の赤と緑チャンネルを交換する
import numpy as np
import sys
import cv2

#load image
fname_in  = sys.argv[1]
fname_out = sys.argv[2]

img    = cv2.imread(fname_in)

#!!ここを編集
height   = img.shape[0]
width    = img.shape[1]

for y in range(height) :
    for x in range(width) :
        #以下のコードでは，画像のr値をimg_grayに代入している(色はBGR順)
        blue  = img[y,x,0]
        img[y,x,1] , img[y,x,2] = img[y,x,2] , img[y,x,1]
        

#save image
cv2.imwrite(fname_out, img )
