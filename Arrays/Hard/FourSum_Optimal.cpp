#include<iostream>
#include<vector>

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

    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> out;
        quickSort(nums, 0, nums.size()-1);
        
        for(int i=0; i<nums.size()-3; i++)
        {
            if((i>0)&&(i<nums.size())&&(nums[i]==nums[i-1])) continue;
            for(int j=i+1; j<nums.size()-2; j++)
            {
                if((j!=(i+1)) && (nums[j]==nums[j-1])) continue;
                int k = j+1, l = nums.size()-1;
                while(true)
                {
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    
                    if(sum == target)
                    {
                        std::vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        out.push_back(temp);
                        
                        do{
                            k++;
                        }while((k<l)&&(nums[k]==nums[k-1]));
                        do{
                            l--;
                        }while((k<l)&&(nums[l]==nums[l+1]));
                    }
                    else if(sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }

                    if(k>=l) break;
                }
            }
        }
        return out;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::vector<std::vector<int>> out = sln.fourSum(nums, target);

    for(int i=0; i<out.size(); i++)
    {
        std::cout << "[" << out[i][0] << ", " << out[i][1] << ", " << out[i][2] << ", " << out[i][3] << "]" << std::endl;
    }
}
