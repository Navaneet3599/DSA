#include<iostream>

class Solution{	
	public:
		int NFactorial(int N){
            int fact = 0;
            if(N == 1) return 1;
            fact = N*NFactorial(N-1);
			return fact;
		}
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::cout << sln.NFactorial(n) << std::endl;
}
