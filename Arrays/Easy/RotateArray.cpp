#include<iostream>
#include<limits>

class Solution
{
public:
    void rotateArray(std::vector<int>& nums, int k)
    {
        int n = nums.size();
        k%=n;
        for(int i=0; i<n; i++)
        {
            if(i>=k) std::swap(nums[i], nums[(i-k)%(n)]);//for left rotate
            else std::swap(nums[i], nums[(i+n)%(n)]);
        }
    }
};


int main()
{
    Solution sln;
    int input, k;

    std::cin >> input;
    std::vector<int> nums(input);
    for(int i=0; i < input; i++) std::cin >> nums[i];
    std::cin >> k;
    sln.rotateArray(nums, k);
    for(int i=0; i<input; i++) std::cout << nums[i] << " ";
}
