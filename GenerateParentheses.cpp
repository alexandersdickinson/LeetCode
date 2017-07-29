class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> solution;
        addParen(solution, "", n, 0);
        return solution; 
    }

    //Adds passed string to the solution vector. Keeps track of the number of open and closing parentheses. Calls itself depending on the number of available open
    //and closing parentheses. 
    void addParen(std::vector<std::string> &solution, std::string str, int openCount, int closeCount){
        if(openCount == 0 && closeCount == 0){
            solution.push_back(str); 
        } 
        else{
            if(openCount > 0){
                addParen(solution, str + "(", openCount - 1, closeCount + 1); 
            }
            if(closeCount > 0){
                addParen(solution, str + ")", openCount, closeCount - 1); 
            }
        }
        return;
    }
};
