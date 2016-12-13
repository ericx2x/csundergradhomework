addints:
		pop
		stod addr:
        lodd on:		
		stod 4093
		stod 4095
		call xbsywt:
		loco hello:
		call printf:
		lodd place:
		push
		jump read:
                
rsub:   lodd cnt2:      
        subd c1:
        jzer write:
        stod cnt2:
        jump read:
        
of:		pop				
		loco overf:
		call printf:
		lodd c0:
		subd c1:
		retn

done:   pop             
		loco noth:		
		call printf:
		lodd c0:			
        halt
        
xbsywt:	lodd 4095       
		subd mask:
		jneg xbsywt:
		retn
		
rbsywt:	lodd 4093       
		subd mask:
		jneg rbsywt:
		retn
		
sb:		loco 8
loop1:	jzer finish:
		subd c1:
		stod lpcnt:
		lodl 1
		jneg add1:
		addl 1
		stol 1
		lodd lpcnt:
		jump loop1:
add1:	addl 1
		addd c1:
		stol 1
		lodd lpcnt:
		jump loop1:
finish:	lodl 1
        retn

num1:	0
c48:	48
nl:		10
cr:		13
cnt:	0
cnt2:   2
c1:		1
c0:     0
mask:	10
on:     8
place:  -1
addr:   0
tmp:	0
c255:	255
pstr1:	0
lpcnt:	0
hello:	"Enter two integers between 1 and 32767, please."
result: " Sum is "
overf:	"Overflow "
noth:	"  "
