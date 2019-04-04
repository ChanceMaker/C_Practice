#include <iostream>
#include <vector>
#include <string>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) ;
};
//binary search algorithm used to find the firstBadVersion
int Solution::firstBadVersion(int n){
    long int endPnt = n;
    long int beginPnt = 1;

//binary search algorithm
    while(beginPnt < endPnt){
        int mid = beginPnt + (endPnt - beginPnt)/2;
        if(isBadVersion(mid)){
            endPnt = mid;
        }else{
            beginPnt = mid + 1;
        }

    }
    return beginPnt;
}


bool isBadVersion(int n){
    std::string input = "TTTTTFFFFFF";
    char x;
    if(n != 0){
        x = input.at(n - 1);
    }else{
        x = input.at(n);
    }


    if(x == 'F'){
        return true;
    }else{
        return false;
    }
}
int main(){
    Solution answer;

    std::cout <<"FIRST BAD VERSION : "<<answer.firstBadVersion(11);
    return 0;
}
    