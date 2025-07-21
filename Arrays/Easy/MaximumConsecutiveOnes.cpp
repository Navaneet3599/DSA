#include<iostream>
#include<vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums)
    {
        int sum=0, bigSum=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                sum+=1;
                if(sum>bigSum)
                    bigSum=sum;
            }
            else
                sum=0;
        }
        return bigSum;
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

    std::cout << sln.findMaxConsecutiveOnes(nums1) << std::endl;
}
