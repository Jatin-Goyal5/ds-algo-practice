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

ListNode *mergeTwoLL(ListNode *left ,ListNode *right){
    ListNode *cans = new ListNode(-1);
    ListNode *canst = cans;
    
    while(left != NULL && right != NULL){
        if(left->val > right->val){
            canst->next = new ListNode(right->val);
            canst= canst->next;
            
            right= right->next;
        }else{
            canst->next = new ListNode(left->val);
            canst= canst->next;
            
            left= left->next;
        }
    }
    
    while(left != NULL){
        canst->next = new ListNode(left->val);
        canst= canst->next;
        left= left->next;
    }
    
    while(right != NULL){
        canst->next = new ListNode(right->val);
        canst= canst->next;
        right= right->next;
    }
    
    return cans->next;
}
ListNode *findmid(ListNode *head){
    ListNode *slow = head;
    ListNode *fast= head;
    while(fast ->next != NULL && fast->next->next != NULL){
        fast= fast->next->next;
        slow= slow->next;
    }
    
    return slow;
}

ListNode *mergeSort(ListNode *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode *mid = findmid(head);
    ListNode *right = mergeSort(mid->next);
    mid->next =NULL;
    ListNode *left = mergeSort(head);
    
    ListNode *ans = mergeTwoLL(left,right);
    return ans;
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

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);

    ListNode *head = mergeSort(h1);
    printList(head);

    return 0;
}