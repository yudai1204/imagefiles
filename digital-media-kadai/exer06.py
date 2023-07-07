#dm 2022 template
import numpy as np
import sys
import cv2

#get file names and threshold
fname_in  = sys.argv[1]
threshold = int( sys.argv[2] )
fname_out = sys.argv[3]

#load image
img = np.float32( cv2.imread(fname_in) )

height   = img.shape[0]
width    = img.shape[1]
img_gray = np.zeros((height, width), dtype=np.float32)



#!!ここを編集!!
#ヒント : 前課題のグレースケール化をそのまま使いつつ，
#        画素値がthreshold以上なら255を代入し，そうでなければ0を代入するとよい
for y in range(height) :
    for x in range(width) :
        #以下のコードでは，画像のr値をimg_grayに代入している(色はBGR順)
        blue  = img[y,x,0]
        green = img[y,x,1]
        red   = img[y,x,2]
        img_gray[y,x] = 255 if ((red + green + blue) >= threshold*3) else 0

#save image
cv2.imwrite(fname_out, np.uint8(img_gray) )
