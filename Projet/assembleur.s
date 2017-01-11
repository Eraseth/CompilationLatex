.text
main:
# Assignation d'un entier
lw $t0,var_temp0
sw $t0,var_b

# Assignation d'un entier
lw $t0,var_temp1
sw $t0,var_a

# Assignation d'un entier
lw $t0,var_temp2
sw $t0,var_c

# Assignation d'un entier
lw $t0,var_temp3
sw $t0,var_d

# Assignation d'un entier
lw $t0,var_temp4
sw $t0,var_e

label5:
# Jump conditionel (<)
# Type int ou bool
lw $t1,var_c
lw $t2,var_temp5
blt $t1, $t2, label6

# Jump
j label13

label6:
# Jump conditionel (>)
# Type int ou bool
lw $t1,var_a
lw $t2,var_temp6
bgt $t1, $t2, label7

# Jump
j label13

label7:
# Addition d'un entier
lw $t0,var_c
lw $t1,var_temp7
add $t0,$t0,$t1
sw $t0,var_temp8

# Assignation d'un entier
lw $t0,var_temp8
sw $t0,var_c

# Soustraction d'un entier
lw $t0,var_b
lw $t1,var_temp9
sub $t0,$t0,$t1
sw $t0,var_temp10

# Assignation d'un entier
lw $t0,var_temp10
sw $t0,var_b

# Affichage d'un string
li $v0,4
la $a0,var_temp11
syscall

# Affichage d'un entier
li $v0,1
lw $a0,var_e
syscall

# Affichage d'un string
li $v0,4
la $a0,var_temp12
syscall

# Addition d'un entier
lw $t0,var_e
lw $t1,var_temp13
add $t0,$t0,$t1
sw $t0,var_temp14

# Assignation d'un entier
lw $t0,var_temp14
sw $t0,var_e

# Jump
j label5

label13:
# Affichage d'un entier
li $v0,1
lw $a0,var_b
syscall

# Affichage d'un entier
li $v0,1
lw $a0,var_c
syscall

label15:
li $v0,10
syscall
.data
var_var_bool_false: .word 0
var_a: .word 0
var_b: .word 0
var_c: .word 0
var_d: .word 0
var_e: .word 0
var_temp0: .word 20
var_temp1: .word 50
var_temp2: .word -2
var_temp3: .word 54
var_temp4: .word 1
var_temp5: .word 20
var_temp6: .word 20
var_temp7: .word 1
var_temp8: .word 0
var_temp9: .word 1
var_temp10: .word 0
var_temp11: .asciiz "Nombre de passage : "
var_temp12: .asciiz " "
var_temp13: .word 1
var_temp14: .word 0
