// Given row and column, find element at that position
int nCr(int r, int c){
    long long ans=1;
    for(int i=0;i<c;i++){
        ans=ans*(r-i);
        ans/=(i+1);
    }
    return ans;
}

//Print any row of the pascal triangle
vector <int> generateRow(int row){
    vector <int> ansRow;
    ansRow.push_back(1);
    int ans=1;
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans/=i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

//Print the entire triangle
vector <int> generateRow(int row){
    vector <int> ansRow;
    ansRow.push_back(1);
    int ans=1;
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans/=i;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector <vector<int>> pascalTriangle(int row){
    vector <vector<int>> ans;
    for(int i=01;i<row;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}