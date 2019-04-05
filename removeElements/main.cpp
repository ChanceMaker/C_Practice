#include <iostream>
#include <vector>
#include <cstdlib>
#include<bits/stdc++.h>
static void printDetachedVector(std::vector<int> &randVec,std::vector<int>::iterator pend){
    for(auto itr = randVec.begin(); itr != pend; itr++){
        std::cout << *itr<< " ";
    }
    std::cout << "\n";
    std::cout << "VALUES THAT ARE copied over\n";
    for (auto itr = pend; itr != randVec.end(); itr++) {
        std::cout << *itr << " ";
    }
    std::cout << "\n";
}

std::vector<int> createVector(int x){
    std::vector<int> ans;
    for(int i = 0 ; i < x ; i++){
        ans.push_back(rand() % 9);
    }
    return ans;
}
void printVector(std::vector<int> & vec1){
    for(auto itr = vec1.begin(); itr != vec1.end(); itr++){
        std::cout << *itr<< " ";
    }

    std::cout <<"\n";
}
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val);


};

int Solution::removeElement(std::vector<int> &nums, int val){
    std::vector<int>::iterator pend;
    pend = std::remove(nums.begin(), nums.end(), val);
    printDetachedVector(nums,pend);
    return pend - nums.begin();

}
int main() {


    std::vector<int> randVec;
    randVec = createVector(5);
    int size = 0;

    printVector(randVec);
    Solution answer;

    size = answer.removeElement(randVec,8);

   // printVector(randVec);

    std::cout << "SIZE :"<<size ;



    return 0;
}