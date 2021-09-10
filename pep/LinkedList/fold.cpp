#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *findMid(ListNode *head){
    // ListNode *temp = head;
    ListNode *slow = head;
    ListNode *fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}

ListNode* reverse(ListNode *head){
     ListNode *curr = head;
    ListNode *prev = NULL;
    
    while(curr != NULL){
        // cout<< curr->val;
        ListNode *future = curr->next;
        
        curr->next = prev ;
        prev = curr;
        curr = future;
        
    }
    
    return prev;

}

void fold(ListNode *head)
{
    ListNode *temp = head;
    ListNode *mid = findMid(head);
    ListNode *slist = mid->next;
    mid->next = NULL;
    
    slist = reverse(slist);
    
    ListNode *flist = head;
    ListNode *nslist = slist;
   
    
    while(nslist != NULL){
        ListNode *fnext =flist->next;
        ListNode *snext = nslist->next;
        
        flist->next = nslist;
        nslist->next= fnext;
        
        // move
        flist = fnext;
        nslist= snext;
        
        
    }
    // return temp;
    
    
    
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    fold(head);
    printList(head);

    return 0;
}