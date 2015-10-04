//
// Created by heath on 15-10-4.
//

#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    char data;
    int left;
    int right;

    Node() { };

    Node(char data, int left, int right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void preorder_visit(Node tree[], int root) {
    cout << tree[root].data;;
    if (tree[root].left > 0) {
        preorder_visit(tree, tree[root].left);
    }
    if (tree[root].right > 0) {
        preorder_visit(tree, tree[root].right);
    }
}

int main() {
    int node_number;
    while (cin >> node_number) {
        Node tree[1001];
        bool is_root[1001];
        int node[1001]; //记录输入了哪些节点
        memset(is_root, true, sizeof(bool) * 1001);
        for (int i = 0; i < node_number; ++i) {
            int id, left, right;
            char data;
            cin >> id >> data >> left >> right;
            node[i] = id;
            is_root[left] = is_root[right] = false;
            tree[id] = Node(data, left, right);
        }

        //找到根节点
        int root = 0;
        for (int j = 0; j < node_number; ++j) {
            if (is_root[node[j]]) {
                root = node[j];
                break;
            }
        }

        preorder_visit(tree, root);
        cout << endl;
    }
}
