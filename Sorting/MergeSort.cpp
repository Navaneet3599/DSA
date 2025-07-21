#include<iostream>
#include<climits>

class Solution
{
private:
    std::vector<int> temp;

    void slice(std::vector<int>& nums, std::vector<int>& temp, int low, int high)
    {
        int mid = (low+high)/2;

        if(high-low <= 1) return;
        else
        {
            slice(nums, temp, low, mid);
            slice(nums, temp, mid, high);
            for(int i=low; i<high; i++) temp[i] = nums[i];
            merge(nums, temp, low, mid, high);
        }
    }

    void merge(std::vector<int>& nums, std::vector<int>& temp, int low, int mid, int high)
    {
        for(int i=low, j=mid, k=low; (i<mid)||(j<high); k++)
        {
            if((i<mid) && (j<high))
            {
                if(temp[i]<temp[j]) nums[k] = temp[i++];
                else nums[k] = temp[j++];
            }
            else if(i<mid)
                nums[k] = temp[i++];
            else
                nums[k] = temp[j++];
        }
    }

public:
    std::vector<int> mergeSort(std::vector<int>& nums)
    {
        std::vector<int> temp(nums.size());
        slice(nums, temp, 0, nums.size());
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
    nums =  sln.mergeSort(nums);
    for(int i=0; i < input; i++) std::cout << nums[i] << " ";
}
