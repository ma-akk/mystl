#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>

namespace ft {
	template <class T, class Allocator = std::allocator<T>>
	class vector {
	 public:
		vector();
		~vector();
		vector(const vector &source);
		vector &operator=(const vector &source);
		allocator_type get_allocator() const;
		void assign( size_type count, const T& value );

		template< class InputIt >
		void assign( InputIt first, InputIt last );

		//capacity
		size_t size() const;
		size_t capacity() const;
		bool empty() const;
		void reserve(size_t n);			//увеличивает capasity до n
		size_t max_size() const;		//???предельно допустимый размер, определяется системой
		
		//access
		T& operator[](size_t n);
		const T& operator[](size_t n) const;
		T& at(size_t n);
		const T& at(size_t n) const;
		T& front();
		const T& front() const;
		T& back();
		const T& back() const;
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
		T *_array;
		size_t _size;
		size_t _cap;
		Alloc _alloc;
	};
}



#endif	//VECTOR_HPP
