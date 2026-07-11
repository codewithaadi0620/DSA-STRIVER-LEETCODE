class Solution {
public:
    bool possible(vector<int>& bloomDay, int m , int k, int day){
        int cnt=0; int noOfBoq=0;
        for(int i=0; i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noOfBoq+=cnt/k;
                cnt=0;
            }
        }
         noOfBoq+=cnt/k;
         if(noOfBoq>=m) return true;
         else return false;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,m,k,mid)==true) {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }

        }
        return ans;
    }
};