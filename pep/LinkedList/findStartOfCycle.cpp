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

ListNode *CycleNode(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    bool check= false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            check = true;
            break;
            
        }
    }
    if(check){
        slow = head;
        while(slow != NULL){
            if(slow == fast){
                return slow;
            }

            slow= slow->next;
            fast = fast->next;
        }
    }else{
        return NULL;    
    }
    
    
}

ListNode *takeInput()
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
    int idx;
    cin >> idx;
    if (idx >= 0)
    {
        ListNode *curr = dummy->next;
        while (idx-- > 0)
        {
            curr = curr->next;
        }
        prev->next = curr;
    }
    return dummy->next;
}

int main()
{
    ListNode *head = takeInput();
    ListNode *ans = CycleNode(head);
    cout << (ans != nullptr ? ans->val : -1) << endl;
    return 0;
}