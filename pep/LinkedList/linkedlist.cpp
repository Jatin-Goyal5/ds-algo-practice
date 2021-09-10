#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val =0;
    Node* next = NULL;
    Node(){

    }
    Node(int val){
        this->val= val;
    }
};


// display of linked list
void display(Node *head){
    while(head != NULL)
    {
        cout<< head->val<< " -> ";
        head= head->next;
    }

    cout<< endl;
}

// not for tail node
void deleteNode(Node * del){
    if(del->next == NULL)
    {
        return;
    }
    Node *future = del->next;
    del->val = future->val;
    del->next = future->next;
    delete future;
}

// find size of linked list
int size(Node *head){
    if(head== NULL){
        return 0;
    }else{
        return size(head->next)+1;
    }
}

// mid of linked list
Node* mid(Node *head){
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


// reverse linked list
Node *reverse(Node *head){
    Node *prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node *future = curr->next;
        curr->next = prev;
        prev= curr;
        curr = future;
    }

    return prev;
}

bool search(Node *head , int val){
    if(head == NULL){
        return false;
    }
    if(head->val == val){
        return true;
    }
    return search(head->next,val);
}

// swap node in pairs
Node* swapPairs(Node* head) {
    Node *trav = head;
    while(trav != NULL && trav->next != NULL){
        Node *future = trav->next;
        int temp = trav->val;
        trav->val = future->val;
        future->val = temp;
        trav = future->next;
    }
    return head;
}


// detect cycle in linked list
bool hasCycle(Node *head) {
    Node *slow= head,*fast = head;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    
    return false;
} 

// kth form end
int kthFromEnd(Node *head,int k){
    Node *slow= head;
    Node *fast= head;
    while(k--)
        fast = fast->next;
    while(fast->next != NULL ){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->val;

}
Node* deleteDuplicates(Node* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *dummy = head;
        while(dummy != NULL && dummy->next != NULL){
            Node * ne = dummy->next;
            if(ne->val == dummy->val ){
                while(ne != NULL && ne->val == dummy->val ){
                    ne= ne->next;
                }
                dummy->next = ne;
                
            }
            dummy = dummy->next;
        }
        return head;
    }
int main(){
    int n;
    cin>> n;
    Node *head = new Node(-1);
    Node *headt = head;
    while(n--){
        int x;
        cin>> x;
        Node *curr = new Node(x);
        headt->next= curr;
        headt= headt->next;
    }
    // headt->next = NULL;

    display(head->next);
    int k;
    // cin>> k;
    // cout<< kthFromEnd(head->next,k);
    // cout<< "size of linked list -"<<size(head->next)<< endl;

    // cout<< "mid of linked list -" <<mid(head->next)->val<< endl;
    // Node *tobedelete = head->next->next;


    // display(reverse(head->next));
    // deleteNode(tobedelete);
    // display(head->next);

    // cout<< search(head->next,1);
    return 0;
}