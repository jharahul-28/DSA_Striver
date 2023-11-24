class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size(), s2=nums2.size();
        vector <int> finalAns;
        map<int,int> refAns;
        stack <int> greaterElement;
        if(s2==1){
            finalAns.push_back(-1);
            return finalAns;
        }
        
        greaterElement.push(nums2[s2-1]);
        refAns[nums2[s2-1]]=-1;
        for(int i=s2-2; i>-1; i--){
            if(nums2[i]<greaterElement.top())
            refAns[nums2[i]]=greaterElement.top();
            else{
                while(!greaterElement.empty() && nums2[i]>=greaterElement.top()){
                    greaterElement.pop();
                }
                if(greaterElement.empty())
                refAns[nums2[i]]=-1;
                else
                refAns[nums2[i]]=greaterElement.top();
            }
            greaterElement.push(nums2[i]);
        }
        for(int i=0;i<s1;i++){
            finalAns.push_back(refAns[nums1[i]]);
        }
        return finalAns;
    }
};