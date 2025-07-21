#include<iostream>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        //using hashmap
        std::unordered_map<int, int> myMap(nums.size());
        for(int i=0; i<nums.size(); i++)
        {
            if(myMap.find(target-nums[i]) != myMap.end()) return {std::min(myMap[target-nums[i]], i), std::max(myMap[target-nums[i]], i)};
            myMap[nums[i]]=i;
        }
        return {-1, -1};
    }
};


int main()
{
    Solution sln;
    int n, target;
    std::cin >> n;
    std::vector<int> nums1(n), out(2);
    for(int i=0; i < n; i++) std::cin >> nums1[i];
    std::cin >> target;

    out = sln.twoSum(nums1, target);
    std::cout << "Index_0: " << out[0] << ", Index_1: " << out[1] << std::endl;
}
