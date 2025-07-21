#include<iostream>
#include<limits>

class Solution
{
public:
    void rotateArrayByOne(std::vector<int>& nums)
    {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(i>=1) std::swap(nums[i], nums[(i-1)%(n)]);
            else std::swap(nums[i], nums[(i+n)%(n)]);
        }
    }
};


int main()
{
    Solution sln;
    int input;

    std::cin >> input;
    std::vector<int> nums(input);
    for(int i=0; i < input; i++) std::cin >> nums[i];
    sln.rotateArrayByOne(nums);
    for(int i=0; i<input; i++) std::cout << nums[i] << " ";
}
