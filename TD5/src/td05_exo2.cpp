#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <string>
#include <functional>
#include <random>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <iomanip>

enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};
const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};
const std::unordered_map<Insect, std::string> insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};
const std::vector<int> expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};
std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    const unsigned int seed = std::random_device{}()) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        //If we have already seen the same insect, increment the count on the last observation
        auto& previous_observation { observations.back() };
        if(previous_observation.first == random_insect) {
            previous_observation.second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

void display(std::vector<float> vec){
    for (auto f : vec){
        std::cout << f << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void display(std::vector<int> vec){
    for (auto f : vec){
        std::cout << f << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void display(std::unordered_map<Insect, int> table){
    for (auto p : table){
        auto nom {insect_to_string.find(p.first)};
        std::cout << "There are " << p.second << " " << (*nom).second << "s." << std::endl;
    }
    std::cout << std::endl;
}

std::vector<float> operator/(std::vector<float> const& vec, float const& a) {
    std::vector<float> retour{};
    for (float f : vec){
        retour.push_back(f/a);
    }
    return retour;
}


std::vector<float> probabilities_from_count(std::vector<int> const& counts){
    std::vector<float> probas{};
    float nb_count {0.};
    for (int c : counts){
        nb_count+= static_cast<float>(c);
        probas.push_back(static_cast<float>(c));
    }
    return operator/(probas,nb_count);
}

std::unordered_map<Insect, int> table_de_comptage (std::vector<std::pair<Insect, int>> const& vec){
    std::unordered_map<Insect, int> table{};
    for (std::pair<Insect, int> p : vec){
        table[p.first] += p.second;
        }
    return table;
}

std::vector<int> count_from_hash(std::unordered_map<Insect,int> table){
    std::vector<int> vec{};
    for (auto i : insect_values){
        vec.push_back(table[i]);
    }
    return vec;
}

std::string comparaison (float a, float b){
    std::string eval{"OK"};
    a*= 100;
    b*= 100;
    if (a-b > 1. || a-b < -1.){
        eval="BAD";
    }
    return eval;
}

void comparaison (std::vector<float> a, std::vector<float> b){
    std::cout << "Probabilities of observed insects vs expected probabilities :" << std::endl;
    for (int i{0}; i<11; i++){
        auto nom {insect_to_string.find(insect_values[i])};
        std::cout << (*nom).second << " : " << a[i] << " vs " << b[i] << " " << comparaison(a[i],b[i]) << std::endl;
    }
}

int main(){
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Les probabilites expectees : ";
    auto proba_expect {probabilities_from_count(expected_insect_counts)};
    display (proba_expect);
    std::vector<std::pair<Insect, int>> vecteur {get_insect_observations(1000,probabilities_from_count(expected_insect_counts))};
    std::unordered_map<Insect, int> comptage {table_de_comptage(vecteur)};
    std::cout << "Le comptage obtenu : ";
    display (comptage);
    //display (count_from_hash(comptage)); //verif
    std::cout << "Les probabilites obtenues : ";
    auto proba_observ {probabilities_from_count(count_from_hash(comptage))};
    display (proba_observ);
    std::cout << "Comparaisons des probabilites : ";
    comparaison(proba_observ,proba_expect);

    return 0;
}