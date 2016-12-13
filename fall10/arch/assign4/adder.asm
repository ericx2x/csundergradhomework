start: 	lodd daddr:
	push
	lodd dcnt:
	push
	call adder:
	stod rslt:
	halt
daddr:	8
	25
	50
	75
	100
	125
dcnt:	5
rslt:	0
	.LOC 20
adder:	lodl 1
	stod mycnt:
	lodl 2
	pshi 
	addd myc1:
	stod myptr:
loop:	lodd mycnt:
	subd myc1:
	jzer done:
	stod mycnt:
	lodd myptr:
	pshi
	addd myc1:
        stod myptr:
	pop
	addl 0
	insp 1
	push
	jump  loop:
done:	pop
	retn
	halt
mycnt:	0
myptr:	0
myc1:	1
	
