// better
vector <int> sort123(vector <int> v){
    int cnt0=0, cnt1=0, cnt2=0;
    for(int i=0;i<v.size();i++){
        if (v[i]==0) cnt0++;
        else if (v[i]==1) cnt1++;
        else cnt2++;
    }
    for(int i=0;i<cnt0;i++){
        v[i]=0;
    }
    for (int i = cnt0; i < cnt1; i++)
    {
        v[i]=1;
    }
    for (int i = cnt2; i < v.size(); i++)
    {
        v[i]=2;
    }
    return v;
}

// optimal dnf
vector <int> sort123(vector <int> v){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(v[mid]==0) {
            swap(v[low],a[mid]);
            low++;
            mid++;
        }
        else if(v[mid]==1) mid++;
        else{
            swap(v[high], v[mid]);
            high--;
        }
    }
    return v;
}