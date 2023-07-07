# dm 2022 template
# 画像の赤と緑チャンネルを交換する
import numpy as np
import sys
import cv2




#load image
img_size  = int(sys.argv[1])
fname_out = sys.argv[2]

#真っ黒な画像を作成
img = np.zeros((img_size, img_size), dtype = np.uint8)


#!!ここを編集
def isPrime(i):
    if i <= 1:
        return False
    for j in range(2, int(i**0.5) + 1):
        if i % j == 0:
            return False
    return True


sumy = 1
for y in range(img_size):
    sumx = 0
    for x in range(img_size):
        if isPrime(sumx + sumy):
            img[y, x] = 255
        sumx += (x+y+1)
    sumy += (y+2)

#save image
cv2.imwrite(fname_out, img )
