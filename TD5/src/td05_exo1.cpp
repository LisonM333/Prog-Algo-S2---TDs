#include <iostream>
#include <vector>
#include <cmath>

size_t folding_string_hash(std::string const& s, size_t max){
    size_t hash {0};
    for (char c : s){
        hash += static_cast<size_t>(c);
        hash %= max+1;
    }
    return hash;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash {0};
    size_t i {0};
    for (char  c : s){
        i++;
        hash += static_cast<size_t>(c)*i;
        hash %= max+1;
    }
    return hash;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash {0};
    size_t pi {1};
    for (char  c : s){
        hash += static_cast<size_t>(c)*pi;
        hash %= m+1;
        pi*=p;
    }
    return hash;
}

int main(){
    std::string mot_1 {"test"};
    std::string mot_2 {"tset"};
    std::string mot_3 {"kayak"};

    std::cout << folding_string_hash(mot_1, 1024) << std::endl;
    std::cout << folding_string_hash(mot_2, 1024) << std::endl;
    std::cout << folding_string_hash(mot_3, 1024) << std::endl;
    std::cout << std::endl;

    std::cout << folding_string_ordered_hash(mot_1, 1024) << std::endl;
    std::cout << folding_string_ordered_hash(mot_2, 1024) << std::endl;
    std::cout << folding_string_ordered_hash(mot_3, 1024) << std::endl;
    std::cout << std::endl;

    std::cout << polynomial_rolling_hash(mot_1, 31, 1e9+9) << std::endl;
    std::cout << polynomial_rolling_hash(mot_2, 31, 1e9+9) << std::endl;
    std::cout << polynomial_rolling_hash(mot_3, 31, 1e9+9) << std::endl;
    std::cout << std::endl;


    return 0;
}