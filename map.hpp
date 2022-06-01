#ifndef MAP_HPP
#define MAP_HPP

#include "iterators/iterator.hpp"
#include "utils.hpp"
#include "Node.hpp"

namespace ft {
	
	template <class Key, class T,
			  class Compare = std::less<Key>,
			  class Allocator = std::allocator<std::pair<const Key, T>>>
	class map {
	 public:
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef pair<const Key, T>				value_type;
		typedef size_t							size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Compare							key_compare;
		typedef Allocator::pointer				pointer;
		typedef value_type&						reference;
	 	typedef const Allocator::pointer		const_pointer;
		typedef const value_type&				const_reference;
	 	typedef ran_it< T >						iterator;
		typedef ran_it< const T >				const_iterator;
		typedef reverse_it< iterator >			reverse_iterator;
		typedef reverse_it< const iterator >	const_reverse_iterator;
		
		/*constructors*/
		map() {
			//здесь можно создавать nil-ноду и приравнивать ее к root
			_size = 0;
			_root = NULL;
			
		}

		// explicit map( const Compare& comp,
		// 			const Allocator& alloc = Allocator() );

		// template< class InputIt >
		// map( InputIt first, InputIt last,
		// 	const Compare& comp = Compare(),
		// 	const Allocator& alloc = Allocator() );
		
		// map( const map& other );

		// /*destructor*/
		// ~map() {}

		// map& operator=( const map& other );

		Allocator get_allocator() const {
			return _alloc;
		}

		// T& at( const Key& key ) {
		// 	if(n > _size || n < 0)
		// 		throw std::out_of_range("range_check it >= size");
		// 	return _array[n];
		// }
		
		// const T& at( const Key& key ) const { }

		// T& operator[]( const Key& key );

		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		/* capacity */
		// bool empty() const {
		// 	return _size == 0 ? true : false;;
		// }

		// size_t size() const {
		// 	return _size;
		// }

		size_t max_size() const {
			size_t res = MAXSIZE / (size_t)sizeof(Node);
			return res;
		}

		/*modify*/
		// void clear() {
		// 	for(size_t i = 0; i < _size; ++i) {
		// 		_alloc.destroy(_array + i);
		// 	}
		// 	_size = 0;
		// 	_first = _array;
		// 	_last = _first;
		// }

		// pair<iterator, bool> insert( const value_type& value );
		// iterator insert( iterator hint, const value_type& value );
			
		// iterator erase(iterator pos) {
		// 	_alloc.destroy(&(*pos));
		// 	for (T* it = &(*pos); it != _array + _size; ++it) {
		// 		_alloc.construct(it, *(it + 1));
		// 		_alloc.destroy(it + 1);
		// 	}
		// 	--_size;
		// 	_last = _array + _size;
		// 	return pos;
		// }

		// iterator erase(iterator first, iterator last) {
		// 	iterator p;
		// 	size_t count = 0;
		// 	for (p = first; p != last; ++p) {
		// 		_alloc.destroy(&(*p));
		// 		++count;
		// 	}
		// 	last = first;
		// 	for (T* ptr = &(*p); ptr != _array + _size; ++ptr) {
		// 		_alloc.construct((&(*last)), *(ptr));
		// 		_alloc.destroy(ptr);
		// 		last++;
		// 	}
		// 	_size -= count;
		// 	_last = _array + _size;
		// 	return first;
		// }

		// size_type erase( const Key& key );

		// void swap(vector& other) {
		// 	if (this != &other && !(this->empty() || other.empty())) {
				
		// 	} else if(this->empty()) {
		// 		*this = other;
		// 		other.clear();
		// 	} else if(other.empty()) {
		// 		other = *this;
		// 		this->clear();
		// 	}
		// }

		// size_type count( const Key& key ) const;
		// iterator find( const Key& key );
		// const_iterator find( const Key& key ) const;
		// pair<iterator,iterator> equal_range( const Key& key );
		// pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
		// iterator lower_bound( const Key& key );
		// const_iterator lower_bound( const Key& key ) const;
		// iterator upper_bound( const Key& key );
		// const_iterator upper_bound( const Key& key ) const;
		// key_compare key_comp() const;
		// map::value_compare value_comp() const;


		void create_nil(Node *root) {
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, Node());
		}
		
		//!!!!обращение к ключу в таком виде возможно, заменить на итераторы!!!
		// С++ - псевдокод
		void rb_insert_node(Node *node) {
			Node <const Key, T> *tmp1 = _root;
			Node <const Key, T> *tmp2 = _nil
			while (tmp1 != _nil) {
				tmp2 = tmp1;
				if (node->key < tmp1->key)
					tmp1 = tmp1->left;
				else
					tmp1 = tmp1->rigth;
			}
			node->parent = tmp2;
			if (tmp2 == _nil)
				_root = node;
			else if (node->key < tmp2->key)
				tmp2->left = node;
			else
				tmp2->rigth = node;
			node->left = _nil;
			node->rigth = _nil;
			node->color = RED;
			rb_insert_balance(node);
		}

		//проверить, как работает else {}
		//возможно стоит перенести все в класс Node
		void rb_insert_balance(Node *node) {
			Node <const Key, T> *tmp = _root;
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
							node->left_rotate(_root, _nil);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node->parent->parent->rigth_rotate(_root, _nil);
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
							node->rigth_rotate(_root, _nil);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						node->parent->parent->left_rotate(_root, _nil);
					}
				}
			}
			_root->color = BLACK;
		}

		Node *rb_min(Node *node) {
			Node *tmp = node;
			while (tmp->left != _nil)
				tmp = tmp->left;
			return tmp;
		}

		void rb_transplant(Node *u, Node *v) {
			if (u->parent == _nil)
				_root = v;
			else if(u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->rigth = v;
			v->parent = u->parent;
		}

		void rb_delete(Node *node) {
			Node *x; 
			Node *tmp = node;
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

		void rb_delete_balance(Node *node) {
			Node *tmp;
			while (node != _root && node->color == BLACK) {
				if (node == node->parent->left) {
					tmp = node->parent->rigth;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						node->parent->left_rotate(_root, _nil);
						tmp = node->parent->rigth;
					}
					if (tmp->left->color == BLACK && tmp->rigth->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					} else {
						if (tmp->rigth->color == BLACK) {
							tmp->left->color = BLACK;
							tmp->color = RED;
							tmp->rigth_rotate(_root, _nil);
							tmp = node->parent->rigth;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->rigth->color = BLACK;
						node->parent->left_rotate(_root, _nil);
						node = _root;
					}
				} else {
					tmp = node->parent->left;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						node->parent->rigth_rotate(_root, _nil);
						tmp = node->parent->left;
					}
					if (tmp->rigth->color == BLACK && tmp->left->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					} else {
						if (tmp->left->color == BLACK) {
							tmp->rigth->color = BLACK;
							tmp->color = RED;
							tmp->left_rotate(_root, _nil);
							tmp = node->parent->left;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->left->color = BLACK;
						node->parent->rigth_rotate(_root, _nil);
						node = _root;
					}
				}
			}
			node->color = BLACK;
		}


	 private:
	 	Node <const Key, T> *_root;
		Node <const Key, T> *_nil;
		Key _key;
		T	_val;
		size_t _size;
		Allocator _alloc;


	};
}

#endif // MAP_HPP
