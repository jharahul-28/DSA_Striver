class Solution {
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int ans=-1;
        int low=1, high=piles[n-1];
        while(low<=high){
            int mid=(low+high)/2;
            long long s=0;
            for(int i=0;i<n;i++){
                s+= ((piles[i]%mid) ? (piles[i]/mid + 1): piles[i]/mid);
            }
            if(s<=h) {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};