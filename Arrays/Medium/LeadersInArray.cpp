#include<iostream>
#include<vector>

class Solution
{
public:
    std::vector<int> leaders(std::vector<int>& nums)
    {
        std::vector<int> leaders;
        leaders.emplace_back(nums[nums.size()-1]);
        for(int i=nums.size()-2; i>0; i--)
        {
            if(nums[i]>leaders.back()) leaders.emplace_back(nums[i]);
        }
        for(int i=0; i<leaders.size()/2; i++)
            std::swap(leaders[i], leaders[leaders.size()-1-i]);
        return leaders;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n), out;
    for(int i=0; i<n; i++) std::cin >> nums[i];
    out = sln.leaders(nums);
    for(int i=0; i<out.size(); i++) std::cout << out[i] << " ";
    std::cout << std::endl;
}
