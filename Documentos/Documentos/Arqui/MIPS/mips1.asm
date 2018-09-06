.data
	prompt2: .asciiz "Please enter value: "
	num: .word 
	
.text

main: 

	li $v0, 4
	la $a0, prompt2 
	syscall 


	li $v0, 5
	la $t0, num
	syscall

	li $v0, 1       
	li $t0, 5
	syscall         

	li $v0, 10
	syscall
