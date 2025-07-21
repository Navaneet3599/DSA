#include<iostream>
#include<vector>

class Solution
{    
public:
    int sortPivot(std::vector<int>& nums, int low, int high)
    {
        int i=low+1, j=high;
        while(i<j)
        {
            while((i<=high)&&(nums[i]<=nums[low]))i++;
            while((j>=low)&&(nums[j]>nums[low]))j--;
            if(i>=j) break;
            else std::swap(nums[i], nums[j]);
        }
        std::swap(nums[low], nums[j]);
        return j;
    }
    void quickSort(std::vector<int>& nums, int low, int high)
    {
        if(low>=high) return;

        int pivotPos = sortPivot(nums, low, high);
        quickSort(nums, low, pivotPos-1);
        quickSort(nums, pivotPos+1, high);
    }
    int singleNumber(std::vector<int>& nums)
    {
        quickSort(nums, 0, nums.size()-1);
        for(int i=0; i<nums.size()-1; i+=2)
            if(nums[i]!=nums[i+1])
                return nums[i];
        return nums[nums.size()-1];
    }
};


int main()
{
    Solution sln;
    int n1;
    std::cin >> n1;
    std::vector<int> nums1(n1);
    for(int i=0; i < n1; i++) std::cin >> nums1[i];

/*    int n2;
    std::cin >> n2;
    std::vector<int> nums2(n2);
    for(int i=0; i < n2; i++) std::cin >> nums2[i];*/

    std::cout << sln.singleNumber(nums1) << std::endl;
}
