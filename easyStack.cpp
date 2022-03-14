/******************************************************************************

A simplified stack exercise

*******************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    int stu_no;
    Node *next; // the conventional way 
};

class stack {
private:
    Node *top; // the conventional way
 
public:
    stack() { 
        this->top = NULL; 
        cout << " # The stack is generated. " << endl; 
    }  
    ~stack() { cout << " # The stack is deleted." << endl; } 
    void push(int n);
    void pop();
    void display();
};
 
void stack::push(int n) {
    Node *newNode = new Node; // the conventional way
    //fill data part
    newNode->stu_no = n;
    //link part
    newNode->next = this->top;
    //make newnode as top/head
    this->top = newNode;
}

void stack::pop() {
    if (this->top == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node *temp;
    cout << top->stu_no << " is removed." << endl;
    temp = top;
    top = top->next;
    delete temp;
}

void stack::display() {
    if (top == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node *temp = top; // the conventional way
    while (temp != NULL){
        cout << temp->stu_no << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    stack st;
    int stu_no;
    char c;

    cout << "push an item: "; 
    cin >> stu_no;
    //push data into the stack
    st.push(stu_no);
    //show the stack content
    st.display();
    cout << "push an item: "; 
    cin >> stu_no;
    //push data into the stack (2nd)
    st.push(stu_no);
    //show the stack content
    st.display();
    //push data into the stack (3rd)
    cout << "push an item: "; 
    cin >> stu_no;
    st.push(stu_no);
    //show the stack content
    st.display();
    
    cout << "Press any key to continue..." << endl;
    cin.ignore(1);
    
    // pop an item 
    cout << "pop out an item: "; 
    cin.ignore(1);
    st.pop();
    //show the stack content
    st.display();
    // pop an item 
    cout << "pop out an item: "; 
    cin.ignore(1);
    st.pop();
    //show the stack content
    st.display();
    // pop an item 
    cout << "pop out an item: "; 
    cin.ignore(1);
    st.pop();
    st.display();
    return 0;
}
