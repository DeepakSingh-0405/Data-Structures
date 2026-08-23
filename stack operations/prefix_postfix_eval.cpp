#include<bits/stdc++.h>
using namespace std;


int postfix(string str){
    stack<int>st;
    string x;
    for(auto i : str){
        if(i == ' ') {
            if(!x.empty()){
                st.push(stoi(x));
            }
            x = "";
        }
        else if(i>='0' && i<='9'){
            x += i;
        }
        else if(i == '+' || i=='-' || i=='*' || i=='/'){
            if(!x.empty()){
                st.push(stoi(x));
                x = "";
            }
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (i)
            {
            case '+':
                st.push(b+a);
                break;
            case '-':
                st.push(b-a);
                break;
            case '*':
                st.push(b*a);
                break;
            case '/':
                st.push(b/a);
                break;
            default:
                break;
            }
        }
    }
    return st.top();

}

int prefix(string str){
    stack<int>st;
    string x;
    for(int i=str.length()-1; i>=0; i--){
        if(str[i] == ' '){
            if(!x.empty()){
                st.push(stoi(x));
            }
            x = "";
        }else if(str[i]>='0' && str[i]<='9'){
            x += str[i];
        }else if(str[i] == '+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            if(!x.empty()){
                st.push(stoi(x));
                x = "";
            }
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (str[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int main(){
    string str;
    cout<<"Enter a postfix expression: ";
    getline(cin,str);
    cout<<"Postfix evaluation: "<<postfix(str)<<endl;
    cout<<"Enter a prefix expression: ";
    getline(cin,str);
    cout<<"Prefix evaluation: "<<prefix(str)<<endl;
}