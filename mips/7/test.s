.text
.globl main
main:
L1: lb $t0, A($t2)
    beq     $t0,    $zero,  L2
    addi    $t2,    $t2,    1
    j       L1
L2: addi $t2, $t2, -1
    blt     $t2,    $zero,  L3
    lb      $t0,    A($t2)
    sb      $t0,    B($t3)
    addi    $t3,    $t3,    1
    j       L2
L3: li $v0,4
    la      $a0,    B
    syscall 
    li      $v0,    10
    syscall 
    jr      $ra
.data
A: .asciiz "OMIYA"
B: .space 5