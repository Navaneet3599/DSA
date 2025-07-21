#include<iostream>
#include<vector>
#include<unordered_map>

class Solution{
public:
    int subarraysWithXorK(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> hashMap;
        int xOR = 0;
        int subArrayCount = 0;
        hashMap[xOR]++;
        for(int i=0; i<nums.size(); i++)
        {
            xOR ^= nums[i];
            
            //if(hashMap.find(xOR^k) != hashMap.end())
            {
                std::cout << "XOR: " << xOR << ", XOR^k: " << (xOR^k)  << ", nums[i]: " << nums[i] << std::endl;
                subArrayCount += hashMap[xOR^k];
                hashMap[xOR]++;
            }
        }
        return subArrayCount;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.subarraysWithXorK(nums, target) << std::endl;
}
