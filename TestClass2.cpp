#include <stdio.h>

class vehicle{
	char const *make;
	char const *model;
	char const *type;
	int year;

public:
	//Default constructor
	vehicle();
	void printVehicle(){
		printf("%s\n",make);
		printf("%s\n",model);
		printf("%s\n",type);
		printf("%d\n",year);
	}

};

class car : public vehicle{
public:
	
};
vehicle::vehicle(){
	make = "Unknown";
	model = "Unknown";
	type = "Unknown";
	year = 0;

}
int main(){
	vehicle generic ;
	generic.printVehicle();

}