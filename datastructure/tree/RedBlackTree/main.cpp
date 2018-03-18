#include <iostream>

#define RED 0
#define BLACK 1
using namespace std;

template<typename Key, typename Value>
class RedBlackTree {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node *parent;
        int color;

        Node(Key key, Value value, int color) {
            this->key = key;
            this->value = value;
            this->color = color;
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
    };

    Node *root;

public:


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}