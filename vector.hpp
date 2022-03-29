#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <exception>
#include <cmath>
#include <limits>

using std::allocator;
using std::cout;
using std::endl;

#define MAXSIZE std::numeric_limits<size_t>::max()

namespace ft {
	template <class T, class Alloc = std::allocator<T>>
	class vector {
	 public:
		vector() : _size(0), _cap(0) {
			_array = NULL;
			//назначить итераторы
		}

  		explicit vector(const Alloc& alloc) : _alloc(alloc) {
			_size = 0;
			_cap = 0;
			_array = NULL;
			//назначить итераторы
		}

  		// explicit vector( size_t count,
        //            const T& value = T(),
        //            const Alloc& alloc = Allocator())
        //            : _size(count), _cap(count), _alloc(alloc) {
		// 	_array = _alloc.allocate(); // -> _alloc.construct(value);
		// 	//назначить итераторы
  		// }

  		explicit vector(size_t count) : _size(count), _cap(count) {
			_array = _alloc.allocate(count);
			for(int i = 0; i < count; i++) {
				_alloc.construct(_array + i, T());
			}
			//назначить итераторы
		}

  		// template< class InputIt >
  		// vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		// vector(const vector& other);

		~vector() {
			if(_array != NULL) {
				for(int i = 0; i < _size; i++) {
					_alloc.destroy(_array + i);
				}
				_alloc.deallocate(_array, _cap);
			}
			//требуется ли действие с итератором???
		}

		// vector(const vector &value);
		// vector &operator=(const vector &value);
		
		Alloc get_allocator() const {
			return _alloc;
		}

		// void assign(size_type count, const T& value);
		// template< class InputIt >
		// void assign( InputIt first, InputIt last );

		//capacity
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
				//переназначить все итераторы
				for(int i = 0; i < _cap; i++) {
					_alloc.destroy(_array + i);
				}
				if (_array != NULL) {
					_alloc.deallocate(_array, _cap);
				}
				_array = newarr;
				_cap = n;
			}
		}

		size_t max_size() const {
			size_t res = MAXSIZE / (size_t)sizeof(T);
			return res;
		}
		
		//access
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


		//modify
		void clear() {
			for(int i = 0; i < _size; i++) {
				_alloc.destroy(_array + i);
			}
			_size = 0;
			//переназначить все итераторы
		}

		// iterator insert( iterator pos, const T& value);
		// void insert( iterator pos, size_type count, const T& value );
		// template<class InputIt>
		// void insert( iterator pos, InputIt first, InputIt last );

		// iterator erase(iterator pos);
		// iterator erase(iterator first, iterator last);

		void resize(size_t n, const T& val = T()) { //ИСПРАВИТЬ НАСТЁНЕ
			if(n < _size) {

				for(int i = n; i < _size; i++) {
					_alloc.destroy(_array + i);
				}
			} else {
				if (n > _cap) {
					this->reserve(_size == 0 ? n : _size * 2);
				}
				for(int i = _size; i < n; i++) {
					_alloc.construct(_array + i, val);
				}
			}
			//переназначить iterator last
			_size = n;
		}

		// void swap(vector& other);

		void push_back(const T& value) {
			
			if(_size == _cap) {
				this->reserve(_cap == 0 ? 1 : _cap * 2);
			}
			_alloc.construct(_array + _size, value);
			_size++;
			//переназначить iterator last
		}

		void pop_back() {
			_alloc.destroy(_array + _size);
			--_size;
			//переназначить iterator last
		}

		//iterators
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

	 private:
		T*		_array;
		size_t	_size;
		size_t	_cap;
		Alloc	_alloc;
	};

//non-member function
	// template< class T, class Alloc >
	// bool operator==( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// bool operator!=(const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs);

	// template< class T, class Alloc >
	// bool operator<( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// bool operator<=( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// bool operator>( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );

	// template< class T, class Alloc >
	// bool operator>=( const vector<T,Alloc>& lhs,
	// 				const vector<T,Alloc>& rhs );
}

#endif	//VECTOR_HPP
