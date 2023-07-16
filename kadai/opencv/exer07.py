#  exer07.py exer07cv
# ターゲット画像とテンプレート画像を読み込み、Template Matchingにより
# テンプレートと最も似た領域『3か所』を発見しその部分に矩形を描画せよ。
# 
# > python exer07.py target.png template.png output.png
# target.png   : ターゲット画像のファイル名
# template.png : テンプレート画像のファイル名
# output.png   : 出力画像のファイル名

import numpy as np
import sys
import cv2

fname_in1 = sys.argv[1]
fname_in2 = sys.argv[2]
fname_out = sys.argv[3]

#画像を読み込み輝度画像へ変換（SSDがオーバーフローしないようfloat64にキャスト）
target_img   = cv2.imread(fname_in1)
template_img = cv2.imread(fname_in2)
target_img   = np.float64( cv2.cvtColor(target_img  , cv2.COLOR_RGB2GRAY) )
template_img = np.float64( cv2.cvtColor(template_img, cv2.COLOR_RGB2GRAY) )

# image size
H, W = target_img  .shape[0], target_img  .shape[1]
h, w = template_img.shape[0], template_img.shape[1]


#-------------------------------------------
#以下を編集


#-------------------------------------------


#画像を出力
cv2.imwrite(fname_out, target_img)
