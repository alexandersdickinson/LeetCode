class Solution {
public:
    int myAtoi(string str) {
        int signs = int();
        long converted = 0;
        bool negative = false;
        if(str.find_first_of("1234567890") == string::npos || str.length() == 0){
            return 0;
        }
        str = str.substr(str.find_first_not_of(" \t"), str.length());
        str = str.substr(0, str.find_first_not_of("+-1234567890"));
        for(int i = str.length() - 1, j = 0; i >= 0; --i, ++j){
            if(str.at(i) == '+' || str.at(i) == '-'){
                break;
            }
            else{
                converted += ((long)str.at(i) - 48) * (long)pow(10, j);
                if(j >= 9 && converted > INT_MAX){
                    if(str.find_first_of("1234567890") > 1){
                        return 0;
                    }
                    else if(str.at(0) == '-'){
                        return INT_MIN;
                    }
                    else{
                        return INT_MAX;
                    }
                }
            }
        }
        if(str.find_first_of("1234567890") > 1){
            return 0;
        }
        else if(str.at(0) == '-'){
            negative = true;
        }
        if(negative){
            return (int)converted * -1;
        }
        else{
            return converted;
        }
    }
};
