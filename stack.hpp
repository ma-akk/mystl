#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T> >
class stack {
   public:
    typedef Container container_type;

	explicit stack(const Container& cont = Container()) : c(cont) {}

	~stack() {}

	stack(const stack& value) { *this = &value; }

	stack& operator=(const stack& value) {
		if (this != &value) {
			c = value.c;
		}
		return *this;
	}

	size_t size() const { return c.size(); }

	bool empty() const { return c.empty(); }

	T& top() { return c.back(); }

	const T& top() const { return c.back(); }

	void push(const T& value) { c.push_back(value); }

	void pop() { c.pop_back(); }

   protected:
	Container c;
};
}  // namespace ft

#endif	// STACK_HPP
