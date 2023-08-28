//optimal-1
vector <int> missingRepeating(vector <int> a){
    long long s,sn,s2,s2n;
    long long n=(long long) a.size();
    sn=n*n*(n+1)/2;
    s2n=(n*n*(n+1)*(2*n+1))/6;
    long long a1,a2,a3;
    for(int i=0;i<n;i++){
        s+=(long long)a[i];
        s2+=((long long)a[i]*(long long)a[i]);
    }
    a1=s-sn;
    a2=s2-s2n;
    a3=a2/a1;
    int x=(int) (a3+a1)/2;
    int y=(int) (a3-a1)/2;
    vector <int> ans{x,y};
    return ans;
}