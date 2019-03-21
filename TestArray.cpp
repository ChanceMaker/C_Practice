#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <iterator>


bool arePermutation(std::string ,std::string);
void replaceSpace(std::string *, int);
int main(){
	std::string sentence;

	std::cout << "Please enter the sentence \n";
	std::getline(std::cin, sentence);
	
    replaceSpace(&sentence,sentence.length());

   
}
//Function is supposed to replace all spaces with %20

void replaceSpace(std::string *x, int len){
	int space = 0;

	for(int i = 0 ; i < len; i++){
		//space position 
		if(x->at(i) == ' '){
			space++;
		}	
	}
	//add space to end and make an array 
	for(int j = 0 ; j < space; j++){
		x->append(" ");
		x->append(" ");
	}
	//create new array form string
	char* x_ary = (char*) malloc(x->length());
	//then turn it to a vector
	std::vector<char> v;
	for(int k = 0 ; k < x->length(); k++){
		v.push_back(x->at(k)) ;
	}

	for (int i = 0; i < x->length(); ++i)
	{
		if(v.at(i) == ' ' && space > 0){
			v.at(i) = '%';
			v.insert(v.begin() + i + 1,'2');
			v.insert(v.begin() + i + 2,'0');
			space--;
			// /
		}
	}
	//print out vector to make sure that it has
	//the right values.
	for (int i = 0; i < x->length(); ++i)
	{
		std::cout << v.at(i);
	}
	printf("\n");
	//move vector into the array 
	for (int i = 0; i < x->length(); ++i)
	{
		x->at(i) = v.at(i);
	}
	//now check the original array 
	printf("------NEW ARRAY-- -----\n");
	for (int i = 0; i < x->length(); ++i)
	{
		std::cout << x->at(i);
	}

	

	
}
bool arePermutation(std::string x, std::string y){
	if(x.length() != y.length()){
		return false;
	}
	if(x.compare(y) == 0){
		return true;
	}
	return false;
}