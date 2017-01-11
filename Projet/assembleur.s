.text
main:
# Assignation d'un entier
lw $t0,var_temp0
sw $t0,var_a

# Assignation d'un entier
lw $t0,var_temp1
sw $t0,var_b

# Multiplication d'un entier
lw $t0,var_b
lw $t1,var_temp2
mul $t0,$t0,$t1
sw $t0,var_temp3

# Addition d'un entier
lw $t0,var_a
lw $t1,var_temp3
add $t0,$t0,$t1
sw $t0,var_temp4

# Negation d'un entier
lw $t0,var_temp4
neg $t0,$t0
sw $t0,var_temp5

# Assignation d'un entier
lw $t0,var_temp5
sw $t0,var_c

# Affichage d'un entier
li $v0,1
lw $a0,var_c
syscall

label3:
li $v0,10
syscall
.data
var_var_bool_false: .word 0
var_a: .word 0
var_b: .word 0
var_c: .word 0
var_temp0: .word 30
var_temp1: .word 10
var_temp2: .word -2
var_temp3: .word 0
var_temp4: .word 0
var_temp5: .word 0
