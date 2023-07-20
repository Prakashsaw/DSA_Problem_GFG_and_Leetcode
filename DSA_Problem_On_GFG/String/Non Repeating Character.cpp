/*
Que:- Non Repeating Character
Level: Easy
Description:- 
    Given a string S consisting of lowercase Latin Letters. Return the first non-repeating character in S. If there is no non-repeating character, return '$'.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
Example 2:

Input:
S = zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is
the character which is non-repeating. 
Your Task:
You only need to complete the function nonrepeatingCharacter() that takes string S as a parameter and returns the character. If there is no non-repeating character then return '$' .

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S|

Constraints:
1 <= N <= 10^5
*/

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       //Brute force approach
    //   int n = s.length();
    //   for(int i = 0; i < n; i++) {
    //       bool flag = false;
    //       for(int j = i+1; j < n; j++) {
    //           if(s[i] == s[j]) {
    //               s[j] = 'A';
    //               flag = true;
    //           }
    //       }
    //       if(flag == false && s[i] != 'A') return s[i];
    //   }
    //   return '$';
    //   //TC = O(N^2)
    //   //SC = O(1)
    //   //Status should be TLE but it accepted... Test case is very week
       
       //Optimized
       //By using hash table to store frequencies of all character
       int n = s.length();
       unordered_map<char, int> mp;
       for(int i = 0; i < n; i++) {
           mp[s[i]]++;
       }
       
       for(int i = 0; i < n; i++) {
           if(mp[s[i]] == 1) return s[i];
       }
       
       return '$';
       
       //TC = O(N)
       //SC = O(N)
       
    }

};