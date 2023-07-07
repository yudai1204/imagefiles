.text
.globl main

main:
la $a0, A

lw $t0, 4($a0)
lw $t1, 0($a0)
sw $t0, 0($a0)
sw $t1, 4($a0)

lw $t0, 8($a0)
lw $t1, 4($a0)
sw $t0, 4($a0)
sw $t1, 8($a0)

lw $t0, 12$a0)
lw $t1, 8($a0)
sw $t0, 8($a0)
sw $t1, 12($a0)

lw $t0, 16($a0)
lw $t1, 12($a0)
sw $t0, 12($a0)
sw $t1, 16($a0)

# 終了処理
li $v0,10
syscall
jr $ra
# データ領域の開始
.data
A: .word 5, 4, 3, 2, 1