/*
Implement stack using Linked list.

*/

#include<bits/stdc++.h>
using namespace std;


//Time complexity: O(1)
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{

    public:
    Node* head;
    int size;

    Stack(){
        this->head = NULL;
        size = 0;
    }

    //For push operation there is no overflow condition check needed as LL stores elements dynamically
    void push(int ele){
        Node* temp = new Node(ele);
        temp->next = head;
        size++;
        head = temp;
    }
    void pop(){
        if(head==NULL){
            cout << "Stack underflow " << endl;
        }

        int result = head->data;
        head = head->next;
        size--;
        cout << result << endl;
    }

    int Peek(){
        if(head == NULL){
            cout << "Stack is empty " << endl;
            return -1;
        }
        return head->data;
    }
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int SizeofStack(){
        return size;
    }
};

int main(){
    Stack st;

    st.push(22);
    st.push(23);
    st.push(24);

    cout << st.Peek() << endl;
    st.pop();
    cout << st.Peek() << endl;
    st.pop();


    if(st.isEmpty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "Stack is not empty " << endl;
    }

    cout <<"Size of the stack is " << st.SizeofStack() << endl;

}