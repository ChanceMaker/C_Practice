#include "string"
#include <bitset>

typedef bitset<8> byte;
//Lexer 

struct Lexer{
	std::string input ;
	int position;//current position in input (points to current char)
	int readPosition; //current reading position in input (after current char)
	char ch //current char under examination 

}
Lexer New(std::string input){
	
}