class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> solution;
        //Number of words and the number of occurrences.
        std::unordered_map<std::string, int> counts;
        std::unordered_map<std::string, int> tempCounts;
        int wordLen = words.at(0).length();
        //Populate counts with words.
        for(auto word = words.begin(); word != words.end(); ++word){
            ++(counts[(*word)]); 
        }
        //Iterate through the string.
        for(int i = 0; i < s.length() - wordLen * words.size() + 1; ++i){
            tempCounts.clear();
            for(int j = i; j - i < wordLen * words.size(); j += wordLen){
                if(counts.find(s.substr(j, wordLen)) != counts.end()){
                    ++(tempCounts[s.substr(j, wordLen)]);
                }
                else{
                    break;
                }
            }
            if(counts == tempCounts){
                solution.push_back(i); 
            }
        }
        return solution;
    }
};
