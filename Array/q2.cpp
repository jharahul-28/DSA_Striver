// optimal
int slargest(vector <int> &v, int n ){
    int largest =v[0];
    int slargest=INT_MIN;
    for(int i=0;i<n;i++){
        if(v[i]> largest){
            slargest=largest;
            largest=v[i];
        }
        else if(v[i]<largest && v[i]> slargest)
        slargest=v[i];
    }
    return slargest;
}