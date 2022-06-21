#ifndef TREE_IT_HPP
#define TREE_IT_HPP

#include <iostream>
#include <string>
#include "iterator.hpp"
#include "Node.hpp"

namespace ft {

	template < class T >
	class tree_it {
	 public:
		typedef std::bidirectional_iterator_tag 				iterator_category;
		typedef typename iterator_traits<T*>::value_type 		value_type;
		typedef typename iterator_traits<T*>::reference 		reference;
		typedef typename iterator_traits<T*>::pointer			pointer;
		typedef typename iterator_traits<T*>::difference_type	difference_type;
		typedef Node<typename remove_const<value_type>::type >* node_pointer;

		tree_it() { }

		tree_it(void *node): _node(static_cast<node_pointer>(node)) {}

		tree_it(const tree_it<typename remove_const<value_type>::type > &value) {
			*this = value;
		}

		tree_it& operator=(const tree_it<typename remove_const<value_type>::type>&value) {
			if (this != &value)
				this->_node = value.node();
			return *this;
		}

		node_pointer get_node() const {
			return _node;
		}

		reference operator*() const {
			return *(_node->value);
		}

		pointer operator->() const {
			return _node->value;
		}

		tree_it& operator++() {
			if (_node->right && !_node->right->is_leaf()) {
				_node = tree_min(_node->right);
			}
			else {
				node_pointer tmp = _node->parent;
				while (!tmp->is_leaf() && _node == tmp->right) {
					_node = tmp;
					tmp = tmp->parent;
				}
				_node = tmp;
			}
			return *this;
		}

		tree_it& operator--() {
			if (_node->left && !_node->left->is_leaf()) {
				_node = tree_max(_node->left);
			}
			else {
				node_pointer tmp = _node->parent;
				while (!tmp->is_leaf() && _node == tmp->left) {
					_node = y;
					tmp = tmp->parent;
				}
				_node = tmp;
			}
			return *this;
		}

		tree_it operator++(int) {
			tree_it<value_type> new_it = *this;
			if (_node->right && !_node->right->is_leaf()) {
				_node = tree_min(_node->right);
			}
			else {
				node_pointer tmp = _node->parent;
				while (!tmp->is_leaf() && _node == tmp->right) {
					_node = tmp;
					tmp = tmp->parent;
				}
				_node = tmp;
			}
			return new_it;
		}

		tree_it operator--(int) {
			tree_it<value_type> new_it = *this;
			if (_node->left && !_node->left->is_leaf()) {
				_node = tree_max(_node->left);
			}
			else {
				node_pointer tmp = _node->parent;
				while (!tmp->is_leaf() && _node == tmp->left) {
					_node = y;
					tmp = tmp->parent;
				}
				_node = tmp;
			}
			return new_it;
		}

		protected:
			node_pointer _node;

			node_pointer tree_min(node_pointer node) {
				node_pointer tmp = node;
				while (!tmp->left->is_leaf())
					tmp = tmp->left;
				return tmp;
			}

			node_pointer tree_max(node_pointer node) {
				node_pointer tmp = node;
				while (!tmp->rigth->is_leaf())
					tmp = tmp->rigth;
				return tmp;
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

};

#endif	//TREE_IT_HPP