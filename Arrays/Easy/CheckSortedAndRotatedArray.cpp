#include<iostream>
#include<limits>

class Solution {
public:
    bool check(std::vector<int>& nums)
    {
        bool flag = false, excp1 = false;
        for(int i=1; i<nums.size(); i++)
        {
            if(excp1==false)
            {
                if(nums[i-1]>nums[i])
                    excp1=true;
            }
            else
            {
                if((nums[i-1]>nums[i])||(nums[i])>nums[0])
                    return false;
            }
        }
        return true;
    }
};


int main()
{
    Solution sln;
    int input;

    std::cin >> input;
    std::vector<int> nums(input);
    for(int i=0; i < input; i++) std::cin >> nums[i];
    std::cout << sln.check(nums) << std::endl;
}
