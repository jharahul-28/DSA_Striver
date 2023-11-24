//brute
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        map <ListNode*,int> mpp;
        mpp.clear();
        while(head->next!=NULL){
            if(head->val!=0 && mpp[head]==head->val) 
            {
                return true;
            }
            else{
                mpp[head]= head->val;
                head=head->next;
            }
        }
        return false;
    }
};

//optimal
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* s=head;
        ListNode* d=head;
        while(head->next!=NULL){
            s=s->next;
            d=d->next;
            if(s==NULL||d==NULL)
            return false;
            d=d->next;
            if(d==NULL)
            return false;
            if(s==d)
            return true;
        }
        return false;
    }
};