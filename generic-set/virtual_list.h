#ifndef VIRTUAL_LIST_H
#define VIRTUAL_LIST_H

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

//	Abstract class representing a list
template<class T, class P>
class virtual_list {
public:
	typedef T data_type;
	typedef P position;
	
	//	Operators
	virtual void init() = 0;
	virtual bool isEmpty() const = 0;
	virtual data_type read(position) const = 0;
	virtual void write(const data_type&, position) = 0;
	virtual position first() const = 0;
	virtual bool end(position) const = 0;
	virtual position next(position) const = 0;
	virtual position previous(position) const = 0;
	virtual void insert(const data_type&, position) = 0;
	virtual void remove(position) = 0;
	
	//	Additional functions
	virtual int size() const = 0;
	virtual void clear() = 0;
	
	//	Output operator overload. If the return type is not primitive
	//	the operator must be overloaded for it too.
	friend ostream& operator<<(ostream& out, const virtual_list<T, P>& l) {
		typename virtual_list<T, P>::position p = l.first();
		out << '[';
		while (!l.end(p)) {
			if (p != l.first())
				out << ", " << l.read(p);
			else
				out << l.read(p);
			
			p = l.next(p);
		}
		out << ']' << endl;
		return out;
	}
};

#endif // !VIRTUAL_LIST_H