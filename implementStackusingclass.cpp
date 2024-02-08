/*
Implement stack using array.

*/

#include<bits/stdc++.h>
using namespace std;


//Time complexity: O(1)

class Stack{
    //data members

    public:
    int top;
    int size;
    int *arr;

    //behaviour
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele){
        if(size-top>1){
            top++;
            arr[top] = ele;
        }
        else{
            cout << "stack overflow" << endl;
        }
    }

    void pop(){

        if(top>=0){
            int result = arr[top];
            top--;
            cout << result << endl;
        }else{
            cout << "Stack underflow" << endl;
        }
    }

    int Peek(){
        if(top>=0){
            return arr[top];
        }else{
            cout << "Stack is empty " << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};
int main(){
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.Peek() << endl;

    st.pop();

    cout << st.Peek() << endl;

    st.pop();

    cout << st.Peek() << endl;

    st.pop();

    cout << st.Peek() << endl;

    if(st.isEmpty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "Stack is not empty " << endl;
    }
    
}