#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <functional>
#include <random>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "Card.hpp"


std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

bool operator==(Card A, Card B){
    if (A.kind == B.kind && A.value==B.value){
        return true;
    }
    return false;
}

size_t hash_perso (Card card){
    size_t hash{0};
    auto kind {kind_to_string.find(card.kind)};
    auto value {value_to_string.find(card.value)};
    hash = static_cast<size_t>((*value).second[0]) * static_cast<size_t>((*value).second[1]);
    hash *= static_cast<size_t>((*kind).second[0]);
    return hash%2048;
}

// std::vector<size_t> hash_paquet (std::vector<Card> paquet){
//     std::vector<size_t> vec {};
//     for (auto c : paquet){
//         vec.push_back(hash_perso(c));
//     }
//     return vec;
// }
// bool verif_repeat(std::vector<size_t> vec){
//     size_t taille {vec.size()};
//     for (int i{0}; i<taille; i++){
//         for (int j{i+1}; j<taille; j++){
//             if (vec[i]==vec[j]){
//                 std::cout << vec[i];
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// void display_verif_paquet (std::vector<Card> paquet){
//     // for (int i{0}; i<52; i++){
//     //     auto v {value_to_string.find(paquet[i].value)};
//     //     auto k {kind_to_string.find(paquet[i].kind)};
//     //     std::cout << (*v).second << " of " << (*k).second << " / ";
//     // }
//     for (int i{0}; i<52; i++){
//         std::cout << hash_perso(paquet[i]) << "/";
//     }
//     std::cout << std::boolalpha;
//     std::cout << verif_repeat(hash_paquet(paquet));
// }
// std::vector<Card> paquet(){
//     std::vector<Card> vec{};
//     for (auto k : kind_of_card){
//         for(auto v : value_of_card){
//             Card new_card {};
//             new_card.kind=k;
//             new_card.value=v;
//             vec.push_back(new_card);
//         }
//     }
//     return vec;
// }
std::vector<size_t> hash_paquet (std::vector<Card> paquet){
    std::vector<size_t> vec {};
    for (auto c : paquet){
        vec.push_back(c.hash());
    }
    return vec;
}
void display_verif_paquet (std::vector<Card> paquet){
    for (int i{0}; i<52; i++){
        std::cout << paquet[i].hash() << "/ ";
    }
    std::cout << std::endl;
}
std::vector<Card> paquet(){
    std::vector<Card> vec{};
    for (auto k : kind_of_card){
        for(auto v : value_of_card){
            Card new_card {};
            new_card.kind=k;
            new_card.value=v;
            vec.push_back(new_card);
        }
    }
    return vec;
}


size_t Card::hash() const{
    size_t hash{static_cast<size_t>(13*static_cast<int>(kind)+ static_cast<int>(value))};
    return hash;
}

std::unordered_map<Card, int> table_de_comptage (std::vector<Card> const& cartes){
    std::unordered_map<Card, int> table{};
    for (auto c : cartes){
        table[c] += 1;
        }
    return table;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

void display_comptage(std::unordered_map<Card, int> cartes_comptees){
    for(auto i : cartes_comptees){
        std::cout << "There is/are " << i.second << " of " << card_name(i.first) << ";" << std::endl;
    }
}

int main(){
    display_verif_paquet (paquet());
    display_comptage(table_de_comptage(get_cards(100)));

    return 0;
}