class Solution {
public:
   int digitSum(int num){
    if(num<=0) return 0;
    return num%10+digitSum(num/10);
   }
    int addDigits(int num) {
        if(num<=9) return num;
        return addDigits(digitSum(num));
    }
};