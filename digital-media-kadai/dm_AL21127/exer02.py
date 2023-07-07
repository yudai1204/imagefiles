#dm 2022 template
import sys

#1つの数値をコマンドライン引数から受け取る
N = int(sys.argv[1])


# !!このfor文の中を編集!!
for i in range(1,N+1):
    if i%15 == 0:
        print("hogefuga")
    elif i%3 == 0:
        print("hoge")
    elif i%5 == 0:
        print("fuga")
    else:
        print(i)
