class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     int l=0,r=0;
    int maxi=0;
    int len=0;
    map<int,int>mpp;
   
     while(r<fruits.size()){
        mpp[fruits[r]]++;
        while(mpp.size()>2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]]==0){
                mpp.erase(fruits[l]);
            
            }
            l++;
           
        }
         len=r-l+1;
            maxi=max(maxi,len);
            r++;
     }
     return maxi;
    }
};