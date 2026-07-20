class Solution {
public:
    int requiredDay(vector<int>& weights,int caps){
        int dayR=1; int currentWeight=0;
        for(int i=0; i<weights.size();i++){
            if(currentWeight+weights[i]<=caps){
                currentWeight+=weights[i];
            }
            else{
                dayR+=1;
                currentWeight=weights[i];
            }
            
        }
        return dayR;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int totalDay=requiredDay(weights,mid);
            if(totalDay<=days){
                 high=mid-1;
            }
            else{
               low=mid+1;
            }
        }
        return low;
    }
};