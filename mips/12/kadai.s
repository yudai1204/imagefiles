# 演習課題 二分探索木
.text
.globl main
main:
                                        # OS からの戻り番地$ra をスタックに push して保存、関数を呼び出す準備
    addi    $sp,    $sp,        -4
    sw      $ra,    0($sp)              # push
                                        # KEY をコンソールから入力
INLOOP: li $v0, 4                       # KEY を入力するよう表示
    la      $a0,    KMSG
    syscall 
    li      $v0,    5                   # KEY の値（整数値）をキーボード入力する準備 (1)
    syscall 
    move    $s6,    $v0                 # 入力された KEY を$s6 に格納
    beq     $s6,    $zero,      ENDPRC  # 入力された KEY 値が 0 なら終了処理へ (2)
    la      $a0,    first               # $a0: ラベル first の番地
    move    $a1,    $s6                 # $a1: 検索する KEY の値
    jal     BST
    j       INLOOP
                                        # 終了処理
ENDPRC: lw $ra, 0($sp)                  # スタックに退避した OS への戻り番地を pop
    addi    $sp,    $sp,        4       # $sp を戻す
    li      $v0,    4                   # 終了メッセージの表示
    la      $a0,    EDMSG
    syscall 
    li      $v0,    10
    syscall 
    jr      $ra                         # OS へ戻る
                                        # 関数 BST ($a0:ラベル first の番地, $a1:検索する KEY の値)
BST: lw $s1, 0($a0)                     # ROOT の NODE の先頭番地を$s1 に格納
    move    $t3,    $a0                 # ROOT が無い場合 first 番地に NODE を追加
    move    $t2,    $a1                 # 検索要素の KEY を$t2 に格納
    beq     $s1,    $zero,      ADDND   # NODE を追加する
LOOP: lw $t1, 0($s1)                                  # 現 NODE の KEY を$t1 に読み出す (3)
    move    $t2,    $a1                 # 検索要素の KEY を$t2 に格納
    beq     $t1,    $t2,        FOUND   # KEY が一致（見つけた）！
    blt     $t1,    $t2, RIGHT                # 現 NODE の KEY<検索要素の KEY なら右をたどる (4)
    addi    $t3,    $s1,        8       # 「左」ポインタが入っている番地を計算し$t3 に格納
    lw $t4, 0($t3)                                    # 現 NODE の左ポインタの値（番地）を読出し$t4 に格納 (5)
    j       NEXT
RIGHT: addi    $t3,    $s1,        12                                 # 「右」ポインタが入っている番地を計算し$t3 に格納 (6)
    lw      $t4,    0($t3)              # 現 NODE の右ポインタの値（番地）を読出し$t4 に格納
NEXT: beq $t4, $zero, ADDND             # ポインタの値が NULL なら NODE を追加
    move    $s1,    $t4                 # 次の NODE の先頭番地を$s1 に設定
    j       LOOP                        # 枝先に進む
# NODE の追加, NODE への KEY 値と VALUE 値の格納
ADDND: li $v0, 9                         # NODE を生成するため動的メモリ割当て (7)
    li $a0, 16                          # 16 バイトを確保 (8)
    syscall 
    move    $s2,    $v0                 # 新 NODE の先頭アドレスを$s2 にセーブ
    sw      $s2,    0($t3)              # 新 NODE を木に追加
    sw      $t2,    0($s2)              # KEY 値を新 NODE に格納
    li      $v0,    4
    la      $a0,    ADDMSG              # NODE 追加, VALUE 値の入力を促す
    syscall 
    li      $v0,    5                   # VALUE の値をキーボード入力
    syscall 
    move    $s7,    $v0                 # 入力された VALUE 値を$s7 に格納
    sw $s7, 4($s2)                      # VALUE 値を NODE に格納 (9)
    sw      $zero,  8($s2)              # 左ポインタを NULL に設定
    sw      $zero,  12($s2)             # 右ポインタを NULL に設定
    jr      $ra
                                        # 検索して木の中に見つけた場合, 木に格納されている KEY と VALUE を表示
FOUND: li $v0, 4                        # メッセージの表示
    la      $a0,    FDMSG
    syscall 
    # KEY と VALUE を 1 回ずつ$a0 に格納して syscall する！
    li      $v0,    1                   # 整数値の表示
    move    $a0,    $t1                 # 現 NODE の KEY 値を表示
    syscall 
    li      $v0,    4                   # 空白文字の表示
    la      $a0,    SPACE
    syscall 
    li      $v0,    1                   # 整数値の表示
    lw      $a0,    4($s1)              # 現 NODE の VALUE 値を表示 (10)
    syscall 
    li      $v0,    4                   # 改行文字の表示
    la      $a0,    NEWL
    syscall 
    jr      $ra
                                        # データ・セグメント
.data
first: .word 0
KMSG: .asciiz "顧客番号を入力して下さい: "
FDMSG: .asciiz "登録されています． 顧客番号と誕生日は: \n"
ADDMSG: .asciiz "無いので登録します．内線番号を入力して下さい: "
SPACE: .asciiz " "
NEWL: .asciiz "\n\n"
EDMSG: .asciiz "プログラムを終了します. \n"