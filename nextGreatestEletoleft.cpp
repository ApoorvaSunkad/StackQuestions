/*


*/


//Brute force: using nested loops
//T.C = O(N^2)
//S.C = O(N)

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreatesttoLeft(int arr[], int n){
    vector<int> v;
    
    for(int i = 0; i<n; i++){
        int nextGreater = -1;
        for(int j = i-1; j>=0; j--){
            if(arr[j]>arr[i]){
                nextGreater = arr[j];
                break;
            }
        }
        v.push_back(nextGreater);
    }
    return v;
    
}
int main()
{
    int arr[] = {6,8,0,1,3};
    int n = 5;
    
    vector<int> ans;
    ans = nextGreatesttoLeft(arr,n);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}


//Optimised solution with Stacks
//Whenever we have 2 nested loops and J loop is dependent on I that means
//we can use stacks here


//T.C = O(2N)
//S.C = O(N) //worst case

vector<int> nextLargerElement(int arr[], int n){

    vector<int> ans;

    stack<int> s;
    
    for(int i = 0; i < n; i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top()>arr[i]){
            ans.push_back(s.top());
        }
        else if(!s.empty() && s.top()<=arr[i]){
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    
    return ans;
}
int main()
{
    int arr[] = {1,3,2,4};
    int n = 4;
    
    vector<int> ans;
    ans = nextLargerElement(arr,n);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}