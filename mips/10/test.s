.text
.globl main
main:
    li      $a0,    4
    addi    $sp,    $sp,    -4
    sw      $ra,    0($sp)
    jal     Fact
    lw      $ra,    0($sp)
    addi    $sp,    $sp,    4
    move    $s1,    $v0
    li      $v0,    10
    syscall 
    jr      $ra
Fact: addi $sp, $sp, -8
    sw      $s0,    4($sp)
    sw      $ra,    0($sp)
    li      $v0,    1
    beq     $a0,    $zero,  Fact_return
    move    $s0,    $a0
    addi    $a0,    $a0,    -1
    jal     Fact
    multu   $s0,    $v0
    mflo    $v0
Fact_return:
    lw      $s0,    4($sp)
    lw      $ra,    0($sp)
    addi    $sp,    $sp,    8
    jr      $ra
.data