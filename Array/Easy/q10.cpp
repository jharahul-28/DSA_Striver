// brute
int missingNumber(int a[], int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]==i){
                return i;
            }
        }
    }
    return -1;
}

//better
int missingNumber(int a[], int n){
    int hash[n+1]={0};
    for(int i=0;i<n-1;i++){
        hash[a[i]]=1;
    }
    for(int i=1;i<n;i++){
        if(hash[i]==0)
        return i;
    }
    return -1;
}

//better
//sum
int missingNumber(int a[], int n){
    int sum=0, s=n*(n+1)/2;
    for(int i=0;i<n-1;i++)
    sum+=a[i];
    return s-sum;
}

//xor
int missingNumber(int a[], int n){
    int xor1=0,xor2=0;
    for(int i=0;i<n-1;i++){
        xor1=xor1^a[i];
        xor2=xor2^(i+1);
    }
    xor2^n;
    return (xor1^xor2);
}