//zig zag linked list 
//for a linked list of the form L(1)->L(2)->L(3)->....l(n-1)->L(n)
//ek element start se uthana h aur ek last se uthana h 
//we have to solve this ques without using any extra spae or new array or something, we have to do it in place
//approach will be : 1->2->3->4->5 if this is given ll
//first half m forward jayenge and last half m backward 
//and jo jo elements aate jayenge unhe add krte jayenge 
// loop chalaenge toh forward travel toh krlenge but travelling backward is not possible in ll
//we will use a trick- split and mid 
//we will traverse the first half in forward manner 
//but for second half we will first reverse it and then will travel forward only



Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = Null;

    while(curr!= NULL){
        next = curr->next;
        curr->next = prev;
    }
    return prev;
}
void ZigZagLL(Node* head){
    splitAtMid(head);
    Node* rightHead = split(head);
    Node* rightHeadRev = reverse(rightHead)

    //alternating merging
    Node* left = head;
    Node* right = rightHeadRev;
    Node* tail=right;

    while(left !=NUll && right !=NUll){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next=right;
        right->next = nextLeft;
        tail=right;

        left = nextLeft;
        right=nextRight;
    }
    if(right!=NULL){
        tail->next = right;
    }
    return head;

}