// http://practice.geeksforgeeks.org/problems/greater-on-right-side/0

/*

Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array. Since there is no element next to the last element, replace it with -1.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[i].

Output:

Print the modified array.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ A[i] ≤ 1000

Example:

Input:
2
6
16 17 4 3 5 2
4
2 3 1 9

Output:
17 5 5 5 2 -1
9 9 9 -1

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
    
    
    vector <int> solution;
    
    solution.push_back(-1);
    
    int current_max = -1;
    
    for(int i = n-1;i > 0;i--){
        current_max = max(current_max, input[i]);
        
        solution.push_back(current_max);
    }
    
    for(int i = n-1;i >= 0;i--){
        cout << solution[i];
        if(i != 0){
            cout << " ";
        }
    }
    cout << endl;
}

int main(){
	int t;
        cin >> t;
        
        while(t--){
            solution();
        }
	return 0;
}
