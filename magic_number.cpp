// http://practice.geeksforgeeks.org/problems/magic-number/0

/*

A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5. First few magic numbers are 5, 25, 30(5 +
25), 125, 130(125 + 5), ….

Given the value of n. find the nth Magic number.

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the value of N.


Output:

Print the nth magic number in a separate line.

Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 100

Example:

Input:
2
1
2
Output:
5 
25

*/

#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    
    int magic = 0;
    int helper = 5;
    while(n > 0){
        if(n%2 == 1){
            magic += helper;
        }
        
        n /= 2;
        helper *= 5;
    }
    
    cout << magic << endl;
}

int main(){
	int t;
        cin >> t;
        
        while(t--){
            solution();
        }
	return 0;
}
