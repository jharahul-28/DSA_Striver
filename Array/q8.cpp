// brute
int unionOfArray(int a1[], int n1, int a2[], int n2){
    set <int> st;
    for(int i=0;i<n1;i++){
        st.insert(a1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(a2[i]);
    }
    int n[st.size()];
    int i=0;
    for(auto it: st){
        n[i]=it;
        i++;
    }
}

//optimal
vector <int> unionOfArray(int a1[], int n1, int a2[], int n2){
    int i,j;
    vector <int> v;
    while(i<n1 && j<n2){
        if(a1[i]<= a2[j]){
            if(v.size()==0 || v.back()!=a1[i])
            v.push_back(a1[i]);
            i++;
        }
        else{
            if(v.size()==0 || v.back()!=a2[j])
            v.push_back(a2[j]);
            j++;
        }
    }
    return v;
}