/*
Minimum Steps Required

Given a string str consisting of only two characters 'a' and 'b'. You need to find the minimum steps required to make the string empty by removing consecutive a's and b's.

Example 1:

Input:
str = "bbaaabb"
Output:
2
Explanation:
Operation 1: Removal of all a's modifies str to "bbbb".
Operation 2: Removal of all remaining b's makes str
empty.
Therefore, the minimum number of operations required
is 2.
Example 2:

Input:
str = "aababaa"
Output:
3
Explanation:
Operation 1: Removal of b's modifies str to "aaabaa".
Operation 2: Removal of b's modifies str = "aaaaa".
Operation 3: Removal of all remaining a's makes str 
empty.
Therefore, the minimum number of operations required 
is 3.
Your Task:

You need to complete the function minSteps() which takes a string str as the only input parameter and returns an integer, denoting the minimum steps required to make the string empty.

Expected Time Complexity: O(N), where N = length of string str
Expected Space Complexity: O(1)

Constraints:

1 <= str.length() <= 10^5
'a' <= str[i] <= 'b' 
*/
int minSteps(string str) {
    int n = str.length();
    int a_cnt = 0;
    int b_cnt = 0;
    for(int i = 0; i < n; ) {
        if(str[i] == 'a') {
            a_cnt++;
            while(i < n && str[i] == 'a') i++;
        } else {
            b_cnt++;
            while(i < n && str[i] == 'b') i++;
        }
    }
    return 1+min(a_cnt, b_cnt);
}