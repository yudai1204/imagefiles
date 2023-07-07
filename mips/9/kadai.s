.text
.globl  main

main:

    li      $a0,    7
    addi    $sp,    $sp,    -4
    sw      $ra,    0($sp)
    jal     Func

    lw      $ra,    0($sp)
    addi    $sp,    $sp,    4
    move    $s1,    $v0
    li      $v0,    10
    syscall 
    jr      $ra

Func:
    bgt     $a0,    $zero,  L1
    move    $v0,    $zero
    jr      $ra

L1:
    addi    $sp,    $sp,    -8
    add     $t0,    $a0,    $a0
    addi    $t0,    $t0,    -1
    sw      $t0,    4($sp)
    sw      $ra,    0($sp)
    addi    $a0,    $a0,    -1
    jal     Func

    lw      $a0,    4($sp)

    add     $v0,    $v0,    $a0
    lw      $ra,    0($sp)
    addi    $sp,    $sp,    8
    jr      $ra
.data