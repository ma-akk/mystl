#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <exception>
#include <cmath>
#include <limits>
#include "iterators/ran_it.hpp"
// #include "iterators/reverse_iterator.hpp"

using std::allocator;
using std::cout;
using std::endl;

#define MAXSIZE std::numeric_limits<size_t>::max()

namespace ft {
	template <class T, class Alloc = std::allocator<T>>
	class vector {
	 public:
		typedef T									value_type;
		typedef size_t								size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef T*									pointer;
		typedef T&									reference;
	 	typedef const T*							const_pointer;
		typedef const T&							const_reference;
	 	typedef ran_it< T >							iterator;
		typedef ran_it< const T >					const_iterator;
		// typedef reverse_iterator< iterator >		reverse_iterator;
		// typedef reverse_iterator< const iterator >	const_reverse_iterator;
		
		/*constructors*/
		vector() : _size(0), _cap(0) {
			_array = NULL;
			_first = NULL;
			_last = _first;
			
		}

  		explicit vector(const Alloc& alloc) : _alloc(alloc) {
			_size = 0;
			_cap = 0;
			_array = NULL;
			_first = NULL;
			_last = _first;
		}

  		// explicit vector( size_t count,
        //         		const T& value = T(),
        //         		const Alloc& alloc = Alloc())
        //         		: _size(count), _cap(count), _alloc(alloc) {
		// 	_array = _alloc.allocate(count);
		// 	for(int i = 0; i < count; i++) {
		// 		_alloc.construct(_array + i, value);
		// 	}
		// 	_first = _array;
		// 	_last = _array + count;
  		// }

  		explicit vector(size_t count) : _size(count), _cap(count) {
			_array = _alloc.allocate(count);
			for(int i = 0; i < count; i++) {
				_alloc.construct(_array + i, T());
			}
			_first = _array;
			_last = _array + count;

		}

  		// template< class InputIt >
  		// vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		// vector(const vector& other);
		// vector& operator=(const vector& value) {
		// 	if (*this != value) {
		// 	}
		// }

		/*destructor*/
		~vector() {
			if(_array != NULL) {
				for(int i = 0; i < _size; i++) {
					_alloc.destroy(_array + i);
				}
				_alloc.deallocate(_array, _cap);
			}
		}
		
		Alloc get_allocator() const {
			return _alloc;
		}

		void assign(size_t count, const T& value) {
			if(count < _size) {
				for(int i = count; i < _size; i++) {
					_alloc.destroy(_array + i);
				}
			} else {
				if (count > _cap)
					this->reserve(count);
			}
			for(int i = 0; i < count; i++) {
				_alloc.destroy(_array + i);
				_alloc.construct(_array + i, value);
			}
			_size = count;
			_first = _array;
			_last = _array + _size;
		}

		// template< class InputIt >
		// void assign( InputIt first, InputIt last ) {

		// }

		/*capacity*/
		size_t size() const {
			return _size;
		}

		size_t capacity() const {
			return _cap;
		}

		bool empty() const {
			bool res = _size == 0 ? true : false;
			return res;
		}

		void reserve(size_t n) {
			if(n > _cap) {
				cout << "reserve: n = " << n << " cap = " << _cap << endl;
				T* newarr = _alloc.allocate(n);
				for(int i = 0; i < _cap; i++) {
					_alloc.construct(newarr + i, _array[i]);
				}
				for(int i = 0; i < _cap; i++) {
					_alloc.destroy(_array + i);
				}
				if (_array != NULL) {
					_alloc.deallocate(_array, _cap);
				}
				_array = newarr;
				_first = _array;
				_last = (_array + _cap);
				_cap = n;
			}
		}

		size_t max_size() const {
			size_t res = MAXSIZE / (size_t)sizeof(T);
			return res;
		}
		
		/*access*/
		T& operator[](size_t n) {
			return _array[n];
		}

		const T& operator[](size_t n) const {
			return _array[n];
		}

		T& at(size_t n) {
			if(n > _size || n < 0)
				throw std::out_of_range("range_check it >= size");
			return _array[n];
		}

		const T& at(size_t n) const {
			if(n > _size || n < 0)
				throw std::out_of_range("range_check it >= size");
			return _array[n];
		}

		T& front() {
			return _array[0];
		}

		const T& front() const {
			return _array[0];
		}

		T& back() {
			return _array[_size - 1];
		}

		const T& back() const {
			return _array[_size - 1];
		}

		T* data() {
			return _array;
		}

		const T* data() const {
			return _array;
		}


		/*modify*/
		void clear() {
			for(int i = 0; i < _size; i++) {
				_alloc.destroy(_array + i);
			}
			_size = 0;
			_first = _array;
			_last = _first;
		}

		// iterator insert( iterator pos, const T& value);
		// void insert( iterator pos, size_type count, const T& value );
		// template<class InputIt>
		// void insert( iterator pos, InputIt first, InputIt last );

		// iterator erase(iterator pos);
		// iterator erase(iterator first, iterator last);

		void resize(size_t n, const T& val = T()) { //заполняет только "пустые" элементы
			if(n < _size) {

				for(int i = n; i < _size; i++) {
					_alloc.destroy(_array + i);
				}
			} else {
				if (n > _cap) {
					this->reserve(n);
				}
				for(int i = _size; i < n; i++) {
					_alloc.construct(_array + i, val);
				}
			}
			_size = n;
			_last = _array + _size;
		}

		// void swap(vector& other) {
		// 	if (this != &other) {
				
		// 	}
		// }

		void push_back(const T& value) {
			
			if(_size == _cap) {
				this->reserve(_cap == 0 ? 1 : _cap * 2);
			}
			_alloc.construct(_array + _size, value);
			_size++;
			_last = _array + _size;
		}

		void pop_back() {
			_alloc.destroy(_array + _size);
			--_size;
			_last = _array + _size;
		}

		/*iterators*/
		iterator begin() {
			return _first;
		}

		const_iterator begin() const {
			return _first;
		}

		iterator end() {
			return _last;
		}

		const_iterator end() const {
			return _last;
		}

		// reverse_iterator rbegin() {
		// 	return --_last;
		// }

		// const_reverse_iterator rbegin() const {
		// 	return --_last;
		// }

		// reverse_iterator rend() {
		// 	return _first;
		// }
		
		// const_reverse_iterator rend() const {
		// 	return _first;
		// }

	 private:
		T*			_array;
		size_t		_size;
		size_t		_cap;
		Alloc		_alloc;

		/*_first указывает на первый элемент вектора*/
		T*			_first;

		/*_last указывает на некоторую область после конца вектора*/
		T*			_last;

	};

	//non-member function
	template< class T, class Alloc >
	bool operator==( const vector<T,Alloc>& lhs,
					const vector<T,Alloc>& rhs ) {
		if (lhs.size() == rhs.size()) {
			for(int i = 0; i < rhs.size(); i++) {
				if(lhs[i] != rhs[i])
					return false;
			}
			return true;
		}
		return false;
	}

	template< class T, class Alloc >
	bool operator!=(const vector<T,Alloc>& lhs,
					const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	// template< class T, class Alloc >
	// bool operator<( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs ) {
		
	// }

	// template< class T, class Alloc >
	// bool operator<=( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// bool operator>( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// bool operator>=( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// void swap( std::vector<T,Alloc>& lhs,
    //        std::vector<T,Alloc>& rhs );
}

#endif	//VECTOR_HPP
