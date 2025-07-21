#include<iostream>
#include<vector>

class Solution
{
public:
    void nextPermutation(std::vector<int>& nums)
    {
        bool flag = false;
        int pivot = 0, swapPos;
        for(int i=nums.size()-1; i>0; i--)
        {
            if(nums[i]>nums[i-1])
            {
                pivot = i;
                flag = true;
                break;
            }
        }
        
        swapPos = pivot;
        if(flag==true)
        {
            for(int i=pivot+1; i<nums.size(); i++)
                if((nums[i]>nums[pivot-1])&&(nums[i]<nums[swapPos]))
                    swapPos = i;
            std::swap(nums[pivot-1], nums[swapPos]);
        }

        for(int i=pivot; i<(nums.size()-pivot)/2; i++)
            std::swap(nums[i], nums[nums.size()-1-i]);
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i < n; i++) std::cin >> nums[i];
    sln.nextPermutation(nums);
    for(int i=0; i < n; i++) std::cout << nums[i] << " ";
    std::cout << std::endl;
}
