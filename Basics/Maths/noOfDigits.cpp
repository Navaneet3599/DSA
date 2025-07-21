class Solution {
public:
    int countDigits(int n) {
        int noOfDigits = 0;
        for(;n>0;n/=10)
            noOfDigits++;
        return noOfDigits;
    }
};