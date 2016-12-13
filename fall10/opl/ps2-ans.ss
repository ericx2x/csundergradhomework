;; Assignment 2
;; Eric Lima

; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
; Exercise 1

#|(define mult
  (lambda (x y)
    (define mult-helper 
      (lambda (y ans)
    (if(= y 0)
       ans
       (mult-helper (- y 1) (+ x ans)))))
  (mult-helper y 0)))
(mult 3 4)|#

(define (inc x)
(+ x 1))

(define (dec z)
(- z 1))

(define (z a b)
  (if (= a 0)
      b
      (inc (z (dec a) b))))

;(z 4 5)
;(inc(z (dec 4) 5))
;(inc(inc(z (dec 3) 5)))))
;(inc(inc(inc(z (dec 2) 5)))))
;(inc(inc(inc(inc(z (dec 1) 5))))))
;(inc(inc(inc(inc(5))))))
;(inc(inc(inc(6))))))
;(inc(inc(7)))))
;(inc(8))))
;9
;recursive

(define (x a b)
  (if (= a 0)
      b
      (x (dec a) (inc b))))
;(x 4 5)
;(x 3 6)
;(x 2 7)
;(x 1 8)
;(x 0 9)
;9
;iterative
; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
; Exercise 2
; recursive
(define f
  (lambda (n)
    (if (< n 3)
        n
        (+ (f(- n 1)) (* (f(- n 2)) 2) (* (f(- n 3)) 3)))))
; iterative
(define (fiter x)
  (fiter2 x 1 2 3 (- x 1)))

(define (fiter2 x a b c tmp)
  (if (< x 3)
           x
           (if (= 2 tmp)
               (+ b (* 2 a))
               (fiter2 x (+ b a) (+ c (* 2 a)) (* 3 a) (- tmp 1)))))

; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
; Exercise 3
; The tree will be drawn on the hard copy of this assignment.
















; _ _ _ _ _ _  _ _ _ _ __ _ __ _ _ __ _ _ _ _ _ _ _ _ _ _ _
; Exercise 4
(define (expt b n t result)
  (cond ((zero? n) result)
        ((even? n)  (expt (* b b) (/ n 2) t result))
        (t (expt b (- n 1) t (* b result)))))
; _ _ _ _ __ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
; Exercise 5
(define (remainder a b)
  (% a b))

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))
 (gcd 206 40) 
  
  
 (gcd 40 (remainder 206 40)) 
 (gcd (remainder 206 40) (remainder 40 (remainder 206 40))) 
 (gcd (remainder 40 (remainder 206 40)) (remainder (remainder 206 40) (remainder 40 (remainder 206 40))))
 (gcd (remainder (remainder 206 40) (remainder 40 (remainder 206 40))) (remainder (remainder 40 (remainder 206 40)) (remainder (remainder 206 40) (remainder 40 (remainder 206 40))))) 
  

 (remainder (remainder 206 40) (remainder 40 (remainder 206 40))) 





;(gcd 206 40)
;(gcd 40 (remainder 206 40)); remainder = 6
;(gcd 6 (remainder 40 6))); remainder = 4
;(gcd 4 (remainder 6 4))); remainder = 2
;(gcd 2 (remainder 4 2))); remainder = 0
;2
;4 remainder operations were used.


; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
; Exercise 6
 (define (itersum term a next b) 
  (define (iter a result) 
          (if (> a b) 
              result 
              (iter (next a) (+ result (term a))))) 
  (iter a 0)) 

; _ _ _ __ _ _ _ _ _ _ _ _ _ __ _ _ _ __ _ __ _ _ __ _ _ __
; Exercise 7
(define (product fun a next b)
  (if (> a b)
      1
      (* (fun a) (product fun (next a) next b))))

(define (factorial a)
  (define (identity x) x)
  (define (iter x) (+ x 1))
  (product identity 1 iter a))

(define (pi n)
  (define (numerator n)
    (cond ((= n 0) 2)
          ((even? n) (+ 2 (numerator (- n 1))))
          (else (numerator (- n 1)))))
  (define (denominator n)
    (cond ((= n 0) 1)
          ((even? n) (denominator (- n 1)))
          (else (+ 2 (denominator (- n 1))))))
  (define (pi-part n)
    (/ (numerator n) (denominator n)))
  (define (iter x) (+ x 1))
  (* 4 (product pi-part 1 iter n)))

; part b
(define (product fun a next b)
  (define (iter a total)
    (if (> a b)
        total
        (iter (next a) (* total (fun a)))))
  (iter a 1))

; _ _ _ _ _ _ _  _ _ _ ___ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
; Exercise 8
(define (accumulate combiner null-value term a next b)
  (define (iter a total)
    (if (> a b)
        total
        (iter (next a) (combiner total (term a)))))
  (iter a null-value))

(define (product fun a next b)
  (accumulate * 1 fun a next b))

;Part B
(define (accumulate combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a) (accumulate combiner null-value term (next a) next b))))
; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
; Exercise 9

(define (fast-expt b n)
  (cond ((= n 0) 1)
        ((even? n) (square (fast-expt b (/ n 2))))
        (else (* b (fast-expt b (- n 1))))))

(define (prime? n)
  (define (prime-test n times)
    (define (expmod base exp m)
      (cond ((= exp 0) 1)
            ((even? exp)
             (remainder (square (expmod base (/ exp 2) m))
                        m))
            (else
             (remainder (* base (expmod base (- exp 1) m))
                        m))))
    (define (fermat-test n)
      (define (try-it a)
        (= (expmod a n n) a))
      (try-it (+ 1 (random (- n 1)))))
    (fermat-test n))
  (prime-test n n))

(define (filtered-accumulate filter combiner null-value term a next b)
  (define (iter a total)
    (if (> a b)
        total
        (if (filter a)
            (iter (next a) (combiner total (term a)))
            (iter (next a) total))))
  (iter a null-value))

(define (sum-of-squared-primes a b)
  (define (next x) (+ x 1))
  (filtered-accumulate prime? + 0 square a next b))

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (product-of-pos-ints-uniquely-prime-to-n-lol n)
  (define (identity x) x)
  (define (incr x) (+ 1 x))
  (define (gcd-is-one a)
    (= (gcd a n) 1))
  (filtered-accumulate gcd-is-one * 1 identity 1 incr n))
; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
; Exercise 10
|#
 (f f) 
 (f 2) 
 (2 2) 
 ; This will create an error. Object 2 is not applicable. 
 #|