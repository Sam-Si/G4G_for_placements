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

// Version 2
// A bit better than before

#include <bits/stdc++.h>
using namespace std;

struct helper_struct{

    int sum;
    int fir;
    int sec;

};

bool compara(const helper_struct &a,const helper_struct &b){

    if(a.sum < b.sum){
        return true;
    }
    return false;

}

bool nocollision(int a,int b,int c,int d){

    if(a == c || a == d || b == c || b == d){
        return false;
    }
    //cerr << "Match: ";
    //cerr << a << " " << b << " " << c << " " << d << endl;
    return true;

}

void solution(){

    vector <vector <int> > final_sol;

    int n;
    int k;

    cin >> n;
    cin >> k;

    vector <int> input(n);

    for(int i = 0;i < n;i++){
        cin >> input[i];

    }
    
    sort(input.begin(),input.end());

    vector <helper_struct> sinput;

    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
            helper_struct temp;

            temp.sum = input[i] + input[j];
            temp.fir = i;
            temp.sec = j;

            sinput.push_back(temp);
        }
    }

    sort(sinput.begin(),sinput.end(),compara);

    int n2 = sinput.size();

    int low = 0;
    int high = n2 - 1;

    while(low < n2 && high >= 0){

        vector <int> temp;

        int temp_sum = sinput[low].sum + sinput[high].sum;

        bool accessF = true;

        if(temp_sum == k){
            if(nocollision(sinput[low].fir,sinput[low].sec,sinput[high].fir,sinput[high].sec)){
                temp.push_back(input[sinput[low].fir]);
                temp.push_back(input[sinput[low].sec]);
                temp.push_back(input[sinput[high].fir]);
                temp.push_back(input[sinput[high].sec]);

                sort(temp.begin(),temp.end());

                for(int i = 0;i < final_sol.size();i++){
                    if(temp == final_sol[i]){
                        accessF = false;
                        break;
                    }
                }
                if(accessF){
                    final_sol.push_back(temp);
                }
            }

            low++;
            high--;

        }
        else if(temp_sum < k){
            low++;
        }
        else if(temp_sum > k){
            high--;
        }
    }

    if(final_sol.empty()){
        cout << "-1";
    }

    for(int i = 0;i < final_sol.size();i++){
        for(int j = 0; j < 4;j++){
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
            solution();
        }
	return 0;
}


// Version 3 N3 solution

#include <bits/stdc++.h>
using namespace std;

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
    
    vector < vector <int> > final_sol;
    
    for(int i = 0;i < n-3;i++){
        for(int j = i+1;j < n-2;j++){
            int find = k - input[i] - input[j];
            
            int low = j+1;
            int high = n-1;
            
            while(low < high){
                
                int temp_sum = input[low] + input[high];
                
                vector <int> temp;
                
                bool access = true;
                
                if(temp_sum == find){
                    
                    temp.push_back(input[i]);
                    temp.push_back(input[j]);
                    temp.push_back(input[low]);
                    temp.push_back(input[high]);
                    
                    for(int iti = 0;iti < final_sol.size();iti++){
                        if(temp == final_sol[iti]){
                            access = false;
                        }
                    }
                    
                    if(access){
                        final_sol.push_back(temp);
                    }
                    
                    low++;
                }
                
                else if(temp_sum < find){
                    low++;
                }
                else{
                    high--;
                }
                
            }
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
            solution();
        }
	return 0;
}
