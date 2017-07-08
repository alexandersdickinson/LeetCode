class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {}; 
        }

        vector<string> combinations = {""};
        int multiple = int();

        std::map<char, vector<string>> letterMap = {{'1', {}}, {'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}}, {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}}, {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}}, {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}}};

        for(int i = 0; i < digits.length(); ++i){
            //iterate through digits, then iterate through mappings to digits
            auto pastLength = combinations.size();
            multiple = letterMap.at(digits.at(i)).size();
            combinations.resize(combinations.size() * multiple);  //multiply by the number of characters mapped to the current digit
            for(int j = 0; j < multiple; ++j){
                std::copy_n(combinations.begin(), pastLength, combinations.begin() + pastLength * j);
            }
            for(int j = 0; j < letterMap.at(digits.at(i)).size(); ++j){
                for(int k = 0; k < pastLength; ++k){
                    //push back char in jth position of value mapping to digit to kth + pastLength * j element in vector
                    combinations.at(k + pastLength * j).append(letterMap.at(digits.at(i)).at(j));
                }
            }
        }
        return combinations;
    }
};
