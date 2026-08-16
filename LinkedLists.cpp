#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node* createNode(int data){
    node* newNode = new node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(node** head, int data){
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(node** head, int data){
    node* newNode = createNode(data);
    node* temp = *head;
    while(temp!=NULL && temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void insertAtPosition(node** head, int data, int pos){
   node* newnode = createNode(data);
   if(pos==1){
    newnode->next = *head;
    *head = newnode;
    return;

   } 
   node* temp = *head;
   for(int i=0; i<pos-2;i++){
    temp = temp->next;
   }
   newnode->next = temp->next;
   temp->next = newnode;
   return;
}

void reverseLLIterative(node** head){
    node* prev = NULL;
    node* curr = *head, *next;
    while(next!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void reverseLLRecursive(node* p, node** head){
    if(p->next == NULL){
        *head = p;
        return;
    }
    reverseLLRecursive(p->next, head);
    node* q = p->next;
    q->next = p;
    p->next = NULL;
    return;
}

void deleteAtBeginning(node** head){
    node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void deleteAtEnd(node** head){
    node* temp = *head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return;
}

void deleteAtPosition(node** head, int pos){
    node* temp = *head;
    if(pos==1){
        *head = (*head)->next;
        delete temp;
        return;
    }
    for(int i=0; i<pos-2;i++){
        temp = temp->next;
    }
    node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
    return;
}

void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void printLLRecursive(node* head){
    if(head==NULL){
        cout<<endl;
        return;
    }
    cout<<head->data<<" ";
    printLLRecursive(head->next);
}

int main(){
    node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 11);
    insertAtPosition(&head, 2, 1);
    insertAtPosition(&head, 22, 2);
    insertAtEnd(&head, 3);
    printLL(head);

    reverseLLIterative(&head);
    printLL(head);
    reverseLLRecursive(head, &head);
    printLLRecursive(head);

    deleteAtPosition(&head, 2);
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    printLL(head);
    
    
}