/*
An optical technician has a collection of lenses, each with an integer magnification factor. The magnification factors of the lenses are given in a sorted array 
L of length N.
By stacking two distinct lenses together, their magnifications multiply. That is, using lens i
 and lens j (i not equal to j), the total magnification becomes Li×Lj.
You are given a target magnification M. 
Determine whether there exists any pair of distinct lenses whose combined magnification is exactly M.


*/


#include <bits/stdc++.h>

using namespace std;

bool targetM(vector<long long>& mFactor, long long M){
    int n = mFactor.size();
    // sort(mFactor.begin(), mFactor.end());
    int p1 = 0, p2 = n-1;
    while(p1 < p2){
        long long product = 1LL * mFactor[p1]*mFactor[p2];
        if(product == M){
            return true;
        }else if (product < M){
            p1++;
        }else if (product > M){
            p2--;
        }

    }
    return false;
}

int main() {
    // Start coding here
    int N; long long M;
    cin >> N >> M;
    vector<long long> magnificationFactor(N);
    for(int i = 0; i <  N; i++){
        cin >> magnificationFactor[i];
    }

    if(targetM(magnificationFactor, M)){
        cout << "YES";        
    }else {
        cout << "NO";
    }

    return 0;
}