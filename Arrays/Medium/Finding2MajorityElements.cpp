#include<iostream>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    std::vector<int> majorityElementTwo(std::vector<int>& nums)
    {
        int cnt1=0, cnt2=0, ele1=1<<31, ele2=1<<31;
        std::vector<int> out;
        for(int i=0; i<nums.size(); i++)
        {
            if((cnt1 == 0)&&(nums[i]!=ele2))
            {
                ele1 = nums[i];
                cnt1++;
            }
            else if((cnt2 == 0)&&(nums[i]!=ele1))
            {
                ele2 = nums[i];
                cnt2++;
            }
            else if(nums[i]==ele1)
                cnt1++;
            else if(nums[i]==ele2)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        out.emplace_back(ele1);
        out.emplace_back(ele2);
        return out;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::vector<int> out = sln.majorityElementTwo(nums);

    for(int i=0; i<out.size(); i++)
    {
        std::cout << out[i] << " ";
    }
}
