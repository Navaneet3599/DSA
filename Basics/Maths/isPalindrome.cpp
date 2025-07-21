#include<iostream>

class Solution {
public:
    bool isPalindrome(int n) {
        int r_num = 0, cpy_num = n;
        for(;cpy_num > 0; cpy_num/=10)
        {
            r_num = r_num*10 + cpy_num%10;
            if((r_num == cpy_num) || (r_num == cpy_num/10))
                return true;
        }
        return false;
    }
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::cout << sln.isPalindrome(n) << std::endl;
}