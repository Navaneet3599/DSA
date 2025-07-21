#include<iostream>
#include<vector>

class Solution
{
public:
    int longestSubarray(std::vector<int> &nums, int k)
    {
        int ptr1=0, ptr2=0;
        int sum=0, len=0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            ptr2+=1;

            if(sum>k)
            {
                sum-=nums[ptr1];
                ptr1++;
            }

            if((sum==k)&&(len<ptr2-ptr1+1))
            {
                len = ptr2-ptr1;
            }
        }
        return len;
    }
};



int main()
{
    Solution sln;
    int n, target;
    std::cin >> n;
    std::vector<int> nums1(n);
    for(int i=0; i < n; i++) std::cin >> nums1[i];
    std::cin >> target;

    std::cout << sln.longestSubarray(nums1, target) << std::endl;
}
