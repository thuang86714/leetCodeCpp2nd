/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        //there will be at least one word in s
        //naive TC O(n), SC(n)
        int count = 0;
        vector<int> nums;
        for(char c:s){
            if(c == ' '){
                if(count != 0){
                    nums.push_back(count);
                }
                count = 0;
            }else{
                count++;
            }
        }
        if(count != 0)nums.push_back(count);
        return nums.back();
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) { 
        //TC O(n), SC(1)
        //jianchao li
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};