#include <iostream>
using namespace std;

struct ListNode {
    int key;
    ListNode* p;
    ListNode* left;
    ListNode* right;
    ListNode(int data) : key(data), p(nullptr), left(nullptr), right(nullptr) {}
};

class BST {
private:
    ListNode* root;

    ListNode* find(int data);
    ListNode* Find_max(ListNode* temp);
    ListNode* Find_min(ListNode* temp);
    ListNode* tree_successor(ListNode* temp);
    ListNode* tree_predecessor(ListNode* temp);
    void insert_num(int x);
    void del(ListNode* temp);
    void inorder(ListNode* temp) {
        if (temp != nullptr) {
            inorder(temp->left);
            cout << temp->key << " ";
            inorder(temp->right);
        }
    }

public:
    BST() : root(nullptr) {}
    BST(int data) {
        root = new ListNode(data);
    }
    void Insert(int x) {
        insert_num(x);
    }
    void delete_node(int key) {
        ListNode* node = find(key);
        if (node != nullptr) {
            del(node);
        }
    }
    void inorder_dis() {
        inorder(root);
        cout << endl;
    }
    ListNode* find_num(int data) {
        return find(data);
    }
    void find_max() {
        ListNode* maxNode = Find_max(root);
        if (maxNode != nullptr) {
            cout << "最大值: " << maxNode->key << endl;
        } else {
            cout << "树为空" << endl;
        }
    }

private:
    ListNode* find(int data) {
        ListNode* temp = root;
        while (temp != nullptr && temp->key != data) {
            if (temp->key > data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return temp;
    }

    ListNode* Find_max(ListNode* temp) {
        while (temp != nullptr && temp->right != nullptr) {
            temp = temp->right;
        }
        return temp;
    }

    ListNode* Find_min(ListNode* temp) {
        while (temp != nullptr && temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }

    ListNode* tree_successor(ListNode* temp) {
        if (temp->right != nullptr) {
            return Find_min(temp->right);
        }
        ListNode* preTemp = temp->p;
        while (preTemp != nullptr && preTemp->right == temp) {
            temp = preTemp;
            preTemp = preTemp->p;
        }
        return preTemp;
    }

    void insert_num(int x) {
        ListNode* newNode = new ListNode(x);
        ListNode* parent = nullptr;
        ListNode* current = root;
        
        while (current != nullptr) {
            parent = current;
            if (x < current->key) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        newNode->p = parent;

        if (parent == nullptr) {
            root = newNode;
        } else if (x < parent->key) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void del(ListNode* node) {
        if (node->left == nullptr) {
            transplant(node, node->right);
        } else if (node->right == nullptr) {
            transplant(node, node->left);
        } else {
            ListNode* successor = Find_min(node->right);
            if (successor->p != node) {
                transplant(successor, successor->right);
                successor->right = node->right;
                successor->right->p = successor;
            }
            transplant(node, successor);
            successor->left = node->left;
            successor->left->p = successor;
        }
        delete node;
    }

    void transplant(ListNode* u, ListNode* v) {
        if (u->p == nullptr) {
            root = v;
        } else if (u == u->p->left) {
            u->p->left = v;
        } else {
            u->p->right = v;
        }
        if (v != nullptr) {
            v->p = u->p;
        }
    }
};

int main() {
    BST tree;
    tree.Insert(15);
    tree.Insert(6);
    tree.Insert(18);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(17);
    tree.Insert(20);

    cout << "中序遍历: ";
    tree.inorder_dis();

    tree.find_max();

    cout << "删除节点15" << endl;
    tree.delete_node(15);

    cout << "中序遍历: ";
    tree.inorder_dis();

    return 0;
}
