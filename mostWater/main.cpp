#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        std::vector<int> bounds;
        int pos = 0;
        int diff;
        int lowerLimit,upperLimit = 0;
        int tmpArea = 0;
        int maxArea = 0;
        /*Nested loop to find all possible volumes and keep the highest*/
        for(auto iter = height.begin(); iter != height.end();iter++){
            for(auto iter2 = height.begin(); iter2 != height.end();iter2++){
                if(iter != iter2){
                    int ndx1,ndx2;
                    ndx1 = iter - height.begin();//iterator 1 index
                    ndx2 = iter2 - height.begin();//iterator 2 index
                    if(*iter < *iter2){
                        if(ndx1 < ndx2){
                            diff = ndx2  - ndx1;
                        }else{
                            diff = ndx1 - ndx2;
                        }
                        tmpArea = *iter * diff;
                    }else{
                        if(ndx1 < ndx2){
                            diff = ndx2  - ndx1;
                        }else{
                            diff = ndx1 - ndx2;
                        }

                        tmpArea = *iter2 * diff;
                    }
                    if(tmpArea > maxArea){//new Max area and its upper and lower bounds need to be saved
                        maxArea = tmpArea;
                        tmpArea = 0;
                    }


                }
            }

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