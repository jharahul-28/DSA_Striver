vector <int> rotatedArray(vector <int> &v, int n){
    int temp=v[-0];
    for(int i=1;i<n;i++){
        v[i-1]=v[i];
    }
    v[n-1]=temp;
    return v;
}