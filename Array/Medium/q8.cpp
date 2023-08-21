//optimal
vector<int> superiorElements(vector<int>&a) {
    int maxE=INT_MIN;
    vector <int> ans;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]>maxE){
            ans.push_back(a[i]);
            maxE=a[i];
        }
    }
    return ans;
}