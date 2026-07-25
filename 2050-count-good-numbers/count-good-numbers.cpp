class Solution {
public:
    long long MOD=1000000007;
    long long power(long long n,long long exp){
        if(exp==0) return 1;
        long long half=power(n,exp/2);
        long long result=(half*half);
        if(exp%2==1){
            result=(n*result)%MOD;
        }
        return result%MOD;
    }
    int countGoodNumbers(long long n) {
       
        long long even=(n+1)/2;
        long long odd=n/2;
        long long result = (power(5,even)*power(4,odd))%MOD;
        return result;
    }
};