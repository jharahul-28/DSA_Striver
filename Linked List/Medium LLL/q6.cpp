int lengthOfLoop(Node *head) {
    map <Node*, int> mpp;
    if (head==NULL) return 0;
    int f=0, val, cnt=0;
    while(head!=NULL){
        if(f){
            if(head->data==val)
             return ++cnt;
            else{
                cnt++;
                head=head->next;
            }
        }
        else{
            if(mpp[head]==head->data && head->data!=0){
                f=1;
                val=head->data;
                head=head->next;
            }
            else{
                mpp[head]=head->data;
                head=head->next;
            }
        }
        
    }
    return 0;
}