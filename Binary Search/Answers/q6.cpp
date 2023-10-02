class Solution {
    private: 
    int sent(vector<int>& weights, int m){
        int c=1, s=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>m) return 0;
            s+=weights[i];
            if(s>m){
                s=weights[i];
                c++;
            }
        }
        cout<< c<< " Hello "<< m<< endl;
        return c;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int mini=weights[0], maxi=weights[0], sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            mini=min(weights[i],mini);
            maxi=max(weights[i],maxi);
        }
        int low=mini+mini;
        int high= sum;                                      //if we need to send the containers in a day
        while(low<=high){
            int mid=(low+high)/2;
            int c= sent(weights, mid);
            if (c==0) low=mid+1;
            else if(c<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};