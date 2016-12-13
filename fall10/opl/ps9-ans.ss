;; Eric Lima
;; Pset 9
;;

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;;Excercise 1

(define (convert-temps stream)
(stream-map (lambda (x) (+ (* x (/ 5 9) 32)) stream ))
;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 2

(define (divisible? x b) (= (remainder x b) 0 ))
(define three-five-sevens
   (stream-filter (lambda (x)
      cond (divisble? x 3) true)
      (divisibe? x 5) true)
      (divisble? x 7) true)
      false))))
;; _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _
;; Exercise 3           

(define integers (cons-stream 1 (stream-map (lambda (x) (+ x 1) integers)))

;; _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 4

(define (show a)
   (display-line a)
a)
(define a (stream-map show (stream-enumerate-interval 0 10)))
; 0
; ; a
(stream-ref a 5)
; 1
; 2
; 3
; 4
; 5
 (stream-ref a 7)
; 6
; 7


;; _ _ _ _ _ _ _  _ _ _ _ __ _ _ _ __ __ _
;; Exercise 5

(define sum 0)
(define (accum a)
  (set! sum (+ a sum))
  sum)
(define seq (stream-map accum (stream-enumerate-interval 1 20)))
;  1
(define b (stream-filter even? seq))
;  6
(define c (stream-filter (lambda (a) (= (remainder a 5) 0))
                         seq))
;  10
(stream-ref b 7)
; 136
(display-stream c)
; 10
; 15`
; 45
; 55
; 105
; 120
; 190
; 210
; 210

;; _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 6

If s is 1, x1, x2, or x3, then s+s= 2, 2*x1, 2*x2, 2*x3.. The result will be x1=2, x2=4, x3=8, ...... so s is 1, 2, 4, 8, 16, 32 ...
;;  __ _ _ _ __ _ _ ___ _ _ __ _ _ _ _ __
;; Exercise 7

(define (mul-streams a b)
  (stream-map * a b))
(define factorials
  (cons-stream 1 (mul-streams
                  factorials
                  (integers-starting-from 2))))
;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 8

;Said not to do in an e-mail.
;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 9

The number of additions will exponentially grow in the way N(m) = N(m) = N(m-1) + N(m-2) + 1 assuming we don’t use memo-proc.

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 10

(define (stream-map proc . argstreams)
  (if (null? (car argstreams))
      the-empty-stream
      (cons-stream
       (apply proc (map stream-car argstreams))
       (apply stream-map
              (cons proc (map stream-cdr argstreams))))))
