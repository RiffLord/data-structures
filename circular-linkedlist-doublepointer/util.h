#ifndef UTIL_H
#define UTIL_H

#include "list.cpp"

template<typename T>
list<T> merge(list<T>& l1, list<T>& l2) {
	list<T> merged;
	typename list<T>::position p1 = l1.first();
	typename list<T>::position p2 = l2.first();
	typename list<T>::position p3 = merged.first();
	
	//	Iterates through the two lists adding the smaller item to merged
	while (!l1.endOfList(p1) && !l2.endOfList(p2)) {
		if (l1.read(p1) < l2.read(p2)) {
			merged.insert(l1.read(p1), p3);
			p1 = l1.next(p1);
		} else {
			merged.insert(l2.read(p2), p3);
			p2 = l2.next(p2);
		}
		p3 = merged.next(p3);
	}
	
	//	Adds any remaining items from l1 and l2 to merged.
	//	These items are in ascending order.
	while (!l1.endOfList(p1)) {
		merged.insert(l1.read(p1), p3);
		p1 = l1.next(p1);
		p3 = merged.next(p3);
	}
	
	while (!l2.endOfList(p2)) {
		merged.insert(l2.read(p2), p3);
		p2 = l2.next(p2);
		p3 = merged.next(p3);
	}
	
	return merged;
}

#endif // !UTIL_H
