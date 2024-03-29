#ifndef TREE_IT_HPP
#define TREE_IT_HPP

#include <iostream>
#include <string>

#include "../utils/Node.hpp"
#include "../utils/utils.hpp"
#include "iterator.hpp"

namespace ft {

template <class T>
class tree_it {
   public:
   	typedef std::bidirectional_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<T*>::value_type value_type;
	typedef typename ft::iterator_traits<T*>::reference reference;
	typedef typename ft::iterator_traits<T*>::pointer pointer;
	typedef typename ft::iterator_traits<T*>::difference_type difference_type;
	typedef Node<typename remove_const<value_type>::type>* node_pointer;
	typedef Node<T>* iterator_type;

   private:
	node_pointer _node;

	node_pointer tree_min(node_pointer node) {
		node_pointer tmp = node;
		while (tmp != NULL && !tmp->left->is_leaf()) tmp = tmp->left;
		return tmp;
	}

	node_pointer tree_max(node_pointer node) {
		node_pointer tmp = node;
		while (tmp != NULL && !tmp->right->is_leaf()) tmp = tmp->right;
		return tmp;
	}

   public:

	tree_it() : _node(NULL) {}

	tree_it(void* node) : _node(static_cast<node_pointer>(node)) {}

	tree_it(const tree_it<typename remove_const<value_type>::type>& value) {
		_node = value._node;
	}

	virtual ~tree_it() { }

	tree_it& operator=(
		const tree_it<typename remove_const<value_type>::type>& value) {
		if (this != &value) this->_node = value._node;
		return *this;
	}

	node_pointer get_node() const { return _node; }

	// node_pointer get_root() const {
	// 	node_pointer root = _node;
	// 	while(root != NULL && root->parent != NULL && !root->parent->is_leaf()) {
	// 		root = root->parent;
	// 	}
	// 	return root;
	// }

	reference operator*() const { return _node->value; }

	pointer operator->() const { return &(_node->value); }

	tree_it& operator++() {
		if (_node->is_leaf()) {
			return *this;
		}
		if (_node->right != NULL && !_node->right->is_leaf()) {
			_node = tree_min(_node->right);
		} else {
			node_pointer tmp;
			tmp = _node->parent;
			while (!tmp->is_leaf() && _node == tmp->right) {
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = tmp;
		}
		return *this;
	}

	tree_it& operator--() {
		if (_node->is_leaf()) {
			
			return *this;
		}
		if (_node->left != NULL && !_node->left->is_leaf()) {
			_node = tree_max(_node->left);
		} else {
			node_pointer tmp;
			tmp = _node->parent;
			while (!tmp->is_leaf() && _node == tmp->left) {
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = _node->parent;
		}
		return *this;
	}

	tree_it operator++(int) {
		tree_it<value_type> new_it = *this;
		if (_node->is_leaf()) {
			return new_it;
		}
		if (_node->right != NULL && !_node->right->is_leaf()) {
			_node = tree_min(_node->right);
		} else {
			node_pointer tmp;
			tmp = _node->parent;
			while (!tmp->is_leaf() && _node == tmp->right) {
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = _node->parent;
		}
		return new_it;
	}

	tree_it operator--(int) {
		tree_it<value_type> new_it = *this;
		if (_node->is_leaf()) {
			return new_it;
		}
		if (_node->left != NULL && !_node->left->is_leaf()) {
			_node = tree_max(_node->left);
		} else {
			node_pointer tmp = _node->parent;
			while (!tmp->is_leaf() && _node == tmp->left) {
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = tmp;
		}
		return new_it;
	}

	bool operator==(const tree_it<T> value) {
		return (_node == value._node);
	}

	bool operator!=(const tree_it<T> value) {
		return (_node != value._node);
	}
};

template <typename T>
bool operator==(const tree_it<T> lhs, const tree_it<T> rhs) {
	return (lhs.get_node() == rhs.get_node());
}

template <typename T>
bool operator!=(const tree_it<T> lhs, const tree_it<T> rhs) {
	return (lhs.get_node() != rhs.get_node());
}

};	// namespace ft

#endif	// TREE_IT_HPP