#include <iostream>
#include <vector>

/*
 *I can be placed before V (5) and X (10) to make 4 and 9.
 *X can be placed before L (50) and C (100) to make 40 and 90.
 *C can be placed before D (500) and M (1000) to make 400 and 900.
 * */
struct symbol {
    std::string name;
    int value;
};
std::vector<symbol> symbols= {
        {"M",1000},
        {"CM",900},
        {"D",500},
        {"CD",400},
        {"C",100},
        {"XC",90},
        {"L",50},
        {"XL",40},
        {"X",10},
        {"IX",9},
        {"V",5},
        {"IV",4},
        {"I",1}
};
int valfromSym(std::string x){//extract the value from the symbol vector.
    for(auto itr = symbols.begin(); itr != symbols.end(); itr++){
        if((*itr).name == x){
            return (*itr).value;
        }
    }
    return 0;
}
bool isSpecial(char x){
    switch(x){
        case 'I' : return true;
        case 'X' : return true;
        case 'C' : return true;
        default  : return false;
    }
}
std::vector<int> RomanToValVector(std::string x){
    std::vector<int> ans;
    for(int i = 0 ; i < x.size(); i++){
           if(i + 1 < x.size()){
               if(isSpecial(x.at(i))){
                   if(x.at(i) == 'I' && ((x.at(i + 1) == 'V') || (x.at(i + 1) == 'X' ))){
                       std::string s(1,x.at(i));
                       s.push_back(x.at(i + 1));
                       ans.push_back(valfromSym(s));
                       i++;
                   }else if(x.at(i) == 'X' && ((x.at(i + 1) == 'L') || (x.at(i + 1) == 'C'))){
                       std::string s(1,x.at(i));
                       s.push_back(x.at(i + 1));
                       ans.push_back(valfromSym(s));
                       i++;
                   }else if(x.at(i) == 'C' && ((x.at(i + 1) == 'D') || (x.at(i + 1) == 'M'))) {
                       std::string s(1, x.at(i));
                       s.push_back(x.at(i + 1));
                       ans.push_back(valfromSym(s));
                       i++;
                   }else{
                       std::string s(1,x.at(i));
                       ans.push_back(valfromSym(s));
                   }


               }else{

                   std::string s(1,x.at(i));
                   ans.push_back(valfromSym(s));
               }

           }else{
                std::string s(1,x.at(i));//create a string ouy of the character
                ans.push_back(valfromSym(s));

           }
    }
    return ans;
}

class Solution {
public:
    int romanToInt(std::string s) {
        int ans = 0;
        std::vector<int> valVect;
        valVect = RomanToValVector(s);
        for(auto itr = valVect.begin(); itr != valVect.end(); itr++){
            ans += *itr;
        }

        return ans;
    }
};
int main() {
    int ans;
    std::vector<std::string> checkRom;

    std::string inX = "D";
    Solution x_1;
    ans = x_1.romanToInt(inX);
    std::cout <<"THE VALUE IS : "<<ans;
    return 0;
}