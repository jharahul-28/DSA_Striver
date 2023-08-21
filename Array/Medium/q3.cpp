// brute
int majorityElement(vector <int> v){
    int cnt=0;
    for (int i = 0; i < v.size(); i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(v[i]==v[j]){
                cnt++;
            }
        }
        if(cnt>(v.size()/2))
        return v[i];
    }
    return -1;
}

// better
int majorityElement(vector <int> v){
    map <int,int> mpp;
    for(int i=0;i<v.size();i++){
        mpp[v[i]]++;
    }
    for(auto it: map){
        if(it.second > (v.size()/2))
        return (it.first);
    }
    return -1;
}

//optimal MVA
int majorityElement(vector <int> v){
    int el, cnt=0;
    for(int i=0;i<v.size();i++){
        if(cnt==0){
            el=v[i];
            cnt++;
        }
        else if(v[i]==el) cnt++;
        else cnt--;
    }
    int cnt2=0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]==el) cnt2++;
    }
    if(cnt2>(v.size()/2)) return el;
    else return -1;
}