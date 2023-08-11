//better
//hashing
int singleOccurance(vector <int> &v){
    int max1= v[0];
    for(int i=1;i<v.size();i++){
        max1= max(v[i], max1);
    }
    int hash[max1+1]={0};
    for(int i=0;i<v.size();i++){
        hash[v[i]]++;
    }
    for(int i=1;i<=max1;i++){
        if (hash[i]==1){
            return i;
        }
    }
    return -1;
}

//map
int singleOccurance(vector <int> &v){
    map <long long, int> mpp;
    for(int i=0;i<v.size();i++){
        mpp[v[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}

//optimal
int singleOccurance(vector <int> &v){
    int xorr=0;
    for(int i=0;i<v.size();i++){
        xorr=xorr^v[i];
    }
    return xorr;
}