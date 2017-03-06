#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#define GET_MACRO(a, b, c, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep2(i, a) rep3 (i, 0, a)
#define rep3(i, a, b) for (int i = (a); i < (b); i++)
#define repr(...) GET_MACRO(__VA_ARGS__, repr3, repr2)(__VA_ARGS__)
#define repr2(i, a) repr3 (i, 0, a)
#define repr3(i, a, b) for (int i = (b) - 1; i >= (a); i--)
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
using namespace std;
typedef long long ll;

struct ST {
	vector<ll> seg, lazy;
	int size;

	ST(int n) {
		size = 1;
		while (size < n) size *= 2;
		// printf("size %d\n", size);
		seg.resize(size * 2);
		lazy.resize(size * 2, -1);
	}

	void push(int k, int l, int r) {
		if (lazy[k] != -1) {
			seg[k] = lazy[k] * (r - l);
			if (r - l > 1) {
				lazy[k * 2 + 1] = lazy[k];
				lazy[k * 2 + 2] = lazy[k];
			}
			lazy[k] = -1;
		}
	}

	ll merge(ll x, ll y) {
		return x + y;
	}

	void update(int a, int b, ll v, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = v;
			push(k, l, r);
		} else {
			update(a, b, v, k * 2 + 1, l, (l + r) / 2);
			update(a, b, v, k * 2 + 2, (l + r) / 2, r);
			seg[k] = merge(seg[k * 2 + 1], seg[k * 2 + 2]);
		}
	}

	void update(int a, int b, ll v) {
		update(a, b, v, 0, 0, size);
	}

	ll query(int a, int b, int k, int l, int r) {
		// printf("%d %d\n", a, b);
		push(k, l, r);
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return seg[k];
		ll x = query(a, b, k * 2 + 1, l, (l + r) / 2);
		ll y = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return merge(x, y);
	}

	ll query(int a, int b) {
		return query(a, b, 0, 0, size);
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep (i, n) scanf("%d", &a[i]);
	map<int, int> first, last;
	repr (i, n) first[a[i]] = i;
	rep (i, n){
		// printf("%d %d\n", a[i], i);
		last[a[i]] = i;
	}
	ST st(n);
	rep (i, n) st.update(i, i + 1, a[i]);
	for (auto kv : first) if (last.count(kv.first)) {
		printf("%d %d %d\n", kv.second, last[kv.first] + 1, kv.first);
		st.update(kv.second, last[kv.first] + 1, kv.first);
	}

	rep (i, n) printf("%d ", (int)st.query(i, i + 1));
	cout << endl;
	return 0;
}