;; Eric Lima
;; Pset 5

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;;Excercise 1
(define (square-tree tree)
   (define nil '())
   (cond ((null? tree) nil)
         ((not (pair? (car tree)))
          (cons (square (car tree)) (square-tree (cdr tree))))
         (else (cons (square-tree (car tree))
                     (square-tree (cdr tree))))))
  
(define (square-tree2 tree) 
   (define nil '()) 
   (cond ((null? tree) nil) 
         ((not (pair? tree)) (square tree)) 
         (else (cons (square-tree2 (car tree)) 
                     (square-tree2 (cdr tree)))))) 
  
  
(define (square-treemap tree) 
   (define nil '()) 
   (map (lambda (x) 
          (cond ((null? x) nil) 
                ((not (pair? x)) (square x)) 
                (else (square-treemap x)))) 
        tree)) 
 ;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 2
(define (treemap proc tree)
   (cond ((null? tree) nil)
         ((pair? tree)  
          (cons  
           (treemap proc (car tree))  
           (treemap proc (cdr tree)))) 
         (else (proc tree)))) 

;; _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _
;; Exercise 3
(define (equal? x y) 
     (if (or 
             (eq? x y) 
             (and  
                 (or  
                     (and  
                         (pair? x)  
                         (pair? y))  
                     (and  
                         (null? x)  
                         (null? y))) 
                 (and  
                     (equal? (car x) (car y))  
                     (equal? (cdr x) (cdr y)))))  
         #t #f)) 

;; _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 4
|#An expression that starts with ' is internally converted to the form (quote <expression>). The interpreter sees (quote (quote abracadabra)) as a list and since car is applied to it we get the first thing from that list, which is a “quote”.#|

;; _ _ _ _ _ _ _  _ _ _ _ __ _ _ _ __ __ _
;; Exercise 5
(define (list1 l) 
   (if (= (length l) 2) 
       (list '+ (car l) (cadr l)) 
       (sum (car l) (list1 (cdr l))))) 
 (define (sum x y) 
   (cond ((=number? x 0) y) 
         ((=number? y 0) x) 
         ((and (number? x) (number? y)) (+ x y)) 
         (else (list1 (list x y))))) 
  
 (define (productlist l) 
   (if (= (length l) 2) 
       (list '* (car l) (cadr l)) 
       (productmake (car l) (productlist (cdr l))))) 
 (define (productmake x1 y2) 
   (cond ((or (=number? x1 0) (=number? y2 0)) 0) 
         ((=number? x1 1) y2) 
         ((=number? y2 1) x1) 
         ((and (number? x1) (number? y2)) (* x1 y2)) 
         (else (productlist (list x1 y2))))) 
  
 (define (augend s) 
   (let ((a (cddr s))) 
     (if (= (length a) 1) 
         (car a) 
         (list1 a)))) 
 (define (multiplicand p) 
   (let ((m (cddr p))) 
     (if (= (length m) 1) 
         (car m) 
         (productlist m))))   
;; _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 6
; Part A
(define (sum x y) 
   (cond ((=number? x 0) y) 
         ((=number? y 0) x) 
         (else (list x '+ y))))   
 (define (sum? x) (and (pair? x) (eq? (cadr x) '+)))
 (define (addend s) (car s))
 (define (augend s) (caddr s))
 (define (productmake x1 y2) 
   (cond ((=number? x1 1) y2) 
         ((=number? y2 1) x1) 
         ((or (=number? x1 0) (=number? y2 0)) 0) 
         (else (list x1 '* y2)))) 
  
 (define (product? x) (and (pair? x) (eq? (cadr x) '*))) 
 (define (multiplier x) (car x)) 
 (define (multiplicand x) (caddr x)) 


                              
;;  __ _ _ _ __ _ _ ___ _ _ __ _ _ _ _ __
;; Exercise 7
|#(subsets '(1 2 3))
rest ← (subsets '(2 3))
       rest ← (subsets '(3))
              rest ← (subsets '())
                     '(())
              (append '(()) (map ⟨...⟩ '(())))
              '(() (3))
       (append '(() (3)) (map ⟨…⟩ '(() (3))))
       '(() (3) (2) (2 3))
(append '(() (3) (2) (2 3)) (map ⟨…⟩ '(() (3) (2) (2 3))))
'(() (3) (2) (2 3) (1) (1 3) (1 2) (1 2 3))#|

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 8
; Part B
(define (cleaner sequence) 
   (if (null? (cdr sequence)) 
       (car sequence) 
       sequence)) 
  
  
 (define (augend x) 
   (cleaner (cddr x))) 
  
 (define (multiplicand x) 
   (cleaner (cddr x))) 
