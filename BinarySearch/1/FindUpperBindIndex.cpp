#include<iostream>
#include<vector>

class Solution{
public:
    int upperBound(std::vector<int> &nums, int x){
        int low = 0, high = nums.size()-1;
        int mid = low + (high-low)/2;
        int ub = high;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(x < nums[mid])
            {
                high = mid-1;
                ub = mid;
            }
            else if(x > nums[mid])
            {
                low = mid+1;
            }
            else
            {
                while((mid<nums.size())&&(nums[mid+1]))
                {
                    mid++;
                    ub = mid;
                }
                return ub;
            }
        }
        return ub;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.upperBound(nums, target) << std::endl;
    return 0;
}
