// http://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array/0

/*

Given an array of elements which is first increasing and then decreasing, find the maximum element in the array.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array
The second line of each test case contains N integers which are the array elements.

Output:

Print the maximum element in the array.


Constraints:

1 ≤ T ≤ 50
3 ≤ N ≤ 100
1 ≤ a[i] ≤ 100000


Example:

Input
2
9
1 15 25 45 42 21 17 12 11
5
1 45 47 50 5

Output
45
50

*/

// CODE

#include <bits/stdc++.h>
using namespace std;

void mod_bin(vector <int>& input,int low , int high){
    
    int mid = (low + high)/2;
    
    if(input[mid] > input[mid-1] && input[mid] > input[mid+1]){
        cout << input[mid] << endl;
        return;
    }
    
    else if(input[mid] > input[mid-1] && input[mid] < input[mid+1]){
        return mod_bin(input,mid+1,high);
    }
    
    else if(input[mid] < input[mid -1] && input[mid] > input[mid+1]){
        return mod_bin(input,low,mid-1);
    }
    
    else{
        cout << "FATAL ERROR" << endl;
        return;
    }
    
    return;
}

void solution(){
    int n;
    cin >> n;
    
    vector <int> input(n);
    
    for(int i = 0;i < n;i++){
        cin >> input[i];
    }
    
    mod_bin(input,0,n-1);
    
}

int main(){
	int t;
        cin >> t;
        
        while(t--){
            solution();
        }
	return 0;
}
