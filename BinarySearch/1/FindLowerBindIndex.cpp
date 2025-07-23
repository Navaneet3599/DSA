#include<iostream>
#include<vector>

class Solution{
public:
    int lowerBound(std::vector<int> &nums, int x){
        int low = 0, high = nums.size()-1;
        int lb = high;
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid] < x)
            {
                low = mid+1;
            }
            else if(nums[mid] > x)
            {
                high = mid-1;
                lb = mid;
            }
            else
            {
                lb = mid;
                while((mid>=0)&&(nums[mid] == nums[mid-1]))
                {
                    mid--;
                    lb = mid;
                }
                return lb;
            }
        }
        return lb;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.lowerBound(nums, target) << std::endl;
    return 0;
}
