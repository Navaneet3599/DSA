#include<iostream>
#include<vector>

class Solution{
public:
    int search(std::vector<int> &nums, int target){
     for(int low=0, high=nums.size()-1; low<=high; )
        if(nums[low + (high-low)/2] < target) low = low + (high-low)/2+1;
        else if(nums[low + (high-low)/2] > target) high = low + (high-low)/2-1;
        else return low + (high-low)/2;
        return -1;
    }
};

int main()
{
    Solution sln;
    int n, target;
    std::cin >> n >> target;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++) std::cin >> nums[i];

    std::cout << sln.search(nums, target) << std::endl;
    return 0;
}
