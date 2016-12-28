.text
main:
# Affichage d'un entier
li $v0,1
lw $a0,var_temp0
syscall

# Affichage d'un entier
li $v0,1
lw $a0,var_temp1
syscall

# Affichage d'un string
li $v0,4
la $a0,var_temp2
syscall

li $v0,10
syscall
.data
var_a: .word 42
var_lo: .float 5.500000
var_c: .word 0
var_c2: .float 0.000000
var_c3: .float 0.000000
var_c4: .word 0
var_temp0: .word 5
var_temp1: .word 42
var_temp2: .asciiz "Bob"
