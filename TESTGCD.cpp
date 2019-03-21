// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
using namespace std;
int gcd(int,int);
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int generalizedGCD(int num, int* arr)
{
    int result = arr[0];
    for(int i = 0 ; i < num; i++){
        result = gcd(arr[i],result);
    }
    return result;
}
// FUNCTION SIGNATURE ENDS