class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head->next;
        ListNode* curr=head;
        ListNode* mid=head;
        ListNode* prev=head;
        int f=1;
        while(curr->next!=nullptr){
            if(f==0){
                f=1;
            }
            else{
                f=0;
                prev=mid;
                mid=mid->next;
            }
            curr=curr->next;
        }
        prev->next=prev->next->next;
        return head;
    }
};