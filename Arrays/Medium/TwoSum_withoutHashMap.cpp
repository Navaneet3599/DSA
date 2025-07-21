#include<iostream>
#include<vector>

class Solution
{
public:
    int placePivot(std::vector<std::pair<int, int>>& nums, int low, int high)
    {
        int left=low+1, right=high;
        
        while(left<=right)
        {
            while((left<=high)&&(nums[left].first<=nums[low].first))left++;
            while((right>=low+1)&&(nums[right].first>=nums[low].first))right--;
            if(left<right) std::swap(nums[left], nums[right]);
        }
        std::swap(nums[low], nums[right]);
        return right;
    }

    void quickSort(std::vector<std::pair<int, int>>& nums, int low, int high)
    {
        if(high<=low) return;
        int pivot = placePivot(nums, low, high);
        quickSort(nums, low, pivot-1);
        quickSort(nums, pivot+1, high);
    }

    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        //without using hashmap
        int left=0, right=nums.size()-1, sum=0;
        std::vector<std::pair<int, int>> myDS(nums.size());
        for(int i=0; i<nums.size(); i++) myDS[i] = {nums[i], i};

        quickSort(myDS, 0, nums.size()-1);

        while(true)
        {
            sum = myDS[left].first + myDS[right].first;
            if(sum > target) right--;
            else if(sum < target) left++;
            else if(sum == target)
            {
                left = myDS[left].second;
                right = myDS[right].second;
                break;
            }
            
            if(left >= right)
            {
                left = -1;
                right = -1;
                break;
            }
        }
        return {left, right};
    }
};


int main()
{
    Solution sln;
    int n, target;
    std::cin >> n;
    std::vector<int> nums1(n), out(2);
    for(int i=0; i < n; i++) std::cin >> nums1[i];
    std::cin >> target;

    out = sln.twoSum(nums1, target);
    std::cout << "Index_0: " << out[0] << ", Index_1: " << out[1] << std::endl;
}
