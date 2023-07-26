/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        //two pointer
        //credit to jianchao li
        /*
        *if asked at an interview, is to test whether a candidate is able to handle all edge  cases systematically and write clean codes :-)
        */
        int n = s.size(), l = 0, r = s.size()-1;
        while(l < r){
            while(l < r && !isalnum(s[l])){
                l++;
            }
            while(l < r && !isalnum(s[r])){
                r--;
            }
            if(tolower(s[l++]) != tolower(s[r--])){
                return false;
            }
        }
        return true;
    }
};