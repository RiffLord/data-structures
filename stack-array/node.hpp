//	Node definition for use in a stack data structure
#ifndef NODE_H
#define NODE_H

#include <ostream>

typedef int data_type;

class node {
public:
	//	Constructors
	node();
	node(data_type);
	~node();	//	Destructor
	
	//	Operators
	void setItem(data_type);
	data_type getItem() const;
	bool operator==(node&);
private:
	data_type item;
};

//	Output operator overload
std::ostream& operator<<(std::ostream& out, const node& n);

#endif // !NODE_H