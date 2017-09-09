class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> solution;
<<<<<<< HEAD
        std::vector<std::string> temp = words;
        int startingIndex; 
        bool match;
        for(int i = 0; i < s.length();){
            match = false;
            //test for a string in words
            for(auto it = temp.begin(); it != temp.end(); ++it){
                //if current element in temp is equal to substring starting at i with same length as current element in temp, set match to true, break out of loop.
                //delete element from temp, reassign iterator, iterate i by the length of element in temp. Add i to solution vector.
                if((*it) == s.substr(i, (*it).length())){
                    match = true;
                    if(temp.size() == words.size()){
                        startingIndex = i;
                    }
                    i += (*it).length();
                    it = temp.erase(it);
                    break; 
                }
            } 
            if(!match){
                i = (temp.size() != words.size()) ? startingIndex + 1 : i + 1;
                temp = words;
            }
            else if(temp.empty()){
                solution.push_back(startingIndex);
                temp = words;
                i = startingIndex + 1;
=======
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
>>>>>>> c63642cdb3397ac153a2798e3fddf793b342108f
            }
        }
        return solution;
    }
};
