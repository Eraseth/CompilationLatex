.text
main:
# Addition d'un réel
l.s $f0,var_temp0
l.s $f1,var_temp1
add.s $f0,$f0,$f1
s.s $f0,var_temp2

# Conversion d'un réel en entier et assignation
l.s $f2,var_temp2
cvt.w.s $f1,$f2
mfc1 $t1, $f1
sw $t1,var_c

# Addition d'un entier
lw $t0,var_temp3
lw $t1,var_temp4
add $t0,$t0,$t1
sw $t0,var_temp5

# Conversion d'un entier en réel et assignation
lw $t2,var_temp5
mtc1 $t2, $f12
cvt.s.w $f1,$f12
s.s $f1,var_c2

# Addition d'un réel
l.s $f0,var_temp6
l.s $f1,var_temp7
add.s $f0,$f0,$f1
s.s $f0,var_temp8

# Assignation d'un réel
l.s $f0,var_temp8
s.s $f0,var_c3

# Addition d'un entier
lw $t0,var_temp9
lw $t1,var_temp10
add $t0,$t0,$t1
sw $t0,var_temp11

# Assignation d'un entier
lw $t0,var_temp11
sw $t0,var_c4

# Affichage d'un entier
li $v0,1
lw $a0,var_temp12
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
var_temp0: .float 30.500000
var_temp1: .float 10.400000
var_temp2: .float 0.000000
var_temp3: .word 30
var_temp4: .word 10
var_temp5: .word 0
var_temp6: .float 30.500000
var_temp7: .float 10.800000
var_temp8: .float 0.000000
var_temp9: .word 12
var_temp10: .word 30
var_temp11: .word 0
var_temp12: .word 42
