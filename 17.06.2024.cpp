class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int start=0;
        long long int end=sqrt(c);
        while(start<=end)
        {
            long long int ans=start*start + end*end;
            if(ans==c)
                return true;
            else if(ans>c)
                end--;
            else
                start++;
        }    
        return false;
    }
};