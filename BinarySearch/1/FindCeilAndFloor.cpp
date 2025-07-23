#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> getFloorAndCeil(std::vector<int> nums, int x) {
        int low = 0, high = nums.size()-1, mid;
        int lb = low, ub = high;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(nums[mid] < x)
            {
                lb = mid;
                low = mid + 1;
            }
            else if(nums[mid] > x)
            {
                ub = mid;
                high = mid - 1;
            }
            else
            {
                ub = mid;
                lb = mid;
                break;
            }
        }
        return {nums[lb], nums[ub]};
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n), out(2);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    out = sln.getFloorAndCeil(nums, target);

    std::cout << out[0] << "<--->" << out[1] << std::endl;
    return 0;
}
