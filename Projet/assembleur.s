.text
main:
lw $t0, temp2
lw $t1, temp3
add $t1,$t0,$t1
sw $t0, temp4

lw $t0, b
lw $t1, temp5
sub $t1,$t0,$t1
sw $t0, temp6

li $v0,10
syscall
.data
a: .word 42
lo: .float 5.500000
b: .word 0
c: .float 0.000000
d: .word 0
temp0: .word 30
temp1: .word 10
temp2: .word 30
temp3: .word 10
temp4: .word 0
temp5: .word 2
temp6: .word 0
