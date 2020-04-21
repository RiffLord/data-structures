#include "node.hpp"

node::node() {}

node::node(data_type d) { item = d; }

node::~node() {}

void node::setItem(data_type d) { item = d; }

data_type node::getItem() const { return item; }

bool node::operator==(node& n) { return getItem() == n.getItem(); }

std::ostream& operator<<(std::ostream& out, const node& n) { return out << n.getItem(); }