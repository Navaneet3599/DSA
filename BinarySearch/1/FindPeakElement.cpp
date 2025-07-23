#include<iostream>
#include<vector>

class Solution {
public:
    int findPeakElement(std::vector<int> &arr) {
        int low=0, high=arr.size()-1, mid;

        if(arr.size() == 1) return 0;
        if((arr.size()>=2)&&(arr[0]>arr[1])) return 0;
        if((arr.size()>=2)&&(arr[arr.size()-2]>arr[arr.size()-1])) return arr.size()-1;

        while(low<=high)
        {
            mid = low + (high-low)/2;
            if((mid>0)&&(mid<arr.size()-1)&&(arr[mid-1]<arr[mid])&&(arr[mid]>arr[mid+1])) return mid;
            if((mid>0)&&(arr[mid]>arr[mid-1])) low=mid;
            else if((mid<arr.size()-1)&&(arr[mid] < arr[mid+1])) high = mid;
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

    std::cout << sln.findPeakElement(nums) << std::endl;
    return 0;
}
