#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void append(Node*& head, int value){
    Node* newNode= new Node();
    newNode->data=value;
    newNode->next=nullptr;
    if(head==nullptr){
        head=newNode;
        return;
    } 
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
}
void print(Node* head){
    Node* temp= head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void sortList(Node* head){
int count[3]={0,0,0};
Node* current=head;
while(current!=nullptr){
    count[current->data]++;
    current=current->next;
}
current=head;
for(int i=0; i<3; i++){
    while(count[i]>0){
        current->data=i;
        current=current->next;
        count[i]--;
    }
}
}
int main(){
    int n;
    cin>>n;
    Node* head=nullptr;
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        append(head, value);
    }
    sortList(head);
    print(head);
}