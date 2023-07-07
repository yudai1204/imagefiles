#dm 2022 template             
import sys

#二つの数値をコマンドライン引数から受け取る
#sys.argv[1]は文字列なので　int( X ) 関数で型変換
a = int(sys.argv[1])
b = int(sys.argv[2])


# !!以下を編集!!
for i in range(a*b):
    print("hello, world")