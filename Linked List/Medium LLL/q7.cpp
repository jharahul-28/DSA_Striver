class Solution {
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        while(head!=nullptr){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* s=head;
        ListNode* d=head;
        while(d->next!=nullptr && d->next->next!=nullptr){
            s=s->next;
            d=d->next->next;
        }
        s->next=reverseList(s->next);
        s=s->next;
        while(s!=nullptr){
            if(head->val!=s->val)
            return false;
            else{
                s=s->next;
                head=head->next;
            }
        }
        return true;
    }
};