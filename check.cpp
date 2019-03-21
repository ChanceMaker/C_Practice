// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <vector>
using namespace std;

vector<int> cellCompete(int* states, int days) 
{
    vector<int> v;//current vecotor
    vector<int> next_vector;
    //creating and populating the vector that is needed for return
      for(int i = 0 ; i < sizeof(states); i++){
          v.insert(v.begin()+ i,states[i]);
          next_vector.insert(next_vector.begin() + i,states[i]);
      }
      for(int j = 0 ; j < days; j++){
          for(int i = 0 ; i < sizeof(states); i++){
             
              if(i == 0  ){
                  if(v.at(i + 1) == 0 ){
                        next_vector.at(i) = 0;
                  }else{
                      next_vector.at(i) = 1;
                  }
              }
              if(i == sizeof(states) - 1){
                if( i > 0){
                    if(v.at(i - 1) == 0){
                      next_vector.at(i) = 0;
                    }else{
                        next_vector.at(i) = 1;
                    }
                }
              }
              if(i > 0  && i != sizeof(states) - 1){
                  if(v.at(i - 1) == v.at(i + 1) ){
                     next_vector.at(i) = 0;
                    }
                  else{
                      next_vector.at(i) = 1;
                  }
                    
              }
        }
        v = next_vector;
          
      }
      
      
    return v;
}
// FUNCTION SIGNATURE ENDS