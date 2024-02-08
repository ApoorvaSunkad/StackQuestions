// Here I have implemented the basic stack operations such as PUSH,POP,EMPTY,
//TOP,EMPLACE,SIZE

#include<bits/stdc++.h>
using namespace std;

int main(){
    //Creation of stack
    stack<int>st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    //Display the top element
    cout << st.top() << endl; // 4

    //Pop the element from stack
    st.pop();

    cout << st.top() << endl; // 3

    //Check is stack is empty or not
    if(st.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "Stack is not empty " << endl;
    }

    //Check the size of stack
    cout << st.size() << endl; //3(size)

}