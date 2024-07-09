class Solution {
public:
    string removeKdigits(string nums, int k) {
        string ans="";
        stack <char> s;
        int i=0, n=nums.size();
        for(;i<n;i++){
            while(!s.empty() && (s.top()-'0')>(nums[i]-'0') && k){
                s.pop();
                k--;
            }
            if(!k) break;
            s.push(nums[i]);
        }
        for(;i<n;i++) s.push(nums[i]);
        for(;k>0;k--) s.pop();
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        int j=0, l=ans.size()-1;
        while(l>0 && ans[l]=='0') {
            l--;
        }
        string num="";
        for(;j<=l;j++) num.push_back(ans[j]);
        j=0;
        while(j<l){
            swap(num[j],num[l]);
            j++;
            l--;
        }
        if(num.size()==0) return "0";
        return num;
    }
};