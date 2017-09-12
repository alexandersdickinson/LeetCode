class Solution {
public:
    std::string countAndSay(int n) {
        std::string solution = "1";
        for(int i = 0; i < n - 1; ++i){
            solution = sayOnce(solution);
        }
        return solution;
    }

    std::string sayOnce(std::string s){
        std::string nextIteration; 
        char currentChar = s.at(0);
        int charCount = int();
        for(int i = 0; i < s.length(); ++i){
            if(s.at(i) != currentChar){
                nextIteration += std::to_string(charCount) + currentChar;
                charCount = 1;
                currentChar = s.at(i);
            } 
            else{
                ++charCount; 
            }
        } 
        nextIteration += std::to_string(charCount) + currentChar;
        charCount = 1;
        return nextIteration;
    }
};
