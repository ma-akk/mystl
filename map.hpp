#ifndef MAP_HPP
#define MAP_HPP

#include "iterators/iterator.hpp"
#include "utils.hpp"
#include "iterators/tree_it.hpp"
#include "rb_tree.hpp"

namespace ft {
	
	template <class Key, class T,
			  class Compare = std::less<Key>,
			  class Allocator = std::allocator<ft::pair<const Key, T>>>
	class map {
	 public:
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef pair<const Key, T>				value_type;
		typedef size_t							size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Compare							key_compare;
		typedef typename Allocator::pointer		pointer;
		typedef value_type&						reference;
	 	typedef typename Allocator::const_pointer	const_pointer;
		typedef const value_type&				const_reference;
//	 	typedef ran_it< T >						iterator;
//		typedef ran_it< const T >				const_iterator;
//		typedef reverse_it< iterator >			reverse_iterator;
//		typedef reverse_it< const iterator >	const_reverse_iterator;

        typedef rb_tree<value_type, key_compare, Allocator > map_tree;
		
		/*constructors*/
//		map() {	}

		// explicit map( const Compare& comp,
		// 			const Allocator& alloc = Allocator() );

		// template< class InputIt >
		// map( InputIt first, InputIt last,
		// 	const Compare& comp = Compare(),
		// 	const Allocator& alloc = Allocator() );
		
		// map( const map& other );

		// /*destructor*/
		// ~map() { }

		// map& operator=( const map& other );

		Allocator get_allocator() const {  }

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
		 bool empty() const { }

		 size_t size() const { }

         size_t max_size() const { }

		/*modify*/
		// void clear() { }

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

        /* lookup */
		// size_type count( const Key& key ) const;
		// iterator find( const Key& key );
		// const_iterator find( const Key& key ) const;
		// pair<iterator,iterator> equal_range( const Key& key );
		// pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
		// iterator lower_bound( const Key& key );
		// const_iterator lower_bound( const Key& key ) const;
		// iterator upper_bound( const Key& key );
		// const_iterator upper_bound( const Key& key ) const;

        /* observers */
		// key_compare key_comp() const;
		// map::value_compare value_comp() const;



	 private:
	 	map_tree _tree;


	};
}

#endif // MAP_HPP
