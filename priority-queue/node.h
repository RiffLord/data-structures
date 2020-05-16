#ifndef NODE_H
#define NODE_H

template<class T>
class node {
public:
    node() { priority = -1; }
    ~node() {}
    void setItem(T t) { data = t; }
    T getItem() const { return data; }
    void setPriority(int p) { priority = p; }
    int getPriority() const { return priority; }
private:
    T data;
    int priority;
};

#endif // NODE_H