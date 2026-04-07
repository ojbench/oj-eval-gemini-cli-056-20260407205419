#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Store intervals as {right, left}
    set<pair<int, int>> intervals;

    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            int deleted_count = 0;
            
            // Find the first interval whose right endpoint is >= l
            auto it = intervals.lower_bound({l, -1});
            
            while (it != intervals.end()) {
                // If the left endpoint of the current interval is > r,
                // it means it does not intersect with [l, r] and all subsequent
                // intervals will also not intersect.
                if (it->second > r) {
                    break;
                }
                
                // Otherwise, it intersects. Delete it.
                it = intervals.erase(it);
                deleted_count++;
            }
            
            intervals.insert({r, l});
            cout << deleted_count << "\n";
        } else if (op == 'B') {
            cout << intervals.size() << "\n";
        }
    }

    return 0;
}
