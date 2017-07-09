class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parenStack;
        for(int i = 0; i < s.length(); ++i){
            if(s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{'){
                parenStack.push(s.at(i)); 
            }
            else if(parenStack.empty() || (s.at(i) == ')' && parenStack.top() != '(') || (s.at(i) == '}' && parenStack.top() != '{') || (s.at(i) == ']' && parenStack.top() != '[')){
                return false;
            }        
            else{
                parenStack.pop(); 
            }
        }            
        return parenStack.empty();
    }
};
