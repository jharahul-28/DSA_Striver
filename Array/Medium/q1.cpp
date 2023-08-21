// brute
void sum2(vector <int> v, int sum){
    for (int i = 0; i < v.size()-1; i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]==v[j]){
                cout<< "YES"<< endl;
                cout<< i << " " << j << endl;
                return;
            }
        }
    }
    cout<< "NO"<< endl;
}

//better
void sum2(vector <int> v, int sum){
    map <int,int> mpp;
    for(int i=0;i<v.size();i++){
        int rem=sum-v[i];
        if(v.find(rem)!=v.end()){
            cout<< "YES"<< endl;
            cout<< mpp.rem<<" "<< i<< endl;
        }
        else{
            mpp[v[i]]=i;
        }
    }
    cout<< "NO"<< endl;
}

void sum2(vector <int> v, int sum){
    int left=0;
    int right=v.size()-1;
    sort(v.begin(),v.end());
    while(left<right){
        int s=v[left]+v[right];
        if(s==sum){
            cout<< "YES"<< endl;
            return;
        }
        else if(s<sum){
            left++:
        }
        else
        right--;
    }
    cout<< "NO"<< endl;    
}