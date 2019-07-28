#include <iostream>
#include <string>
using namespace std;
/*Creating a pascal type programming language with a debugger like 
pdb.This project will be in parts. Part 1 will be a simple interpreter 
of arithmetic expressions. Original code was written in python but I have
Repe*/

/*Token Types

EOF (end-of-file) token is used to indicate that 
there is no more input left for lexical analysis.
Here is my token class.*/



token::token(token & t,auto _type,auto _value){
	t.type = _type;
	t.value = _value;
}
//token class funciton definitions

int main() {
    return 0;
}