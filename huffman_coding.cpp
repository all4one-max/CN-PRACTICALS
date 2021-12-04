#include <bits/stdc++.h>
using namespace std;

map<char, string> codes;

struct Node {
    char data; Node* left; Node* right; int freq;
    Node(char c, int cnt) {
        data = c;
        freq = cnt;
        left = NULL;
        right = NULL;
    }
};

struct comp {
    bool operator()(Node* n1, Node* n2) {
        return n1->freq > n2->freq;
    }
};

void gen_codes(Node* root, string cur_bits) {
    if (root == NULL) return;

    if (root->data != '$') codes[root->data] = cur_bits;

    gen_codes(root->left, cur_bits + '0');
    gen_codes(root->right, cur_bits + '1');

    return;
}

string compressed_text(string text) {
    map<char, int> mp; for (auto it : text) mp[it]++;
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto it : mp) {
        Node* node = new Node(it.first, it.second);
        pq.push(node);
    }
    while (pq.size() > 1) {
        auto node1 = pq.top(); pq.pop();
        auto node2 = pq.top(); pq.pop();
        Node* new_node = new Node('$', node1->freq + node2->freq);
        new_node->left = node1; new_node->right = node2;
        pq.push(new_node);
    }
    Node* root = pq.top();
    gen_codes(root, "");
    string comp = "";
    for (auto it : text) comp += codes[it];
    return comp;
}

int main() {
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    string text;
    cout << "ENTER TEXT" << endl; cin >> text;
    string comp_txt = compressed_text(text);
    cout << "compressed_text is " << comp_txt << endl;
    return 0;
}
