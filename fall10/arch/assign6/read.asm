read:
		call rbsywt:	
		lodd 4092		
		subd c48:		
		jneg conv:
		push
		lodd cnt:		
		addd c1:
		stod cnt:
		jump read:
		
conv:   call rbsywt:    
        lodd 4092
		pop             
        addd num1:      
        stod num1:
		
        lodd cnt:       
        subd c1:
		stod cnt:
		jzer rsub:
		mult 10
		pop
        addd num1:
		stod num1:
        
        lodd cnt:       
		subd c1:
		stod cnt:
		jzer rsub:
		mult 10
        mult 10
		pop
        addd num1:
		stod num1:
		
        lodd cnt:       
		subd c1:
		stod cnt:
		jzer rsub:
		mult 10
        mult 10
        mult 10
		pop
        addd num1:
		stod num1:

        lodd cnt:       
		subd c1:
		stod cnt:
		jzer rsub:
		mult 10
        mult 10
        mult 10
        mult 10
		pop
        addd num1:
		stod num1:
        
        lodd cnt:       
		subd c1:
		stod cnt:
		jzer rsub:
		mult 10
        mult 10
        mult 10
        mult 10
        mult 10
		pop
        addd num1:
		stod num1:
		jump rsub:
