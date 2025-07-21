#include<iostream>
#include<limits>

class Solution {
public:
    int largestElement(std::vector<int>& nums)
    {
        int max = std::numeric_limits<int>::min();
        for(int i=0; i<nums.size(); i++)
            if(nums[i]>max) max = nums[i];
        return max;
    }
};


int main()
{
    Solution sln;
    int input;

    std::cin >> input;
    std::vector<int> nums(input);
    for(int i=0; i < input; i++) std::cin >> nums[i];
    std::cout << sln.largestElement(nums) << std::endl;
}
