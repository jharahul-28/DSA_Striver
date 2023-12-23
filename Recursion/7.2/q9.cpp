void f(int i, vector<int> &n, int s, vector<int> &ans){
	if(i==n.size()){
		ans.push_back(s);
		return;
	}
	f(i+1,n,s+n[i],ans);	
	f(i+1,n,s,ans);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int> ans;
	f(0,num,0,ans);
	sort(ans.begin(),ans.end());
	return ans;
}