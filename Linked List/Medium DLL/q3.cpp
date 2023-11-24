Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* c=head;
    while(c->next!=NULL){
        Node* n=c->next;
        while(n->data==c->data){
            c->next=n->next;
            n=n->next;
            if(n==NULL) break;
        }
        if(n==NULL) break;
        c=c->next;
    }
    return head;
}