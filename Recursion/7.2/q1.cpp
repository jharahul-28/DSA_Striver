void recGenerate(int n, string &str, vector<string> &ans, int index){
    if(index==n){
        ans.push_back(str);
        return;
    }
    if(str[index-1]=='1'){
        str[index]='0';
        recGenerate(n,str,ans,index+1);
    }
    else{
        str[index]='0';
        recGenerate(n,str,ans,index+1);
        str[index]='1';
        recGenerate(n,str,ans,index+1);
    }
}

vector<string> generateString(int N) {
    // Write your code here.
    vector <string> ans;
    if(N==0) return ans;
    string str(N,0);
    str[0]='0';
    recGenerate(N,str,ans,1);
    str[0]='1';
    recGenerate(N,str,ans,1);
    sort(ans.begin(),ans.end());
    return ans;
}