#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int> &height) {
        std::vector<int> bounds;
        int pos = 0;

        int size = height.size();
        int diff;
        int ndx1,ndx2;
        int lowerLimit,upperLimit = 0;
        int tmpArea = 0;
        int maxArea = 0;
        /*Reworked volume finder with moving pointer from front to back with wile loop
         * Ideation: Each time this loop checks if the two end meet in the middle.  After
         * that check there is a forward biased iterator and a reverse biased iterator
         * because the value of the volume is based on the smaller "wall" you calculate the volume
         * and then if increment the smaller of the two walls iterator.
         * **The right wall moves in if it is smaller than the left wall and the inverse of that is true as well
         */
        auto itr = height.begin();
        auto itr2 = height.rbegin();
        while(true){
            if(pos >= size){
                break;
            }
            ndx1 = itr - height.begin();
            ndx2 = itr2 - height.rbegin();
            diff = size - 1 - pos;
            if(*itr <= *itr2){
                tmpArea = diff * (*itr);
                itr++;
            }else{
                tmpArea = diff * (*itr2);
                itr2++;
            }
            if(tmpArea > maxArea){
                maxArea = tmpArea;
            }
            pos++;

        }
        return maxArea;
    }


};
int main() {

    std::vector<int> x;
    std::string strX = "186254837";
    int max = 0;
    for (int i = 0; i < strX.length(); ++i) {
        x.push_back(strX.at(i) - '0');
    }

    Solution answer;
    max = answer.maxArea(x);
    std::cout <<"MAX Area: "<< max <<"\n";

    return 0;
}