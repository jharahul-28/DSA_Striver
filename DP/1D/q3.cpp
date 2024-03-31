int f(int n, int k, vector<int> &height, vector<int> &d){
    if(n==0) return 0;
    if(d[n]!=-1) return d[n];
    int mp=INT_MAX;
    for(int i=1;i<=k;i++){
        if(i>n) break;
        mp=min(mp,f(n-i,k,height,d) + abs(height[n]-height[n-i]));
    }
    return d[n]=mp;
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> d(n+1,-1);
    return f(n-1,k,height,d);
}