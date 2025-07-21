#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
  public:
    int maxLen(std::vector<int>& arr) {
        int maxLength = 0;
        std::unordered_map<int, int> hashSum;
        hashSum[0]=1;
        for(int i=0, sum=0; i<arr.size(); i++)
        {
            sum+= arr[i];
            if(hashSum.find(sum) != hashSum.end())
                maxLength = std::max(maxLength, i-hashSum[sum]);
            else
                hashSum[sum]=i;
        }
        return maxLength;
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.maxLen(nums) << std::endl;
}
