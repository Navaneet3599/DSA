#include<iostream>

class Solution {
public:
    bool isArmstrong(int n) {
        int nn = 0, cpy_n = n;
        int temp;
        for(; cpy_n > 0; cpy_n /= 10)
        {
            temp = cpy_n%10;
            nn = nn + temp*temp*temp;
        }
        if(nn == n) return true;
        else return false;
    }
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::cout << sln.isArmstrong(n) << std::endl;
}