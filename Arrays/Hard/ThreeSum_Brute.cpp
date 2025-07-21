#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    int findPivot(std::vector<int>& nums, int left, int right)
    {
        int i=left+1, j=right;
        while(true)
        {
            while((i<=right)&&(nums[left]>=nums[i])) i++;
            while((left<=j)&&(nums[left]<nums[j])) j--;
            if(i<j) std::swap(nums[i], nums[j]);
            else break;
        }
        std::swap(nums[left], nums[j]);
        return j;
    }

    void quickSort(std::vector<int>& nums, int left, int right)
    {
        if(left >= right) return;
        else
        {
            int pivot = findPivot(nums, left, right);
            quickSort(nums, left, pivot-1);
            quickSort(nums, pivot+1, right);
        }
    }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> sets;
        quickSort(nums, 0, nums.size()-1);
        for(int i=0; i<nums.size()-2; i++)
        {
            for(int j=i+1; j<nums.size()-1; j++)
            {
                for(int k=j+1; k<nums.size(); k++)
                {
                    if((nums[i]+nums[j]+nums[k])==0)
                    {
                        std::vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        sets.emplace_back(temp);
                    }
                }
            }
        }
        return sets;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::vector<std::vector<int>> out = sln.threeSum(nums);

    for(int i=0; i<out.size(); i++)
    {
        std::cout << "[" << out[i][0] << ", " << out[i][1] << ", " << out[i][2] << "]" << std::endl;
    }
}
