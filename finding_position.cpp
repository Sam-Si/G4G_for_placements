// http://practice.geeksforgeeks.org/problems/finding-position/0

/*

Some people are standing in a queue. A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected. This continues until we are left with one person. Find out the position of that person in the original queue.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,number of people standing in a queue.

Output:

Print the position(original queue) of that person who is left.

Constraints:

1 ≤ T ≤ 1000
1 ≤ N ≤ 100000000

Example:

Input
1
5

Output
4

*/

#include <bits/stdc++.h>
using namespace std;

void solution(){
    int num;
    cin >> num;
    
    int out_pos = 1;
    
    while((out_pos*2) < num){
        out_pos *= 2;
    }
    
    cout << out_pos << endl;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
	    solution();
	}
	return 0;
}
