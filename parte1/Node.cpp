//
// Created by mauluna52 on 9/03/23.
//

#include "Node.h"

Node::Node() {
    data = 0;
    next = nullptr;
}

Node::Node(int d) {
    this->data = d;
    this->next = nullptr;
}

int Node::getData() const {
    return data;
}

void Node::setData(int d) {
    data = d;
}


