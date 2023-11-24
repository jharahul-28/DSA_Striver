class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1) return head;
        ListNode* prev=nullptr;
        ListNode* start=head;
        ListNode* end;
        ListNode* next;
        ListNode* curr=head;
        int cnt=0;
        while(curr!=nullptr){
            cnt++;
            curr=curr->next;
        }
        curr=head;
        while(curr!=nullptr && cnt>=k){
            //finding nodes which have to be reversed
            start=curr;
            for(int i=1;i<k;i++){
                curr=curr->next;
                end=curr;
            }
            cnt-=k;
            if(curr!=nullptr)
            next=curr->next;
            //reversing
            ListNode* dummy=start;
            ListNode* rprev=nullptr;
            ListNode* rnext;
            while(dummy!=next){
                rnext=dummy->next;
                if(rprev!=nullptr)
                dummy->next=rprev;
                rprev=dummy;
                dummy=rnext;
            }
            start->next=next;
            if(prev!=nullptr)
            prev->next=end;
            else
            head=end;
            prev=start;
            curr=next;
        }
        return head;
    }
};