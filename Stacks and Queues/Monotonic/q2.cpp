class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int s=nums.size();
        stack <int> greaterElement;
        greaterElement.push(nums[s-1]);
        for(int i=s-2; i>-1; i--){
            if(nums[i]<greaterElement.top()){
                greaterElement.push(nums[i]);
                continue;
            }
            else{
                while(!greaterElement.empty() && nums[i]>=greaterElement.top()){
                    greaterElement.pop();
                }
            }
            greaterElement.push(nums[i]);
        }
        for(int i=s-1;i>-1;i--){
            int num=nums[i];
            if(num<greaterElement.top()){
                nums[i]=greaterElement.top();
                greaterElement.push(num);
            }
            else {
                while(!greaterElement.empty() && num>=greaterElement.top()){
                    greaterElement.pop();
                }
                if(greaterElement.empty()){
                    nums[i]=-1;
                    greaterElement.push(num);
                }
                else {
                    nums[i]=greaterElement.top();
                    greaterElement.push(num);
                }
            }
        }
        return nums;
    }
};