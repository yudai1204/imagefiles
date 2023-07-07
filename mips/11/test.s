.text
.globl main
main:
    li      $t0,    0
    lw      $t1,    N($t0)
    sll     $t1,    $t1,    2
loop1: addi $t1, $t1, -4
    beq     $t1,    $zero,  fin
    li      $t2,    0
    li      $t4,    4
loop2: lw $t3, A($t4)
    lw      $t0,    A($t2)
    bgt     $t3,    $t0,    skip
    sw      $t3,    A($t2)
    sw      $t0,    A($t4)
skip: addi $t2, $t2, 4
    addi    $t4,    $t4,    4
    blt     $t2,    $t1,    loop2
    j       loop1
fin: li $v0,10
    syscall 
    jr      $ra
.data
A: .word 6, 2, 5, 7, 4
N: .word 5