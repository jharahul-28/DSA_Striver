//optimal
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum=0, cnt=0;
        map <int ,int> hmap;
        for(int i=0;i<nums.size();i++){
            hmap[preSum]+=1;
            preSum+=nums[i];
            cnt+=hmap[preSum-k];
        }
        return cnt;
    }
};