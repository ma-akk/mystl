#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <memory>
#include "utils.hpp"
#include "iterators/tree_it.hpp"
#include "iterators/reverse_it.hpp"

#define RED 1
#define BLACK 0

using std::cout;
using std::endl;

namespace ft {
	template < typename value_type, class Compare = std::less<value_type>, class Allocator = std::allocator<value_type> >
	class rb_tree {
	 public:
		typedef size_t							size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Compare							value_compare;
		typedef Allocator						allocator_type;
		typedef typename Allocator::template rebind<Node<value_type>>::other	node_allocator;
		typedef	typename node_allocator::pointer 			node_pointer;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::reference			reference;
	 	typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::const_reference		const_reference;
	 	typedef tree_it<value_type>			iterator;
		typedef tree_it<const value_type>		const_iterator;
		typedef reverse_it<iterator>			reverse_iterator;
		typedef reverse_it<const_iterator>	const_reverse_iterator;
		
		void init_tree() {
			_nil = _node_alloc.allocate(1);
			_node_alloc.construct(_nil, Node<value_type>());
			_root = _node_alloc.allocate(1);
			_node_alloc.construct(_root, Node<value_type>());
			_root->parent = _nil;
			_root->left = _nil;
			_root->right = _nil;
			_root->color = BLACK;
		}

        //функция печати дерева от @lelle from slack
//        void printBT(const std::string& prefix, const node<value_type>* nodeV, bool isLeft) const
//        {
//            std::cout << prefix;
//            std::cout << (isLeft ? “├──” : “└──” );
//            if (nodeV == _nil){
//                std::cout <<“\033[0;36m”<< “nil” << “\033[0m”<<std::endl;
//                return ;
//            }
//            // print the value of the node
//            if (nodeV->color == 0)
//                std::cout <<“\033[0;36m”<< nodeV->key.first<<“\033[0m”<<std::endl;
//            else
//            std::cout <<“\033[0;31m”<< nodeV->key.first << “\033[0m”<<std::endl;
//            printBT( prefix + (isLeft ? “│   ” : ”    “), nodeV->left, true);
//            printBT( prefix + (isLeft ? “│   ” : ”    “), nodeV->right, false);
//        }
//        void printTree(){
//            printBT(“”, _root, false);
//        }

//		void clear_tree() {
//            node_pointer tmp = _root;
//            while(tmp != _nil) {
//                _alloc.destroy(_array + i);
//            }
//            _alloc.deallocate(_array, _cap);
//		}
		
		/* consructors */
		rb_tree() : _size(0) {
			init_tree();
		}

		explicit rb_tree( const Compare& comp, const Allocator& alloc = Allocator() ) :
						_node_alloc(alloc), _compare(comp), _size(0) {
			init_tree();
		}

		// template< class InputIt >
		// rb_tree( InputIt first, InputIt last, const Compare& comp = Compare(),
		// 		const Allocator& alloc = Allocator() ) : _node_alloc(alloc), _compare(comp)	{
			
		// }

		rb_tree(const rb_tree &value) {
			cout << "copy constructor " << endl;
			if (this != &value) {
				_root = value._root;
				_nil = value._nil;
				_value_alloc = value._value_alloc;
				_node_alloc = value._node_alloc;
				_compare = value._compare;
				_size = value._size;
			}
		}

		rb_tree &operator=(const rb_tree &value) {
			cout << "operator = " << endl;
			if (this != &value) {
                _root = value._root;
                _nil = value._nil;
                _value_alloc = value._value_alloc;
                _node_alloc = value._node_alloc;
                _compare = value._compare;
                _size = value._size;
			}
			return *this;
		}

		//why is virtual destructor??
		virtual ~rb_tree() { }

        //method for debug; remove after finish project
        node_pointer get_root() const {
            return _root;
        }

        //method for debug; remove after finish project
        node_pointer get_leaf() const {
            return _nil;
        }

		void left_rotate(node_pointer node) {
			rb_tree *child = node->rigth;
            node->rigth = child->left;
			if(child->left != _nil)
				child->left->parent = node;
			if(node->parent == _nil)
				_root = child;
			else if (node == node->parent->left)
                node->parent->left = child;
			else
                node->parent->rigth = child;
			child->left = node;
            node->parent = child;
		}

		void right_rotate(node_pointer node) {
			rb_tree *child = node->left;
            node->left = child->rigth;
			if(child->rigth != _nil)
				child->rigth->parent = node;
			if(node->parent == _nil)
				_root = child;
			else if (node == node->parent->left)
                node->parent->left = child;
			else
                node->parent->rigth = child;
			child->rigth = node;
            node->parent = child;
		}

		//!!!!обращение к ключу в таком виде невозможно, заменить на итераторы!!!
		void rb_insert_node(node_pointer node) {
            node_pointer tmp1 = _root;
            node_pointer tmp2 = _nil;
			while (tmp1 != _nil) {
				tmp2 = tmp1;
				if (_compare(node, tmp1)) //(node->key < tmp1->key)
					tmp1 = tmp1->left;
				else
					tmp1 = tmp1->rigth;
			}
			node->parent = tmp2;
			if (tmp2 == _nil)
				_root = node;
			else if (_compare(node, tmp2)) //(node->key < tmp2->key)
				tmp2->left = node;
			else
				tmp2->rigth = node;
			node->left = _nil;
			node->rigth = _nil;
			node->color = RED;
			rb_insert_balance(node);
		}

		//проверить, как работает else {}
		void rb_insert_balance(node_pointer node) {
            node_pointer tmp = _root;
			while (node->parent->color == RED) {
				if (node->parent == node->parent->parent->left) {
					tmp = node->parent->parent->rigth;
					if (tmp->color == RED) {
						node->parent->color = BLACK;
						tmp->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->rigth) {
							node = node->parent;
							left_rotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						right_rotate(node->parent->parent);
					}
				}
				else {
					tmp = node->parent->parent->left;
					if (tmp->color == RED) {
						node->parent->color = BLACK;
						tmp->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					} else {
						if (node == node->parent->left) {
							node = node->parent;
							right_rotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						left_rotate(node->parent->parent);
					}
				}
			}
			_root->color = BLACK;
		}

        node_pointer rb_min(node_pointer node) {
            node_pointer tmp = node;
			while (tmp->left != _nil)
				tmp = tmp->left;
			return tmp;
		}

		void rb_transplant(node_pointer u, node_pointer v) {
			if (u->parent == _nil)
				_root = v;
			else if(u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->rigth = v;
			v->parent = u->parent;
		}

		void rb_delete(node_pointer node) {
            node_pointer x;
            node_pointer tmp = node;
			bool tmp_orig_color = tmp->color;

			if (node->left == _nil) {
				x = node->rigth;
				rb_transplant(node, node->rigth);
			} else if (node->rigth == _nil) {
				x = node->left;
				rb_transplant(node, node->left);
			} else {
				tmp = rb_min(node->rigth);
				tmp_orig_color = tmp->color;
				x = tmp->rigth;
				if (tmp->parent == node) {
					x->parent = tmp;
				} else {
					rb_transplant(tmp, tmp->rigth);
					tmp->rigth = node->rigth;
					tmp->rigth->parent = tmp;
				}
				rb_transplant(node, tmp);
				tmp->left = node->left;
				tmp->left->parent = tmp;
				tmp->color = node->color;
			}
			if (tmp_orig_color == BLACK)
				rb_delete_balance(x);
		}

		void rb_delete_balance(node_pointer node) {
            node_pointer tmp;
			while (node != _root && node->color == BLACK) {
				if (node == node->parent->left) {
					tmp = node->parent->rigth;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						left_rotate(node->parent);
						tmp = node->parent->rigth;
					}
					if (tmp->left->color == BLACK && tmp->rigth->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					} else {
						if (tmp->rigth->color == BLACK) {
							tmp->left->color = BLACK;
							tmp->color = RED;
							right_rotate(tmp);
							tmp = node->parent->rigth;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->rigth->color = BLACK;
						left_rotate(node->parent);
						node = _root;
					}
				} else {
					tmp = node->parent->left;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						right_rotate(node->parent);
						tmp = node->parent->left;
					}
					if (tmp->rigth->color == BLACK && tmp->left->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					} else {
						if (tmp->left->color == BLACK) {
							tmp->rigth->color = BLACK;
							tmp->color = RED;
							left_rotate(tmp);
							tmp = node->parent->left;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->left->color = BLACK;
						right_rotate(node->parent);
						node = _root;
					}
				}
			}
			node->color = BLACK;
		}

        node_pointer	_root;
        node_pointer	_nil;
	 private:

		allocator_type	_value_alloc;
		node_allocator	_node_alloc;
		value_compare 	_compare;
		size_type		_size;
		node_pointer	_tree;
	};
}


#endif	//RB_TREE_HPP