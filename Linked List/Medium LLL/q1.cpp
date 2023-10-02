/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* curr=head;
        int f=1;
        while(curr->next!=nullptr){
            if(f==0){
                f=1;
            }
            else{
                f=0;
                head=head->next;
            }
            curr=curr->next;
        }
        return head;
    }
};