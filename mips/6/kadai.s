.text
.globl main
main:
    li      $s0,    5           # 三角形の底辺の長さN
    la      $a0,    A
    li      $s1,    0x2A        # 文字*のアスキーコード
    li      $s2,    0x0A        # ¥nのアスキーコード
L1: addi $t1, $t1, 1            # 行カウンタをカウントアップ
    bgt     $t1,    $s0,    L3  # 行カウンタの値>底辺の値ならループを抜ける
L2: sb $s1, A($t7)              # *をストア
    addi    $t7,    $t7,    1   # インデックスレジスタをカウントアップ
    addi    $t2,    $t2,    1   # ループカウンタをカウントアップ
    blt     $t2,    $t1,    L2  # その行で必要な"＊"の描画は済んだか
    sb      $s2,    A($t7)      # 引き続きその行に¥nを格納
    addi    $t7,    $t7,    1
    move    $t2,    $zero       # ループカウンタをゼロ・クリア
    j       L1
L3: li      $v0,    4
    la      $a0,    A           # 配列Aに格納された文字列をコンソールに出力
    syscall 
    li $v0,10
    syscall 
    jr      $ra
.data
A: .space 54                    # 設問1では10でよいが設問2では54必要なため