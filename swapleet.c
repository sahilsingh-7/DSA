struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode *temp = head;
    int i, count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    temp = head;

    struct ListNode *ar[count];
    for(i = 0; temp != NULL; i++){
        ar[i] = temp;
        temp = temp->next;
    }

    if(k > count) return head; // If k is greater than the length of the list, return the list as is

    // Swap the kth node from the start and the kth node from the end
    struct ListNode *tempNode = ar[k-1];
    ar[k-1] = ar[count-k];
    ar[count-k] = tempNode;

    // If we're swapping the first node, update the head
    if(k == 1) head = ar[0];

    // Update the next pointers for the swapped nodes and their neighbors
    if(k > 1) ar[k-2]->next = ar[k-1];
    ar[k-1]->next = (k == count) ? NULL : ar[k];
    if(count-k > 0) ar[count-k-1]->next = ar[count-k];
    ar[count-k]->next = (count-k == count-1) ? NULL : ar[count-k+1];

    return head;
}