// http://practice.geeksforgeeks.org/problems/bit-difference/0

/*

You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a and b.

Output:

Print the number of bits needed to be flipped.

Constraints:

1 ≤ T ≤ 100
1 ≤ a,b ≤ 1000

Example:

Example:
Input
1
10 20

Output
4
 

Explanation:

A  = 1001001
B  = 0010101
No of bits need to flipped = set bit count i.e. 4

*/

#include <bits/stdc++.h>
using namespace std;

void solution(){
    int fnum;
    int snum;
    
    cin >> fnum;
    cin >> snum;
    
    int count_sol = 0;
    
    while(fnum != 0 || snum != 0){
        if((fnum%2) != (snum%2)){
            count_sol++;
        }
        fnum /= 2;
        snum /= 2;
    }
    
    cout << count_sol << endl;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--){
	    solution();
	}
	return 0;
}
