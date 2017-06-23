/*

Reverse a sub array in an array.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the size of array.
The second line of each test case contains N input A[i].
The third line of each test case contains L and R, L is left index of array and R is right index of array.

Output:

Print the modified array.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
1 ≤ A[i] ≤ 1000
1 ≤ L ≤ R ≤ N

Example:

Input:
1
7
1 2 3 4 5 6 7
2 4

Output:
1 4 3 2 5 6 7 

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
    
    int left;
    int right;
    
    cin >> left >> right;
    left--;
    right--;
    while(left < right){
        swap(input[left++],input[right--]);
    }
    
    for(int i = 0;i < n;i++){
        cout << input[i] << " ";
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
