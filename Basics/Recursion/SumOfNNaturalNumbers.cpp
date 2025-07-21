#include<iostream>

class Solution{	
	public:
		int NnumbersSum(int N){
            int sum = 0;
            if(N == 1) return 1;
            sum = N + NnumbersSum(N-1);
			return sum;
		}
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::cout << sln.NnumbersSum(n) << std::endl;
}
