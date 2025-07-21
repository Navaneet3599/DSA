#include<iostream>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    int longestSubarray(std::vector<int> &nums, int k)
    {
        std::unordered_map<long long, int> myMap;
        long long tempSum=0;
        int len=0;
        for(int i=0; i<nums.size(); i++)
        {
            tempSum+=nums[i];
            myMap[tempSum] = (i+1);
            if(tempSum==k) len=(i+1);
            else if(myMap.find(tempSum-k)!=myMap.end()) len=std::max(len, i+1-myMap[tempSum-k]);
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
