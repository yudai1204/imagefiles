.text
.globl main
main:
addi $sp, $sp, -4
sw $ra, 0($sp)
li $a0, 5
li $a1, 3
jal MBA
move $t0, $v0
li $a0, 7
li $a1, 2
jal MBA
add $s0, $t0, $v0
lw $ra, 0($sp)
addi $sp, $sp, 4
li $v0,10
syscall
jr $ra
MBA: addi $a1, $a1, -1
move $v0, $a0
L1: addi $a1, $a1, -1
add $v0, $v0, $a0
bgt $a1, $zero, L1
jr $ra
.data