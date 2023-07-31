// brute
vector <int> rotatedArray (vector <int> &v, int n, int d){
    d=d%n;
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=v[i];
    }
    for(int i=0;i<n-d;i++){
        v[i]=v[i+d];
    }
    for(int i=n-d;i<n;i++){
        v[i]=temp[i-(n-d)];
    }
    return v;
}

// optimal
vector <int> rotatedArray (vector <int> &v, int n, int d){
    reverse(v,v+d);
    reverse(v+d,v+n);
    reverse(v,v+n);
}