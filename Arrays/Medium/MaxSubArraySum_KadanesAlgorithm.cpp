#include<iostream>
#include<vector>

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        int sum = 0, max = (-1 << 31);
        for(int i=0; i<nums.size(); i++)
        {
            sum = nums[i] + std::max(0, sum);
            if(sum>max) max = sum;
            if(sum<0) sum=0;
        }
        return max;
    }
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i < n; i++) std::cin >> nums[i];

    std::cout << sln.maxSubArray(nums) << std::endl;
}
