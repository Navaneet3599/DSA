#include<iostream>
#include<vector>

class Solution {
public:
    int countReversePairs(std::vector<int>& nums, int low, int mid, int high)
    {
        int j=mid+1, count=0;
        for(int i=low; i<=mid; i++)
        {
            while((j<=high)&&((long long)nums[i]>2LL*(long long)nums[j])) j++;
            count += (j-(mid+1));
        }
        return count;
    }
    int slice(std::vector<int>& nums, std::vector<int>& temp, int low, int high)
    {
        int count = 0;
        if(low>=high) return count;
        int mid = low+(high-low)/2;
        count += slice(nums, temp, low, mid);
        count += slice(nums, temp, mid+1, high);
        for(int i=low; i<=high; i++) temp[i]=nums[i];
        count+= countReversePairs(nums, low, mid, high);
        merge(nums, temp, low, mid, high);
        return count;
    }
    void merge(std::vector<int>& nums, std::vector<int>& temp, int low, int mid, int high)
    {
        int count=0;
        int i=low, j=mid+1, k=low;
        while((i<=mid)&&(j<=high))
            if(temp[i]<=temp[j]) nums[k++]=temp[i++];
            else nums[k++]=temp[j++];
        while(i<=mid) nums[k++]=temp[i++];
        while(j<=high) nums[k++]=temp[j++];
    }
   int reversePairs(std::vector<int> nums) {
        std::vector<int> temp(nums.size());
        for(int i=0; i<nums.size(); i++) temp[i]=nums[i];
        int count = slice(nums, temp, 0, nums.size()-1);
        return count;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for(int i=0; i<n; i++) std::cin >> arr[i];

    std::cout << sln.reversePairs(arr) << std::endl;
    return 0;
}
