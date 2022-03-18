#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <exception>


using std::allocator;


namespace ft {
	template <class T, class Alloc = std::allocator<T>>
	class vector {
	 public:
		vector();
		~vector();
		vector(const vector &source);
		vector &operator=(const vector &source);
		
		Alloc get_allocator() const {
			return _alloc;
		}

		void assign(size_type count, const T& value);

		template< class InputIt >
		void assign( InputIt first, InputIt last );

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

		void reserve(size_t n);			//увеличивает capasity до n

		size_t max_size() const {
			return 2^(64 - sizeof(T)) - 1;
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

		T* data();
		const T* data() const;


		//modify
		void clear();

		iterator insert( iterator pos, const T& value);
		void insert( iterator pos, size_type count, const T& value );
		template<class InputIt>
		void insert( iterator pos, InputIt first, InputIt last );

		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);
		void resize(size_t n, T val);
		void swap(vector& other);
		void push_back(const &T value);
		void pop_back(const &T value);

		//iterators
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		//non-member function
		template< class T, class Alloc >
		bool operator==( const std::vector<T,Alloc>& lhs,
						const std::vector<T,Alloc>& rhs );

		template< class T, class Alloc >
		bool operator!=( const std::vector<T,Alloc>& lhs,
						const std::vector<T,Alloc>& rhs );

		template< class T, class Alloc >
		bool operator<( const std::vector<T,Alloc>& lhs,
						const std::vector<T,Alloc>& rhs );

		template< class T, class Alloc >
		bool operator<=( const std::vector<T,Alloc>& lhs,
						const std::vector<T,Alloc>& rhs );

		template< class T, class Alloc >
		bool operator>( const std::vector<T,Alloc>& lhs,
						const std::vector<T,Alloc>& rhs );

		template< class T, class Alloc >
		bool operator>=( const std::vector<T,Alloc>& lhs,
						const std::vector<T,Alloc>& rhs );

	 private:
		T *		_array;
		size_t	_size;
		size_t	_cap;
		Alloc	_alloc;
	};
}



#endif	//VECTOR_HPP
