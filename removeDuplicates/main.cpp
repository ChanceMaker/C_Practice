#include <iostream>
#include <vector>
#include <set>
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
        std::set<int> s;

        for (auto itr = nums.begin(); itr != nums.end(); itr++) {
            s.insert(*itr);
        }
        nums.assign(s.begin(), s.end());
        return s.size();
    }
};
int main() {
    Solution answer;
    std::vector<int> randVec;
    int size = 0;
    randVec = createRandVec(7);
    std::cout << "ORIGINAL : \n";
    printVector(randVec);
    size = answer.removeDuplicates(randVec);

    std::cout <<"DUPLICATES REMOVED\n";
    printVector(randVec);
    std::cout << "SIZE :" << size << "\n";
    return 0;
}