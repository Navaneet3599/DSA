#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> findMissingRepeatingNumbers(std::vector<int> nums) {
        long long missing=-1, repeating=-1;
        long long S1=0, SN1=0, S2=0, SN2=0;
        for(int i=0; i<nums.size(); i++)
        {
            S1+=nums[i];
            S2+=(nums[i]*nums[i]);
        }
        SN1 = (nums.size())*(nums.size()+1)/2;
        SN2 = (nums.size())*(nums.size()+1)*(2*nums.size()+1)/6;
        missing = S1-SN1;
        repeating = (S2-SN2)/(missing);
        missing = (missing+repeating)/2;
        repeating = repeating-missing;
        return {(int)missing, (int)repeating};
    }
};

int main()
{
    Solution sln;
    int n;
    std::cin >> n;
    std::vector<int> arr(n), out;

    for(int i=0; i<n; i++) std::cin >> arr[i];

    out = sln.findMissingRepeatingNumbers(arr);

    std::cout << out[0] << " " << out[1] << std::endl;
}
