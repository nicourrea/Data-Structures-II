# Project 3 — Binary Trees

Builds an expression tree from infix/postfix, reports size & leaf-count, and tests copy/assignment.

## Build
make

## Run (interactive)
./my_program
# when prompted:
# Enter in a postfix notation: 4 5 + 5 6 + /

## Run (one-liner)
echo "4 5 + 5 6 + /" | ./my_program

## Example Output
( 4 + 5 ) / ( 5 + 6 ) 
Number of Leaf Nodes in myinfix2: 4
Size of myinfix2: 7
Enter in a postfix notation: ( 4 + 5 ) / ( 5 + 6 ) 
Number of Leaf Nodes in myinfx1: 4
Size of myinfix1: 7
 Testing the assignment operator= overload
Size of myinfix3 (copied from myinfx2) is: 7
( 4 + 5 ) / ( 5 + 6 ) 
 Testing the copy constructor, creating myinfix4. 
Size of myinfix4 is: 7
( 4 + 5 ) / ( 5 + 6 )
