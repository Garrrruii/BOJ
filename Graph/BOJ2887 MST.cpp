#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct vertex {			
	int idx, x, y, z;	
};
vertex P[100000];
bool sortx(vertex A, vertex B) { return A.x < B.x; }
bool sorty(vertex A, vertex B) { return A.y < B.y; } 
bool sortz(vertex A, vertex B) { return A.z < B.z; }
struct edge {
	int a, b, c;
};
bool sortd(edge A, edge B) { return A.c < B.c; }
vector<edge> E;

int par[100000];
int find(int a) {SS
	if (par[a] == a) return a;
	par[a] = find(par[a]); return par[a];
}
int main() {
	// Get inputs
	int N, xx, yy, zz;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d", &xx, &yy, &zz); P[i] = { i, xx, yy, zz };
	}

	// Add and sort edges
	sort(P, P + N, sortx);
	for (int i = 1; i < N; ++i) E.push_back({ P[i].idx, P[i - 1].idx, P[i].x - P[i - 1].x });
	sort(P, P + N, sorty);
	for (int i = 1; i < N; ++i) E.push_back({ P[i].idx, P[i - 1].idx, P[i].y - P[i - 1].y });
	sort(P, P + N, sortz);
	for (int i = 1; i < N; ++i) E.push_back({ P[i].idx, P[i - 1].idx, P[i].z - P[i - 1].z });
	sort(E.begin(), E.end(), sortd);

	// Make MST, by union & find
	long long COST = 0;
	for (int i = 0; i < N; ++i) par[i] = i;
	for (edge e : E) {
		int para = find(e.a), parb = find(e.b);

		if (para == parb) continue;
		// a and b are in MST

		COST += (long long)e.c; par[para] = parb;
		// add egde a-b and union(a,b)
	}

	// Print answer
	printf("%lld", COST); return 0;
}