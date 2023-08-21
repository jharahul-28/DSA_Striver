//better
int longestSuccessiveElements(vector<int>&a) {
    int cnt=0, maxC=0;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++){
        if((a[i+1]-a[i])==1){
            cnt++;
            maxC= max(maxC, cnt);
        }
        else if((a[i+1]-a[i])==0){
            continue;
        }
        else{
            cnt=0;
        }
    }
    return (maxC+1);
}

//optimal
int longestSuccessiveElements(vector<int>&a) {
    unordered_set <int> st;
    int cnt=0, maxC=0;
    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }
    for(auto it: st){
        if(st.find(it-1)==st.end()){
            cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x++;
                cnt++;
            }
            maxC= max(maxC, cnt);
        }
    }
    return maxC;
}