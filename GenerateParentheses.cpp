class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::stack<char> openStack;
        std::stack<char> closeStack;
        for(int i = 0; i < n; ++i){
            openStack.push('('); 
            closeStack.push(')');
        }
        std::vector<string> solution = {""};
        while(!openStack.empty() || !closeStack.empty()){
            std::vector<string> temp;
            if(!openStack.empty()){
                for(int i = 0; i < solution.size(); ++i){
                    temp.push_back(solution.at(i) + openStack.top()); 
                }
                openStack.pop();
            }
            solution.swap(temp);
            temp = {};
            if(!closeStack.empty() && closeStack.size() > openStack.size()){
                for(int i = 0; i < solution.size(); ++i){
                    temp.push_back(solution.at(i) + closeStack.top()); 
                }
                closeStack.pop();
            }
            solution.swap(temp);
        }
        return solution;
    }
};
