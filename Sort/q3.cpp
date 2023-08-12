vector <int> insertionSort(vector <int> v){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && v[j]<v[j-1]){
            int temp= v[j];
            v[j]=v[j-1];
            v[j-1]= temp;
            j--;
        }
    }
    return v;
}