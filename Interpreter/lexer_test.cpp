#include "token.h"
#include "string"



void printTok(char);
//Creating a test ... I'm not gonna follow the go test example 
//I'm just going to print out what is seen and checking if the 
//token that is seen is correct 

void TestNextToken(){
	char * input "=+(){},;";

	for (int i = 0; i < input.size(); ++i)
	{
		printTok(input[i]);
	}
}
void printTok(char x){
	for (std::vector<const char*>::iterator i = v.begin(); i != v.end(); ++i)
	{
		if(x == *i){
			printf("%s\n",*i );
		}else{
			printf("Could not find token\n");
		}
		
	}
}
int main(){
	TestNextToken();
}