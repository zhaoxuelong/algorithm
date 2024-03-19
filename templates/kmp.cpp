#include <string>

std::vector<int> calc_pi(std::string s) {
    std::vector<int> pi(s.size());
    for (int i = 1, cnt = 0; i < s.size(); i++) {
        auto v = s[i];
        while (cnt > 0 && s[cnt] != v) {
            cnt = pi[cnt - 1];
        }
        if (s[cnt] == v) {
            cnt++;
        }
        pi[i] = cnt;
    }
    return pi;
}
std::vector<int> kmp_search(std::string text, std::string pattern) {
    std::vector<int> pos;
    auto pi = calc_pi(pattern);
    for (int i = 0, cnt = 0; i < text.size(); i++) {
        auto v = text[i];
        while (cnt > 0 && pattern[cnt] != v) {
            cnt = pi[cnt - 1];
        }
        if (pattern[cnt] == v) {
            cnt++;
        }
        if (cnt == pattern.size()) {
            pos.push_back(i - pattern.size() + 1);
            cnt = pi[cnt - 1];
        }
    }
    return pos;
}