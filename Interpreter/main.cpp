#include <iostream>
#include "token.h"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    Token x;

    x.token = "full";
    printf("%s \n", x.token.c_str());
    return 0;
}