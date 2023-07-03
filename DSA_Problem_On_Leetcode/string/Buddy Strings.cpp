/*
859. Buddy Strings
Easy
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 

Constraints:

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // My thought 
        if(s.length() != goal.length()) return false;
        if(s.length() == 1) return false;

        unordered_map<char, int> mp1, mp2;
        for(int i = 0; i < s.length(); i++) {
            mp1[s[i]]++;
            mp2[goal[i]]++;
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            if((mp1.count(ch) && !mp2.count(ch)) || (!mp1.count(ch) && mp2.count(ch))) {
                return false;
            }

            if(mp1[ch] != mp2[ch]) return false;

        }

        int cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != goal[i]) cnt++;
        }

        if(cnt == 0) {
            for(char ch = 'a'; ch <= 'z'; ch++) {
                if(mp1[ch] >= 2) return true;
            }
            return false;
        } else if(cnt == 2){
            return true;
        } 
        return false;
        //TC = O(N)
        //SC = O(26) = O(1)
    }
};