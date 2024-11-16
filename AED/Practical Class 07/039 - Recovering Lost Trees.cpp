#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int   value;
    Node *left;
    Node *right;
};

class BTree {
  private:
    Node *root;

  public:
    BTree() { this->root = nullptr; }

    ~BTree() { this->destroy(this->root); }

    void destroy(Node *n) {
        if (n == nullptr) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

    void setRoot(Node *n) { this->root = n; }

    int leafCount() { return this->leafCount(this->root); }

    int leafCount(Node *n) {
        if (n == nullptr) return 0;
        if (n->left == nullptr and n->right == nullptr) return 1;
        return leafCount(n->left) + leafCount(n->right);
    }

    void printPostOrder() { this->printPostOrder(this->root); }

    void printPostOrder(Node *n) {
        if (n == nullptr) return;
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->value << (n == this->root ? '\n' : ' ');
    }

    static Node *parse(vector<int> &preOrder, vector<int> &inOrder) {
        // cout << "Pre:";
        // for (auto i : preOrder) cout << " " << i;
        // cout << endl;

        // cout << "In:";
        // for (auto i : inOrder) cout << " " << i;
        // cout << endl;

        if (preOrder.size() == 0) return nullptr;

        Node *root  = new Node;
        root->value = preOrder.front();

        // cout << "Root: " << root->value << endl;

        if (preOrder.size() == 1) {
            root->left  = nullptr;
            root->right = nullptr;
            return root;
        }

        int iPost = find(inOrder.begin(), inOrder.end(), preOrder.front()) - inOrder.begin();

        vector<int> leftPreOrder;
        for (int i = 1; i <= iPost; i++) leftPreOrder.push_back(preOrder.at(i));
        vector<int> leftInOrder;
        for (int i = 0; i < iPost; i++) leftInOrder.push_back(inOrder.at(i));
        // cout << endl << "parsing left from root: " << root->value << endl;
        Node *left = parse(leftPreOrder, leftInOrder);
        root->left = left;

        vector<int> rightPreOrder;
        for (int i = iPost + 1; i < preOrder.size(); i++) rightPreOrder.push_back(preOrder.at(i));
        vector<int> rightInOrder;
        for (int i = iPost + 1; i < inOrder.size(); i++) rightInOrder.push_back(inOrder.at(i));
        // cout << endl << "parsing right from root: " << root->value << endl;
        Node *right = parse(rightPreOrder, rightInOrder);
        root->right = right;

        return root;
    }
};

int main() {
    int T;

    cin >> T;
    for (size_t i = 0; i < T; i++) {
        int size;
        cin >> size;

        vector<int> preOrder(size);
        vector<int> inOrder(size);
        for (size_t j = 0; j < size; j++) cin >> preOrder[j];
        for (size_t j = 0; j < size; j++) cin >> inOrder[j];

        BTree tree;
        // cout << "Going to Parse: " << i << endl;
        tree.setRoot(BTree::parse(preOrder, inOrder));

        tree.printPostOrder();

        cout << "leafs = " << tree.leafCount() << endl;
    }
}
