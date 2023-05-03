/*
Q_Name:- Make Palindrome

You are given an array of strings arr of size n. You have to find out if it is possible to make a palindromic string by concatenating the strings in any order. Provided that all the strings given in the array are of equal length.

Example 1:

Input:
n = 4
arr = {"djfh", "gadt", "hfjd", "tdag"}
Output:
YES
Explanation:
You can make the string "djfhgadttdaghfjd", by concatenating the given strings which is a palindrome.
Example 2:

Input:
n = 3
arr = {"jhjdf", "sftas", "fgsdf"}
Output:
NO
Explanation:
You can't make a palindromic string with this strings.
Your Task:
You don't need to read input or print anything. Your task is to complete the function makePalindrome() which takes an integer n and an array of strings arr respectively and returns true or false.

Expected Time Complexity: O(n * len(arr[i]))
Expected Space Complexity: O(n * len(arr[i]))

Constraints:
1 <= n <= 104
0 <= |arr[i]| <= 104
The sum of n*|arr[i]| over all test cases won't exceed 106
*/
class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        /*
        Logic:- 
            Store the frequency of each string in the array. 
            Then check each string in the map to see if it is already a palindrome. 
            If it is, and it appears an odd number of times, 
            then set a flag and store the string. 
            If it is not a palindrome, then check if the reverse 
            of the string has the same frequency in the map. 
            If not then set the flag and store the string.
            If more than one string is found that cannot 
            be part of a palindrome, then return false. 
            Otherwise, construct the palindrome by using the 
            stored string as the middle character (if any), 
            and concatenating the reversed of each remaining 
            string in the map. Finally, check whether the 
            resulting string is a palindrome and returns the 
            appropriate Boolean value.
        */
        //4
        //abc cba ss aa
        
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        
        string candidate_palindrome = "";
        int cnt = 0;
        
        for(auto str : mp) {
            string temp = str.first;
            
            reverse(temp.begin(), temp.end());
            
            if(temp == str.first) {
                if(mp[str.first]%2 == 1) { //means their frequencies are odd
                    cnt++;
                    candidate_palindrome = str.first;
                }
            } else { //means their reverse not exist and might be that str is itself a palindrome
                if(mp[str.first] != mp[temp]) {
                    cnt++;
                    candidate_palindrome = str.first;
                }
            }
        }
        
        if(cnt > 1) { //means that type of string which are either itself a palindrom or their reverse not exist in arr
            return false;
        }
        
        //now check that candidate_palindrome is palindrome or not
        int i = 0;
        int j = candidate_palindrome.length()-1;
        //cout << candidate_palindrome << endl;
        while(i <= j) {
            if(candidate_palindrome[i] != candidate_palindrome[j]) return false;
            i++;
            j--;
        }
        return true;
        
        //TC = O(N*N) Here N*N max to max could be 10^6
        //SC = O(N)
        
    }
};