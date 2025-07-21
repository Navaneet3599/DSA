#include<iostream>
#include<limits>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums)
    {
        int p1 = -1, p2 = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                p1 = i;
                break;
            }
        }
        for(int i=p1+1; i<nums.size(); i++)
        {
            if(nums[i]!=0)
            {
                std::swap(nums[p1], nums[i]);
                p1++;
            }
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
    sln.moveZeroes(nums);
    for(int i=0; i<input; i++) std::cout << nums[i] << " ";
}
