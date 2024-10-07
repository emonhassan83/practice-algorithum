#include <bits/stdc++.h>
using namespace std;

void findMaxHeightIndices(vector<int>& heights) {
    int n = heights.size();

    if (n < 2) 
        return; 

    int max1 = INT_MIN, max2 = INT_MIN;  
    int idx1 = -1, idx2 = -1;

    for (int i = 0; i < n; i++) {
        if (heights[i] > max1) {
            max2 = max1;  
            idx2 = idx1; 
            max1 = heights[i];
            idx1 = i;
        } else if (heights[i] > max2) {
            max2 = heights[i]; 
            idx2 = i;
        }
    }

    if (idx1 > idx2)
        swap(idx1, idx2);

    cout << idx1 << " " << idx2 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> heights(n);

        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }

        findMaxHeightIndices(heights);
    }

    return 0;
}
