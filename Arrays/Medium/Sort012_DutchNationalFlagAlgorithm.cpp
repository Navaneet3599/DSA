#include<iostream>
#include<vector>

class Solution
{
public:
    void sortZeroOneTwo(std::vector<int>& nums)
    {
        int low=0, mid=0, high=nums.size()-1;
        while(mid <= high)
        {
            if(nums[mid]==0)
            {
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i < n; i++) std::cin >> nums[i];

    sln.sortZeroOneTwo(nums);

    for(int i=0; i<nums.size(); i++) std::cout << nums[i] << " ";
}
