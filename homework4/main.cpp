/// 生成 Mermaid 图
#include <bits/stdc++.h>
using namespace std;

// 第 1 题数据
const int N = 8;
const unsigned initial_state = 141;

// 第 2 题数据
// const int N = 6;
// const unsigned initial_state = 37;

/// @brief 将 `state` 转换为二进制字符串
/// @param state 
/// @return 二进制字符串
string convert_to_string(unsigned state) {
    string result;
    for (int i = N - 1; i >= 0; i--) {
        if (state & (1 << i)) {
            result += '1';
        } else {
            result += '0';
        }
    }
    return result;
}

/// @brief 将 `v` 转换为用逗号分隔的字符串
/// @param v 
/// @return 用逗号分隔的字符串
string to_list(vector<unsigned> v) {
    string result = "";
    for (size_t i = 0; i < v.size(); i++) {
        result += v[i] + '0';
        if (v[i] == N + 1) {
            result += "+";
        }
        if (i != v.size() - 1) {
            result += ", ";
        }
    }
    return result;
}

int main() {
    puts("```mermaid");
    puts("graph TD\n\nstyle 初始状态 fill:none,stroke-width:0px\n");
    cout << "初始状态 --> " << convert_to_string(initial_state) << '\n' << endl;
    queue<unsigned> q;
    bool vis[1 << N];
    q.push(initial_state);
    while (!q.empty()) {
        unsigned state = q.front();
        q.pop();
        if (vis[state]) {
            continue;
        }
        vis[state] = true;
        map<unsigned, vector<unsigned>> graph;
        for (size_t i = 1; i <= N; i++) {
            if (state & (1 << i - 1)) {

            } else {
                unsigned new_state = initial_state | (state >> i);
                graph[new_state].push_back(i);
            }
        }
        graph[initial_state].push_back(N + 1);
        for (auto pair : graph) {
            unsigned key = pair.first;
            vector<unsigned> value = pair.second;
            cout << convert_to_string(state) << " -->|" << to_list(value) << "|" << convert_to_string(key) << endl;
            if (key != initial_state && !vis[key]) {
                q.push(key);
            }
        }
    }
    puts("```");
    return 0;
}
