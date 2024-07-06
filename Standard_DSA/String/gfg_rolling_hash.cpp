#include <iostream>
#include <string>

typedef long long ll;

ll rolling_hash(const std::string& s, ll base = 256, ll prime = 1000000007) {
    ll hash_value = 0;
    for (char c : s) {
        hash_value = (hash_value * base + c) % prime;
    }
    return hash_value;
}

int main() {
    std::string text = "rishabh";
    ll hash_result = rolling_hash(text);
    std::cout << "The rolling hash of '" << text << "' is " << hash_result << std::endl;
    return 0;
}
