#ifndef BIDIT_HPP
#define BIDIT_HPP

#include <iostream>
#include <string>
#include "iterator.hpp"

namespace ft {

template < class T, class Dist, class Ptr, class Ref >
	class BidIt : public iterator< bidirectional_iterator_tag
									T, Dist, Ptr, Ref > {
		
	};

};

#endif	//BIDIT_HPP