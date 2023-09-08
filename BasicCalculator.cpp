class Solution {
    
    bool isOperand(string &s){
        return s == "+" || s == "-";
    }
    bool isOpenedBracket(string &s){
        return s == "(";
    }
 
    bool isDigit(char a){
        return a>='0' && a<='9';
    }
    bool isSpace(char a){
        return a == ' ';
    }

    bool isNumber(string &s){
        return isDigit(s[0]);
    }

    vector<string>convertToTokens(string &s){
        vector<string>str;
        int n = s.size();

        for(int i=0;i<n;){

            if(isSpace(s[i])){
                i++;
                continue;
            }

            string t;

            if(isDigit(s[i])){
                while(i<n && isDigit(s[i])){
                    t+=s[i];
                    i++;
                }

            }
            // is operand
            else if(!isSpace(s[i])){
                if(s[i] == '-' && (str.empty()  || !isNumber(str.back()) )){
                    if(!str.empty() && !isOpenedBracket(str.back() ))
                        str.push_back("+");

                    str.push_back("0");
                }
                t+=s[i];
                i++;
                
            }
            str.push_back(t);
        }
        return str;
    }

    vector<string>convertToPostfix(string &s){
        vector<string>str,tokens = convertToTokens(s);
        stack<string>stk;

        for(auto &i:tokens){
            if(isNumber(i))
                str.push_back(i);
            
            else if(isOperand(i)){
                if(! (stk.empty() || isOpenedBracket(stk.top()) ) ){    
                    str.push_back(stk.top());
                    stk.pop();
                } 

                stk.push(i);
            }
            else if(isOpenedBracket(i)){
                stk.push(i);
            }
            // Closed bracket
            else{
                while(!stk.empty() && !isOpenedBracket(stk.top()) ){
                    str.push_back(stk.top());
                    stk.pop();
                } 
                stk.pop();
            }

        }

        while(!stk.empty()){
            str.push_back(stk.top());
            stk.pop();
        } 

        return str;

    }

    int pop(stack<int>& stk ){
        int top = stk.top();
        stk.pop();
        return top;
    }

    int calculatePostfix(vector<string> postfix){
        int res = 0;
        stack<int>stk;
        for(auto &i: postfix){
            if(isNumber(i))
                stk.push(stoi(i));
            else{
                if(stk.size() == 1){
                    if(i == "-"){
                        stk.top()*=-1;
                    }

                    continue;
                }
                int op2 = pop(stk),op1 = pop(stk);
                
                if(i == "+")
                    op1 += op2;
                else
                    op1 -= op2;

                stk.push(op1);
            }
        }

        return stk.top();
    }
public:
    int calculate(string s) {

        return calculatePostfix(convertToPostfix(s));
    }
};
