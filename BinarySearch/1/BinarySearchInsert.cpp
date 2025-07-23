#include<iostream>
#include<vector>

class Solution {
public:
    int searchInsert(std::vector<int> &nums, int target)  {
       int low=0, high = nums.size()-1;
       int mid = low + (high-low)/2;
       int index = high;
       while(low <= high)
       {
            mid = low + (high-low)/2;
            if(target < nums[mid])
            {
                high = mid-1;
                index = mid;
            }
            else if(nums[mid] < target) low = mid+1;
            else return mid;
       }
       return index;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.searchInsert(nums, target) << std::endl;
    return 0;
}
