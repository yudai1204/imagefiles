.text
.globl main
main:
    li $s1,0x41
    li $s2,0x5a
    li $s3,0x61
    li $s4,0x7a
    li $s5,0x20
    # 入力処理
    li $v0, 8
    la $a0, A
    li $a1, 100
    syscall
L1: lb $t0, A($t2)
    beq $t0, $zero, L6
    beq $t2, $zero, L3
    beq $t0, $s5, L5
    bne $t6, $zero, L3
    blt $t0, $s1, L2
    bgt $t0, $s2, L2
    xori $t0, $t0, 0x20
L2: sb $t0, B($t3)
    addi $t2, $t2, 1
    addi $t3, $t3, 1
    j L1
L3: blt $t0, $s3, L4
    bgt $t0, $s4, L4
    xori $t0, $t0, 0x20
L4: sb $t0, B($t3)
    li $t6, 0
    addi $t2, $t2, 1
    addi $t3, $t3, 1
    j L1
L5: li $t6, 1
    sb $t0, B($t3)
    addi $t2, $t2, 1
    addi $t3, $t3, 1
    j L1
L6: sb $zero, B($t3)
    li $v0, 4
    la $a0, B
    syscall
    li $v0, 10
    syscall
    jr $ra
.data
A: .space 101
B: .space 101