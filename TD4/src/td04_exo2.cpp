#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <random>

auto const is_space = [](char letter){ return letter == ' '; };

int number_letter_first(std::string const& sentence){
    return (std::distance(sentence.begin(), std::find_if(sentence.begin(),sentence.end(),is_space)));
}

std::vector<std::string> split_string(std::string const& str){
    int i{0};
    int j{0};
    std::vector<std::string> sentence_vector {};
    while (j<str.size()){
        i=j;
        int taille_mot{static_cast<int>(std::distance(str.begin()+i, std::find_if(str.begin()+i,str.end(),is_space)))};
        j+=taille_mot;
        std::string mot{str.begin()+i, str.begin()+j};
        sentence_vector.push_back(mot);
        j++;
    }
    return sentence_vector;
}

int main(){
    std::cout << "Donnez une phrase : ";
    std::string sentence{};
    std::getline(std::cin, sentence);
    std::cout << "Le premier mot contient " << number_letter_first(sentence) << " lettres."<< std::endl;

    std::vector<std::string> vector{split_string(sentence)};
    for (auto it{vector.begin()};it!=vector.end();it++){
        std::cout << *it << std::endl;  
    }
    // std::size_t taille{vector.size()};
    // for (int it{0};it<taille;it++){
    //     std::cout << vector[it] <<std::endl;  
    // }
    return 0;
}