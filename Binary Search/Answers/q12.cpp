//brute
long double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	vector <long double> sector(n-1,0);
	while(k--){
		int maxIndex=-1;
		long double maxElement=-1;
		for(int i=0;i<n-1;i++){
			long double sectionLength= (arr[i+1]-arr[i])/(long double)(sector[i]+1);
			if(maxElement<sectionLength){
				maxIndex=i;
				maxElement=sectionLength;
			}
		}
		sector[maxIndex]++;
	}
	long double maxi=-1;
	for(int i=0;i<n-1;i++){
		long double sectionLength= (arr[i+1]-arr[i])/(long double)(sector[i]+1);
		maxi= max(maxi, sectionLength);
	}
	return maxi;
}

//