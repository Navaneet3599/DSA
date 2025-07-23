#include<iostream>
#include<vector>

class Solution{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(nums[mid] < target) low = mid+1;
            else if(nums[mid] > target) high = mid-1;
            else
            {
                low = mid;
                high = mid;
                while(low <= high)
                {
                    if((low>0)&&(nums[low-1] == nums[low])) low--;
                    else if((high<nums.size()-1)&&(nums[high+1] == nums[high])) high++;
                    else break;
                }
                return {low, high};
            }
        }
        return {-1, -1};
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n), out(2);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    out = sln.searchRange(nums, target);

    std::cout << out[0] << "<--->" << out[1] << std::endl;
    return 0;
}
