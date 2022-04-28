#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;


namespace ft {

	class input_iterator_tag { };

	class output_iterator_tag { };

	class forward_iterator_tag : public input_iterator_tag { };

	class bidirectional_iterator_tag : public forward_iterator_tag { };

	class random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <	class Category,
				class T,
				class Distance = std::ptrdiff_t,
				class Pointer = T*,
				class Reference = T& > class iterator {
		
	 public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};

	//за ненадобностью удалить
	template < class T, class Dist, class Ptr, class Ref >
	class OutIt : public iterator< output_iterator_tag,
								void, void, void, void > { };

	template<class Iter>
	class iterator_traits {
	 public:
		typedef typename Iter::iterator_category	iterator_category ;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	};
	
	template<class T>
	class iterator_traits<T*> {
	 public:
		typedef random_access_iterator_tag	iterator_category;
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef T*							pointer;
		typedef T&							reference;
	};

	template<class T>
	class iterator_traits<const T*> {
	 public:
		typedef random_access_iterator_tag	iterator_category;
		typedef const T						value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef const T*					pointer;
		typedef const T&					reference;
	};

	//шаблонные функции, которые могут быть использованы вместо полей класса iterator_traits
	//iterator_traits<It>::iterator_category
	template < class Cat, class T, class Dist >  
	Cat Iter_cat(const iterator<Cat, T, Dist>& ) {
		Cat x;
		return x;
	};

	template < class T >
	random_access_iterator_tag Iter_cat(const T* ) {
		random_access_iterator_tag x;
		return x;
	};

	//iterator_traits<It>::value_type
	template < class Cat, class T, class Dist, class Ptr, class Ref >
	T* Val_type(iterator <Cat, T, Dist, Ptr, Ref> ) {
		return 0;
	};

	template < class T >
	T* Val_type(const T* ) {
		return 0;
	};

	//iterator_traits<It>::difference_type
	template < class Cat, class T, class Dist, class Ptr, class Ref >
	Dist* Dist_type(iterator <Cat, T, Dist, Ptr, Ref> ) {
		return 0;
	};

	template < class T >
	ptrdiff_t* Dist_type(const T* ) {
		return 0;
	};

	//inline namespace for encapsulation func *_imlp
	namespace {
		template < class InIt, class Dist = ptrdiff_t >
		void advance_impl(InIt& iter, Dist n, std::input_iterator_tag) { //РАБОТАЕТ ТОЛЬКО С STD!!!!!!!!!!
			cout << "it is InIt" << endl;
			for(int i = 0; i < n; i++) {
				++iter;
			}
		}

		template < class InIt, class Dist = ptrdiff_t >
		void advance_impl(InIt& iter, Dist n, ft::random_access_iterator_tag) {
			cout << "it is RanIt" << endl;
			iter += n;
		}


		template < class InIt >
		typename iterator_traits<InIt>::difference_type
		distance_impl(InIt& first, InIt& last, std::input_iterator_tag) {
			cout << "impl common" << endl;
			typename iterator_traits<InIt>::difference_type n;
			InIt tmp = first;
			for(n = 0; tmp != last; n++) {
				++tmp;
			}
			return n; 
		};

		template < class InIt >
		typename iterator_traits<InIt>::difference_type
		distance_impl(InIt& first, InIt& last, ft::random_access_iterator_tag) {
			cout << "impl ran_it" << endl;
			return last - first;
		}
	};
	
	template < class InIt, class Dist = ptrdiff_t >
	void advance(InIt& iter, Dist n) {
		advance_impl(iter, n, typename std::iterator_traits <InIt>::iterator_category());
	}

	template < class InIt >
	typename iterator_traits<InIt>::difference_type
	distance(InIt& first, InIt& last) {
		return distance_impl(first, last, typename ft::iterator_traits<InIt>::iterator_category()); 
	}

	
};

#endif	//ITERATOR_HPP
