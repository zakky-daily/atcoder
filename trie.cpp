#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define MOD 998244353  // 1000000007
#define FOR(i, n) for (int i = 0; i < n; i++)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a; i > b; i--)
#define PRINTVW(v) for (auto &_v : v) cout << _v << " "; cout << endl;
#define PRINTVH(v) for (auto &_v : v) cout << _v << endl;
#define PRINTVV(v) for (auto &_v : v) { for (auto &__v : _v) cout << __v << " "; cout << endl; }
#define YN(c) (c ? "Yes" : "No")
#define DRANGE(x, y, w, h) 0 <= x && x < w && 0 <= y && y < h
#define mp(a, b) make_pair(a, b)
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const char DC[] = {'U', 'R', 'D', 'L'};

struct Node {
    Node *children[26];
    int all_count = 0, parent_count = 0;
    Node() { fill(begin(children), end(children), nullptr); } 
};

struct Trie {
    Node *root;
    Trie() { root = new Node(); }
    void Add(const string S) {
        Node *node = root;
        for (auto s : S) {
            node->all_count++;
            if (node->children[s - 'a'] == nullptr) node->children[s - 'a'] = new Node();
            node = node->children[s - 'a'];
        }
        node->all_count++; node->parent_count++;
    }
    void Erase(const string S) {
        stack<Node*> nodes;
        nodes.push(root);
        FOR(i, (int)S.size()) {
            nodes.push(nodes.top()->children[S[i] - 'a']);
            if (nodes.top() == nullptr) return;
        }
        if (nodes.top()->parent_count == 0) return;
        nodes.top()->parent_count--; nodes.top()->all_count--;
        RREP(i, (int)S.size() - 1, -1) {
            nodes.pop();
            if (nodes.top()->children[S[i] - 'a']->all_count == 0) delete nodes.top()->children[S[i] - 'a'];
            nodes.top()->all_count--;
        }
    }
    Node* Match(const string S) {
        Node *node = root;
        for (auto s : S) {
            if (node->children[s - 'a'] == nullptr) return 0;
            node = node->children[s - 'a'];
        }
        return node;
    }
    int PerfectMatch(const string S) { return Match(S)->parent_count; }
    int StartMatch(const string S) { return Match(S)->all_count; }
};