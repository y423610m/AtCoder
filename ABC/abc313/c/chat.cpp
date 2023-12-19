#include "bits/stdc++.h"

using namespace std;
// #define INT_MAX 1000000000000000000

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int minOperations = INT_MAX;
    for (int i = 0; i < N; ++i) {
        // Find the index of the largest element less than A[i]
        int lowerIndex = lower_bound(A.begin(), A.end(), A[i] - 1) - A.begin();
        // Find the index of the smallest element greater than A[i]
        int upperIndex = upper_bound(A.begin(), A.end(), A[i] + 1) - A.begin();

        // Calculate the number of operations needed to make the range [A[i], A[upperIndex - 1]] equal
        int operations = N - (upperIndex - lowerIndex);

        // Update the minimum operations if necessary
        minOperations = min(minOperations, operations);
    }

    cout << minOperations << endl;

    return 0;
}
