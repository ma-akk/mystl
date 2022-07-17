#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

#include "vector.hpp"

namespace ft {
template <class T, class Container = std::vector<T> >
class stack {
   public:
	explicit stack(const Container& cont = Container()) : _cont(cont) {}

	~stack() {}

	stack(const stack& value) { *this = &value; }

	stack& operator=(const stack& value) {
		if (this != &value) {
			_cont = value._cont;
		}
		return *this;
	}

	size_t size() const { return _cont.size(); }

	bool empty() const { return _cont.empty(); }

	T& top() { return _cont.back(); }

	const T& top() const { return _cont.back(); }

	void push(const T& value) { _cont.push_back(value); }

	void pop() { _cont.pop_back(); }

   private:
	Container _cont;
};
}  // namespace ft

#endif	// STACK_HPP
