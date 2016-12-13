;; Eric Lima
;; Pset 8
;;

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;;Excercise 1
(define (make-accumulator initialval) 
   (let ((sum initialval)) 
     (lambda (x)
       (set! sum (+ sum x))
       sum)))

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 2
(define (make-monitored f)
  (let ((number-of-calls 0))
    (define (mf a)
      (cond ((eq? a 'reset)
             (begin (set! number-of-calls 0)
                    0))
            ((eq? a 'how-many-calls) number-of-calls)
            (else (begin (set! number-of-calls
                               (+ 1 number-of-calls))
                         (f a)))))
    mf))





;; _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _
;; Exercise 3           
(define (make-account balance password)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)
  (define (display-error amount)
    "Incorrect password")
  (define (dispatch x m)
    (if (eq? x password)
        (cond ((eq? m 'withdraw) withdraw)
              ((eq? m 'deposit) deposit)
              (else (error "Error has occurred."
                           m)))
        display-error))
  dispatch)

;; _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 4
(define (make-account balance password)
  (let ((number-of-incorrect-password 0))
    (define (withdraw amount)
      (if (>= balance amount)
          (begin (set! balance (- balance amount))
                 balance)
          "Insufficient funds"))
    (define (deposit amount)
      (set! balance (+ balance amount))
      balance)
    (define (call-the-cops amount)
      (display "call the cops"))
    (define (display-error amount)
      "Incorrect password")
    (define (dispatch x y)
      (if (eq? x password)
          (begin (set! number-of-incorrect-password 0)
                 (cond ((eq? y 'withdraw) withdraw)
                       ((eq? y 'deposit) deposit)
                       (else (error "Error has occurred."
                                    y))))
          (begin (set! number-of-incorrect-password
                       (+ 1  number-of-incorrect-password))
                 (if (> number-of-incorrect-password 7)
                     call-the-cops
                     display-error))))
    dispatch))

;; _ _ _ _ _ _ _  _ _ _ _ __ _ _ _ __ __ _
;; Exercise 5
(define (make-balance balance)
  "This procedure is exclusively for balance management"
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)
  (define (dispatch m)
      (cond ((eq? m 'withdraw) withdraw)
            ((eq? m 'deposit) deposit)
            (else (error " Error has occurred."
                         m))))
  dispatch)

(define (make-account balance password)
  "This is a password procedure."
  (define (get-balance)
    (define balance-ref balance)
    balance-ref)
  (define (wrong-passwd arg)
    "Incorrect password")
  (define (check-pass pass)
    (eq? pass password))
  (define (set-passwd pass)
    (set! password pass))
  (define (dispatch passwd cmd)
    (if (eq? cmd 'check-passwd)
          (check-pass passwd)
        (if (eq? passwd password)
              (cond ((eq? cmd 'get-balance) (get-balance))
                    ((eq? cmd 'change-passwd) set-passwd)
                    ((eq? cmd 'check-passwd) #t)
                    (else (balance cmd)))
            wrong-passwd)))
  dispatch)

(define (make-joint-account accnt accnt-passwd passwd)
  (if (accnt accnt-passwd 'check-passwd)
      (make-account (accnt accnt-passwd 'get-balance) passwd)
      "Wrong passwd...")) 


(define peter-acc (make-account (make-balance 1000) 'open-sesame))

(display ((peter-acc 'open-sesame 'withdraw) 40)) (newline)
(display ((peter-acc 'open-sesame 'withdraw) 40)) (newline)
(display ((peter-acc 'open-sesame 'withdraw) 40)) (newline)
(display ((peter-acc 'some-other-password 'deposit) 50)) (newline)

(define paul-acc (make-joint-account peter-acc 'open-sesame 'rosebud))

(display ((paul-acc 'rosebud 'withdraw) 40)) (newline)
(display ((paul-acc 'rosebud 'withdraw) 40)) (newline)
(display ((paul-acc 'rosebud 'withdraw) 40)) (newline)
(display ((paul-acc 'some-other-password 'deposit) 50)) (newline)

((paul-acc 'rosebud 'change-passwd) 'lotus-leaf)
(display ((paul-acc 'lotus-leaf 'withdraw) 40)) (newline)

(display ((peter-acc 'open-sesame 'withdraw) 40)) (newline)

;; _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 6
(define f
  (let ((state 0))
    (define (switch-state x)
      (let ((old-state state))
        (set! state (+ x state))
        old-state))
    switch-state))

(f 0)
; 0
(f 1)
; 0

(f 1)
; 0
(f 0)
; 1
;;  __ _ _ _ __ _ _ ___ _ _ __ _ _ _ _ __
;; Exercise 7
(define (append! x y)
  (set-cdr! (last-pair x) y)
  x)

(define (last-pair x)
  (if (null? (cdr x))
      x
      (last-pair (cdr x))))

(define x (list 'a 'b))
(define y (list 'c 'd))
(define z (append x y))

;(display x)(newline)
;(display y)(newline)
;(display z)(newline)


(display (cdr x)) (newline)

(define w (append! x y))
(display w) (newline)

(display (cdr x)) (newline)






;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 8








;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 9
(define z3 '(a b c))
(count-pairs z3)
; 3

(define x '(a))
(define z4 (list x x))
z4
; ((a) (a))
(count-pairs z4)
; 4

(define x '(a))
(define y (cons x x))
y
; ((a) a)
(define z7 (cons y y))
z7
; (((a) a) (a) a)
(count-pairs z7)
; 7

(define zi '(a b c))
(set-cdr! (cddr zi) zi)
(count-pairs zi)























;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 10
(define (count-pairs x)
  (let ((aux '()))
    (define (count z)
      (cond ((not (pair? z)) 0)
            ((memq z aux) 0)
            (else
             (if (null? aux)
                 (set! aux (list z))
                 (set-cdr! (last-pair aux) (list z)))
             (+ (count (car z))
                (count (cdr z))
                1))))
    (count x)))

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 11
(define (cycle? x)
  (let ((aux '()))
    (define (find-cycle z)
      (cond ((null? z) false)
            ((memq z aux) true)
            (else
             (set-cdr! (last-pair aux) (list z))
             (find-cycle (cdr z)))))
    (if (not (pair? x))
        (error "Is a pair"))
    (set! aux (list x))
    (find-cycle (cdr x))))

(define (make-cycle x)
  (set-cdr! (last-pair x) x)
  x)
(define z1 (make-cycle (list 'a 'b 'c)))
(define z2 (cons 'q z1))

(cycle? z1)
; #t
(cycle? z2)
; #t
(cycle? (make-cycle '(a)))
; #t
(cycle? (list 'a 'b (make-cycle '(1 2 3 4)) 'c))
; #f






















7

 
 
8
 
9
 

