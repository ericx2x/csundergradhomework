;; Eric Lima
;; Pset 1
;;
;;excercise 1

(define p1
  (lambda (x y)
    (+ (p2 x y) (p3 x y))))

(define p2
  (lambda (z w)
    (* z w)))

(define p3
  (lambda (a b)
    (+ (p2 a) (p2 b))))


;; The error was that the "procedure spindle: expects 1 argument, given 2:1 2" and the reason for this was because fold was calling spindle with two arguments so I deleted one of the arguments that fold was sending.
(define fold
  (lambda (x y)
    (* (spindle x)
       (+ (mutilate y)
          (spindle y)))))

(define spindle
  (lambda (w) (* w w)))

(define mutilate
  (lambda (z)
    (+ (spindle z) z)))
;; Tests: (spinde 2) = 4
;; (multilate 2) = 6
;; (fold 2 2) = 40
;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 2

(define fact
  (lambda (n)
    (if (= n 0)
        1
        (* n (fact (- n 1))))))
;; tests: (fact 4) = 24
;; _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _
;; Exercise 3
(define comb
  (lambda (n k)
    (/ (fact n) (* (fact k)(fact (- n k))))))
;;118206769052646517220135262
;; _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 4
(define quad
  (lambda (n)(* 4 n)))
;; tests: (quad 5)= 20
;; (quad -5) = -20
;; _ _ _ _ _ _ _  _ _ _ _ __ _ _ _ __ __
;; Exercise 5
(define quadifference
  (lambda (x y)(- (quad x)(quad y))))
;; _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 6
(define smallest
  (lambda (x y)(if(< x y)
                  x
                  y)))
;; tests: (smallest 3 2) = 2
;;  __ _ _ _ __ _ _ ___ _ _ __ _ _ _ _ __
;; Exercise 7
(define quadsmallest
  (lambda (x y)(quad(smallest x y))))
;; tests: (quadsmallest 3 2) = 8
;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 8
;; In order to re-indent in the region selected by the
;; mouse (or to reindent the current line if no region is selected by
;;the mouse) one must hit the Scheme menu and then hit reindent.
;; In order to re-indent an entire buffer one can press Ctrl+I
;; _ _ _ __ _ _ _ _  __ _ _ __ _ __ _ _ __
;; Exercise 9
;;4.2.3  Whitespace and comments

#|4.2.3  Whitespace and comments

Whitespace characters are spaces, linefeeds, carriage returns,
character tabulations, form feeds, line tabulations, and any other
character whose category is Zs, Zl, or Zp. Whitespace is used for
improved readability and as necessary to separate lexemes from each
other. Whitespace may occur between any two lexemes, but not within a
lexeme. Whitespace may also occur inside a string, where it is
significant.

The lexical syntax includes several comment forms. In all cases,
comments are invisible to Scheme, except that they act as delimiters,
so, for example, a comment cannot appear in the middle of an
identifier or representation of a number object.

A semicolon (;) indicates the start of a line comment.The comment
continues to the end of the line on which the semicolon appears.

Another way to indicate a comment is to prefix a <datum> (cf. section
4.3.1) with #;, possibly with <interlexeme space> before the <datum>.
The comment consists of the comment prefix #; and the <datum>
together. This notation is useful for .commenting out. sections of
code.

Block comments may be indicated with properly nested #|and |# pairs.


#|
   The FACT procedure computes the factorial
   of a non-negative integer.
|#
(define fact
  (lambda (n)
    ;; base case
    (if (= n 0)
        #;(= n 1)
        1       ; identity of *
        (* n (fact (- n 1))))))

The lexeme #!r6rs, which signifies that the program text that follows
is written with the lexical and datum syntax described in this report,
is also otherwise treated as a comment.
|#

#|(zero? z)    procedure
(positive? x)    procedure
(negative? x)    procedure
(odd? n)    procedure
(even? n)    procedure
(finite? x)    procedure
(infinite? x)    procedure
(nan? x)    procedure |#

;; _ __ _ __ _ _ _ _ _ __ _ _ __ _ _ _ _ __ _ _ _ _ _ _ _
;; Exercise 10
(define mystery
  (lambda (a b)
    (cond ((zero? b) 0)
          ((odd? b)
           (+ a (mystery (+ a a)
                         (quotient b 2))))
          (else
           (mystery (+ a a)
                    (quotient b 2))))))
(mystery 7 2)
;;about 25 steps
(define abs (lambda (x)
              (if (> 0 x)
                  (- 0 x)
                  x)))
(define square (lambda (x) (* x x)))
(define a -2.0)



(square(proc ( (x)
              (if (> 0 x)
                  (- 0 x)
                  x))))

(square(proc ( (a)
              (if (> 0 a)
                  (- 0 a)
                  a))))


(square(proc ( ((-2))
              (if (> 0 (-2))
                  (- 0 (-2))
                  (-2)))))
|#
({proc (x) (* x x)} -2)
[{proc (x) (* x x)} {-2}]
({proc (a) (* a a)} -2)
[{proc (a) (* a a)} {-2}]
(* {-2} {-2})
[{mult} {-2} {-2}])       
((lambda (a) (* a a)
({proc (a) (* a a)} -2)
[{proc (a) (* a a)} {-2}]
(* {-2} {-2})
[{mult} {-2} {-2}])
#|
