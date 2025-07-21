#include<iostream>
#include<limits>

class Solution {
public:
    int linearSearch(std::vector<int>& nums, int target)
    {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==target)
                return i;
        }
        return -1;
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
    sln.linearSearch(nums, k);
    std::cout << k;
    //for(int i=0; i<input; i++) std::cout << nums[i] << " ";
}
