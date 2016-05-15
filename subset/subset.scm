#!/usr/bin/guile -s 
!#





(define (subset list) 
	(if (null? list)
		(cons '() '())
		(append (map (lambda (x) (cons (car list) x)) (subset (cdr list))) (subset (cdr list)))))

(display (for-each (lambda (x)  (display x) (newline)) (subset '(1 2 3 4 5)) ))
