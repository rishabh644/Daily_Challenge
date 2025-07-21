Count ways:
#include <bits/stdc++.h>
using namespace std;

struct Ratio {
    long long num;
    long long den;
    bool operator<(const Ratio &other) const {
        if (num != other.num) return num < other.num;
        return den < other.den;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<long long> A(N);
    for(auto &x: A) cin >> x;

    vector<Ratio> all_ratios;

    for(int p=0; p < N; p++){
        for(int q=p+1; q < N; q++){
            if(A[q] == 0) continue;
            long long g = gcd(A[p], A[q]);
            Ratio r;
            r.num = A[p] / g;
            r.den = A[q] / g;
            all_ratios.push_back(r);
        }
    }

    for(int r=0; r < N; r++){
        for(int s=r+1; s < N; s++){
            if(A[r] == 0) continue;
            long long g = gcd(A[s], A[r]);
            Ratio ratio;
            ratio.num = A[s] / g;
            ratio.den = A[r] / g;
            all_ratios.push_back(ratio);
        }
    }

    sort(all_ratios.begin(), all_ratios.end());
    all_ratios.erase(unique(all_ratios.begin(), all_ratios.end(), [&](const Ratio &a, const Ratio &b) -> bool{
        return a.num == b.num && a.den == b.den;
    }), all_ratios.end());

    int K = all_ratios.size();

    vector<vector<int>> list_pq(K, vector<int>());
    vector<vector<int>> list_rs(K, vector<int>());

    auto get_ratio_id = [&](const Ratio &r) -> int{
        return lower_bound(all_ratios.begin(), all_ratios.end(), r) - all_ratios.begin();
    };


    for(int p=0; p < N; p++){
        for(int q=p+1; q < N; q++){
            if(A[q] == 0) continue;
            long long g = gcd(A[p], A[q]);
            Ratio r;
            r.num = A[p] / g;
            r.den = A[q] / g;
            int id = get_ratio_id(r);
            list_pq[id].push_back(q);
        }
    }


    for(int r_idx=0; r_idx < N; r_idx++){
        for(int s=r_idx+1; s < N; s++){
            if(A[r_idx] == 0) continue;
            long long g = gcd(A[s], A[r_idx]);
            Ratio r;
            r.num = A[s] / g;
            r.den = A[r_idx] / g;
            int id = get_ratio_id(r);
            list_rs[id].push_back(r_idx);
        }
    }

    for(int id=0; id < K; id++){
        sort(list_pq[id].begin(), list_pq[id].end());
        sort(list_rs[id].begin(), list_rs[id].end());
    }

    long long ans = 0;
    for(int id=0; id < K; id++){
        const vector<int> &pq = list_pq[id];
        const vector<int> &rs = list_rs[id];
        if(pq.empty() || rs.empty()) continue;

        int size_rs = rs.size();
        for(auto q : pq){

            int pos = upper_bound(rs.begin(), rs.end(), q) - rs.begin();
            ans += (size_rs - pos);
        }
    }

    cout << ans;
}