//brute
vector <int> intersectionArray(vector <int> a, int m, vector <int> b, int n){
    vector <int> vis(n2, 0);
    vector <int> v;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j] && vis[j]==0){
                v.push_back(b[j]);
                vis[j]++;
                break;
            }
            if(a[i]< b[j])
            break;
        }
    }
    return v;
}

// optimal
vector <int> intersectionArray(vector <int> a, int m, vector <int> b, int n){
    int i=0, j=0;
    vector <int> v;
    while(i< m && j<n){
        if(a[i]< b[j])
        i++;
        else if(a[i]>b[j])
        j++;
        else{
            v.push_back(a[i]);
            i++;
            j++;
        }
    }
    return v;
}