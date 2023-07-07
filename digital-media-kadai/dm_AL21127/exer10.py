# dm 2022 template
import numpy as np
import sys
import cv2

fname_in  = sys.argv[1]
fname_out = sys.argv[2]

#画像をロードして、グレースケール化して, float型へ変換
img = cv2.imread(fname_in)
img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
img = np.float64(img)

#出力画像を準備(グレースケール，float型)
img_out = np.zeros_like( img )



#!!以下を編集する!!
for y in range( 1, img.shape[0]-1 ) :
    for x in range( 1, img.shape[1]-1 ) :
        all = 2*sum([i for row in img[y-1:y+2, x-1:x+2] for i in row])
        all -= sum([i for row in img[y-1:y+2:2, x-1:x+2:2] for i in row])
        all += 2*img[y,x]
        img_out[y,x] = (all//16)

#float型からuint8型に変換し、書き出し
cv2.imwrite(fname_out, np.uint8( img_out) )
