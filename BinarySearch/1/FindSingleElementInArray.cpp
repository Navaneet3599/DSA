#include<iostream>
#include<vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int> &nums) {
        int low=0, high=nums.size()-1, mid;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if((mid>0)&&(mid<nums.size()-1)&&(nums[mid]!=nums[mid-1])&&(nums[mid]!=nums[mid+1])) return nums[mid];
            if((mid<nums.size()-1)&&(nums[mid]==nums[mid+1]))
            {
                if((mid-1)%2 != 0) low = mid+2;
                else high = mid-1;
            }
            else if((mid>0)&&(nums[mid]==nums[mid-1]))
            {
                if((mid+1)%2 != 0) low = mid+1;
                else low = mid-2;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.singleNonDuplicate(nums) << std::endl;
    return 0;
}
