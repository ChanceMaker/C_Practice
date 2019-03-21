// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
void orderedJunctionBoxes(int ,vector<string>);
void printVector(vector<auto>);


int main(int argc, char const *argv[])
{
    vector<string> boxList;
    vector<int> orderedBoxes;
    boxList.push_back("w1 re sks sdk ehl");
    boxList.push_back("bw2 he skd sd fld");
    boxList.push_back("we1 12 245 13 342");
    boxList.push_back("he 39 23 13 43 43");
    cout <<"----Original----\n";
    printVector(boxList);
    orderedBoxes = orderedJunctionBoxes(4,boxList);

    cout <<"----After----\n";
    printVector(orderedBoxes);


    return 0;
}

void printVector(vector<auto> x){
    for (int i = 0; i < x.size(); ++i)
    {
        cout <<x.at(i)<<"\n";
    }
}
void orderedJunctionBoxes(int numberOfBoxes, vector<string> boxList)
{
    vector<string> orderedBoxes;
    vector<bool> formatVector;
    string tmp;
    int cur_ndx = 0;//current index to figure out figuire out if new or old
    orderedBoxes = boxList;
    int oldFormat = 0; //format check
    
    
    //sorting list by old an young
    for(int i = 0 ; i < numberOfBoxes; i++){
        cur_ndx  = boxList.at(i).find_first_of(" ");
        cur_ndx++;
        if((int)boxList.at(i).at(cur_ndx)  >= 48  && (int)boxList.at(i).at(cur_ndx)  <= 57){
            oldFormat = 0;
        }
        else{
            oldFormat = 1;
        }
        if(oldFormat == 0){//move all old format to the front
            boxList.push_back(boxList.at(i));//push to the back 
            boxList.erase(boxList.begin() +  i );//erase te current box
        }
        
    }
    //sorting te list in perspective old and young catagories
    for(int i = 0 ; i < numberOfBoxes; i++){
        cur_ndx  = boxList.at(i).find_first_of(" ");
        cur_ndx++;
        if((int)boxList.at(i).at(cur_ndx)  >= 48  && (int)boxList.at(i).at(cur_ndx)  <= 57){
            oldFormat = 0;
        }
        else{
            oldFormat = 1;
        }
        if(oldFormat == 0 && ( i + 1) != numberOfBoxes){
            //beginning case
           
            if((int)boxList.at(i).at(cur_ndx) < (int)boxList.at(i + 1).at(cur_ndx)){//swap
                
                iter_swap(boxList.begin() + i, boxList.begin() +i + 1);
                
            }
            
        }
        if(oldFormat == 1 && ( i + 1) != numberOfBoxes){
            //beginning case
           
            if((int)boxList.at(i).at(cur_ndx) < (int)boxList.at(i + 1).at(cur_ndx)){//swap
                
                iter_swap(boxList.begin() + i, boxList.begin() +i + 1);
                
            }
            
        }
       
    }
    orderedBoxes = boxList;
   
    
}
// FUNCTION SIGNATURE ENDS