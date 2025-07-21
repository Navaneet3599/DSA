#include<iostream>
#include<climits>

class Solution {
public:
    std::vector<int> insertionSort(std::vector<int>& nums)
    {
        for(int i=1; i<nums.size(); i++)
        {
            for(int j = i-1; j>=0; j--)
            {
                if(nums[j]<=nums[i])
                {
                    break;
                }
                else
                {
                    nums[i] = nums[i]+nums[j];
                    nums[j] = nums[i]-nums[j];
                    nums[i] = nums[i]-nums[j];
                    i = j;
                }
            }
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
    nums =  sln.insertionSort(nums);
    for(int i=0; i < input; i++) std::cout << nums[i] << " ";
}
