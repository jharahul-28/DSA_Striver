//optimal
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	unordered_map <int,int> mp;
	int preSum=0, maxL=0;
	for(int i=0;i<arr.size();i++){
		preSum+=arr[i];
		if(!preSum){
			maxL=i+1;
		}
		else if(mp.find(preSum)!=mp.end()){
			maxL= max(maxL, i-mp[preSum]);
		}
		else
		mp[preSum]=i;
	}
	return maxL;
}