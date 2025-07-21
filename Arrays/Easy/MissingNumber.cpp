#include<iostream>
#include<vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums)
    {
        int n = nums.size();
        n = n*(n+1)/2;
        for(int i=1; i<nums.size(); i++) nums[0]+=nums[i];
        return n-nums[0];
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

    std::cout << sln.missingNumber(nums1) << std::endl;
}
