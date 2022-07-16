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

         /*destructor*/
         ~set() { }

        Allocator get_allocator() const {  }

        iterator begin() {
            return _tree.begin();
        }
        const_iterator begin() const {
            return _tree.begin();
        }

        iterator end() {
            return _tree.end();
        }

        const_iterator end() const {
            return _tree.end();
        }

        reverse_iterator rbegin() {
            return _tree.rbegin();
        }

        const_reverse_iterator rbegin() const {
            return _tree.rbegin();
        }

        reverse_iterator rend() {
            return _tree.rend();
        }

        const_reverse_iterator rend() const {
            return _tree.rend();
        }

        /* capacity */
        bool empty() const {
            return _tree.empty();
        }

        size_t size() const {
            return _tree.size();
        }

        size_t max_size() const {
            return _tree.max_size();
        }

        /*modify*/
         void clear() {
            _tree.clear_tree();
         }

        // pair<iterator, bool> insert( const value_type& value );
        // template< class InputIt >
        //void insert( InputIt first, InputIt last );

        // iterator erase(iterator pos) ;
        // iterator erase(iterator first, iterator last) ;
//        size_type erase( const Key& key );

        // void swap(vector& other)

        /* lookup */
         size_type count( const Key& key ) const {
            return _tree.count(key);
        }

        iterator find( const Key& key ) {
            return _tree.find(key);
        }

        const_iterator find( const Key& key ) const {
            return _tree.find(key);
        }

        pair<iterator,iterator> equal_range( const Key& key ) {
            return _tree.equal_range(key);
        }
        pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
            return _tree.equal_range(key);
        }

        iterator lower_bound( const Key& key ) {
            return _tree.lower_bound(key);
        }

        const_iterator lower_bound( const Key& key ) const {
            return _tree.lower_bound(key);
        }

        iterator upper_bound( const Key& key ) {
            return _tree.upper_bound(key);
        }

        const_iterator upper_bound( const Key& key ) const {
            return _tree.upper_bound(key);
        }

        /* observers */
         key_compare key_comp() const {
             return _compare;
         }
         set::value_compare value_comp() const {
             return _tree.value_comp();
         }



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
