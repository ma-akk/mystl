#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "utils/Node.hpp"
#include "utils/rb_tree.hpp"

using std::cout;
using std::endl;

int main() {
    typedef ft::pair<int, int> value;
    value v1 = ft::make_pair(12, 0);
    value v2 = ft::make_pair(13, 1);
    value v3 = ft::make_pair(10, 2);
    value v4 = ft::make_pair(25, 3);
    value v5 = ft::make_pair(29, 4);
    value v6 = ft::make_pair(7, 5);
    value v7 = ft::make_pair(15, 6);
	value vKey =  ft::make_pair(14, -5);

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
    ft::Node<value> *pnode4 = tree->init_node(v4);
    ft::Node<value> *pnode5 = tree->init_node(v5);
    ft::Node<value> *pnode6 = tree->init_node(v6);
    ft::Node<value> *pnode7 = tree->init_node(v7);
    tree->rb_insert_node(pnode1);
    tree->rb_insert_node(pnode2);
    tree->rb_insert_node(pnode3);
    tree->rb_insert_node(pnode4);
    tree->rb_insert_node(pnode5);
    tree->rb_insert_node(pnode6);
    tree->rb_insert_node(pnode7);
    tree->printTree();
    if (tree->tree_search(tree->get_root(), v1) == pnode1)
        cout << "SEARCH WORKS CORRECT!" << endl;
    else cout << "FAIL SEARCH!" << endl;
    if (tree->tree_search(tree->get_root(), vKey) == tree->get_leaf())
        cout << "SEARCH WORKS CORRECT!" << endl;
    else cout << "FAIL SEARCH!" << endl;
    cout << "tree->min = " << tree->rb_min(tree->get_root())->value.first << " color = " << tree->rb_min(tree->get_root())->color << endl;
    cout << "tree->max = " << tree->rb_max(tree->get_root())->value.first << " color = " << tree->rb_max(tree->get_root())->color << endl;
    cout << "tree->get_root() = " << tree->get_root()->value.first << " color = " << tree->get_root()->color << endl;

    ft::rb_tree<value>::iterator it = tree->begin();
    cout << "iterator:first = " << it.get_node()->value.first << " second = " << it.get_node()->value.second << endl;
//    cout << it->first << endl;

    cout << "lower_bound = " << tree->lower_bound(vKey).get_node()->value.first << endl;
    cout << "lower_bound = " << tree->lower_bound(v3).get_node()->value.first << endl;
    cout << "lower_bound = " << tree->lower_bound(ft::make_pair(140, -5)).get_node()->value.first << endl;
    cout << "upper_bound = " << tree->upper_bound(vKey).get_node()->value.first << endl;
    cout << "upper_bound = " << tree->upper_bound(v3).get_node()->value.first << endl;
    cout << "upper_bound = " << tree->upper_bound(ft::make_pair(140, -5)).get_node()->value.first << endl;
    //    std::map<int, int> m1;
//    std::map<int, int>::iterator it;
//    m1[0] = 6;
//    m1[3] = 3;
//    m1[-3] = -3;
//    m1[2] = 22;
//    m1[5] = 10;
//
//    for (it = m1.begin(); it != m1.end(); ++it) {
//        cout << "[" << it->first << "]" << it->second << endl;
//    }
//    cout << m1.lower_bound(12)->first << " " << m1.lower_bound(12)->second << endl;

    //    cout << "tree->get_leaf() = " << tree->get_leaf() << " color = " << tree->get_leaf()->color << endl;



}