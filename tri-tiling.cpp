// Tri-Tiling 

#include <bits/stdc++.h>

using namespace std;

void solution(){
    int N;
    cin >> N;

    int A[9999] = {1};
    int B[9999] = {1};

    for(int n = 2; n <= N+2; n++) {
        A[n] = A[n-2] + 2 * B[n-1];
        B[n] = A[n-1] + B[n-2];
    }

    cout << A[N+2] << endl;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        solution();
    }
}


// Better Solution

#include <bits/stdc++.h>

using namespace std;

void solution(){
    int N;
    cin >> N;

    int A[9999] = {1};
    A[2] = 3;

    for(int n = 4; n <= N+2; n++) {
        A[n] = 4*A[n-2] - A[n-4];
    }

    cout << A[N] << endl;
}

int main(){

    int t;
    cin >> t;

    while(t--){
        solution();
    }
}
