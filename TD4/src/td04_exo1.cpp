#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <random>

std::vector<int> generate_random_vector(){
    std::vector<int> vec{};
    srand(time(nullptr));
    for (int i = 0; i < 20; i++) {
        int num = std::rand() % 101;
        vec.push_back(num);
    }
    return vec;
}


int main(){
    std::vector<int> vec{generate_random_vector()};
    for (auto it{vec.begin()};it!=vec.end();it++){
        std::cout << *it <<" ";  
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Cherchez vous un nombre ? : ";
    int value_to_find{};
    std::cin >> value_to_find;
    auto it { std::find(vec.begin(), vec.end(), value_to_find) };
    if (it != vec.end())
    {
        std::cout << "Ce nombre est dans la liste." << std::endl;
        std::cout << "Il apparait " << std::count(vec.begin(), vec.end(), value_to_find) << " fois dans la liste." << std::endl;
    }
    else
    {
        std::cout << "Ce nombre n'est pas dans la liste." << std::endl;
    }
    std::cout << std::endl;

    std::sort(vec.begin(),vec.end());
    std::cout << "La liste triee est : ";
    for (auto it{vec.begin()};it!=vec.end();it++){
        std::cout << *it <<" ";  
    }
    std::cout << std::endl;
    std::cout << std::endl;

    
    std::cout << "La somme est : " << std::accumulate(vec.begin(),vec.end(), 0) << std::endl;
    std::cout << std::endl;

    return 0;
}