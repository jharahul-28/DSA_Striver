Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* curr=head;
    Node* next;
    Node* prev;
    if (curr->data==k){
        head=head->next;
        next=head;
        next->prev=NULL;
    }
    curr=head;
    while(curr->next!=NULL){
        if(curr->data==k){
            prev=curr->prev;
            next=curr->next;
            if(prev==NULL)
            head=head->next;
            else{
                prev->next=next;
            }
            next->prev=prev;
        }
        curr=curr->next;
    }
    if(curr->data==k){
        prev=curr->prev;
        if(prev==NULL)
        head=head->next;
        else{
            prev->next=NULL;
        }
    }
    return head;
}