vector <int> nextPerm(vector<int>& v){
    int index=-1;
    for(int i=v.size()-2;i>=0;i++){
        if(a[i]<a[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(v.begin().v.end)
        return v;
    }
    swap(v[i],v[index]);
    reverse(v.begin()+index+1,v.end());
    return v;
}