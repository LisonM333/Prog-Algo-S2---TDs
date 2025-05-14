#pragma once
#include <iostream>
#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;

    void insert(int value);

    // int height(int count) const;
    int height() const;

    void delete_childs();

    void display_infix() const;

    std::vector<Node const*> prefix() const;

    std::vector<Node const*> postfix() const;

    int min() const;
    
    int max() const;
};

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);

Node* create_node(int value);

Node*& most_left(Node*& node);

bool remove(Node*& node, int value);

void display_vec (std::vector<Node const*> vec);

void delete_tree(Node* node);