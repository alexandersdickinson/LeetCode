class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0; 
        }
        for(int i = 0; i + needle.length() - 1 < haystack.length(); ++i){
            if(haystack.substr(i, needle.length()) == needle){
                return i;
            } 
        }
        return -1;
    }
};
