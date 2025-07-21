#include<iostream>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> triangle;
        std::vector<int> curr;
        int ele=1;
        /*curr.emplace_back(1);
        triangle.emplace_back(curr);
        curr.clear();*/
        for(int i=1; i<=numRows; i++)
        {
            curr.emplace_back(1);
            for(int j=1; j<i; j++)
            {
                ele *= (i-j);
                ele /= j;
                curr.emplace_back(ele);
            }
            ele = 1;
            triangle.emplace_back(curr);
            curr.clear();
        }
        return triangle;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n;
    std::vector<std::vector<int>> out = sln.generate(n);

    for(int i=0; i<out.size(); i++)
    {
        for(int j=0; j<out[i].size(); j++)
            std::cout << out[i][j] << " ";
        std::cout << std::endl;
    }
}
