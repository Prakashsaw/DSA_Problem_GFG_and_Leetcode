/*
Q_Id:- 1456.
Q_Name:- Maximum Number of Vowels in a Substring of Given Length
Company:- Amazon
Difficulty:- Medium
Description:- 
    Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/

class Solution {
public:

    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int ans = INT_MIN;
        int curr_cnt = 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        while(j < n) {
            if(isVowel(s[j])) {
                curr_cnt++;
            }
            if(j-i+1 < k) {
                j++;
            } else {
                ans = max(ans, curr_cnt);
                if(isVowel(s[i])) {
                    curr_cnt--;
                }
                i++;
                j++;
            }
        }
        return ans;
        //TC = O(N)
        //SC = O(1)
    }
};