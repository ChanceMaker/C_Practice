//
// Created by ChanceMaker on 7/21/2019.
//In this file is a definiton of the tokens that we will be using
//in this interpreter
//
#include <vector>
#include "string"


#ifndef INTERPRETER_TOKEN_H
#define INTERPRETER_TOKEN_H

//token class
class token{
	std::string type,value;
public:
	//Base constructor for when you are given the 
	//token object
	token();
	token(token & ,std::string,std::string);
	token(std::string);//constructor that just takes a string and creates the token
	std::string getType();
	std::string getValue();

};


#endif //INTERPRETER_TOKEN_Hv