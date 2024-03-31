class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> mp(255,-1);
        int l=0,r=0,n=s.length(), ml=0;
        while(r<n){
            if(mp[s[r]]==-1 || mp[s[r]]<l){
                ml=max(ml,r-l+1);
                mp[s[r]]=r;
            }
            else{
                l=mp[s[r]]+1;
                mp[s[r]]=r;
            }
            r++;
        }
        return ml;
    }
};