#include<iostream>
#include<limits>

class Solution {
public:
    int secondLargestElement(std::vector<int>& nums)
    {
        int largest = nums[0], sLargest = std::numeric_limits<int>::min();
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]>largest)
                largest = nums[i];
            if((nums[i]<largest)&&(nums[i]>sLargest))
                sLargest = nums[i];
        }
        if(sLargest == std::numeric_limits<int>::min()) return -1;
        else return sLargest;
    }
};


int main()
{
    Solution sln;
    int input;

    std::cin >> input;
    std::vector<int> nums(input);
    for(int i=0; i < input; i++) std::cin >> nums[i];
    std::cout << sln.secondLargestElement(nums) << std::endl;
}
