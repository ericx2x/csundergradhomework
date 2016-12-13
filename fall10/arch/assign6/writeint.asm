write:  lodd num1:		
		jneg of:
		lodd addr:		
		swap
		stod tmp:
		lodd num1:
		stol 0
		lodd tmp:
		swap
		loco result:	
		call printf:
		lodd place:     
        push			
        push
write2: 
        lodd nl:		
        push
        lodd num1:
        push
        div
        pop
        stod num1:
        push
        jzer print:
        jump write2: 

print:
        insp 1
printt: pop
        jneg done:		
        addd c48:
        stod 4094
        call xbsywt:
        insp 3
        jump printt:
