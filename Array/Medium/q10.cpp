//brute
void colChange(int& arr[][], int j, int n){
    for(int i=0;i<n;i++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}
void rowChange(int& arr[][], int i, int m){
    for(int j=0;j<m;j++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}
void setZero(int& arr[][], int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                rowChange(i,m);
                colChange(j,n);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
}

//better
void setZero(int& arr[][], int n, int m){
    int row[n]={0};
    int col[m]={0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i]==1 || col[i]==1)
            {
                arr[i][j]=0;
            }
        }
    }
}

//optimal
void setZero(int& arr[][], int n, int m){
    int col0=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]==0){
                arr[i][0]=0;//mark ith row
                if(j!=0)
                    arr[0][j]=0;//mark jth row
                else
                    col0=0;
            }
        }   
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][0]==0 || arr[0][j]==0)
            {
                arr[i][j]=0;
            }
        }
    }
    if(arr[0][0]==0){
        for(int j=0;j<m;j++) arr[0][j]=0;
    }
    if(col0==0){
        for(int i=0;i<n;i++) arr[i][0]=0;
    }
}