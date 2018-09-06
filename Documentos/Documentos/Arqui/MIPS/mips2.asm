.data
	res:		.space 8				# Resultado del producto escalar
	tvector: 	.word 6 				# Tamaño de los vectores
	vector1: 	.word 6,7,8,9,4,1 			# Vector 1
	vector2: 	.word 2,3,5,4,6,7 			# Vector 2
	prmp01:	.asciiz "Hola!"
.text 

__start:
	li $s1, 6
	la $s0, vector1
	li $t0,0
	li $t2,0
	li $t3,0
loop:
	add $t4,$s0,$t3
	lw $t1, 0($t4)
	mul $t0,$t0,$t1
	addi $t2,$t2,1
	add $t3,$0,$t2
	add $t3,$t3,$t3
	add $t3,$t3,$t3
	beq $t2,$s1,endLoop
	j loop
	
endLoop:
	mtc1 $t0,$f8
	mtc1 $s1,$f9
	cvt.s.w $f8,$f8
	cvt.s.w $f9,$f9
	add.s $f12,$f8,$f9
	la $a0, prmp01
	li $v0, 4
	syscall
	li $v0, 2
	syscall
	li $v0, 10
	syscall