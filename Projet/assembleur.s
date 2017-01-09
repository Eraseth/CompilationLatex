.text
main:
# Jump conditionelle (==)
# Type int ou bool
lw $t1,var_temp0
lw $t2,var_temp1
beq $t1, $t2, label0

# Jump
j label1

label0:
# Affichage d'un string
li $v0,4
la $a0,var_temp2
syscall

label2:
# Jump conditionelle (==)
# Type int ou bool
lw $t1,var_temp3
lw $t2,var_temp4
beq $t1, $t2, label1

# Jump
j label2

label1:
# Affichage d'un string
li $v0,4
la $a0,var_temp5
syscall

li $v0,10
syscall
.data
var_temp0: .word 4
var_temp1: .word 2
var_temp2: .asciiz "Baobab"
var_temp3: .word 4
var_temp4: .word 4
var_temp5: .asciiz "Baobab2"
