#include<iostream>

class Solution {
public:
    int GCD(int n1,int n2) {
        while((n1>0) && (n2>0))
            if(n1 > n2) n1 %= n2;
            else n2 %= n1;
        if(n1 == 0) return n2;
        else return n1;
    }
};


int main()
{
    Solution sln;
    int n1, n2;
    std::cin >> n1 >> n2;
    std::cout << sln.GCD(n1, n2) << std::endl;
}