#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "iterators/Node.hpp"
#include "rb_tree.hpp"

using std::cout;
using std::endl;

int main() {
    typedef ft::pair<int, int> value;
    value v1 = ft::make_pair(1, -1);
    value v2 = ft::make_pair(2, -2);
    value v3 = ft::make_pair(3, -3);

    ft::Node<value> node;

//    cout << "new pointer node: " << pnode->left << ", " << pnode->right  << ", " << pnode->color   << ", " << pnode->parent << endl;
//    cout << "new node: " << node.left << ", " << node.right  << ", " << node.color   << ", " << node.parent << endl;
//    node.parent = pnode;
//    ft::Node<value> *pnode_copy = new ft::Node<value>(node);
//    cout << "new pointer node: " << pnode_copy->left << ", " << pnode_copy->right  << ", " << pnode_copy->color   << ", " << pnode_copy->parent << endl;
//
//
    ft::rb_tree<value> *tree = new ft::rb_tree<value>();
    ft::Node<value> *pnode1 = tree->init_node(v1);
    ft::Node<value> *pnode2 = tree->init_node(v2);
    ft::Node<value> *pnode3 = tree->init_node(v3);
    ft::Node<value> *pnode4 = tree->init_node();
    tree->rb_insert_node(pnode1);
    tree->rb_insert_node(pnode2);
    tree->rb_insert_node(pnode3);
    tree->rb_insert_node(pnode4);
    tree->printTree();
    if (tree->tree_search(tree->get_root(), v1) == pnode1)
        cout << "SEARCH WORKS CORRECT!" << endl;
    else cout << "FAIL SEARCH!" << endl;
    if (tree->tree_search(tree->get_root(), ft::make_pair(5, -5)) == tree->get_leaf())
        cout << "SEARCH WORKS CORRECT!" << endl;
    else cout << "FAIL SEARCH!" << endl;
    cout << "tree->get_root() = " << tree->get_root()->value.first << " color = " << tree->get_root()->color << endl;
    cout << "tree->get_root()->right = " << tree->get_root()->right->value.first << " color = " << tree->get_root()->right->color << endl;
    cout << "tree->get_root()->left = " << tree->get_root()->left->value.first << " color = " << tree->get_root()->left->color << endl;

    std::map<int, int> m1;
    m1[1] = 10;
    m1.find(1);

    //    cout << "tree->get_leaf() = " << tree->get_leaf() << " color = " << tree->get_leaf()->color << endl;



}