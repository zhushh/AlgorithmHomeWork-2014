#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int num) {
    struct Node *temp = new struct Node;
    temp->value = num;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* addToTree(struct Node *root, int num) {
    if (NULL == root) {
        root = createNode(num);
    } else {
        if (root->value > num) {
            root->left = addToTree(root->left, num);
        } else {
            root->right = addToTree(root->right, num);
        }
    }
    return root;
}

// inOrder: root->left->right
void inOrderSearch(struct Node * root) {
    if (NULL == root) return;
    struct Node *left = root->left;
    struct Node *right = root->right;
    cout << root->value;
    if (NULL != left) {
        cout << " ";
    }
    inOrderSearch(left);
    if (NULL != right) {
        cout << " ";
    }
    inOrderSearch(right);
}
// preOrder: left->root>right
void preOrderSearch(struct Node * root) {
    if (NULL == root) return;
    struct Node *left = root->left;
    struct Node *right = root->right;
    preOrderSearch(left);
    if (NULL != left) {
        cout << " ";
    }
    cout << root->value;
    if (NULL != right) {
        cout << " ";
    }
    preOrderSearch(right);
}

void clear(struct Node *root) {
    if (NULL == root) return;
    struct Node *left = root->left;
    struct Node *right = root->right;
    delete root;
    clear(left);
    clear(right);
}

int main() {
    int n, num, i;
    while (cin >> n && n != 0) {
        struct Node *root = NULL;
        for (i = 0; i < n; i++) {
            cin >> num;
            root = addToTree(root, num);
        }
        preOrderSearch(root);
        cout << " " << endl;    // print the last blank
        inOrderSearch(root);
        cout << " " << endl;    // print the last blank
        clear(root);
    }
    return 0;
}

