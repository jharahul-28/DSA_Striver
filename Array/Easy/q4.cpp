// brute
int noOfUniuque(vector <int> &v, int n){
    set <int> st;
    for(int i=0;i<n;i++){
        st.insert(v[i]);
    }
    int index=0;
    for(auto it:st){
        v[index]=it;
        index++;
    }
    return index;
}

// optimal
int noOfUniuque(vector <int> &v, int n){
    int index=0;
    for(int i=1;i<n;i++){
        if(v[index]!=v[i]){
            v[++index]=v[i];
        }
    }
    return index+1;
}