main: lodd op1:
push
lodd op2:
push
call max:
insp 2
stod opres:
halt

max: lodl 1
subl 2
jneg first:
lodl 1
; push     <== not supposed to put answer on stack
retn
first: lodl 2
; push     <== not supposed to put answer on stack
retn
.LOC 50
op1: 10
op2: 5
opres: 0
