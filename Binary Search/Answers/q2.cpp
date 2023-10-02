int pro(int m, int n, int mid){
  long long p=1;
  for(int i=1;i<=n;i++){
    p*=mid;
    if(p>m) return 2;
    if(p==m) return 1;
  }
  return 0;
}

int NthRoot(int n, int m) {
  // Write your code here.
  if (m==1) return 1;
  int low=2, high=m;
  while(low<=high){
    int mid=(low+high)/2;
    int prod=pro(m,n,mid);
    if(prod==1) return mid;
    if(prod==2) high=mid-1;
    else low=mid+1;
  }
  return -1;
}