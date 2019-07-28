//
// Created by ChanceMaker on 7/21/2019.
//In this file is a definiton of the tokens that we will be using
//in this interpreter
//
#include <vector>
#include "string"


#ifndef INTERPRETER_TOKEN_H
#define INTERPRETER_TOKEN_H
typedef char* TokenType;

struct Token{
	TokenType type;
    std::string literal;
};
//token class
class token{

	std::string type,value;
public:
	//Base constructor for when you are given the 
	//token object
	token(token & t,auto,auto);
};
//Vector of tokentypes initialized as constants
std::vector< std::string> v{"ILLEGAL","EOF","IDENT","INTEGER",
					   "=","+",",",";","LPAREN","RPAREN",
					   "LBRACE","RBRACE","FUNCTION","LET"};
for (std::vector<std::string*>::iterator i = v.begin(); i != v.end(); ++i)
{
	printf("%s\n", *(i));
}
#endif //INTERPRETER_TOKEN_Hv