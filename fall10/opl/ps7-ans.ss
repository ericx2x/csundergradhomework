;; Eric Lima
;; Pset 6
;;

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;;Excercise 1

named-object  ----> place
|
mobile-object -----> thing
|
person -----> troll

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 2

[heaven]

[dungeon]                            [computer-lab]      [dept-office]-----[tom-office]
  |                                         |                  |                 |
[network-closet]->[ systems-lab ]--->[elevator-lobby]---->[east-hall]-------[conf-room]
                  |                                            |                 |
               [west-hall]--------------------------------------           [ken-office]
                  |
              [robot-lab]     

;; _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _
;; Exercise 3

              
            
              pizza
                |
             [owner: 'holly mobile_obj:]
                |
             [named_obj:]                  ;; asci :*[
                
             
              
              
;; _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _
;; Exercise 4
; They are not the same item even if it does print the name. There is still two procedure objects so even though 
; it prints the same item they aren't necessarily the same item. I see pizza pizza is what holly says.

;; _ _ _ _ _ _ _  _ _ _ _ __ _ _ _ __ __ _
;; Exercise 5
                
|#' ((get-method mobile-obj 'install)self))) uses the embedded mobile-obj to figure out how to install the person using in our version. Louis' version does (ask mobile-obj 'INSTALL) and installs itself. The problem is when the birthplace the person can't be installed into its birthplace. mobile-obj goes into birthplace. The character can be in two places beacuse mobile-obj will stay even if the person moves, so Alyssa is correct. #|

;; _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _
;; Exercise 6
;a. A swathi is more restless. 
;b. Once every six clock ticks is when they will move at the same time.

;;  __ _ _ _ __ _ _ ___ _ _ __ _ _ _ _ __
;; Exercise 7
(define(make-student name birthplace threshold)
  (let((person (make-person name birthplace threshold))
       (passed-opl #f))
    (lambda (message)
      (cond ((eq? message 'take-opl)
             (lambda (self)
               (ask self'say '(I will take OPL))
               (set! passed-opl #t)
               #t))
            ((eq? message 'cheat-on-problem-set)
             (lambda (self)
               (ask self'say '(I failed))
               (set! passed-opl #f)
               #f))
            ((eq? message 'passed-opl?)
             (lambda (self)
               (if passed-opl
                   (ask self'say '(I have passed OPL))
                   (ask self'say'(I have not passed OPL)))
               passed-opl)))
      (else (get-method person message))))))

(define (make&install-student name birthplace threshold)
  (let((student(make-student name birthplace threshold)))
    (ask student 'install)
    student))

;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 8

(define you (make&install-student 'you computer-lab 100))
(define late-homework (make&install-thing 'late-homework computer-lab))

;transcript...

;You have late homework to give to Holly.

(ask you 'take late-homework)
; At computer-lab : you says-- I take late-homework
;Value: #t

(ask you 'go ' south)
;you moves from computer-lab to elevator-lobby
;Value: #t

(ask you 'go ' west)
;you moves from elevator-lobby to west-hall
;Value: #t

(ask you 'go 'north)
;you moves from west-hall to robot-lab
;At robot-lab :you says -- Hi holly
;Value: #t

(ask you 'lose late-homework)
;At robot-lab : you says -- I take late-homework
;Value: #t

(ask you 'take late-homework)
;At robot-lab : holly says -- I take late-homework
;Value: #t


;; _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __
;; Exercise 9

(define (make-advisor name birthplace threshold)
  (let((person (make-person name borthplace threshold)))
    (lambda (message) ¶
      (cond((eq? message 'advise)
          (lambda(self person)
            (if(method?(get-method person 'passed-opl?))
               (if(not(ask person 'passed-opl?))
                  (begin
                    (ask self'say (list(ask person 'name) "take OPL now!"))
                    (ask person 'take-opl)
                    (ask person 'move-to opl-classroom))
                  (ask self'say(list(ask person 'name) "has already taken opl.")))
               (ask self'say(list(ask person 'name) "is not a student")))))
           ((eq? message 'act )
          (lambda(self)
            (let((others(other-people-at-place self (ask self'place))))
              (if(not(null? other))
                 (for-each(lambda(person)ask self'advise person )) others)
              (get-method person message)))))
    (else(get-method person message)))))

(define (make&install-advisor name birthplace threshold)
  (let (( advisor(make-advisor name birthplace threshold)))
    (ask advisor 'install)
    advisor))

