;; Eric Lima
;; Pset 6
;;

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;;Excercise 1
;a.) It is impossible to apply a procedure operator to an expression or number. 

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 2
;Apply-generic was invoked twice.  Magnitude is the procedure dispatched in each case.
;; _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _
;; Exercise 3
(define (type-tag data)
  (cond ((pair? data) (car data))
        ((number? data) 'scheme-number)
        (else (error "ERROR" data))))

(define (contents data)
  (cond ((pair? data) (cdr data))
        ((number? data) data)
        (else (error "ERROR" data))))

(define (attach-tag type-tag contents)
  (if (number? contents)
      contents
      (cons type-tag contents)))

;; _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 4
(define (=zero? x)
  (apply-generic '=zero? x))

  (put '=zero? '(scheme-number)
       (lambda (x) (= x 0)))

  (put '=zero? '(rational)
       (lambda (x) (= (numer x) 0)))

  (put '=zero? '(complex)
       (lambda (x) (= (magnitude x) 0)))

(install-scheme-number-package)
(install-rational-package)
(install-rectangular-package)
(install-polar-package)
(install-complex-package)

(=zero? (make-scheme-number 3.2))

(=zero? (make-scheme-number 0))

;; _ _ _ _ _ _ _  _ _ _ _ __ _ _ _ __ __ _
;; Exercise 5
#|If we call exp with two complex numbers, Louis’s program will enter an inifinite loop of calling apply-generic. 
Louis’s program is an infinite loop. It just calls apply-generic over and over again.
Louis is not correct about something having to be done about coercion with arguments of the same type.  Both t1->t2 and t2->t1 will have the value of false, and an error message will be correctly displayed.|#
(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (apply proc (map contents args))
          (if (= (length args) 2)
              (let ((type1 (car type-tags))
                    (type2 (cadr type-tags))
                    (a1 (car args))
                    (a2 (cadr args)))
                (if (equal? type1 type2)
                    (error "No method"
                           (list op type-tags))
                    (let ((t1->t2 (get-coercion type1 type2))
                          (t2->t1 (get-coercion type2 type1)))
                      (cond (t1->t2
                             (apply-generic op (t1->t2 a1) a2))
                            (t2->t1
                             (apply-generic op a1 (t2->t1 a2)))
                            (else
                             (error "No method"
                                    (list op type-tags)))))))
              (error "No method"
                     (list op type-tags)))))))



;; _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 6
(define (apply-generic op . args)
  (define (try-convert a xtype)
    (let ((converter (get-coercion (type-tag a) xtype)))
      (if converter
          (converter a)
          a)))
  (define (apply-generic1 op args tlist)
    (if (null? tlist)
        (error "No method"
               (list op (map type-tag args)))
        (let ((new-args (map (lambda (a)
                               (try-convert a (car tlist)))
                             args)))
          (let ((xttags (map type-tag new-args)))
            (let ((proc (get op xttags)))
              (if proc
                  (apply proc (map contents new-args))
                  (apply-generic1 op args (cdr tlist))))))))
  (let ((ttags (map type-tag args)))
    (let ((proc (get op ttags)))
      (if proc
          (apply proc (map contents args))
          (apply-generic1 op args ttags)))))

;The apply-generic procedure will fail. If we wanted it to work then we would have to conver type 1 to type 3 and make a procedure that will correctly apply the procedure to the original type of object.                              
;;  __ _ _ _ __ _ _ ___ _ _ __ _ _ _ _ __
;; Exercise 7
(define (raise a) (apply-generic 'raise a))

  (put 'raise '(scheme-number)
       (lambda (a)
         (if (exact-integer? a)
             (make-rational a 1)
             (make-complex-from-real-imag a 0))))

  (put 'raise '(rational)
       (lambda (r)
         (make-scheme-number (exact->inexact (/ (numerator r) (denominator r))))))

(raise (make-rational 4 2))

(raise (make-scheme-number 1))
;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 8
 (define (tower-level a)
  (let ((typea (ttag a)))
    (cond ((eq? typea 'rational) 1)
          ((eq? typea 'complex) 3)
          (else ; scheme-number
           (let ((b (contents a)))
             (if (exact-integer? b)
                 0
                 2))))))
(define (raise-to level a)
  (if (= level (tower-level a))
      a
      (raise-to level (raise a))))

(define (apply-generic op . args)
  (let ((ttags (map ttag args)))
    (let ((proc (get op ttags)))
      (if proc
          (apply proc (map contents args))
          (if (= (length args) 2)
              (let* ((a1 (car args))
                     (a2 (cadr args))
                     (level1 (tower-level a1))
                     (level2 (tower-level a2)))
                (cond ((< level1 level2)
                       (apply-generic op (raise-to level2 a1) a2))
                      ((< level2 level1)
                       (apply-generic op a1 (raise-to level1 a2)))
                      (else
                       (error "No method"
                              (list op ttags)))))
              (error "No method"
                     (list op ttags)))))))

 (install-scheme-number-package)
(install-rational-package)
(install-rectangular-package)
(install-polar-package)
(install-complex-package)
(install-coercion-package)

(add (make-rational 4 3) (make-scheme-number 2.0))

(mul (make-rational 4 3) (make-complex-from-mag-ang 3.0 0.55))

(sub (make-scheme-number 2.0) (make-complex-from-real-imag 1.0 5.0))