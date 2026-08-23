#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};
node* top=NULL;
void push(int data){
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if(top==NULL){
        top = newNode;
    }else{
        newNode->next = top;
        top = newNode;
    }
}

int pop(){
    if(top==NULL){
        cout<<"Stack is empty"<<endl;
        return -1;
    }else{
        int poppedData = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        return poppedData;
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    cout<<"Popped element: "<<pop()<<endl;
    cout<<"Popped element: "<<pop()<<endl;
    return 0;
}