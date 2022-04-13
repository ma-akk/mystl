#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;


namespace ft {

	struct input_iterator_tag { };

	struct output_iterator_tag { };

	struct forward_iterator_tag : public input_iterator_tag { };

	struct bidirectional_iterator_tag : public forward_iterator_tag { };

	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

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
	}

	template < class T >
	random_access_iterator_tag Iter_cat(const T* ) {
		random_access_iterator_tag x;
		return x;
	}

	//iterator_traits<It>::value_type
	template < class Cat, class T, class Dist, class Ptr, class Ref >
	T* Val_type(iterator <Cat, T, Dist, Ptr, Ref> ) {
		return 0;
	}

	template < class T >
	T* Val_type(const T* ) {
		return 0;
	}

	//iterator_traits<It>::difference_type
	template < class Cat, class T, class Dist, class Ptr, class Ref >
	Dist* Dist_type(iterator <Cat, T, Dist, Ptr, Ref> ) {
		return 0;
	}

	template < class T >
	ptrdiff_t* Dist_type(const T* ) {
		return 0;
	}

	//inline namespace for encapsulation func *_imlp
	namespace {
		template < class InIt, class Dist = ptrdiff_t, class Cat >
		void advance_impl(InIt& iter, Dist n, Cat iter_cat) {
			cout << "it is InIt" << endl;
			for(int i = 0; i < n; i++) {
				++iter;
			}
		}

		template < class InIt, class Dist = ptrdiff_t >
		void advance_impl(InIt& iter, Dist n, random_access_iterator_tag) {
			cout << "it is RanIt" << endl;
			iter += n;
		}

		template < class InIt, class Dist, class Cat >
		Dist distance_impl(InIt& first, InIt& last, Cat iter_cat) {
			Dist n;
			for(n = 0; first != last; n++) {
				++first;
			}
			return n;
		}

		template < class InIt, class Dist = ptrdiff_t >
		Dist distance_impl(InIt& first, InIt& last, random_access_iterator_tag) {
			Dist n;
			n = Dist(last - first);
			return n;
		}
	};
	
	template < class InIt, class Dist = ptrdiff_t >
	void advance(InIt& iter, Dist n) {
		advance_impl(iter, n, typename iterator_traits <InIt>::iterator_category());
	}

	template < class InIt >
	typename iterator_traits<InIt>::difference_type
	distance(InIt& first, InIt& last) {
		distance_impl(first, last, typename iterator_traits <InIt>::iterator_category()); 
	}
};

#endif	//ITERATOR_HPP
