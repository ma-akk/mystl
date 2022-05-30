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
			_nil = NULL;
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


		//!!!!обращение к ключу в таком виде возможно, заменить на итераторы!!!
		// С++ - псевдокод
		void rb_insert_node(Node *node) {
			Node <const Key, T> *tmp1 = _root;
			Node <const Key, T> *tmp2 = _nil
			while (tmp1 != _nil) {
				tmp2 = tmp1;
				if (node->key < tmp1->key)
					tmp1 = tmp1->_left;
				else
					tmp1 = tmp1->_rigth;
			}
			node->_parent = tmp2;
			if (tmp2 == _nil)
				_root = node;
			else if (node->key < tmp2->key)
				tmp2->_left = node;
			else
				tmp2->_rigth = node;
			node->_left = _nil;
			node->_rigth = _nil;
			node->_color = RED;
		}

		//проверить, как работает else {}
		//возможно стоит перенести все в класс Node
		void rb_insert_balance(Node *node) {
			Node <const Key, T> *tmp = _root;
			while (node->_parent->_color == RED) {
				if (node->_parent == node->_parent->_parent->left) {
					tmp = node->_parent->_parent->rigth;
					if (tmp->_color == RED) {
						node->_parent->_color = BLACK;
						tmp->_color = BLACK;
						node->_parent->_parent->_color = RED;
						node = node->_parent->_parent;
					} else if (node == node->_parent->_rigth) {
						node = node->_parent;
						node->left_rotate(_root, _nil);
					}
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					node->_parent->_parent->rigth_rotate(_root, _nil);
				}
				else {
					tmp = node->_parent->_parent->left;
					if (tmp->_color == RED) {
						node->_parent->_color = BLACK;
						tmp->_color = BLACK;
						node->_parent->_parent->_color = RED;
						node = node->_parent->_parent;
					} else if (node == node->_parent->_left) {
						node = node->_parent;
						node->rigth_rotate(_root, _nil);
					}
					node->_parent->_color = BLACK;
					node->_parent->_parent->_color = RED;
					node->_parent->_parent->left_rotate(_root, _nil);
				}
				_root->_color = BLACK;
			}
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
