#ifndef MAP_HPP
#define MAP_HPP

#include "iterators/iterator.hpp"
#include "utils.hpp"

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
		typedef T*								pointer;
		typedef T&								reference;
	 	typedef const T*						const_pointer;
		typedef const T&						const_reference;
	 	typedef ran_it< T >						iterator;
		typedef ran_it< const T >				const_iterator;
		typedef reverse_it< iterator >			reverse_iterator;
		typedef reverse_it< const iterator >	const_reverse_iterator;
		
		/*constructors*/
		// map();

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

		// size_t max_size() const {
		// 	size_t res = MAXSIZE / (size_t)sizeof(T);
		// 	return res;
		// }

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




	 private:
		Key _key;
		T	_val;
		size_t _size;
		Allocator _alloc;


	};
}

#endif // MAP_HPP
