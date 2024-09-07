#include <bits/stdc++.h>
using namespace std;
// class Pair {
//     public:
//         int first, second;
//         void make_pair(int x, int y){
//             first = x;
//             second = y;
//         }
// };

int main()
{
    // Pair p;
    // p.make_pair(10, 20);

    pair<int, int> p;
    p = make_pair(10, 20);

    cout << p.first << " " << p.second << endl;
    return 0;
}