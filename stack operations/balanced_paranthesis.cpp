#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout<<"Enter a string with paranthesis: ";
    cin>>str;

    stack<char>st;

    for(auto i :str){
        if(i == '(' || i=='{' || i=='['){
            st.push(i);
        }else{
            if(i==')' && st.top()=='(' || i=='}' && st.top()=='{' || i==']' && st.top()=='['){
                st.pop();
            }else if(st.empty()){
                cout<<"invalid paranthesis.";
                break;
            }else{
                cout<<"invalid paranthesis.";
                break;
            }
        }
    }
    if(!st.empty()){
        cout<<"invalid paranthesis";
    }else{
        cout<<"valid paranthesis";
    }
}