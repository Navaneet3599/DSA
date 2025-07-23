#include<iostream>
#include<vector>

class Solution {
public:
    int search(std::vector<int> &nums, int k) {
        int low=0, high=nums.size()-1, mid;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(nums[mid] == k) return mid;
            else if((mid<high)&&(nums[mid+1] < nums[high]))
            {
                if(nums[high] <= k) high = mid-1;
                else low = mid+1;
            }
            else if(mid>0)
            {
                if(nums[mid-1] <= k) high = mid-1;
                else low = mid+1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.search(nums, target) << std::endl;
    return 0;
}
