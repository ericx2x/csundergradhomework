#lang scheme
(require (planet "sicp.ss" ("soegaard" "sicp.plt" 2 1)))
;; Eric Lima
;; Pset 4
;;



;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;;Excercise 1
;The first procedure will print out a black square. The x and y values are multiplied by each other so this causes whatever that multiplication to be to print to the screen which is somewhere between 0 and 1. The second will print a square with a gradient. The top right of the square will be white and it will grow black as it goes down right. This is because the coordinates given will start it going in one direction and changing colors as it grows. The third procedure will be a gradient from top to bottom, top being white and the bottom being black. This works the same way as the second one just with different coordinates.
;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 2
;The effect transform-painter does to the picture is distorts it to make the bottom left corner of the image to move halfway up to the left side. The bottom right corner is stretched to the middle of the top of the screen, and the top right will be flipped close to the bottom left of the screen. Basically, the image is flipped vertically then the image is streched to certain corners.
;; _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _
;; Exercise 3

(define my-number-painter( number->painter 5))

(define my-procedure-painter( procedure->painter (lambda (x y) (* 200 (abs(- x y))))))

(define my-segments-painter
(let ((v1 (make-vect .2 .3))
(v2 (make-vect .4 .6))
(v3 (make-vect .8 .7))
(v4 (make-vect .9 .6)))
(segments->painter
(list (make-segment v1 v2)
(make-segment v2 v3)
(make-segment v3 v4)))))

(define my-image-painter(load-painter "C:/Documents and Settings/Eric/My Documents/My Pictures/DrScheme.png"))
(paint my-image-painter)
;; _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 4

;; _ _ _ _ _ _ _  _ _ _ _ __ _ _ _ __ __
;; Exercise 5
(define diamond (transform-painter (make-vect 0 .5)
(make-vect .5 0)
(make-vect .5 1)))

(paint (diamond my-image-painter))

;; _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 6

(define (make-non-square-diamond x y z)
(transform-painter
(make-vect 0 y)
(make-vect x 0)
(make-vect z 1)))

(define (non-square-diamond-1)  ((make-non-square-diamond .2 .1 .9)my-segments-painter))

(paint (non-square-diamond-1))
                              
;;  __ _ _ _ __ _ _ ___ _ _ __ _ _ _ _ __
;; Exercise 7

(define (right-split painter n)
(if (= n 0)
painter
(let ((smaller (right-split painter (- n 1))))
(beside painter (below smaller smaller)))))

(paint (right-split my-image-painter 3))

(define (up-split painter n)
(if (= n 0)
painter
(let ((smaller (up-split painter (- n 1))))
(below painter (beside smaller smaller)))))

(paint (up-split my-image-painter 3))

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 8

(define (keep-combining combine-2)
  (lambda(painter n)
    (if(= n 0)
       painter
       (let ((smaller ((keep-combining combine-2) painter(- n 1))))
         (combine-2 painter smaller)))))




(define new-right-split
(keep-combining
(lambda (p1 p2)
(beside p1 (below p2 p2)))))


(define new-up-split
(keep-combining
(lambda (p1 p2)
(below p1 (beside p2 p2)))))

(paint(new-up-split my-image-painter 3))
;; _ _ _ __ _ _ _ _  __ _ _ __ _ __ _ _ __
;; Exercise 9

(define painter-9a
  (keep-combining
   (lambda(p1 p2)(superpose (diamond p1)(diamond(diamond p2))))))
(paint (painter-9a diagonal-shading 6))

(define painter-9b
(keep-combining
(lambda (p1 p2)
(below p1 p2)3)))
(painter-9b my-segments-painter 1)


;; _ __ _ __ _ _ _ _ _ __ _ _ __ _ _ _ _ __ _ _ _ _ _ _ _
;; Exercise 10
(define (left-split painter n)
(if (= n 0)
painter
(let ((smaller (left-split painter (- n 1))))
(beside painter (beside smaller smaller)))))
(paint (left-split my-image-painter 3))


(define painter-10a
  (keep-combining 
   (lambda(p1 p2)(superpose (diamond p1)(diamond(diamond(diamond p2)))))))
(paint (painter-10a diagonal-shading 6))

