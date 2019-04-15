#include <iostream>
#include <string>

void printString(std::string A){
    for (int i = 0; i < A.size() ; i++) {
        std::cout << A.at(i) << " ";
    }
    std::cout << "\n";
}
class Solution {
public:
    bool rotateString(std::string A, std::string B) ;

};
bool Solution::rotateString(std::string A, std::string B) {
    char tmpChar;
    std::string tmpStr;
    tmpStr = A;
    printString(A);
    for (int i = 0; i < A.size(); i++) {
        //possible rotation option
        char tmpChar = tmpStr.at(tmpStr.size() - 1);
        for (int j = A.size() - 1 ; j > 0; --j) {
            char  tmpChar2 = tmpStr.at(j - 1);
            tmpStr.replace(j,1,1,tmpChar2);
        }
        tmpStr.replace(0,1,1,tmpChar);
        if(tmpStr == B)
            return true;

    }
    return false;
}
int main() {
    Solution answer;
    bool isRotate = false;
    std::string strA = "12345";
    std::string strB = "51234";
    isRotate = answer.rotateString(strA,strB);

    std::cout << "Is possible : "<< isRotate;

    return 0;
}