/**
 * @file node.cpp
 * @author  Bruno Pezer (bruno.pezer@tutanota.com)
 * @brief   Node implementation file for use in various pointer-based data structures
 * @version 1.0
 * @date    2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "node.h"

Node::Node(int d) { data = d; }

Node::Node(const Node &rval) { data = rval.data; }

void Node::setData(int d) { data = d; }

int Node::getData() const { return data; }

bool Node::operator==(const Node &rval) const { return data == rval.data; }

bool Node::operator!=(const Node &rval) const { return !(*this == rval); }
