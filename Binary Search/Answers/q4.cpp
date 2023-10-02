class Solution {
    private:
    long long noBouquet(int mid, vector<int>& bd, int k){
        int c=(mid>=bd[0])? 1: 0;
        long long cnt=(c>=k)? 1: 0;
        for(int i=1;i<bd.size();i++){
            if(k>1){
                if((mid>=bd[i])&&(mid>=bd[i-1])){
                    c++;
                    if(c>=k){
                        c=0;
                        cnt++;
                    }
                }
                else if((mid>=bd[i])&&(mid<bd[i-1])) c=1;
                else c=0;
            }
            else{
                if(mid>=bd[i]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=bloomDay[0], high=bloomDay[0];
        long long n = bloomDay.size();
        long long t = static_cast<long long>(m) * static_cast<long long>(k);
        if((t)>n) return -1;
        for(int i=1;i<n;i++){
            low=min(low,bloomDay[i]);
            high=max(high, bloomDay[i]);
        }
        while(low<=high){
            int mid=(low+high)/2;
            int number= noBouquet(mid, bloomDay, k);
            if(number>=m) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};