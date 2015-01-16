#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// huffman_leaf for store data
struct huffman_leaf {
    int weight;
    char ch;
};
// huffman_root for construct huffman tree
struct huffman_root {
    int sum_weight;
    struct huffman_leaf * data;
    struct huffman_root * left;
    struct huffman_root * right;
    huffman_root() : sum_weight(0), data(NULL), left(NULL), right(NULL) {}
};

// store huffman roots' address
struct huffman_root * huffman[113];

// compare the data
int compare(const void * l, const void * r) {
    struct huffman_root * a = (struct huffman_root *)l;
    struct huffman_root * b = (struct huffman_root *)r;
    if (a->sum_weight > b->sum_weight) return 1;
    else return 0;
}

// increasing sort depen on the weight of huffman leaf
void sort_huffman(int low, int hig, int (*compare)(const void *, const void*)) {
    if (low < hig) {
        int l = low, h = hig;
        struct huffman_root * ptr = huffman[low];
        while (l < h) {
            // while (l < h && huffman[h]->sum_weight > ptr->sum_weight) --h;
            while (l < h && compare((void*)huffman[h], (void*)ptr)) --h;
            if (l < h) huffman[l++] = huffman[h];
            // while (l < h && huffman[l]->sum_weight < ptr->sum_weight) ++l;
            while (l < h && compare((void*)ptr, (void*)huffman[l])) ++l;
            if (l < h) huffman[h--] = huffman[l];
        }
        huffman[l] = ptr;
        sort_huffman(low, l - 1, compare);
        sort_huffman(l + 1, hig, compare);
    }
}

// construct the huffman tree
struct huffman_root* create_huffman_tree(int n) {
    int i, j, k;
    for (i = n - 1, j = 0, k = 0; i > 0; i--, j++, k += 2) {
        huffman[n + j] = new struct huffman_root;
        huffman[n + j]->sum_weight = huffman[k]->sum_weight + huffman[k+1]->sum_weight;
        huffman[n + j]->left = huffman[k];
        huffman[n + j]->right = huffman[k + 1];
        sort_huffman(k + 2, n + j, compare);
    }
    return huffman[n + j - 1];
}
// compute the length of the code
int count_length(struct huffman_root * root, int level) {
    if (NULL == root) return 0;
    int sum = 0;
    if (NULL != root->data) {
        sum += root->data->weight * level;
    } else {
        sum += count_length(root->left, level + 1);
        sum += count_length(root->right, level + 1);
    }
    return sum;
}
// free the space allocated during constructing the huffman tree
void clear_huffman_tree(struct huffman_root * root) {
    if (NULL == root) return;
    clear_huffman_tree(root->left);
    clear_huffman_tree(root->right);
    root->left = root->right = NULL;
    if (NULL != root->data) {
        delete root->data;
        root->data = NULL;
    }
    delete root;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {   // read the data of leaf
        struct huffman_root * temp = new struct huffman_root;
        temp->data = new huffman_leaf;
        cin >> temp->data->ch >> temp->data->weight;
        temp->sum_weight = temp->data->weight;
        huffman[i] = temp;
    }
    sort_huffman(0, n - 1, compare);

    struct huffman_root * root;
    root = create_huffman_tree(n);

    int sum = count_length(root, 0);
    cout << sum << endl;
    clear_huffman_tree(root);
    return 0;
}

