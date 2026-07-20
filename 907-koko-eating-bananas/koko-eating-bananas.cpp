class Solution {
public:
    long long totalHours(vector<int>& piles, int mid,int h){
        long long currentSpeed=0;
        for(int i=0; i<piles.size();i++){
            currentSpeed+=ceil((double)piles[i]/mid);
        }
        return currentSpeed;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low=1; long long high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long requireTime=totalHours(piles,mid,h);
            if(requireTime<=h){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};