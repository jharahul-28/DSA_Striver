class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return nullptr;
        map <ListNode*,int> mpp;
        int i=0;
        while(head->next!=NULL){
            if(head->val!=0 && mpp[head]==head->val)
                return head;
            else{
                mpp[head]= head->val;
                head=head->next;
            }
        }
        return nullptr;
    }
};