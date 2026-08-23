#include<bits/stdc++.h>
using namespace std;
vector<int>st;

//array implementation of stack
void push(int data, int &top){
    st.push_back(data);
    top++;
}
void pop(int &top){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return;
    }
    st.pop_back();
    top--;
}

int main(){
    int top=-1;
    push(10,top);
    push(20,top);
    push(30,top);
    push(40,top);
    push(50,top);
    cout<<"Stack elements are: ";

    for(int i=0; i<=top; i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
    pop(top);
    cout<<"Stack elements after pop operation are: ";
    for(int i=0; i<=top; i++){
        cout<<st[i]<<" ";
    }
    cout<<endl;
}

//  (2:51:34) Array implementation of stacks
// ⌨️ (3:04:42) Linked List implementation of stacks
// ⌨️ (3:15:39) Reverse a string or linked list using stack.
// ⌨️ (3:32:03) Check for balanced parentheses using stack
// ⌨️ (3:46:14) Infix, Prefix and Postfix
// ⌨️ (3:59:14) Evaluation of Prefix and Postfix expressions using stack
// ⌨️ (4:14:00) Infix to Postfix using stack
// ⌨️ (4:32:17) Introduction to Queues
// ⌨️ (4:41:35) Array implementation of Queue
// ⌨️ (4:56:33) Linked List implementation of Queue