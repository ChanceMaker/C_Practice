#include <iostream>
#include <vector>
#include <tuple>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int val = 0;
        int checkNum = 0;
        std::vector<int> answer;
        for(std::vector<int>::size_type i =0; i < nums.size();++i){
            for(std::vector<int>::size_type j = 0; j < nums.size();++j){
                checkNum = nums[i] + nums[j];
                if(checkNum == target){
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }

            }

        }


        std::cout << "\n";


        return answer;
    }
    void printSolution(std::vector<int> x){
        for(std::vector<int>::iterator i = x.begin(); i != x.end();++i){
            std::cout << *i;
        }
    }
};


int main() {
    std::vector<int> values{2,7,11,5};
    int target = 9;
    std::vector<int> answer;

    Solution x;
    answer = x.twoSum(values,target);
    x.printSolution(answer);

    return 0;
}