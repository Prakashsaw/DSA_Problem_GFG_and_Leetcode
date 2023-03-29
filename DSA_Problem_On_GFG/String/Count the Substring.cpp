/*
Q_name:- Count the Substring
platfrom:- gfg
Description:- 
    Given a string S. The task is to count the number of substrings which contains equal number of lowercase and uppercase letters. 

Example 1:

Input:
S = "gEEk"
Output: 3
Explanation: There are 3 substrings of
the given string which satisfy the
condition. They are "gE", "gEEk" and "Ek".
Example 2:

Input:
S = "WomensDAY"
Output: 4
Explanation: There are 4 substrings of 
the given string which satisfy the
condition. They are "Wo", "ensDAY", 
"nsDA" and "sD"
Your Task:
The task is to complete the function countSubstring() which takes the string S as input parameter and returns the number of substrings which contains equal number of uppercase and lowercase letters.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 10^3
*/
class Solution
{
    public:
    int countSubstring(string s)
    {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int capital = 0;
            int small = 0;
            for(int j = i; j < n; j++) {
                if(s[j] >= 'A' && s[j] <= 'Z') capital++;
                else if(s[j] >= 'a' && s[j] <= 'z') small++;
                
                if(capital == small) ans++;
            }
        }
        return ans;
    }
};