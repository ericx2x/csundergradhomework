main:					
		loco Label2:		;the result will be stored using by loading this.
		push
		call Label3:	        ;call Label3 function
		halt			

Label3:
		pop
		stod addr:
        lodd on:		      
		stod 4093
		stod 4095
		call xbsywt:
		loco prompt:
		call printf:
		lodd place:
		push
        
read:                              ;loop
		call rbsywt:	        ;this is running through the input
		lodd 4092		
		subd c48:		 ;conversion to digit
		jneg conv:
		push
		lodd cnt:		
		addd c1:             
		stod cnt:
		jump read:	        ;end loop


conv:   call rbsywt:                   
        lodd 4092
		pop                     ;least significant digit is used here
        addd Label1:                
        stod Label1:
		
        lodd cnt:                   ;move to next significant digit if cnt isn't zero.
        subd c1:
		stod cnt:
		jzer rsub:
		mult 10
		pop
        addd Label1:
		stod Label1:
        
        lodd cnt:                       ;add sig digit if cnt isn't zero.
		subd c1:
		stod cnt:
		jzer rsub:
		mult 10
        mult 10
		pop
        addd Label1:
		stod Label1:
		
        lodd cnt:                       ;same basic method used above.
		subd c1:
		stod cnt:
		jzer rsub:
		mult 10
        mult 10
        mult 10
		pop
        addd Label1:
		stod Label1:
							; "  "  "   "   "
        lodd cnt:                      
		subd c1:
		stod cnt:
		jzer rsub:
		mult 10
        mult 10
        mult 10
        mult 10
		pop
        addd Label1:
		stod Label1:
        
        lodd cnt:                       ; "  "  "   "   "
		subd c1:
		stod cnt:
		jzer rsub:
		mult 10
        mult 10
        mult 10
        mult 10
        mult 10
		pop
        addd Label1:
		stod Label1:
        
rsub:   lodd cnt2:                    
numbers
        subd c1:
        jzer save:
        stod cnt2:
        jump read:
        
of:
	        pop			;call to print overflow
		loco overf:
		call printf:
		lodd c0:
		subd c1:
		retn

save:  lodd Label1:		        ;check's overflow
		jneg of:
		lodd addr:	  	;saves the result for use
		swap
		stod tmp:
		lodd Label1:
		stol 0
		lodd tmp:
		swap
		loco result:	        ;print result string
		call printf:
		lodd place:           
        push			        
        push
save2: 
        lodd nl:		        
        push
        lodd Label1:
        push
        div
        pop
        stod Label1:
        push
        jzer print:
        jump save2: 

print:
        insp 1
printt: po
        jneg done:		        
        addd c48:
        stod 4094
        call xbsywt:
        insp 3
        jump printt:
        
printf:                             ;loop
		pshi
		addd c1:
		stod pstr1:
		pop
		jzer crnl:
		stod 4094
		push
		subd c255:
		jneg crnl:
		call sb:
		insp 1
		push
		call xbsywt:
		pop
		stod 4094
		call xbsywt:
		lodd pstr1:
		jump printf:	        ;endloop
crnl:
	lodd cr:
		stod 4094
		call xbsywt:
		lodd nl:
		stod 4094
		call xbsywt:
		retn

done:
	pop				
		loco noth:		
		call printf:
		lodd c0:		
		retn

xbsywt:
	lodd 4095                       
		subd mask:
		jneg xbsywt:
		retn
		
rbsywt:	lodd 4093                       
		subd mask:
		jneg rbsywt:
		retn
		
sb:		loco 8
loop1:
	jzer done:
		subd c1:
		stod lpcnt:
		lodl 1
		jneg add1:
		addl 1
		stol 1
		lodd lpcnt:
		jump loop1:
add1:
	addl 1
		addd c1:
		stol 1
		lodd lpcnt:
		jump loop1:
done:
	lodl 1
        retn

.LOC 200
Label1:	0
Label2:	0
c48:	48
nl:	10
cr:	13
cnt:	0
cnt2:   2
c1:	1
c0:     0
mask:	10
on:     8
place:  -1
addr:   0
tmp:	0
c255:	255
pstr1:	0
lpcnt:	0
prompt:	"Enter two integer numbers between 1 and 32767:"
result: "Answer ="
overf:	"Error. There is overflow."
noth:	"  "
