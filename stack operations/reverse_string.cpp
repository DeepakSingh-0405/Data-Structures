#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout<<"enter a string: ";
    cin>>str;
    stack<char>st;
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }
    cout<<"Reversed string: ";
    int i=0;
    while(!st.empty()){
        str[i] = st.top();
        st.pop();
        i++;
    }
    cout<<str<<endl;
    return 0;
}