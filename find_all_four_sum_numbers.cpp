// http://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0

/*

Given an array A of size N, find all combination of four elements in the array whose sum is equal to a given value K. For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and K = 23, one of the quadruple is “3 5 7 8” (3 + 5 + 7 + 8 = 23).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains two integers N and K. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print all the quadruples present in the array separated by space which sums up to value of K. Each quadruple is unique which are separated by a delimeter "$" and are in increasing order.

Constraints:
1<=T<=100
1<=N<=100
-1000<=K<=1000
-100<=A[]<=100

Example:
Input:
2
5 3
0 0 2 1 1 
7 23
10 2 3 4 5 7 8
Output:
0 0 1 2 $
2 3 8 10 $2 4 7 10 $3 5 7 8 $

*/

#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > final_sol;

bool helper_bin(vector <int> &input,int i, int k){
    if(binary_search(input.begin() + i,input.end(),k)){
        return true;
    }
    return false;
}

void helper_gen_sol(vector <int> &num1,vector <int> &input, int smaller, int larger){
    vector <int> temp;
    int n = input.size();
    
    
    int one = smaller/n;
    int two = smaller%n;
    
    temp.push_back(input[one]);
    temp.push_back(input[two]);
    
    one = larger/n;
    two = larger%n;
    
    temp.push_back(input[one]);
    temp.push_back(input[two]);
    
    sort(temp.begin(),temp.end());
    
    vector <int> num2(202,0);

    for(int i = 0;i < 4;i++){
        num2[101 + temp[i]]++;
    }
    
    bool access = true;
    for(int i = 0;i < final_sol.size();i++){
        if(final_sol[i] == temp){
            access = false;
        }
    }
    
    for(int i = 0;i < 4;i++){
        if(num1[101 + temp[i]] < num2[101 + temp[i]]){
            access = false;
            break;
        }
    }
    
    if(access){
        final_sol.push_back(temp);
    }
}

void solution(){
    int n;
    int k;
    
    cin >> n;
    cin >> k;
    
    vector <int> input(n);
    
    for(int i = 0;i < n;i++){
        cin >> input[i];
    }
    
    sort(input.begin(),input.end());
    
    vector <int> num1(202,0);
    
    for(int i = 0;i < n;i++){
        num1[101 + input[i]]++;
    }
    
    vector <int> input_sq;
    vector <int> helper;
    
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            input_sq.push_back(input[i] + input[j]);
            helper.push_back(i*n + j);
        }
    }
    
    for(int i = 0;i < input_sq.size();i++){
        bool temp = helper_bin(input_sq,i+1, (k-input_sq[i]));
        
        if(temp){
            int index = lower_bound(input_sq.begin() + i + 1,input_sq.end(), k-input_sq[i]) - input_sq.begin();
            helper_gen_sol(num1,input,helper[i],helper[index]);            
        }
    }
    
    if(final_sol.empty()){
        cout << "-1";
    }
    
    for(int i = 0;i < final_sol.size();i++){
        for(int j = 0;j < 4;j++){
            cout << final_sol[i][j] << " ";
        }
        cout << "$";
    }
    cout << endl;
}

int main(){
	int t;
        cin >> t;
        
        while(t--){
            final_sol.clear();
            solution();
        }
	return 0;
}
