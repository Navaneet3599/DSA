class Solution {
public:
    int reverseNumber(int n) {
        int r_num = 0;
        for(;n>0;n/=10)
            r_num = r_num*10 + n%10;
        return r_num;
    }
};