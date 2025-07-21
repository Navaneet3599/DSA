#include<iostream>

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        else return fib(n-1)+fib(n-2);
    }
};



int main()
{
    Solution sln;
    int input;
    std::cin >> input;
    std::cout << sln.fib(input) << std::endl;
}
