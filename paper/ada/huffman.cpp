#include <bits/stdc++.h>
using namespace std;
#define f(a,b) for(int i =a ; i < b ; i++)
typedef vector<int> vi;
typedef vector<char> vc;

class MinHeapNode {
public:
char data;
unsigned freq;
MinHeapNode *left, *right;
MinHeapNode(char data, unsigned freq){
left = right = NULL;
this->data = data;
this->freq = freq;
}
};

class compare {
public:
bool operator()(MinHeapNode* l, MinHeapNode* r)
{
return (l->freq > r->freq);
}
};

void printhuffman(struct MinHeapNode* root, string str)
{
    if (!root)
    return;
    if (root->data != '$')
    cout << root->data << ": " << str << endl;
    printhuffman(root->left, str + "0");
    printhuffman(root->right, str + "1");
}
void huffman(vc data, vi freq, int size){
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
    minHeap.push(new MinHeapNode(data[i],freq[i]));
    while (minHeap.size() != 1) {
    left = minHeap.top();
    minHeap.pop();
    right = minHeap.top();
    minHeap.pop();
    top = new MinHeapNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    minHeap.push(top);
    }
    printhuffman(minHeap.top(), "");
}
int main(int argc ,char **argv)
{
    int n;
    cin>> n;
    vector<char> a(n);
    f(0,n)
    cin>> a[i];
    vector<int>freq(n);
    f(0,n)
    cin>> freq[i];
    huffman(a, freq, n);
    return 0;
}