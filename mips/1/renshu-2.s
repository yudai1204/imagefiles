.text
.globl main
main:
# 7*9
li $s0, 7
li $s1, 9
mult $s0, $s1
mflo $t0
# 1 * -2
li $s2, 1
li $s3, -2
mult $s2, $s3
mfhi $t1
mflo $t2
# 52 / 6
li $s4, 52
li $s5, 6
div $s4, $s5
mflo $t3
mfhi $t4

# 終了処理
li $v0,10
syscall
jr $ra
.data # データ領域の開始