#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    std::vector<int> divisors(int n) {
        std::vector<int> div;
        for(int temp = 1;;temp++)
        {
            if(temp*temp > n) break;
            else if(temp*temp == n)
            {
                div.emplace_back(temp);
                break;
            }
            else if(n%temp == 0)
            {
                div.emplace_back(temp);
                div.emplace_back(n/temp);
            }
        }
        std::sort(div.begin(), div.end());
        return div;
    }
};


int main()
{
    Solution sln;
    int n;
    std::vector<int> answer;
    std::cin >> n;
    answer = sln.divisors(n);
    for(auto it : answer)
        std::cout << it << std::endl;
}