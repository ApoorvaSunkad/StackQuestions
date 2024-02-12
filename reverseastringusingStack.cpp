/*

You are given a string S, the task is to reverse the string using stack.

Example 1:

Input: S="GeeksforGeeks"
Output: skeeGrofskeeG

*/

//T.C = O(N)
//S.C = O(N)

#include<bits/stdc++.h>
using namespace std;

char* reverse(char *S, int len)
{
    
    stack<char> st;
    
    for(int i = 0; i<len; i++){
        st.push(S[i]);
    }
    
     for (int i = 0; i < len; i++) {
        S[i] = st.top();
        st.pop();
    }

    return S;
}


//Another method
//STACK always uses LIFO property

#include<bits/stdc++.h>
using namespace std;

int main(){

    stack<char>st;

    string str = "Apoorva";

    for(int i =0; i<str.length();i++){
        st.push(str[i]);
    }

    string ans = "";

    while(!st.empty()){
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }

    cout << "answer is: " << ans << endl;
}