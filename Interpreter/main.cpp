#include <iostream>
#include <string>
#include "token.h"
using namespace std;
/*Creating a pascal type programming language with a debugger like 
pdb.This project will be in parts. Part 1 will be a simple interpreter 
of arithmetic expressions. Original code was written in python but I have
Repe*/
//fucntion declarations
std::vector<token> tokenFactory();
void printTokenFactory(std::vector<token>);
/*Token Types

EOF (end-of-file) token is used to indicate that 
there is no more input left for lexical analysis.
Here is my token class.*/
//token class funciton definitions

int main() {
	std::vector<token> token_dict;
	token_dict = tokenFactory();
	printTokenFactory(token_dict);

    return 0;
}
//creating a vector of tokens that can be used as a look up for the known constants
std::vector<token> tokenFactory(){
	std::vector<token> token_vect;
	//just going to add all of the tokens to the factory 
	//there might be a smarter way to do this but .... idk 
	std::string token_list[14] = {"ILLEGAL","EOF","IDENT","INT","ASSIGN",
								  "PLUS","COMMA","SEMICOLON","LPAREN",
								  "RPAREN","LBRACE","RBRACE","FUNCTION",
								  "LET"};
	for(int i = 0 ; i < 14; i++ ){
		token_vect.push_back(token(token_list[i]));
	}
	return token_vect;
}
void printTokenFactory(std::vector<token> token_list){
	cout << "--------\n";
	for(auto itr = token_list.begin(); itr != token_list.end(); itr++){
		cout << "TYPE : " << (*itr).getType() <<"\n"<<"VALUE : " <<(*itr).getValue()<<"\n";
	}
	cout << "--------\n";
}

//First let me make a constructor to then build the token vector
token::token(token & t, std::string t_type,std::string t_value){
	t.type = t_type;
	t.value = t_value;
}
token::token(){
	type = "UNKNOWN";
	value = "UNKNOWN";
}
//constructor used to conver the string literal to its type value pair 
token::token(std::string literal){
	type = literal;
	if(literal == "ILLEGAL" || "EOF" || "IDENT"||"INT"||"FUNCTION"||"LET"){
		value = literal;
	}if(literal == "ASSIGN"){
		value = "=";
	}if(literal == "PLUS"){
		value = "+";
	}if(literal =="COMMA"){
		value = ",";
	}if(literal == "SEMICOLON"){
		value = ";";
	}if(literal == "LPAREN"){
		value ="(";
	}if(literal == "RPAREN"){
		value = ")";
	}if(literal == "LBRACE"){
		value = "{";
	}if(literal == "RBRACE"){
		value = "}";
	}
}
std::string token::getValue(){return value;}
std::string token::getType(){return type;}




//Put this in a function 
// for (std::vector<std::string*>::iterator i = v.begin(); i != v.end(); ++i)
// {
// 	printf("%s\n", *(i));
// }