#include<iostream>
#include<vector>

class Solution
{
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums)
    {
        int posIndex = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[posIndex]>0) posIndex+=2;
            if((nums[i]>0) && ((i%2)!=0))
            {
                std::swap(nums[i], nums[posIndex]);
                posIndex+=2;
            }
        }
        return nums;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i < n; i++) std::cin >> nums[i];
    nums = sln.rearrangeArray(nums);
    for(int i=0; i < n; i++) std::cout << nums[i] << " ";
    std::cout << std::endl;
}
