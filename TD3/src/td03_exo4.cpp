#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}
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

int search (std::vector<int> vec, int left, int right, int valeur){
    int middle {left + (right-left)/2};
    if (vec[middle]==valeur){
        return middle;
    }
    else if(left==right && vec[left]!=valeur){
        return -1;
    }
    else if(vec[middle]>valeur){
        return search(vec, left, middle-1, valeur);
    }
    else {
       return search(vec, middle+1, right, valeur);
    }
}

int search (std::vector<int> vec, int valeur){
   return search(vec, 0, vec.size()-1, valeur);
}

int main(){
    
    std::vector<std::pair<std::vector<int>,int>> test {
        {{1, 2, 2, 3, 4, 8, 12}, 8},
        {{1, 2, 3, 3, 6, 14, 12, 15}, 15},
        {{2, 2, 3, 4, 5, 8, 12, 15, 16}, 16},
        {{5, 6, 7, 8, 9, 10, 11, 12, 13}, 6},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 10}
    };
    int i{1};
    for (auto p : test){
        std::cout << "Dans la liste " << i << " la valeur "<< p.second << " est a la place : " <<  search(p.first,p.second) <<std::endl;
        i++;
    }

    return 0;
}