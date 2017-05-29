// http://practice.geeksforgeeks.org/problems/count-substrings/0
/*
Given a binary string, count number of substrings that start and end with 1. For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string containing 0's and 1's.
 

Output:
For each test case, output a single line denoting number of substrings possible.

Constraints:
1<=T<=100
1<=Lenght of String<=100


Example:
Input:
1
10101

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;

long long helper(int n){
    return (n*(n-1))/2;
}

void solution_run(){
    string input;
    cin >> input;
    
    int length_input = input.length();
    
    int count_input = 0;
    
    for(int i = 0;i < length_input;i++){
        if(input[i] == '1'){
            count_input++;
        }
    }
    
    cout << helper(count_input) << endl;
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        solution_run();
    }
    
    return 0;
}
