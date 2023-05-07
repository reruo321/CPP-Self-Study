# These codes are from the CS book

.data
.text
.global main
proc:
    movq 16(%rsp), %rax
    addq %rdi, (%rsi)
    addl %edx, (%rcx)
    addw %r8w, (%r9)
    movl 8(%rsp), %edx
    addb %dl, (%rax)
    ret
    
main:
	# X1: rdi, &x1: rsi
	# X2: rdx, &x2: rcx
	# X3: r8,  &x3: r9
	# X4: (rsp)
	# X &x4: 8(rsp)
	
	subq $32, %rsp
	
	movq $1, 24(%rsp)
	movl $2, 20(%rsp)
	movw $3, 18(%rsp)
	movb $4, 17(%rsp)
	
	leaq 17(%rsp), %rax
	movq %rax, 8(%rsp)
	movl $4, (%rsp)
	
	leaq 18(%rsp), %r9
	movl $3, %r8d
	
	leaq 20(%rsp), %rcx
	movl $2, %edx
	
	leaq 24(%rsp), %rsi
	movl $1, %edi
	
	call proc
	
	movslq 20(%rsp), %rdx
	addq 24(%rsp), %rdx
	
	movswl 18(%rsp), %eax
	movsbl 17(%rsp), %ecx
	subl %ecx, %eax
	
	cltq
	imulq %rdx, %rax
	
	addq $32, %rsp
	ret
