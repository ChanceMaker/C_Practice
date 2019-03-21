//Vector Practice
#include <vector>
#include <iostream>
//mypair generic class
using namespace::std;
template <typename T,typename U>
class Car{
    T const *model,*make ;
    U year;
public:
    Car();
    Car(char const*,char const*,int);
    void printCar(){
        cout << "Make : " << this->make<<"\n";
        cout << "Model : " << this->model<<"\n";
        cout << "Year : " << this->year;
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
template <typename T,typename U>
Car<T,U>::Car() {
    this->make = "Generic";
    this->model = "Generic";
    this->year = 0;
}
template <typename T,typename U>
Car<T,U>::Car(char const *make, char const *model,int year){
    this->make = make;
    this->model = model;
    this->year = year;
}

template <typename T>
class mypair {
    T a, b;
public:
    mypair (T first, T second)
    {a=first; b=second;}
    T getmax ();
};


template <typename T>
T mypair<T>::getmax()
{
    T retval;
    retval = a>b? a : b;
    return retval;
}

template <typename T>
int compare(const T &x, const T &y){
    //Function template for compare
    if(x < y)return -1;
    if(y < x) return 1;
    return 0;
}
int main() {
    long m = 0;
    long n = 5;
    int x = 1;
    double y = 1.4;
    double w = 3.6;
    int answer = 0;
    answer = compare(n,m);
    if(answer == 1){
        std::cout << "less than\n";
    }
    else if(answer == -1){
        std::cout << "greater than\n";
    }
    else{

        std::cout << "equal\n";
    }

    mypair <int> theobject(348,342);
    std::cout << theobject.getmax();
    std::cout << " CAR TEST " << "\n";
    Car <char,int> ford ("Ford","Focus",1963);
    ford.printCar();
    return 0;
}
