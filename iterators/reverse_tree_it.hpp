#ifndef REVERSE_TREE_IT_HPP
#define REVERSE_TREE_IT_HPP

#include <iostream>
#include <string>

#include "../utils/Node.hpp"
#include "../utils/utils.hpp"
#include "iterator.hpp"

namespace ft {

template <class T>
class reverse_tree_it {
   public:
   	typedef std::bidirectional_iterator_tag iterator_category;
	typedef typename ft::iterator_traits<T*>::value_type value_type;
	typedef typename ft::iterator_traits<T*>::reference reference;
	typedef typename ft::iterator_traits<T*>::pointer pointer;
	typedef typename ft::iterator_traits<T*>::difference_type difference_type;
	typedef Node<typename remove_const<value_type>::type>* node_pointer;
	typedef Node<T>* iterator_type;

	reverse_tree_it() {}

	reverse_tree_it(void* node) : _node(static_cast<node_pointer>(node)) {}

	reverse_tree_it(const reverse_tree_it<typename remove_const<value_type>::type>& value) {
		*this = value;
	}

	reverse_tree_it& operator=(
		const reverse_tree_it<typename remove_const<value_type>::type>& value) {
		if (this != &value) this->_node = value._node;
		return *this;
	}

	node_pointer get_node() const { return _node; }

	reference operator*() const { return _node->value; }

	pointer operator->() const { return &(_node->value); }

	reverse_tree_it& operator++() {
		if (_node->left && !_node->left->is_leaf()) {
			_node = tree_max(_node->left);
		} else {
			node_pointer tmp = _node->parent;
			while (!tmp->is_leaf() && _node == tmp->left) {
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = tmp;
		}
		return *this;
	}

	reverse_tree_it& operator--() {
		if (_node->right && !_node->right->is_leaf()) {
			_node = tree_min(_node->right);
		} else {
			node_pointer tmp = _node->parent;
			while (!tmp->is_leaf() && _node == tmp->right) {
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = tmp;
		}
		return *this;
	}

	reverse_tree_it operator++(int) {
		reverse_tree_it<value_type> new_it = *this;
		if (_node->left && !_node->left->is_leaf()) {
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

	reverse_tree_it operator--(int) {
		reverse_tree_it<value_type> new_it = *this;
		if (_node->right && !_node->right->is_leaf()) {
			_node = tree_min(_node->right);
		} else {
			node_pointer tmp = _node->parent;
			while (!tmp->is_leaf() && _node == tmp->right) {
				_node = tmp;
				tmp = tmp->parent;
			}
			_node = tmp;
		}
		return new_it;
	}

   private:
	node_pointer _node;

	node_pointer tree_min(node_pointer node) {
		node_pointer tmp = node;
		while (!tmp->left->is_leaf()) tmp = tmp->left;
		return tmp;
	}

	node_pointer tree_max(node_pointer node) {
		node_pointer tmp = node;
		while (!tmp->right->is_leaf()) tmp = tmp->right;
		return tmp;
	}
};

template <typename T>
bool operator==(const reverse_tree_it<T> lhs, const reverse_tree_it<T> rhs) {
	return (lhs.get_node() == rhs.get_node());
}

template <typename T>
bool operator!=(const reverse_tree_it<T> lhs, const reverse_tree_it<T> rhs) {
	return (lhs.get_node() != rhs.get_node());
}

};	// namespace ft

#endif	// REVERSE_TREE_IT_HPP