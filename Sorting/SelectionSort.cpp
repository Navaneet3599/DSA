#include<iostream>
#include<climits>

class Solution {
public:
    std::vector<int> selectionSort(std::vector<int>& nums) {
        int sortIndex = nums.size()-1;
        for(int i = 0; i < nums.size()-1; i++)
        {
            int minIndex = i;
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] < nums[minIndex])
                    minIndex = j;
            }
            if(minIndex != i)
            {
                nums[i] = nums[i] + nums[minIndex];
                nums[minIndex] = nums[i] - nums[minIndex];
                nums[i] = nums[i] - nums[minIndex];
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
    nums =  sln.selectionSort(nums);
    for(int i=0; i < input; i++) std::cout << nums[i] << " ";
}
