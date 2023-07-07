.text
.globl main
main:
    li $v0, 5 # キーボードから整数値を入力するsyscall の準備
    syscall
    move $s0, $v0 # 入力された整数値を別のレジスタにコピー
    li $t0, 0x0A # ¥nのアスキーコード
L1: jal Linedisp
    addi $s0, $s0, -1
    bgt $s0, $zero, L1
    j L3

Linedisp: 
    addi $t1, $s0, 0x30
    move $t5, $zero
L2: sb $t1, A($t7) # 数字をストア
    addi $t5, $t5, 1
    addi $t7, $t7, 1
    blt $t5, $s0, L2
    sb $t0, A($t7)
    addi $t7, $t7, 1
    jr $ra

L3: li $v0, 4
    la $a0, A # Output A to console
    syscall
    li $v0,10
    syscall
    jr $ra
.data
A: .space 55