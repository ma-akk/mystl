//
// Created by maakk on 14.07.22.
//

#ifndef SET_HPP
#define SET_HPP

#include "utils/utils.hpp"
#include "iterators/tree_it.hpp"
#include "utils/rb_tree.hpp"

namespace ft {

    template<class Key, class Compare = std::less<Key>,
            class Allocator = std::allocator<Key>>
    class set {
     public:
        typedef Key						    		key_type;
        typedef Key             				    value_type;
        typedef size_t			        			size_type;
        typedef std::ptrdiff_t			    		difference_type;
        typedef Compare						    	key_compare;
        typedef Compare						        value_compare;
        typedef Allocator	                        allocator_type;
        typedef typename Allocator::pointer	        pointer;
        typedef value_type&						    reference;
        typedef typename Allocator::const_pointer   const_pointer;
        typedef const value_type&				    const_reference;
        typedef tree_it< value_type >				iterator;
        typedef tree_it< const value_type >		    const_iterator;
        typedef reverse_it< iterator >		    	reverse_iterator;
        typedef reverse_it< const iterator >	    const_reverse_iterator;
        typedef rb_tree<value_type, key_compare, Allocator> set_tree;

        /*constructors*/
//		set() {	}

        // explicit set( const Compare& comp,
        // 			const Allocator& alloc = Allocator() );

        // template< class InputIt >
        // set( InputIt first, InputIt last,
        // 	const Compare& comp = Compare(),
        // 	const Allocator& alloc = Allocator() );

        // set( const set& other );

        // set& operator=( const set& other );

        // /*destructor*/
        // ~set() { }

        Allocator get_allocator() const {  }

        // iterator begin();
        // const_iterator begin() const;
        // iterator end();
        // const_iterator end() const;
        // reverse_iterator rbegin();
        // const_reverse_iterator rbegin() const;
        // reverse_iterator rend();
        // const_reverse_iterator rend() const;

        /* capacity */
        bool empty() const { }

        size_t size() const { }

        size_t max_size() const { }

        /*modify*/
        // void clear() { }

        // pair<iterator, bool> insert( const value_type& value );
        // template< class InputIt >
        //void insert( InputIt first, InputIt last );

        // iterator erase(iterator pos) ;
        // iterator erase(iterator first, iterator last) ;
//        size_type erase( const Key& key );

        // void swap(vector& other)

        /* lookup */
        // size_type count( const Key& key ) const;
        // iterator find( const Key& key );
        // const_iterator find( const Key& key ) const;
        // pair<iterator,iterator> equal_range( const Key& key );
        // pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
        // iterator lower_bound( const Key& key );
        // const_iterator lower_bound( const Key& key ) const;
        // iterator upper_bound( const Key& key );
        // const_iterator upper_bound( const Key& key ) const;

        /* observers */
        // key_compare key_comp() const;
        // set::value_compare value_comp() const;



    private:
        set_tree _tree;
        Allocator _alloc;
        Compare _compare;
    };

//    template< class Key, class Compare, class Alloc >
//    bool operator==( const set<Key,Compare,Alloc>& lhs,
//                     const set<Key,Compare,Alloc>& rhs );

//    template< class Key, class Compare, class Alloc >
//    bool operator!=( const set<Key,Compare,Alloc>& lhs,
//                     const set<Key,Compare,Alloc>& rhs );
//
//    template< class Key, class Compare, class Alloc >
//    bool operator<( const set<Key,Compare,Alloc>& lhs,
//                    const set<Key,Compare,Alloc>& rhs );
//
//    template< class Key, class Compare, class Alloc >
//    bool operator<=( const set<Key,Compare,Alloc>& lhs,
//                     const set<Key,Compare,Alloc>& rhs );
//
//    template< class Key, class Compare, class Alloc >
//    bool operator>( const set<Key,Compare,Alloc>& lhs,
//                    const set<Key,Compare,Alloc>& rhs );
//
//    template< class Key, class Compare, class Alloc >
//    bool operator>=( const set<Key,Compare,Alloc>& lhs,
//                     const set<Key,Compare,Alloc>& rhs );
//
//    template< class Key, class Compare, class Alloc >
//    void swap( set<Key,Compare,Alloc>& lhs,
//               set<Key,Compare,Alloc>& rhs );
}

#endif //SET_HPP
