;;Tampugao, Mohammad Muraya

;; Sceheme Programming(Magic Racket of VSC): The program performs several processes in each function as follows:
;;A. Performs a simple factorial.
;;B. T-Ice function will allow you to input a certain number to be a range starting from 1 to that number, then it will check its divisibilities and return its corresponding output
;;C. Sumprimes will allow you to input a certain number then, from one up to that number it will identify the prime numbers then get the summation of it.
;;D. Perform Operations. Using two integers as input and choosing one operator
;;E. Calc-Distance is having 4 inputs and solve it using distance formula.
;;F. Count Factors ask for an integer as input in getting the number of factors of 1st number if divided to the second number.
;; The program tested using REPL of VSC

;;Programming Exercise 03 


#lang racket

;; A. Factorial Function
(define (factorial n)
  (let fact-loop ((n n) (res 1)) ;;local function (let binding) serves as tail-recursive helper function
    (if (= n 0)
        res
        (fact-loop (- n 1) (* res n)) ;;recursive call that performs multiplication to the given number and keeps decreasing until 0 is reached
     )
  )
)

;;Example of Usage (factorial 10)


;;B. T-Ice
(define (T-Ice n)
  (define (helper num)

    ;; this contains the divisibility conditions and its corresponding output
    (cond ((= (modulo num 2) 0) "T")
          ((= (modulo num 3) 0) "ICE")
          ((and (= (modulo num 2) 0) (= (modulo num 3) 0)) "T-ICE")
          (else (number->string num))))
  
  ;; for space character
  (define (display_space str)
    (display str)
    (display " "))
  
  ;;loop in traversing 1 up to the given number and be evaluated in the helper function
  (let loop ((i 1))
    (if (> i n)
        (void)  ; Return void when done
        (begin
          (display_space (helper i))
          (loop (+ i 1))))))

;;Example of Usage (T-Ice 8)


;; C. Sum of the primes numbers within the range of number
(define (Sumprimes n)
  (define (prime? x)
    (cond ((= x 1) #f)                      ; 1 is not a prime number, #f is a boolean for false
          ((= x 2) #t)                      ; 2 is a prime number; #t boolean for true
          ((even? x) #f)                    ; even numbers are not primes except 2
          (else
           (let loop ((i 3))                ; recursive loop
             (cond ((> i (sqrt x)) #t)      ; no need to check beyond the square root of x
                   ((zero? (remainder x i)) #f) ; if x is divisible by i, it's not a prime
                   (else (loop (+ i 2)))))))) ; increment i by 2 for odd numbers
;; this traverse from 1 to n then gather all the primes and add it to the total
  (define (sum_primes_helper current total)
    (if (> current n)
        total
        (if (prime? current)
            (sum_primes_helper (+ current 1) (+ total current))
            (sum_primes_helper (+ current 1) total))))

  (sum_primes_helper 1 0)) ; start from 1 and accumulate prime numbers

;; Example usage (Sumprimes 10)


;; D. Perform Operation Function
(define (perform-op m n opt)
  (cond ((char=? opt #\+) (+ m n)) ;;char=? is used for checking if two characters is the same 
        ((char=? opt #\-) (- m n))
        ((char=? opt #\*) (* m n))
        ((char=? opt #\/) (/ m n))
        ((char=? opt #\%) (remainder m n))
        (else (display "Invalid operator, choose again!!"))))

;;Example of Usage (perform-op 3 4 #\+)

;; E. Calculate Distance Function
(define (calc-distance x1 x2 y1 y2)  ;;this uses the the exponential and squarerooot functions to get the distance formula
  (sqrt (+ (expt (- x2 x1) 2)
           (expt (- y2 y1) 2))))


;;Example of Usage (calc-distance 1 2 3 4)


;; F. Count Factors Function
;; lambda is used to avoid the given conditions
(define (count-factors m n)
  (
    (lambda (m n) ;; lambda acts like an anonymous 
     (
        (lambda (factor)
            (factor factor m n 0) ;;function that passes it self as an argument to allow a recursion; one of the uses of lambda
        )

        (lambda (factor m n res)
            (cond ((= n 0) (if (=  res 0) "none"  res)) ;; res where it is stored
                ((= (remainder n m) 0) (factor factor m (floor (/ n m)) (+  res 1))) ;;recursive call of  f for updating the values
                (else (factor factor m (floor (/ n m))  res))
            )
         )

      )
     ) 
     m n
    )
)

;;Example of Usage (count-factors 48 4)








