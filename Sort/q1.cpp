vector <int> selectionSort(vector <int> v){
    for(int i=0;i<(v.size()-1);i++){
        mini=i;
        for(int j=i;j<v.size();j++){
            if(v[j]<v[mini]){
                mini=j
            }
        }
        int temp=v[j];
        v[j]=v[mini];
        v[mini]=temp;
    }
    return v;
}