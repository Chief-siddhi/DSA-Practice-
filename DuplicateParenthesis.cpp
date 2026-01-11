//duplicate parenthesis
//we have to find that whether there are any duplicate parenthesis or not 
//Given a balanced expression that can contain opening and closing parenthesis, check if it contains any duplicate parenthesis or not.
//A set of parenthesis are duplicate if the same sub-expression is surrounded by multiple parenthesis.
//Example:
//Input: ((x+y))+z
//output: true
//Explanation: ((x+y)) has duplicate parenthesis
#include <iostream>
#include <stack>    
using namespace std;

bool duplicateParenthesis(string str){
    stack<char> s;

    for(int i=0; i<str.size(); i++){
        char ch = str[i];

        if(ch==')'){
            int count =0;
            while(!s.empty() && s.top()!='('){
                s.pop();
                count++;
            }
            if(!s.empty()){
                s.pop(); //for opening bracket
            }
            if(count<1){
                return true; //duplicate parenthesis found
            }
        } else{
            s.push(ch);
        }
    }
    return false; //no duplicate parenthesis
}
int main(){
    string str = "((a+b)+((c+d)))";
    if(duplicateParenthesis(str)){
        cout<<"Duplicate Parenthesis found"<<endl;
    } else{
        cout<<"No Duplicate Parenthesis found"<<endl;
    }
    return 0;
}