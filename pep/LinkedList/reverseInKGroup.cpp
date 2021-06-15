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
int findSize(ListNode *head)
{
    ListNode *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

ListNode *reverseInKGroup(ListNode *head, int k)
{
    //* if size of group is zero or no element is present in list
    if (k == 0 || head == NULL)
    {
        return head;
    }

    //* declaring ansNode and curr for traversal of list
    ListNode *ansH = NULL;
    ListNode *ansT = NULL;
    ListNode *curr = head;
    int size = findSize(head);
    //* if group size greater than size of list return head
    if (k > size)
    {
        return head;
    }

    // traversing list
    while (size >= k)
    {
        int temp = k;          //* storing as it will change
        ListNode *prev = NULL; //* prev node
        ListNode *fc = curr;   //* fake current or current head list that going to be reversed
        while (temp-- > 0)
        {
            //* preserve head of future node e.g if list is 1->5 store reference for 5
            ListNode *future = curr->next;

            //* connect e.g null <- 1
            curr->next = prev;

            //*move prev from null to 1 which is current
            prev = curr;

            //* move curr to 5
            curr = future;
        }
        //* if 1 st group
        if (ansH == NULL)
        {

            ansH = prev;
            ansT = fc;
        }
        //* other than 1st grp
        else
        {
            ansT->next = prev;
            ansT = fc;
        }
        size -= k;
    }
    if (size > 0)
    {
        ansT->next = curr;
    }
    return ansH;
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
    h1 = reverseInKGroup(h1, k);
    printList(h1);

    return 0;
}