#include <iostream>
#include <vector>
#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value){
    Node* root { new Node {value, nullptr, nullptr}};
    return root;
}

bool Node::is_leaf() const{
    if (left == nullptr && right == nullptr){
        return true;
    }
    return false;
}

void Node::insert(int valueToInsert){
    Node* leaf{create_node(valueToInsert)};
    if (valueToInsert<value){
        if(left==nullptr){
            left=leaf;
        }
        else{
            left->insert(valueToInsert);
        }
    }
    else{
        if(right==nullptr){
            right=leaf;
        }
        else{
            right->insert(valueToInsert);
        }
    }
}

// int Node::height(int count)const{
//     if(!is_leaf()){
//         if(left!=nullptr){
//             return left->height(count+1);
//         }
//         if(right!=nullptr){
//             return right->height(count+1);
//         }   
//     }
//     return count;
    
// }
// int Node::height()const{
//     return height(1);
// }

int Node::height()const{
    if (is_leaf()){
        return 1;
    }
    else{
        int left_height {0};
        int right_height {0};
        if(left!=nullptr){
            left_height = left->height();
        }
        if(right!=nullptr){
            right_height = right->height();
        }
        return 1 + std::max(left_height, right_height);
    }  
}

void Node::delete_childs(){
    if(!is_leaf()){
        if(left!=nullptr){
            left->delete_childs();
            delete left;
            left = nullptr;
        }
        if(right!=nullptr){
            right->delete_childs();
            delete right;
            right = nullptr;
        }   
    }
}

void Node::display_infix() const{
    if (left != nullptr){
        left -> display_infix();
    }
    std::cout << value << " ; ";
    if (right != nullptr){
        right -> display_infix();
    }
}

std::vector<Node const*> Node::prefix() const{
    std::vector<Node const*> prefixes {this};
    if (left != nullptr){
        std::vector<Node const*> prefixe_left {left -> prefix()};
        prefixes.insert(prefixes.end(), prefixe_left.begin(), prefixe_left.end());
    }
    if (right != nullptr){
        std::vector<Node const*> prefixe_right {right -> prefix()};
        prefixes.insert(prefixes.end(), prefixe_right.begin(), prefixe_right.end());
    }
    return prefixes;
}

std::vector<Node const*> Node::postfix() const{
    std::vector<Node const*> postfixes {};
    if (left != nullptr){
        std::vector<Node const*> postfixe_left {left -> postfix()};
        postfixes.insert(postfixes.end(), postfixe_left.begin(), postfixe_left.end());
    }
    if (right != nullptr){
        std::vector<Node const*> postfixe_right {right -> postfix()};
        postfixes.insert(postfixes.end(), postfixe_right.begin(), postfixe_right.end());
    }
    postfixes.push_back(this);
    return postfixes;
}

void display_vec(std::vector<Node const*> vec){
    for (auto i : vec){
        std::cout << i->value << " ; ";
    }
    std::cout << std::endl;
}

Node*& most_left(Node*& node){
    if (node -> left != nullptr){
        return most_left(node -> left);
    }
    return node;
}

bool remove(Node*& node, int value){
    if (node==nullptr) {
        return false;
    }
    if (value < node->value){
        return remove(node->left,value);
    }
    else if (value > node->value){
        return remove(node->right,value);
    }
    else {
        if (value == node->value && node->is_leaf()) {
            delete node;
            node = nullptr;
            return true;
        }
        else if (value == node->value && node->right==nullptr) {
            node = node->left;
            delete node->left;
            node->left = nullptr;
            return true;
        }
        else if (value == node->value && node->left==nullptr) {
            node = node->right;
            delete node->right;
            node->right = nullptr;
            return true;
        }
        else if (value == node->value){
            auto& remplace {most_left(node->right)};
            node->value = remplace->value;
            remove(node->right, remplace->value);
            return true;
        }
        else{ return false;}
    } 
}

void delete_tree(Node* node){
    node->delete_childs();
    delete node;
    node=nullptr;
}

int Node::min() const{
    if (left != nullptr){
        return left->min();
    }
    return value;
}
int Node::max() const{
    if (right != nullptr){
        return right->max();
    }
    return value;
}