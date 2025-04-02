#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "ScopedTimer.hpp"

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}
bool is_sorted(std::vector<float> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

std::vector<int> generate_random_vector_int(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}
std::vector<float> generate_random_vector_float(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

void display(std::vector<int> array){
    std::size_t const n {array.size()};
    for (int i {0}; i<n-1; i++){
        std::cout << array[i] << ", ";
    }
    std::cout <<array[n-1] << std::endl;
}
void display(std::vector<float> array){
    std::size_t const n {array.size()};
    for (int i {0}; i<n-1; i++){
        std::cout << array[i] << ", ";
    }
    std::cout <<array[n-1] << std::endl;
}

void verif_tri(std::vector<int> array){
    display(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }
}
void verif_tri(std::vector<float> array){
    display(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }
}



void bubble_sort(std::vector<int> & vec){
    ScopedTimer timer("chrono_bubble_sort");
    std::size_t const n {vec.size()};
    for (int j {0}; j<n-1;j++){
        bool tri_fini {true};
        for (int i {0}; i<n-j-1; i++){
            if (vec[i]>vec[i+1]){
                int sauvegarde {vec[i]};
                vec[i]= vec[i+1];
                vec[i+1]= sauvegarde;
                tri_fini = false;
            }
        }
        if (tri_fini){
            break;
        }
    }
      
}

void selection_sort(std::vector<int> & vec){
    ScopedTimer timer("chrono_selection_sort");
    std::size_t const n {vec.size()};
    for (int j{0}; j<n-1; j++){
        int val_min{j};
        for (int i{j+1}; i<n; i++){
            if (vec[val_min] > vec[i]){
                val_min = i;
            }          
        }
        int sauvegarde {vec[j]};
        vec[j]= vec[val_min];
        vec[val_min]= sauvegarde;
    }
}

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot){
    size_t index_max {right +1};
    for (size_t i{right}; i>left; i--){
        if (vec[i]>vec[pivot]){
            index_max--;
            std::swap(vec[i],vec[index_max]);
        }
    }
    std::swap(vec[index_max-1],vec[pivot]);
    return index_max-1;
}
void quick_sort(std::vector<float> & vec, size_t const left, size_t const right){
    if (left<right){
        size_t pivot{left};
        size_t nouveau_pivot{quick_sort_partition(vec,left,right,pivot)};
        quick_sort(vec, nouveau_pivot+1, right);
        quick_sort(vec, left, nouveau_pivot);
    }
}
void quick_sort(std::vector<float> & vec) {
    ScopedTimer timer("chrono_quick_sort");
    quick_sort(vec, 0, vec.size() - 1);
}

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right){
    std::vector<float> vec1 (vec.begin()+left, vec.begin()+middle);
    std::vector<float> vec2 (vec.begin()+middle, vec.begin()+right+1);
    std::size_t const n1 {vec1.size()};
    int compteur1 {0};
    std::size_t const n2 {vec2.size()};
    int compteur2 {0};
    while (compteur1!=n1 && compteur2!=n2){
        if (vec1[compteur1] < vec2[compteur2]){
            vec[left+compteur1+compteur2]=vec1[compteur1];
            compteur1++;
        }
        else{
            vec[left+compteur1+compteur2]=vec2[compteur2];
            compteur2++;
        }
    }
    if (compteur1!=n1){
        while (compteur1!=n1){
            vec[left+compteur1+compteur2]=vec1[compteur1];
            compteur1++;
        }
    }
    else{
        while (compteur2!=n2){
            vec[left+compteur1+compteur2]=vec2[compteur2];
            compteur2++;
        }
    }
}
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right){
    if (left<right){
        std::size_t n{vec.size()};
        size_t middle {(left+right)/2};
        if  (right-left == 1){
            middle++;
        }
        merge_sort(vec, left, middle-1);
        merge_sort(vec, middle, right);
        merge_sort_merge(vec, left, middle, right);
    }
}
void merge_sort(std::vector<float> & vec) {
    {
    ScopedTimer timer("chrono_merge_sort");
    merge_sort(vec, 0, vec.size() - 1);
    }
}



int main(){
    std::vector<int> array_int{generate_random_vector_int(20)};
    std::vector<float> array_float {generate_random_vector_float(20)};
    std::vector<int> copy_int{array_int};
    std::vector<float> copy_float {array_float};
    
    bubble_sort(array_int);
    verif_tri(array_int);
    std::cout << std::endl;

    array_int = copy_int;
    selection_sort(array_int);
    verif_tri(array_int);
    std::cout << std::endl;

    array_float = copy_float;
    merge_sort(array_float);
    verif_tri(array_float);
    std::cout << std::endl;

    array_float = copy_float;
    quick_sort(array_float);
    verif_tri(array_float);
    std::cout << std::endl;

    return 0;
}