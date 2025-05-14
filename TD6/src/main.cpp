#include <iostream>
#include "node.hpp"

// int main(){
//     Node* test{create_node(5)};
//     std::cout << std::boolalpha;
//     std::cout << test->is_leaf() << std::endl;
//     test->insert(3);
//     std::cout << test->is_leaf() << std::endl;
//     std::cout << test->left->is_leaf() << std::endl;
//     test->insert(7);
//     test->insert(2);
    
//     // test->insert (1);
//     // test->insert(4);
//     // test->insert(6);
//     // test->insert(8);
//     // test->insert(9);
    

//     pretty_print_left_right((*test));
//     std::cout << "liste en ordre infixe : ";
//     test ->display_infix();
//     std::cout << std::endl;

//     auto vec_test {test->prefix()};
//     std::cout << "liste en ordre prefixe : ";
//     display_vec(vec_test);
//     auto vec_test2 {test->postfix()};
//     std::cout << "liste en ordre postfixe : ";
//     display_vec(vec_test2);

//     int hauteur {test->height()};
//     std::cout << "la hauteur : " << hauteur << std::endl;

//     auto left {most_left(test)};
//     std::cout << "le plus a gauche : " << left->value << std::endl;

//     bool rem {remove(test, 5)};
//     pretty_print_left_right((*test));
//     std::cout << "la valeur a ete supprimee : "<< rem << std::endl;

//     int min {test->min()};
//     int max {test->max()};
//     std::cout << "la plus petite valeur est : " << min << " | la plus grande valeur est : " << max << std::endl;

//     delete_tree(test);

//     return 0;
// }

int main(){
    Node* arbre{create_node(5)};
    arbre->insert(3);
    arbre->insert(7);
    arbre->insert(2);
    arbre->insert(4);
    arbre->insert(6);
    arbre->insert(8);
    arbre->insert(1);
    arbre->insert(9);
    arbre->insert(0);

    //pretty_print_left_right(*arbre);

    std::cout << "liste en ordre infixe : ";
    arbre->display_infix();
    std::cout << std::endl;
    int min {arbre->min()};
    int max {arbre->max()};
    std::cout << "la plus petite valeur est : " << min << " | la plus grande valeur est : " << max << std::endl;

    auto prefixe {arbre->prefix()};
    int somme{0};
    for (auto i : prefixe){somme+=i->value;}
    std::cout << "la somme des noeuds est : " << somme << std::endl;

    int hauteur{arbre->height()};
    std::cout << "la hauteur de l'arbre est : " << hauteur << std::endl;

    delete_tree(arbre);

    return 0;
}


