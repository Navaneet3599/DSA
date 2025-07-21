#include<iostream>
#include<vector>

class Solution {
public:
    bool insert(std::vector<int>& nums1, std::vector<int>& nums2, int& n1, int& n2, int& num)
    {
        if((nums1.size()>n1)||(nums2.size()>n2))
        {
            if((nums1.size()>n1)&&(nums2.size()>n2))
            {
                if(nums1[n1]<nums2[n2])
                    num = nums1[n1++];
                else
                    num = nums2[n2++];
                return true;
            }
            else if(nums1.size()>n1)
            {
                num = nums1[n1++];
                return true;
            }
            else
            {
                num = nums2[n2++];
                return true;
            }
        }
        else
            return false;
    }

    std::vector<int> unionArray(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int i=-1, ptr1=0, ptr2=0, num;
        std::vector<int> unionArr;
        while((ptr1<nums1.size())||(ptr2<nums2.size()))
        {
            if(unionArr.empty())
            {
                if(insert(nums1, nums2, ptr1, ptr2, num))
                {
                    unionArr.emplace_back(num);
                    i++;
                }
            }
            else
            {
                if(insert(nums1, nums2, ptr1, ptr2, num)&&(num!=unionArr[i]))
                {
                    unionArr.emplace_back(num);
                    i++;
                }
            }
        }
        return unionArr;
    }
};


int main()
{
    Solution sln;
    int n1;
    std::cin >> n1;
    std::vector<int> nums1(n1);
    for(int i=0; i < n1; i++) std::cin >> nums1[i];

    int n2;
    std::cin >> n2;
    std::vector<int> nums2(n2);
    for(int i=0; i < n2; i++) std::cin >> nums2[i];

    std::vector<int> out(n1+n2);
    out = sln.unionArray(nums1, nums2);
    for(int i=0; i<out.size(); i++) std::cout << out[i] << " ";
}
