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
		typedef const T						reference;
	};

};

#endif	//ITERATOR_HPP
