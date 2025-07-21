#include<iostream>
#include<climits>

class Solution {
public:
    std::vector<int> bubbleSort(std::vector<int>& nums)
    {
        for(int i = nums.size()-1 ; i > 0; i--)
        {
            bool swap = false;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    nums[j] = nums[j]+nums[j+1];
                    nums[j+1] = nums[j]-nums[j+1];
                    nums[j] = nums[j]-nums[j+1];
                    swap = true;
                }
            }
            if(swap == false)
                break;
        }
        return nums;
    }
};





int main()
{
    Solution sln;
    int input;

    std::cin >> input;
    std::vector<int> nums(input);
    for(int i=0; i < input; i++) std::cin >> nums[i];
    nums =  sln.bubbleSort(nums);
    for(int i=0; i < input; i++) std::cout << nums[i] << " ";
}
