#include<iostream>
#include<vector>

class Solution {
public:
    int findKRotation(std::vector<int> &arr)  {
        int low=0, high=arr.size()-1, mid;
        int minIndex = high;
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
                if(arr[minIndex] > arr[mid]) minIndex = mid;
                high = mid-1;
            }
            else
            {
                if(arr[minIndex] > arr[high]) minIndex = high;
                low=mid+1;
            }
        }
        return minIndex;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.findKRotation(nums) << std::endl;
    return 0;
}
