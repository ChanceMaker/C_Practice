#include <stdio.h>
#include <unordered_map>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*Function declarations*/
bool isUnique(string);
class Car{
	char const *model ="Generic" ;
	char const *make = "Generic";
	int year = 0;
public:
	Car();
	Car(char const *,char const *,int);
	void printCar(){
		printf("Make : %s\n",this->make);
		printf("Model : %s\n", this->model);
		printf("Year : %d\n",this->year);
	}
	char const *getMake(){
		return make;
	}
	char const * getModel(){
		return model;
	}
	int getYear(){
		return year;
	}
	setModel(char const * x){
		this->model = x;
	}
	setMake(char const * x){
		this->make = x;
	}
	setYear(int x){
		this->year = x;
	}


};
class ECar: public Car{
	int batteryLevel = 0;
public:
	//Default subclass constructor
	ECar():Car(){
		this->batteryLevel = 0;
	}
	//Battery Constructor
	ECar(int x):Car(){
		this->batteryLevel = x;
	}
	ECar(char const *make,char const *model,int year,int batteryLevel):Car(make,model,year){
		(*this).batteryLevel = batteryLevel;
	}
	ECar(char const *make,char const *model,int year):Car(make,model,year){	
	}
	void printBattery(){
		printf("Batery Level : %d\n",this->batteryLevel );
	}
	void chargeBattery(){
		this->batteryLevel = 100 ;
	}
};
Car::Car(){
	this->make = "Generic";
	this->model = "Generic";
	this->year = 0;
}
Car::Car(char const *make, char const *model,int year){
	this->make = make;
	this->model = model;
	this->year = year;
}
int main(){
	
	Car ford ("Ford","Focus",1963);
	ford.printCar();
	printf("\n");
	ECar tesla ("Tesla","X",2019);
	vector<Car> Car_lot ;
	Car_lot.push_back(ford);
	Car_lot.push_back(tesla);
	printf("----------------\n");
	/*Messing with vectors*/
	for(auto x : Car_lot){
		x.printCar();
	}
	printf("----------------\n");

	tesla.printCar();
	tesla.printBattery();
	tesla.chargeBattery();
	tesla.printBattery();
	

}

bool isUnique(string str){
	return false;
}