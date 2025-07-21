#include<iostream>
#include<vector>
#include<unordered_set>

class Solution
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::unordered_set<int> unq;
        int longest = 0;
        for(int i=0; i<nums.size(); i++) unq.insert(nums[i]);

        for(int it:unq)
        {
            int length = 1;
            if(unq.find(it-1)!=unq.end()) continue;
            else while(unq.find(++it)!=unq.end()) length++;

            if(length > longest) longest = length;
        }
        return longest;
    }
};

int main()
{
    Solution sln;
    int n, out;
    std::cin >> n;
    std::vector<int> nums(n);
    for(int i=0; i<n; i++) std::cin >> nums[i];
    
    std::cout << sln.longestConsecutive(nums) << std::endl;
}
