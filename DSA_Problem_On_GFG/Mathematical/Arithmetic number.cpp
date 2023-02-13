/*
Q_Name:- Arithmetic number
Platform:- GFG
Description:- 
    Given three integers  'A' denoting the first term of 
    an arithmetic sequence , 'C' denoting the common 
    difference of an arithmetic sequence and an integer 'B'. 
    you need to tell whether 'B' exists in the arithmetic 
    sequence or not. Return 1 if B is present in the sequence. 
    Otherwise, returns 0.
Constraints:- 
    -10^9 ≤ A, B, C ≤ 10^9      
*/

class Solution{
public:
    int inSequence(int a, int b, int c){
        //Handle edge case
        //like  if c == 0
        //      if negative numbers are there
        //..
        //edge case
        if(c == 0) {
            return (a == b);
        }
        if( (b-a) % c == 0 && (b-a)/c >= 0) return 1;
        else return 0;
        //TC = O(1)
        //SC = O(1)
    }
};