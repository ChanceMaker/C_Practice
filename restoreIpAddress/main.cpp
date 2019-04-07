#include <iostream>
#include <vector>
#include <string>
std::string createString(int );
void printString(std::string &);
void printVectStr(std::vector<std::string> &);
/*Given a string containing only digits,
 * restore it by returning all possible
 * valid IP address combinations.
    Example:

    Input: "25525511135"
    Output: ["255.255.11.135", "255.255.111.35"]
 * */
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

int main() {
    Solution answer;
    std::vector<std::string> strVect;
    std::string str;
    str = "25525511135";
    strVect = answer.restoreIpAddresses(str);
    //printString(str);
    printVectStr(strVect);
    return 0;
}
std::string createString(int x){
    std::string tmpStr;
    for (int i = 0; i < x; i++) {
        tmpStr.append(std::to_string(rand() % 9));
    }
    return tmpStr;
}
void printString(std::string &x){
    for (int i = 0; i < x.length(); i++) {
        std::cout << x.at(i);
    }
}
void printVectStr(std::vector<std::string> &x){
    for (auto itr = x.begin(); itr != x.end(); itr++) {
        std::cout << *itr << " ";
    }
}
