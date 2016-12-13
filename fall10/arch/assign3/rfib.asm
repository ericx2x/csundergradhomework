loop:   lodd count:
        jzer done:
        subd c1:
        stod count:

p1:     lodd daddr:
        pshi
        addd c1:
        stod daddr:
        call fib:
        insp 1

p2:     push
        lodd faddr:
        popi
        addd c1:
        stod faddr:
        jump loop:
	
fib:   lodl 1
       jzer fibzer:
       subd c1:
       jzer fibone:
       push
       call fib:
       push
       lodl 1
       subd c1:
       push
       call fib:
       insp 1
       addl 0
       insp 2
       retn

fibzer:lodd c0:
       retn

fibone:lodd c1:
       retn

done:  halt
      .loc 100
	
