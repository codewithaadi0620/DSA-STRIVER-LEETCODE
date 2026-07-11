class Solution {
public:
bool canWePlace(vector<int>& position,int m , int dist){
    int lastElement=position[0]; int elePlac=1;
    for(int i=1; i<position.size();i++){
        if(position[i]-lastElement>=dist){
            elePlac++;
            lastElement=position[i];
        }
        
    }
    return elePlac>=m;
}
    int maxDistance(vector<int>& position, int m) {
        int ans=1;
       sort(position.begin(),position.end());
       int low=1;
       int high = position.back()- position[0];
       while(low<=high){
        int mid=(low+high)/2;
        if(canWePlace(position,m,mid)==true) {
            ans=mid;
            low=mid+1;

        }
        else{
            high=mid-1;
        }
        
       }
       return ans;
    }
};