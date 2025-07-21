#include<iostream>
#include<vector>

class Solution
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        int cnt = 1, ele = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(cnt  != 0)
            {
                if(ele==nums[i]) cnt++;
                else cnt--;
            }
            else
            {
                ele = nums[i];
                cnt = 1;
            }
        }
        cnt=0;
        for(int i=0; i<nums.size(); i++) if(ele==nums[i]) cnt++;
        
        if(cnt > (nums.size()/2)) return ele;
        else return -1;
    }
};


int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i < n; i++) std::cin >> nums[i];

    std::cout << sln.majorityElement(nums) << std::endl;
}
