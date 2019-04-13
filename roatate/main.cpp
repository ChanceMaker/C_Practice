#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printVector(vector<int> x){
    for (auto itr = x.begin(); itr != x.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "\n";
}

vector<int> createVect(string x){
    vector<int> vect1;
    for (int i = 0; i < x.size(); i++) {
        vect1.push_back(x.at(i) - '0');
    }
    return vect1;
}
class Solution {
public:
    void rotate(vector<int>& nums, int k);
};
void Solution::rotate(vector<int> &nums, int k) {
   vector<int> tmp;
   tmp = nums;
   for(int i = 0 ; i < nums.size();i++){
       tmp[(i + k) % nums.size()] = nums[i];
   };
   //int i = 0;
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = tmp[i];
    }
}
int main() {

    Solution answer;
    vector<int> vec1;
    vec1 = createVect("12345");
    printVector(vec1);
    answer.rotate(vec1, 3);
    printVector(vec1);
    return 0;
}