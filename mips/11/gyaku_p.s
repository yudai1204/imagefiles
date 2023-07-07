# 逆ポーランド変換
.text
.globl main
main:
    li      $v0,    8                       # キーボードから文字列を入力(syscall 8番)
    la      $a0,    A
    li      $a1,    30
    syscall 
    li      $t3,    0                       # 配列Aのインデックス$t3
    lb      $t1,    A($t3)
    beq     $t1,    $zero,      PLEXT       # A[0]がNULLなら終了
                                            # ## 変換処理 ###
                                            # OSに戻るための戻り番地をスタックにpushする
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # OSへの戻り番地をpush
    addi    $sp,    $sp,        -4          # 領域確保
    li      $t8,    0xffffffff              # スタック清掃用の目印をpushする
    sw      $t8,    0($sp)                  # 戻り番地をpush
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     GETC                            # 1文字取り出す
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     EXP                             # 変換処理を開始
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    li      $t9,    0x0A                    # 改行文字のアスキーコード
    bne     $t1,    $t9,        EREND       # 最後の文字が改行文字でなければエラー
    li      $v0,    4                       # 変換結果をモニター出力（syscall 4番）
    la      $a0,    B                       # Output B to console
    syscall 
                                            # スタック上に残っているごみを通り越して、処理開始時点の$spまで
                                            # スタックポインタを戻す
                                            # これは、スタック内のデータが最後まできれいに最後までpopされない
                                            # 可能性があるため
CLEAR: lw $t6, 0($sp)                       # pop
    addi    $sp,    $sp,        4           # $spを戻していく
    li      $t8,    0xffffffff              # スタック清掃用の目印の値
    bne     $t6,    $t8,        CLEAR
    lw      $ra,    0($sp)                  # OSへの戻り番地をpop
    addi    $sp,    $sp,        4           # $spを戻す
                                            # 終了処理
PLEXT: li $v0,10
    syscall 
    jr      $ra
EREND: li $v0, 4                            # 変換結果をモニター出力（syscall 4番）
    la      $a0,    ERMSG                   # Output B to console
    syscall 
    j       CLEAR                           # CLEARに飛んで終了処理
                                            # mainのテキストセグメントのコードはここで終わり
                                            # ##############################################
                                            # この下から、データセグメントよりも前の部分に、関数のコードを書くこと
                                            # #### 関数 GETC #####
GETC: lb $t1, A($t3)                        # $t3は配列Aのインデックス, 1文字ロード
    addi    $t3,    $t3,        1           # Aのインデックスをカウントアップ
    li      $t9,    0x20                    # 空白文字のアスキーコード
    beq     $t1,    $t9,        GETC        # 空白文字なら再度、次の文字を取りに行く
    jr      $ra
                                            # #### 関数 TERM: 項の処理 #####
TERM: addi $sp, $sp, -4                     # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     FACTOR                          # 左の因子
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
T0: li $t9, 0x2A                            # "*" のアスキーコード
    beq     $t1,    $t9,        T1          # "*"ならT1に分岐
    li      $t9,    0x2F                    # "/"のアスキーコード
    bne     $t1,    $t9,        TERMEND     # "/"でないならTERMENDに分岐
T1: addi $sp, $sp, -4                       # 領域確保
    sw      $t1,    0($sp)                  # 演算子の文字コードをスタックにpush
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     GETC
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     FACTOR                          # 右の因子
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    lw      $t0,    0($sp)                  # 演算子の文字コードをpopし$t0に格納
    addi    $sp,    $sp,        4           # $spを戻す
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     STORE
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    j       T0
TERMEND: jr $ra
                                            # #### 関数 EXP: 式の処理 #####
EXP: addi $sp, $sp, -4                     # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     TERM                          # 左の因子
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
E0: li $t9, 0x2B                            # "+" のアスキーコード
    beq     $t1,    $t9,        E1          # "+"ならT1に分岐
    li      $t9,    0x2D                    # "-"のアスキーコード
    bne     $t1,    $t9,        EXPEND      # "-"でないならTERMENDに分岐
E1: addi $sp, $sp, -4                       # 領域確保
    sw      $t1,    0($sp)                  # 演算子の文字コードをスタックにpush
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     GETC
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     TERM                             # 右の因子
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    lw      $t0,    0($sp)                  # 演算子の文字コードをpopし$t0に格納
    addi    $sp,    $sp,        4           # $spを戻す
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     STORE
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    j       E0
EXPEND: jr $ra
FACTOR:
    li      $t9,    0x28                    # "(" のアスキーコード
    bne     $t1,    $t9,        P1          # 文字が"("でないならP1に分岐
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     GETC
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     EXP                             # 括弧の中の式
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    li      $t9,    0x29                    # ")" のアスキーコード
    bne     $t1,    $t9,        EREND       # 文字が")"でないならERENDに分岐, エラー
    j       GETC
P1: li $t9, 0x41                            # "A"のアスキーコード
    blt     $t1,    $t9,        EREND       # 文字のアスキーコードが"A"より小さければ
                                            # ERENDへ
    li      $t9,    0x5A                    # "Z"のアスキーコード
    bgt     $t1,    $t9,        EREND       # 文字のアスキーコードが"Z"より大きければ
                                            # ERENDへ
P2: move $t0, $t1                           # レジスタ内容をコピー
    addi    $sp,    $sp,        -4          # 領域確保
    sw      $ra,    0($sp)                  # 戻り番地をpush
    jal     STORE
    lw      $ra,    0($sp)                  # 戻り番地をpopして戻す
    addi    $sp,    $sp,        4           # $spを戻す
    j       GETC
                                            # #### 関数 STORE: 配列Bに格納 #####
STORE: sb $t0, B($t2)                       # 配列Bに1文字格納
    addi    $t2,    $t2,        1           # Bのインデックスをカウントアップ
    jr      $ra
                                            # データセグメント
.data
A: .space 30                                # 入力した文字列を格納
B: .space 30                                # 出力する文字列を格納
ERMSG: .asciiz "*ERROR*\n"                  # エラーメッセージ