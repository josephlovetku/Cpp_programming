#include <iostream>
#include <string.h>
#include <memory> // this is for shared_ptr
using namespace std;

struct Node {
    int stu_no;
    char stu_name[50];
    //shared_ptr<Node> next;
    Node *next; // the conventional way 
};

class stack {
private:
    //shared_ptr<Node> top; 
    Node *top; // the conventional way
 
public:
    stack() { 
        this->top = NULL; 
        cout << " # The stack is generated. " << endl; 
    }  
    ~stack() { cout << " # The stack is deleted." << endl; } 
    void push(int n, char name[]);
    void pop();
    void display();
};
 
void stack::push(int n, char name[]) {
    Node *newNode = new Node; // the conventional way
    //auto newNode = make_shared<Node>();
    //fill data part
    newNode->stu_no = n;
    strcpy(newNode->stu_name, name);
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
    cout << top->stu_name << " is removed." << endl;
    top = top->next;
}

void stack::display() {
    if (top == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    //shared_ptr<Node> temp = this->top;
    Node *temp = this->top; // the conventional way
    while (temp != NULL){
        cout << temp->stu_no << " ";
        cout << temp->stu_name << " ";
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    stack s;
    char ch;
    int stu_no;
    char stu_name[50];
    
    do {
        int n;
         
        cout << "ENTER CHOICE\n"<<"1.Push\n"<<"2.Pop\n"<<"3.Display\n";
        cout << "Make a choice: ";
        cin >> n;
     
        switch(n) {
            case 1:  
                cout << "Enter details of the element to be pushed: \n";
                cout << "Roll Number: ";
                cin >> stu_no;
                cout << "Enter Name: ";
                std::cin.ignore(1); // to absort '\n' newline input
                cin.getline(stu_name, 50);

                //push data into the stack
                s.push(stu_no, stu_name);
                break;
         
            case 2 : 
                //pop data from stack
                s.pop();
                break;
             
            case 3 : 
                //display data
                s.display();
                break;
                 
            default : 
                cout << "Invalid Choice\n";
    }
     
    cout << "Do you want to continue? : ";
    cin >> ch;
 
    } while (ch != 'n' && ch != 'N');
     
    return 0;
}
