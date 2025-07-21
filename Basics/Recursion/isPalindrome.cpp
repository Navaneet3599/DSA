#include<iostream>

class Solution{	
	public:		
		bool palindromeCheck(std::string& s){
            if(s.length() <= 1) return true;
			if(s.front() != s.back())
                return false;
            s.erase(s.begin());
            s.pop_back();
            return palindromeCheck(s);
		}
};



int main()
{
    Solution sln;
    std::string input;
    std::cin >> input;
    std::cout << sln.palindromeCheck(input) << std::endl;
}
