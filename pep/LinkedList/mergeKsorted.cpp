#include <iostream>
#include <vector>

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

ListNode *mergeTwoList(ListNode *left ,ListNode *right){
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
ListNode *mergeKListHelper(vector<ListNode *> lists , int lo , int hi ){
    if(lo == hi ){
        return lists[lo];
    }
    int mid = (lo+hi)/2;
    ListNode *left = mergeKListHelper(lists,lo,mid);
    ListNode *right = mergeKListHelper(lists,mid+1,hi);
    
    ListNode *res = mergeTwoList(left,right);
    return res;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *ans = mergeKListHelper(lists,0,lists.size()-1);
    
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
    vector<ListNode *> list(n, 0);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        list[i] = createList(m);
    }

    ListNode *head = mergeKLists(list);
    printList(head);

    return 0;
}