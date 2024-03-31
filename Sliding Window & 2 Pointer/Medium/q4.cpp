class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int l=0,r=0,mf=0,n=s.length(),ans=0;
        while(r<n){
            mp[s[r]]++;
            mf=max(mf,mp[s[r]]);
            if(((r-l+1)-mf)>k){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};