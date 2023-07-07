.text
.globl main
main:
li $s0, 3
li $s1, 11
li $s2, 26
li $s3, -4

add $t0, $s1, $s2
add $t1, $t0, $s3
sub $s4, $s0, $t1

# 終了処理
li $v0,10
syscall
jr $ra
.data # データ領域の開始