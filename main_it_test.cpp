#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "Node.hpp"
#include "../rb_tree.hpp"

using std::cout;
using std::endl;

int main() {
    typedef ft::pair<int, int> value;
    ft::Node<value> *pnode = new ft::Node<value>;
    ft::Node<value> node;

    cout << "new pointer node: " << pnode->left << ", " << pnode->right  << ", " << pnode->color   << ", " << pnode->parent << endl;
    cout << "new node: " << node.left << ", " << node.right  << ", " << node.color   << ", " << node.parent << endl;
    node.parent = pnode;
    ft::Node<value> *pnode_copy = new ft::Node<value>(node);
    cout << "new pointer node: " << pnode_copy->left << ", " << pnode_copy->right  << ", " << pnode_copy->color   << ", " << pnode_copy->parent << endl;




}