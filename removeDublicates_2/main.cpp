#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
void printVector(std::vector<int> &x){
    for (auto itr = x.begin(); itr != x.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << "\n";
}
std::vector<int> createRandVec(int n){
    std::vector<int> randVec;
    for (int i = 0; i < n; i++) {
        randVec.push_back(rand() % 9);
    }
    return randVec;

}
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        //std::set<int> s;
        std::vector<int> uniqueVect;
        for (auto itr = nums.begin(); itr != nums.end(); itr++) {
            int tmpVal = *itr;
            int numOccur = 0;
            for (auto itr2 = uniqueVect.begin(); itr2 != uniqueVect.end(); itr2++) {
                if (*itr == *itr2) {
                    numOccur++;
                }
            }
            if(numOccur < 2){
                uniqueVect.push_back(*itr);
            }
        }
        nums.assign(uniqueVect.begin(), uniqueVect.end());
        return nums.size();
    }
};
int main() {
    Solution answer;
    std::vector<int> randVec;
    int size = 0;

    randVec = createRandVec(7);
    std::cout << "----BEFORE----\n";
    printVector(randVec);
    answer.removeDuplicates(randVec);
    std::cout << "----AFTER----\n";
    printVector(randVec);



    return 0;
}