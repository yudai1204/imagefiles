# 配列要素中の3の倍数の個数を求める(配列から順に読み出して判定する)
    .text   # テキスト(プログラム)領域の開始
    .globl main
main:
    la $a0, A           # 配列Aの先頭アドレス, $a0に入れて取っておく
    la $a1, B           # 配列Aの先頭アドレス, $a1に入れて取っておく
    li $s0, 8           # 配列要素の個数
    li $s7, 4           # 配列要素の個数/2
    li $s1, 0           # sum(合計値)
    lw $s3, 0($a0)      # max(最大値)
    lw $s4, 0($a0)      # min(最小値)
L1: sll $t3, $t2, 2     # インデックス$t2の値を4倍にする
    add $t1, $a0, $t3   # 読み出す配列要素のアドレスを計算(A+i*4)
    lw $t0, 0($t1)      # メモリから1語ロードし、$t0に格納
    add $s1, $s1, $t0   # $s1(sum)に$t0を足す
    bgt $t0, $s3, L3    #$s3(max)より大きかったらL3に飛ぶ
    blt $t0, $s4, L4    #$s4(min)より小さかったらL3に飛ぶ
L2: addi $t2, $t2, 1    #インデックス$t2をカウントアップ(ループカウンタも兼用)
    bne $t2, $s0, L1    #$t2が8になっていなければL1に飛ぶ(ループする)
    j L5
L3: lw $s3, 0($t1)       #t0の値を最大値に代入
    j L2
L4: lw $s4 0($t1)       #t0の値を最小値に代入
    j L2
L6: addi $s2, $s2, 1
    j L7
L5: div $s1, $s0        #平均算出
    mflo $s2
    mfhi $s5
    bgt $s5, $s7, L6
L7: sw $s2, 0($a1)
    sw $s3, 4($a1)
    sw $s4, 8($a1)
#end
    li $v0,10
    syscall
    jr $ra
    .data   # データ領域の開始
A:  .word   8, 6, 10, 5, 7, 4, 6, 3
B:  .space  12