#include<iostream>
#include<vector>

class Solution
{
public:
    void maxSubArray(std::vector<int>& nums)
    {
        int sum = 0, max = (-1 << 31), start = 0, end = 0, prev = 0;
        bool flag = false;
        for(int i=0; i<nums.size(); i++)
        {
            sum = nums[i] + std::max(0, sum);
            if(sum>max)
            {
                max = sum;
                prev = end;
                end = i;
                if(end != (prev+1)) start = end;
            }
            if(sum<0) sum=0;
        }
        std::cout << start << ":" << end << std::endl;

        for(int i=start; i<=end; i++) std::cout << nums[i] << " ";
        std::cout << std::endl;
    }
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i < n; i++) std::cin >> nums[i];

    sln.maxSubArray(nums);
}
