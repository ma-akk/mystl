#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

using std::cout;
using std::endl;

namespace ft {

template <class T>
struct remove_const {
	typedef T type;
};

template <class T>
struct remove_const<const T> {
	typedef T type;
};

template <class Iterator>
class iterator_traits {
   public:
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
};

template <class T>
class iterator_traits<T*> {
   public:
	typedef std::random_access_iterator_tag iterator_category;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
};

template <class T>
class iterator_traits<const T*> {
   public:
	typedef std::random_access_iterator_tag iterator_category;
	typedef const T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
};

//NEED TESTED
/* inline namespace for encapsulation func *_imlp */
namespace {
	template <class InIt>
	void advance_impl(InIt& iter, typename ft::iterator_traits<InIt>::difference_type n,
					std::input_iterator_tag) {
		cout << "it is InIt" << endl;
		for (int i = 0; i < n; i++) {
			++iter;
		}
	}

	template <class InIt>
	void advance_impl(InIt& iter, typename ft::iterator_traits<InIt>::difference_type n,
					std::random_access_iterator_tag) {
		iter += n;
	}

	template <class InIt>
	typename ft::iterator_traits<InIt>::difference_type distance_impl(
		InIt& first, InIt& last, std::input_iterator_tag) {
		typename ft::iterator_traits<InIt>::difference_type n;
		InIt tmp = first;
		for (n = 0; tmp != last; n++) {
			++tmp;
		}
		return n;
	};

	template <class InIt>
	typename ft::iterator_traits<InIt>::difference_type distance_impl(
		InIt& first, InIt& last, std::random_access_iterator_tag) {
		return last - first;
	}
};	// namespace

template <class InIt>
void advance(InIt& iter, typename ft::iterator_traits<InIt>::difference_type n) {
	advance_impl(iter, n,
				 typename ft::iterator_traits<InIt>::iterator_category());
}

template <class InIt>
typename ft::iterator_traits<InIt>::difference_type
distance(InIt& first, InIt& last) {
	return distance_impl(
		first, last, typename ft::iterator_traits<InIt>::iterator_category());
}

};	// namespace ft

#endif	// ITERATOR_HPP
