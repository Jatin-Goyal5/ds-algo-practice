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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *ans= new ListNode(-1);
    ListNode *anst = ans;
    
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            anst->next = new ListNode(l1->val);
            anst = anst->next;
            l1 = l1->next;
        }else if(l1->val >= l2->val){
            anst->next = new ListNode(l2->val);
            anst = anst->next;
            
            l2 = l2->next;
        }
    }
    
    while(l1 != NULL){
        anst->next = new ListNode(l1->val);
        anst= anst->next;
        l1= l1->next;
    }
    
    while(l2 != NULL){
        anst->next = new ListNode(l2->val);
        anst= anst->next;
        l2= l2->next;
    }
    return ans->next;
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
    int n, m;
    cin >> n ;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);

    ListNode *head = mergeTwoLists(h1, h2);
    printList(head);

    return 0;
}