.text
.globl main
main:
    li      $s0,    20                  # 要素数 5 のバイト数への換算値
    li      $s1,    16                  # 要素数より 1 少ない数の、バイト数への換算値
    li      $t1,    0
outloop:
    addi    $t2,    $t1,   4
    move    $t3,    $t1
    lw      $t4,    A($t1)
inloop: lw  $t8,    A($t2)
    bgt     $t4,    $t8,    skip
    move    $t4,    $t8
    move    $t3,    $t2
skip: addi $t2, $t2, 4
    blt     $t2,    $s0,    inloop
    lw      $t0,    A($t1)
    sw      $t0,    A($t3)
    sw      $t4,    A($t1)
    addi    $t1,    $t1,    4
    blt     $t1,    $s1,    outloop
fin: li $v0,10
    syscall 
    jr      $ra
                                        # データ・セグメント
.data
A: .word 7, 2, 1, 10, 15
