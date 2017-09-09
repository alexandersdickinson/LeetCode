class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //iterate through string
        std::vector<int> solution;
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
            }
        }
        return solution;
    }
};
