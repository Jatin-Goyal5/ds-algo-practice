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

bool isPalindrome(ListNode *head)
{
    ListNode *fList = head;
    
    ListNode *mid = findMid(head);
    ListNode *sList = mid->next;
    mid->next = NULL;
    
    ListNode *revSecList = reverse(sList);
    
   
    while(revSecList != NULL){
        if(revSecList->val != fList->val){
            return false;
        }
        revSecList =revSecList->next;
        fList = fList->next;
        
    }
    return true;
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

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}