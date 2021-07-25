#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

struct pqsort {
    bool operator()(pii A, pii B) {
        return A.second > B.second;
    }
};
priority_queue<pii,vector<pii>,pqsort> pq;

vector<pii> E[1001];
int main() {
    pii dij[1001];
    int N, M, a, b, c;
    scanf("%d%d", &N, &M);
    for (int i = 2; i <= N; ++i) dij[i] = { 987654321,0 };
    while (M--) {
        scanf("%d%d%d", &a, &b, &c);
        E[a].push_back({ b,c });
        E[b].push_back({ a,c });
    }

    vector<pii> ans;
    dij[1] = { 0,1 };
    for (pii e : E[1]) dij[e.first] = { e.second,1 }, pq.push(e);
    while (!pq.empty()) {
        a = pq.top().first;
        c = pq.top().second; pq.pop();
        if (c > dij[a].first) continue;
        ans.push_back({ dij[a].second,a });

        for (pii e : E[a]) {
            b = e.first;
            int nc = c + e.second;
            if (nc < dij[b].first) dij[b] = { nc,a }, pq.push({ b,nc });
        }
    }
    printf("%d\n", ans.size());
    for (pii e : ans) printf("%d %d\n", e.first, e.second);
}