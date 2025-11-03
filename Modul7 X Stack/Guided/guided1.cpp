#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isEmpty( Node *top) {
    return top == NULL;
}

void push (Node *&top , int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
} 

int pop (Node *&top)
{
    if (isEmpty(top))
    {
        cout << "Stack kosong, tidak bisa pop" << endl;
        return 0;
    }

    int poppedData = top -> data;
    Node *temp = top;
    top = top -> next;

    delete temp;
    return poppedData;
}

void show(Node *top) {
    if (isEmpty(top)) {
        cout << "Stack kosong" << endl;
        return;
    }

    cout << "TOP -> ";
    Node *temp = top;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main () {
    Node *stack = NULL;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    cout << "Menampilkan isi stack: " << endl;
    show(stack);

    cout << "Pop data: " << pop(stack) << endl;
    
    cout << "Menampilkan isi stack: " << endl;
    show(stack);

    return 0;
}


int main()
{
    cout << "Hello world!" <<
endl;
    Stack S;
    createStack(S);
    Push(S,3);
    Push(S,4);
    Push(S,8);
    pop(S)
    Push(S,2);
    Push(S,3);
    pop(S);
    Push(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}