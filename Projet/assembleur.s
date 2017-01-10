.text
main:
# Assignation d'un entier
lw $t0,var_temp0
sw $t0,var_a

# Assignation d'un entier
lw $t0,var_temp1
sw $t0,var_b

# Multiplication d'un entier
lw $t0,var_temp2
lw $t1,var_a
mul $t0,$t0,$t1
sw $t0,var_temp3

# Assignation d'un entier
lw $t0,var_temp3
sw $t0,var_c

# Jump conditionel (==)
# Type int ou bool
lw $t1,var_a
lw $t2,var_b
beq $t1, $t2, label3

# Jump
j label7

label3:
# Soustraction d'un entier
lw $t0,var_b
lw $t1,var_temp4
sub $t0,$t0,$t1
sw $t0,var_temp5

# Assignation d'un entier
lw $t0,var_temp5
sw $t0,var_b

# Soustraction d'un entier
lw $t0,var_b
lw $t1,var_a
sub $t0,$t0,$t1
sw $t0,var_temp6

# Assignation d'un entier
lw $t0,var_temp6
sw $t0,var_c

# Soustraction d'un entier
lw $t0,var_c
lw $t1,var_temp7
sub $t0,$t0,$t1
sw $t0,var_temp8

# Assignation d'un entier
lw $t0,var_temp8
sw $t0,var_c

# Affichage d'un string
li $v0,4
la $a0,var_temp9
syscall

# Jump
j label20

label7:
# Addition d'un entier
lw $t0,var_b
lw $t1,var_temp10
add $t0,$t0,$t1
sw $t0,var_temp11

# Assignation d'un entier
lw $t0,var_temp11
sw $t0,var_b

# Addition d'un entier
lw $t0,var_b
lw $t1,var_a
add $t0,$t0,$t1
sw $t0,var_temp12

# Assignation d'un entier
lw $t0,var_temp12
sw $t0,var_c

# Addition d'un entier
lw $t0,var_c
lw $t1,var_temp13
add $t0,$t0,$t1
sw $t0,var_temp14

# Assignation d'un entier
lw $t0,var_temp14
sw $t0,var_c

# Affichage d'un string
li $v0,4
la $a0,var_temp15
syscall

# Jump conditionel (==)
# Type int ou bool
lw $t1,var_a
lw $t2,var_b
beq $t1, $t2, label12

# Jump
j label16

label12:
# Soustraction d'un entier
lw $t0,var_b
lw $t1,var_temp16
sub $t0,$t0,$t1
sw $t0,var_temp17

# Assignation d'un entier
lw $t0,var_temp17
sw $t0,var_b

# Soustraction d'un entier
lw $t0,var_b
lw $t1,var_a
sub $t0,$t0,$t1
sw $t0,var_temp18

# Assignation d'un entier
lw $t0,var_temp18
sw $t0,var_c

# Soustraction d'un entier
lw $t0,var_c
lw $t1,var_temp19
sub $t0,$t0,$t1
sw $t0,var_temp20

# Assignation d'un entier
lw $t0,var_temp20
sw $t0,var_c

# Affichage d'un string
li $v0,4
la $a0,var_temp21
syscall

# Jump
j label20

label16:
# Addition d'un entier
lw $t0,var_b
lw $t1,var_temp22
add $t0,$t0,$t1
sw $t0,var_temp23

# Assignation d'un entier
lw $t0,var_temp23
sw $t0,var_b

# Addition d'un entier
lw $t0,var_b
lw $t1,var_a
add $t0,$t0,$t1
sw $t0,var_temp24

# Assignation d'un entier
lw $t0,var_temp24
sw $t0,var_c

# Addition d'un entier
lw $t0,var_c
lw $t1,var_temp25
add $t0,$t0,$t1
sw $t0,var_temp26

# Assignation d'un entier
lw $t0,var_temp26
sw $t0,var_c

# Affichage d'un string
li $v0,4
la $a0,var_temp27
syscall

# Jump
j label20

# Jump
j label20

label20:
# Affichage d'un entier
li $v0,1
lw $a0,var_c
syscall

label21:
li $v0,10
syscall
.data
var_var_bool_false: .word 0
var_a: .word 0
var_b: .word 0
var_c: .word 0
var_temp0: .word -15
var_temp1: .word 5
var_temp2: .word -2
var_temp3: .word 0
var_temp4: .word 5
var_temp5: .word 0
var_temp6: .word 0
var_temp7: .word 2
var_temp8: .word 0
var_temp9: .asciiz "\nif"
var_temp10: .word 5
var_temp11: .word 0
var_temp12: .word 0
var_temp13: .word 2
var_temp14: .word 0
var_temp15: .asciiz "\n  2nd else if"
var_temp16: .word 5
var_temp17: .word 0
var_temp18: .word 0
var_temp19: .word 2
var_temp20: .word 0
var_temp21: .asciiz "\nif"
var_temp22: .word 5
var_temp23: .word 0
var_temp24: .word 0
var_temp25: .word 2
var_temp26: .word 0
var_temp27: .asciiz "\n 2nd else if"
