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

// find size of list
int size(ListNode *head){
        if(head == NULL)
            return 0;
        return size(head->next)+1;
        
}


ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0|| head == NULL|| head->next == NULL){
            return head;
        }
        int length= size(head);
        ListNode *ansh = NULL;
        ListNode *anst = ansh;
        ListNode *temp = head;
        for(int j =0 ; j < length/k && temp != NULL ; j++){
            ListNode *curr = temp;
            ListNode *prev = NULL;
            ListNode *future;
            for(int i =0 ; i < k && curr != NULL ; i++){
                future = curr->next;
                curr->next= prev;
                prev = curr;
                curr = future;               
            }
            if(ansh== NULL){
                ansh = prev;
                anst = temp;
            }else{
                anst->next = prev;
                anst =temp;
            }
            temp = future;            
        }
        anst->next=temp;
        return ansh;
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
    int k;
    cin >> k;
    h1 = reverseKGroup(h1, k);
    printList(h1);

    return 0;
}