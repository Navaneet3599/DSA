#include<iostream>
#include<vector>

class Solution {
public:
    int findMin(std::vector<int> &arr)  {
        int low=0, high=arr.size()-1, mid;
        int min = (1<<31)-1;
        while(low <= high)
        {
            while((low<arr.size()-1)&&(high>0))
            {
                if(arr[low]==arr[low+1]) low++;
                else if(arr[high]==arr[high-1]) high--;
                else break;
            }

            mid = low + (high-low)/2;

            if(arr[high] >= arr[mid])
            {
                min = std::min(min, arr[mid]);
                high = mid-1;
            }
            else
            {
                min=std::min(min, arr[high]);
                low=mid+1;
            }
        }
        return min;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.findMin(nums) << std::endl;
    return 0;
}
