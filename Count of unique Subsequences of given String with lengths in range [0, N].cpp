// Given a string S of length N, the task is to find the number of unique subsequences 
// of the string for each length from 0 to N.

// Note: The uppercase letters and lowercase letters are considered different and 
// the result may be large so print it modulo 1000000007.


#include <iostream>
#include <string>
#include <vector>

void numberOfUniqueSubsequences(const std::string& S) {
    int n = S.length();
    std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(n+1));

    const int MOD = 1000000007;
    

}
int main(){
    std::string S;
    std::cin >> S;

    numberOfUniqueSubsequences(S);
    return 0;
}
