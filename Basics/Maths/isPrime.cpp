#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    bool isPrime(int n) {
        for(int temp = 2; temp*temp <= n; temp++)
            if(n%temp == 0) return false;
        return true;
    }
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::cout << sln.isPrime(n) << std::endl;
}