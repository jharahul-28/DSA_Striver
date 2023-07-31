// brute
int pushZeroes(int a[], int n)
{
    vector<int> temp;
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }
    for (i = 0; i < sizeof(temp) / sizeof(temp[0]); i++)
        a[i] = temp[i];
    for (i = i; i < n; i++)
        a[i] = 0;
    return a;
}

// optimal
int pushZeroes(int a[], int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1)
        return a;
    for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }
    return a;
}