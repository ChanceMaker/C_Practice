#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    int search(std::vector<int>& nums, int target) ;
    void printVec(std::vector<int>& nums);
};

int Solution::search(std::vector<int>& nums, int target){
    std::vector<int> reOrdered;
    std::vector<int> rankVec;
    int tmpRank = 0;
    int pos = 0;
    for(auto itr = nums.begin(); itr != nums.end(); itr++){
        if(*itr == target){
            pos = itr - nums.begin();
            return pos;
        }
    }

    std::cout << "\n-----actualVec-----\n";
    printVec(nums);
    std::cout << " POSITION VECTOR " << pos<< "\n";

    return -1;

    
}

void Solution::printVec(std::vector<int> &nums) {
    for(auto itr = nums.begin(); itr != nums.end(); itr++){
        std::cout << *itr << " ";
    }

}

std::vector<int> createVec(std::string x){
        std::vector<int> vecBuild;
        for(int i = 0 ; i < x.size(); i++){
            vecBuild.push_back(x.at(i) - '0');
        }
    return vecBuild;
}
int main() {
    Solution answer;
    int num = 0;
    std::vector<int> x;
    x = createVec("4567012");
    num = answer.search(x,0);
    std::cout << "\nOutput : "<<num << "\n";
    return 0;
}