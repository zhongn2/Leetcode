//Length of Last Word

//method 1: NO STL
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = strlen(s);
        if(length == 0) return 0;
        int lengthofLast = 0;
		// visit from back, add 1 to length when it does not meet with " " 
		// stop at " "
        for(int i = length - 1; i >= 0; i--){
            if(s[i] != ' ') lengthofLast ++;
            else { // e.g "a ".  we have to check the length is greater than 0
                if(lengthofLast > 0) return lengthofLast;
            }
        }
        return lengthofLast;
        
    }
};

// method 2: STL
// find the first alpha and start from the alpha, find isnot alpha one.
class Solution {
public:
    int lengthOfLastWord(const char *s) {
      const string str(s);
      auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
      auto last = find_if_not(first, str.rend(), ::isalpha);
      return distance(first, last);
    }
};