/*
Given an integer array Arr of size N. For each element in the array, 
check whether the left adjacent element (on the next immediate position) 
of the array is smaller. If previous element is smaller, update the current index 
to that element. If not, then  -1.

Example 1:

Input:
N = 5
Arr[] = {4, 2, 1, 5, 3}
Output:
-1 -1 -1 1 1

*/

//Brute force: nested loops
//T.C = O(N^2)
//S.C = O(N)
#include <bits/stdc++.h>
using namespace std;

vector<int> nearestsmaller(int arr[], int n){
    
    vector<int> v;
    
    for(int i = 0; i<n; i++){
        int nearSmall = -1;
        for(int j = i-1; j>=0; j--){
            if(arr[j]<arr[i]){
                nearSmall = arr[j];
                break;
            }
        }
        v.push_back(nearSmall);
    }
    return v;
}
int main()
{
    int arr[] = {4,5,2,10,8};
    int n = 5;
    vector<int>ans;
    ans = nearestsmaller(arr,n);
    
    for(int i = 0; i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}


//Optimised solution with Stacks
//Whenever we have 2 nested loops and J loop is dependent on I that means
//we can use stacks here


//T.C = O(2N)
//S.C = O(N) //worst case


#include <bits/stdc++.h>
using namespace std;

vector<int> nearestsmaller(int arr[], int n){
    
    vector<int> v;
    
    stack<int> s;
    
    for(int i = 0; i<n; i++){
        if(s.empty()){
            v.push_back(-1);
        }
        else if(!s.empty() && s.top()<arr[i]){
            v.push_back(s.top());
        }
        else if(!s.empty() && s.top()>=arr[i]){
            while(!s.empty() && s.top()>=arr[i]){
                s.pop();
            }
            
            if(s.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return v;
}
int main()
{
    int arr[] = {4,5,2,10,8};
    int n = 5;
    vector<int>ans;
    ans = nearestsmaller(arr,n);
    
    for(int i = 0; i<ans.size();i++){
        cout << ans[i] << " ";
    }

    return 0;
}