// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// #define int long long


// const int MAXN = 2e6+5;

// long long fac[MAXN + 1];
// long long inv[MAXN + 1];






// // Function to calculate nCr using DP and Pascal's Triangle
// /** Precomputes n! from 0 to MAXN. */
// void factorial()
// {
// 	fac[0] = 1;
// 	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i; }
// }

// /**
//  * Precomputes all modular inverse factorials
//  * from 0 to MAXN in O(n + log p) time
//  */
// void inverses()
// {
// 	inv[MAXN] = exp(fac[MAXN], p - 2, p);
// 	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
// }

// /** @return nCr mod p */
// long long choose(long long n, long long r, long long p)
// {
// 	return fac[n] * inv[r] % p * inv[n - r] % p;
// }

// int32_t main()
// {
//     int t;
//     cin >> t;
//     long long p = 1e9 + 7;

//     factorial(p);
//     inverses(p);


//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         vector<int> vec(n);
//         int counto = 0;

//         for (int i = 0; i < n; i++)
//         {
//             cin >> vec[i];
//             if (vec[i] == 1)
//                 counto++;
//         }

//         int countz = n - counto;
//         int rno = (k / 2) + 1;

//         if (counto >= rno)
//         {
//             int result = 0;
//             for (int j = rno; j <= k; j++)
//             {
//              result+=(choose(counto,j, p) * choose(countz, k - j, p)) % p;
//             }
//             cout << result << endl;
//         }
//         else
//         {
//             cout << 0 << endl;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;
int64_t fact[N];
int64_t pw(int64_t a, int64_t b) {
	int64_t r = 1;
	while(b > 0) {
		if(b & 1) r = (r * a) % mod;
		b /= 2;
		a = (a * a) % mod;
	}
	return r;
}
int64_t C(int64_t n, int64_t k) {
	if(n < k) return 0LL;
	return (fact[n] * pw((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}
int main() {
	int t; cin >> t;
	fact[0] = 1;
	for(int64_t i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % mod;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		int ones = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			ones += a[i];
		}
		//at least k/2+1 ones
		int64_t ans = 0;
		for(int cnt_ones = k / 2 + 1; cnt_ones <= min(ones, k); ++cnt_ones) {
			ans += C(ones, cnt_ones) * C(n - ones, k - cnt_ones) % mod;
			ans %= mod;
		}
		cout << ans << "\n";
	}
}