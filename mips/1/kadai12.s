.text
.globl main
main:
li $s0, 2022
li $s1, 9
li $s2, 27

mult $s1, $s2
mflo $t0
sll $t1,$t0,1
div $s0, $t1
mflo $s3
mfhi $s4

# 終了処理
li $v0,10
syscall
jr $ra
.data # データ領域の開始