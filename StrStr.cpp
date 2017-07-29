class Solution {
public:
    int strStr(string haystack, string needle) {
        int substringLen = 1;
        if(needle == ""){
            return 0; 
        }
        for(int i = 0; i + substringLen -1 < haystack.length();){
            if(haystack.substr(i, substringLen) == needle.substr(0, substringLen)){
                if(substringLen == needle.length()){
                    return i; 
                }
                else{
                    ++substringLen; 
                }
            } 
            else{
                ++i;
                substringLen = 1; 
            }
        }
        return -1;
    }
};
