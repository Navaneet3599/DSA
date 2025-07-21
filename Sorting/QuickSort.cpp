#include<iostream>
#include<climits>

class Solution
{
private:
    int rearrange(std::vector<int>& nums, int low, int high)
    {
        int j = high, i = low+1;
        while(true)
        {
            while((i<=high)&&(nums[low]>=nums[i]))i++;
            while((j>=low)&&(nums[low]<nums[j]))j--;
            if(i<j) std::swap(nums[i], nums[j]);
            else break;
        }
        
        std::swap(nums[j], nums[low]);

        return j;
    }

    void sort(std::vector<int>& nums, int low, int high)
    {
        if(low >= high) return;

        int pivot = low;
        pivot = rearrange(nums, low, high);
        sort(nums, low, pivot-1);
        sort(nums, pivot+1, high);
    }
public:
    std::vector<int> quickSort(std::vector<int>& nums)
    {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};


int main()
{
    Solution sln;
    int input;

    std::cin >> input;
    std::vector<int> nums(input);
    for(int i=0; i < input; i++) std::cin >> nums[i];
    nums =  sln.quickSort(nums);
    for(int i=0; i < input; i++) std::cout << nums[i] << " ";
}
