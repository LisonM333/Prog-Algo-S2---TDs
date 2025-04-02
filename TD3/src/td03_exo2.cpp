#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<float> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

std::vector<float> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<float> array_inv {9, 8, 7, 6, 5, 4, 3, 2, 1};

void display(std::vector<float> array){
    std::size_t const n {array.size()};
    for (int i {0}; i<n-1; i++){
        std::cout << array[i] << ", ";
    }
    std::cout <<array[n-1] << std::endl;
}

void verif_tri(std::vector<float> array){
    display(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
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
    merge_sort(vec, 0, vec.size() - 1);
}


int main(){
    // verif_tri(array);
    // verif_tri(array_inv);

    // std::vector<float> test {2,1,3,7,5,4};
    // merge_sort(test);
    // quick_sort(test);
    // verif_tri(test);

    array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    merge_sort(array);
    verif_tri(array);
    array_inv = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(array_inv);
    verif_tri(array_inv);
    std::cout << std::endl;

    array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    quick_sort(array);
    verif_tri(array);
    array_inv = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    quick_sort(array_inv);
    verif_tri(array_inv);
    std::cout << std::endl;

    return 0;
}