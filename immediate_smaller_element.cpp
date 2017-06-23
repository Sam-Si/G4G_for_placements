/*

Given an integer array, for each element in the array check whether there exist a smaller element on the next immediate position of the array. If it exist print the smaller element. If there is no smaller element on the immediate next to the element then print -1.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case contains an integer N, where N is the size of array.
The second line of each test case contains N integers sperated with a space which is input for the array arr[ ]

Output:

For each test case, print in a newline the next immediate smaller elements for each element in the array.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 500
1 ≤ arr[i] ≤ 1000

Example:

Input
2
5
4 2 1 5 3
6
5 6 2 3 1 7

Output
2 1 -1 3 -1
-1 2 -1 1 -1 -1

*/

#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    
    vector <int> input(n);
    
    for(int i = 0;i < n;i++){
        cin >> input[i];
    }
    
    for(int i = 0;i < n-1;i++){
        if(input[i] <= input[i+1]){
            cout << "-1" << " ";
        }
        else{
            cout << input[i+1] << " ";
        }
    }
    cout << "-1\n";
    return;
}

int main(){
	int t;
        cin >> t;
        
        while(t--){
            solution();
        }
	return 0;
}
