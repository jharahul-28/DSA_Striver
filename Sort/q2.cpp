vector <int> bubbleSort(vector <int> v){
    for(int i=v.size()-1;i<=0;i++){
        int didSwap= 0;
        for(int j=0;j<i-1;i++){
            if(v[j]>v[j+1]){
                int temp= v[j];
                v[j]=v[j+1];
                v[j+1]= temp;
                didSwap=1;
            }
        }
        if(didSwap == 0)
        break;
    }
    return v;
}