// brute force
int largestElement(vector <int> &v, int n) {
    sort (v.begin(), v.end());
    return v[n-1];
}

// optimal
int largestElement (vector <int> &v, int n){
    int lar=v[0];
    for(int i=1;i<n;i++){
        lar= (v[i]> lar) ? v[i] : lar;
    }
    return lar;
} 