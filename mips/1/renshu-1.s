# 加算と減算のプログラム
.text # テキスト(プログラム)領域の開始
.globl main
main:
li $s0, 7
li $s1, 3
li $s2, 5
add $t0, $s0, $s1
sub $t1, $s0, $s1
sub $t2, $s2, $s0
# 終了処理
li $v0,10
syscall
jr $ra
.data # データ領域の開始