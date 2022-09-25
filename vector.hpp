#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>
#include <exception>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include "iterators/iterator.hpp"
#include "iterators/ran_it.hpp"
#include "iterators/reverse_it.hpp"
#include "utils/utils.hpp"

using std::allocator;
using std::cout;
using std::endl;
using std::cerr;

namespace ft {
template <class T, class Allocator = std::allocator<T> >
class vector {
   public:
	typedef T value_type;
	typedef size_t size_type;
	typedef Allocator allocator_type;
	typedef std::ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
	typedef const T* const_pointer;
	typedef const T& const_reference;
	typedef ft::ran_it<T> iterator;
	typedef ft::ran_it<const T> const_iterator;
	typedef ft::reverse_it<T> reverse_iterator;
	typedef ft::reverse_it<const T> const_reverse_iterator;

   private:
    Allocator _alloc;
	size_type _size;
	size_type _cap;
	pointer _array;
	pointer _first;
	pointer _last;

   public:

	/* constructors */
	vector() : _size(0), _cap(0) {
		_array = NULL;
		_first = NULL;
		_last = _first;
	}

	explicit vector(const Allocator& alloc) : _alloc(alloc), _size(0), _cap(0),
			_array(NULL), _first(NULL), _last(_first) {	}

	explicit vector(size_type count, const T& value = T(),
					const Allocator& alloc = Allocator())
		: _alloc(alloc), _size(count), _cap(count), _array(NULL), _first(NULL), _last(_first) {
		try { 
		_array = _alloc.allocate(count);
		} catch (std::bad_alloc const&) {
			cerr << "Bad allocate exception" << endl;
		}
		for (size_t i = 0; i < count; i++) {
			_alloc.construct(_array + i, value);
		}
		_first = _array;
		_last = _array + count;
	}

	template <class InputIt>
	vector(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first,
					InputIt last, const Allocator& alloc = Allocator())
		: _alloc(alloc), _size(0), _cap(0), _array(NULL), _first(NULL), _last(_first) {
		difference_type n = last - first;
			if (n < 0)
				throw std::length_error("vector");
			if (n == 0)
				return;
			_size = n;
			_cap = n;
			try {
				_array = _alloc.allocate(n);
			} catch (std::bad_alloc const&) {
				cerr << "Bad allocate exception" << endl;
			}
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_array[i], *first++);
			_first = _array;
			_last = _array + _size;
	}

	/*copy constructor*/
	vector(const vector& value) : _size(value.size()), _cap(_size), _array(NULL) {
		try {
			_array = _alloc.allocate(_cap);	
		} catch (std::bad_alloc const&) {
			cerr << "Bad allocate exception" << endl;
		}
		for (size_type i = 0; i < _size; ++i) {
			_alloc.construct(_array + i, value[i]);
		}
		_first = _array;
		_last = _array + _size;
	}

	/*destructor*/
	~vector() {
		if (_array != NULL) {
			clear();
			_alloc.deallocate(_array, _cap);
		}
	}

	vector& operator=(const vector& value) {
		if (this != &value) {
			if (_array != NULL) {
				clear();
				_alloc.deallocate(_array, _cap);
			}
			_size = value.size();
			_cap = _size;
			try {
				_array = _alloc.allocate(_cap);
			} catch (std::bad_alloc const&) {
				cerr << "Bad allocate exception" << endl;
			}
			for (size_type i = 0; i < _size; ++i) {
				_alloc.construct(_array + i, value[i]);
			}
			_first = _array;
			_last = _array + _size;
		}
		return *this;
	}

	allocator_type get_allocator() const { return _alloc; }

	void assign(size_type count, const T& value) {
		if (count < _size) {
			for (size_type i = count; i < _size; i++) {
				_alloc.destroy(_array + i);
			}
		} else if (count > _cap) {
			this->reserve(count);
		}

		for (size_type i = 0; i < count; i++) {
			_alloc.destroy(_array + i);
			_alloc.construct(_array + i, value);
		}
		_size = count;
		_first = _array;
		_last = _array + _size;
	}

	template <class InputIt>
	void assign(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first,
				InputIt last) {
		size_type count = (size_type)ft::distance(first, last);
		if (count < _size) {
			for (size_type i = count; i < _size; i++) {
				_alloc.destroy(_array + i);
			}
		} else if (count > _cap) {
			this->reserve(count);
		}
		int i = -1;
		for (InputIt p = first; p != last; ++p) {
			_alloc.destroy(_array + (++i));
			_alloc.construct(_array + i, (*p));
		}
		_size = count;
		_first = _array;
		_last = _array + _size;
	}

	/* capacity */
	size_type size() const { return _size; }

	size_type capacity() const { return _cap; }

	bool empty() const { return _size == 0 ? 1 : 0; }

	void reserve(size_type n) {
		if (n > _cap) {
			T* newarr = NULL;
			try {
				newarr = _alloc.allocate(n);
			} catch (std::bad_alloc const&) {
				cerr << "Bad allocate exception" << endl;
			}
			for (size_type i = 0; i < _cap; i++) {
				_alloc.construct(newarr + i, _array[i]);
			}
			for (size_type i = 0; i < _cap; i++) {
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

	size_type max_size() const { return _alloc.max_size(); }

	/*access*/
	reference operator[](size_type n) { return _array[n]; }

  	const_reference operator[](size_type n) const { return _array[n]; }

  	reference at(size_type n) {
		if (n > _size)
			throw std::out_of_range("range_check it >= size");
		return _array[n];
	}

  	const_reference at(size_type n) const {
		if (n > _size)
			throw std::out_of_range("range_check it >= size");
		return _array[n];
	}

	T& front() { return _array[0]; }

	const T& front() const { return _array[0]; }

	T& back() { return _array[_size - 1]; }

	const T& back() const { return _array[_size - 1]; }

	T* data() { return _array; }

	const T* data() const { return _array; }

	/*modify*/
	void clear() {
		for (size_type i = 0; i < _size; ++i) {
			_alloc.destroy(_array + i);
		}
		_size = 0;
		_first = _array;
		_last = _first;
	}

	iterator insert(iterator pos, const T& value) {
		difference_type ipos = &(*pos) - _first;
		if (_size == _cap) {
			reserve(_cap == 0 ? 1 : _cap * 2);
		}
		pointer ptr = _array + _size;
		for (; ptr != _array + ipos; --ptr) {
			_alloc.construct(ptr, *(ptr - 1));
			_alloc.destroy(ptr - 1);
		}
		_alloc.construct(ptr, value);
		++_size;
		_first = _array;
		_last = _array + _size;
		return iterator(_array + ipos);
	}

	void insert(iterator pos, size_type count, const T& value) {
		difference_type ipos = &(*pos) - _first;
		if ((_size + count) >= _cap) {
			reserve((_cap == 0 || (_size + count > _cap * 2)) ? _size + count : _cap * 2);
		}
		pointer last_free_ptr = _array + _size + count;
		pointer ptr = _array + _size;
		while (ptr != _array + ipos) {
			--last_free_ptr;
			--ptr;
			_alloc.construct(last_free_ptr, *(ptr));
			_alloc.destroy(ptr);
		}
		for (; ptr != last_free_ptr; ++ptr) {
			_alloc.construct(ptr, value);
		}
		_size += count;
		_first = _array;
		_last = _array + _size;
	}

	template <class InputIt>
	void insert(iterator pos, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first,
				 InputIt last) {
		difference_type ipos = &(*pos) - _first;
		size_type count = (size_type)ft::distance(first, last);
		if ((_size + count) >= _cap) {
			reserve(_cap == 0 ? count : _cap * 2);
		}
		pointer last_free_ptr = _array + _size + count;
		pointer ptr = _array + _size;
		while (ptr != _array + ipos) {
			--last_free_ptr;
			--ptr;
			_alloc.construct(last_free_ptr, *(ptr));
			_alloc.destroy(ptr);
		}
		for (InputIt tmp = first; tmp != last; ++tmp, ++ptr) {
			_alloc.construct(ptr, (*tmp));
		}
		_size += count;
		_first = _array;
		_last = _array + _size;
	}

	iterator erase(iterator pos) {
		_alloc.destroy(&(*pos));
		for (T* it = &(*pos); it != _array + _size; ++it) {
			_alloc.construct(it, *(it + 1));
			_alloc.destroy(it + 1);
		}
		--_size;
		_last = _array + _size;
		return pos;
	}

	iterator erase(iterator first, iterator last) {
		iterator p;
		size_type count = 0;
		for (p = first; p != last; ++p) {
			_alloc.destroy(&(*p));
			++count;
		}
		last = first;
		for (T* ptr = &(*p); ptr != _array + _size; ++ptr) {
			_alloc.construct((&(*last)), *(ptr));
			_alloc.destroy(ptr);
			last++;
		}
		_size -= count;
		_last = _array + _size;
		return first;
	}

	void resize(size_type n,
				const T& val = T()) {
		if (n < _size) {
			for (size_type i = n; i < _size; i++) {
				_alloc.destroy(_array + i);
			}
		} else {
			if (n > _cap) {
				this->reserve(n);
			}
			for (size_type i = _size; i < n; i++) {
				_alloc.construct(_array + i, val);
			}
		}
		_size = n;
		_last = _array + _size;
	}

	void swap(vector& other) {
		std::swap(this->_array, other._array);
		std::swap(this->_size, other._size);
		std::swap(this->_cap, other._cap);
		std::swap(this->_alloc, other._alloc);
		std::swap(this->_first, other._first);
		std::swap(this->_last, other._last);
	}

	void push_back(const T& value) {
		if (_size == _cap) {
			this->reserve(_cap == 0 ? 1 : _cap * 2);
		}
		_alloc.construct(_array + _size, value);
		_size++;
		_last = _array + _size;
	}

	void pop_back() {
		--_size;
		_alloc.destroy(_array + _size);
		_last = _array + _size;
	}

	/*iterators*/
	iterator begin() { return _first; }

	const_iterator begin() const { return _first; }

	iterator end() { return _last; }

	const_iterator end() const { return _last; }

	reverse_iterator rbegin() { return reverse_iterator(_last - 1); }

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(_last - 1);
	}

	reverse_iterator rend() { return reverse_iterator(_first - 1); }

	const_reverse_iterator rend() const {
		return const_reverse_iterator(_first - 1);
	}
};

/* non-member function */
template <class T, class Allocator>
bool operator==(const ft::vector<T, Allocator>& lhs,
				const ft::vector<T, Allocator>& rhs) {
	if (lhs.size() == rhs.size()) {
		for (size_t i = 0; i < rhs.size(); i++) {
			if (lhs[i] != rhs[i]) return false;
		}
		return true;
	}
	return false;
}

template <class T, class Allocator>
bool operator!=(const ft::vector<T, Allocator>& lhs,
				const ft::vector<T, Allocator>& rhs) {
	return !(lhs == rhs);
}

template <class T, class Allocator>
bool operator<(const ft::vector<T, Allocator>& lhs,
			   const ft::vector<T, Allocator>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
									rhs.end()));
}

template <class T, class Allocator>
bool operator<=(const ft::vector<T, Allocator>& lhs,
				const ft::vector<T, Allocator>& rhs) {
	return (lhs < rhs || lhs == rhs);
}

template <class T, class Allocator>
bool operator>(const ft::vector<T, Allocator>& lhs,
			   const ft::vector<T, Allocator>& rhs) {
	return !(lhs < rhs || lhs == rhs);
}

template <class T, class Allocator>
bool operator>=(const ft::vector<T, Allocator>& lhs,
				const ft::vector<T, Allocator>& rhs) {
	return !(lhs < rhs);
}

template <class T, class Allocator>
void swap(ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs) {
	lhs.swap(rhs);
}
}  // namespace ft

#endif	// VECTOR_HPP
