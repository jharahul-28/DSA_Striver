int findMaxFruits(vector<int> &arr, int n) {
    // Write your code here.
    int l=0,r=0,ml=0;
    map<int,int> mp;
    while(r<n){
        mp[arr[r]]++;
        if(mp.size()>2){
            mp[arr[l]]--;
            if(mp[arr[l]]==0) mp.erase(arr[l]);
            l++;
        }
        ml=max(ml,r-l+1);
        r++;
    }
    return ml;
}