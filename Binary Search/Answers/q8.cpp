bool isPossible(vector<int> &stalls, int mid, int k){
    int cnt=1;
    int prev=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if((stalls[i]-prev)>=mid){
            cnt++;
            prev=stalls[i];
        }
    }
    return ((cnt>=k)? true: false);
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int low=1;
    int ans=-1;
    int high=stalls[stalls.size()-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        bool b=isPossible(stalls, mid, k);
        if(b) {
            ans=mid;
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return ans;
}