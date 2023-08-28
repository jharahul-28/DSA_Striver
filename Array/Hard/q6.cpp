//optimal
int xorCount(vector <int>& v, int k){
    int cnt=0;
    map <int,int> mp;
    int xr=0;
    mp[xr]++;
    for(int i=0;i<v.size;i++){
        xr=xr^v[i];
        int req= xr^k;
        cnt+= mp[req];
        mp[xr]++;
    }
    return cnt;
}