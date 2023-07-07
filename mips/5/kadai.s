.text
.globl main
main:
    la      $a0,    msg         # ラベルmsgは何番地？, $a0に入れる
    li      $s1,    0x41        # 大文字Aのアスキーコード
    li      $s2,    0x5a        # 大文字Zのアスキーコード
    li      $s3,    0x61        # 大文字aのアスキーコード
    li      $s4,    0x7a        # 大文字zのアスキーコード
L1: add $t2, $a0, $t1           # $t2: msgの頭から何文字目か, $t1: カウンタ
    lb      $t0,    0($t2)      # 1文字ロードする
    beq     $t0,    $zero,  L4  # ロードした文字のアスキーコードが0（NULL）なら終了
    blt     $t0,    $s1,    L3  # 大文字Aより小さい場合は飛ぶ（アルファベットでない）
    ble     $t0,    $s2,    L2  # Z以下なら、大文字と判定でき、変換処理に飛ぶ
    blt     $t0,    $s3,    L3  # 大文字でなくaより小さい場合は飛ぶ（アルファベットでない）
    bgt     $t0,    $s4,    L3  # 小文字zより大きい場合は飛ぶ（アルファベットでない）
L2: xori    $t0,    $t0,    0x20# 大文字は小文字に、小文字は大文字に変換 ・・・ ①
L3: sb      $t0,    0($t2)      # msg（メモリのデータ）に上書き
    addi    $t1,    $t1,    1   # 次の文字へ
    j       L1
L4: li $v0, 4
    la      $a0,    msg         # Output A to console
    syscall 
    li      $v0,    10
    syscall                     # exit
    jr      $ra
.data
msg: .asciiz "2toyoSU\n"
