#include<iostream>
#include<vector>

class Solution
{    
public:
    int singleNumber(std::vector<int>& nums)
    {
        int XOR=nums[0];
        for(int i=1; i<nums.size(); i++)
            XOR^=nums[i];
        return XOR;
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

    std::cout << sln.singleNumber(nums1) << std::endl;
}
