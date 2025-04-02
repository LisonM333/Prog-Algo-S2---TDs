#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> array_inv {9, 8, 7, 6, 5, 4, 3, 2, 1};

void display(std::vector<int> array){
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

void bubble_sort(std::vector<int> & vec){
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

int main(){
    // verif_tri(array);
    // verif_tri(array_inv);
    // std::cout << std::endl;
    
    bubble_sort(array);
    verif_tri(array);
    bubble_sort(array_inv);
    verif_tri(array_inv);
    std::cout << std::endl;

    array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    selection_sort(array);
    verif_tri(array);
    array_inv = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    selection_sort(array_inv);
    verif_tri(array_inv);
    std::cout << std::endl;

    return 0;
}