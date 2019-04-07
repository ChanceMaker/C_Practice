#include <iostream>
#include <string>
#include <vector>
void printVect(std::vector<std::string> &x );

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        int len = s.length();
        std::vector<std::string> ret;
        std::string ipBuild;
        
        if (len <= 0 || len > 12)
            return ret;
        
        restore_help(s, ret, ipBuild, 0, 0, len);
        
        return ret;
    }
    void restore_help(std::string &s, std::vector<std::string> &ret, std::string ipBuild, int step, int start, int len)
    {
        if (step == 4 && start == len)
        {   
            ipBuild.erase(ipBuild.end()-1);
            ret.push_back(ipBuild);
            return;
        }
        if (step == 4 && start <= len)
            return;
        if (step < 4 && start >= len)
            return;
            
        for (int j = 1; (start + j - 1) < len && j <= 3; j++)
        {
            std::string ss = s.substr(start, j);
                
            if (j > 1 && ss[0] == '0')
                continue;
                    
            if (j == 3)
            {
                int num = (ss[0] - '0') * 100 + (ss[1] - '0') * 10 + (ss[2] - '0');
                if (num > 255)
                    continue;
            }
                
            ss += ".";
            int l = ipBuild.length();
            ipBuild += ss;

            restore_help(s, ret, ipBuild, step+1, start+j, len);
                
            ipBuild.erase(l, ss.length() + 1);
        }
    }
};

int main()
{
    Solution answer;
    std::string str = "25525511135";
    std::vector<std::string> strVect;
    strVect = answer.restoreIpAddresses(str);
    printVect(strVect);
   
    return 0;
}
void printVect(std::vector<std::string> & x){
    for(auto itr = x.begin(); itr != x.end(); itr++){
        std::cout << *itr <<" ";
    }
    std::cout <<"\n";
}