.text
main:

# Affichage d'un entier
li $v0,1
lw $a0,var_i
syscall

label1:
li $v0,10
syscall
.data
var_var_bool_false: .word 0
var_i: .word 0
var_temp0: .word 42
