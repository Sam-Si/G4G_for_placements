// http://practice.geeksforgeeks.org/problems/minimum-difference-pair/0

/*

Given an unsorted array, find the minimum difference between any pair in given array.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array. Second line of the test case is the Array.

Output:

Print the minimum difference between any two pairs.

Constraints:

1 <= T <= 30
1 < N <= 100
1 <= arr[i] <= 100000

Example:
Input:
2
5
2 4 5 7 9
10
87 32 99 75 56 43 21 10 68 49

Output:
1
6

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
    
    sort(input.begin(),input.end());
    
    int min_diff = 1e9;
    
    for(int i = 0;i < n-1;i++){
        int diff = input[i+1] - input[i];
        
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
}

int main(){
	int t;
        cin >> t;
        
        while(t--){
            solution();
        }
	return 0;
}
