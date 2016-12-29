.text
main:
# Addition d'un entier
lw $t0,var_a
lw $t1,var_a
add $t0,$t0,$t1
sw $t0,var_temp0

# Addition d'un entier
lw $t0,var_temp0
lw $t1,var_temp1
add $t0,$t0,$t1
sw $t0,var_temp2

# Addition d'un entier
lw $t0,var_temp2
lw $t1,var_temp3
add $t0,$t0,$t1
sw $t0,var_temp4

# Assignation d'un entier
lw $t0,var_temp4
sw $t0,var_c

# Assignation d'un entier
lw $t0,var_temp5
sw $t0,var_cbool

# Assignation d'un entier
lw $t0,var_temp6
sw $t0,var_cbool

# Affichage d'un entier
li $v0,1
lw $a0,var_c
syscall

label5:
# Jump conditionelle (==)
# Type int ou bool
lw $t1,var_v1
lw $t2,var_v2
beq $t1, $t2, label5
li $v0,4
la $a0,var_v1
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
var_v1: .word 5
var_v2: .word 5
var_cbool: .word 0
var_temp0: .word 0
var_temp1: .word 2
var_temp2: .word 0
var_temp3: .word 3
var_temp4: .word 0
var_temp5: .word 1
var_temp6: .word 0
