#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <random>

bool verif_palindrome(std::string palindrome){
    int taille (palindrome.size()/2);
    return std::equal(palindrome.begin()+taille,palindrome.end(),palindrome.rbegin()+taille,palindrome.rend());
    
}

int main(){
    std::cout << "Donnez un palindrome : ";
    std::string palindrome{};
    std::cin >> palindrome;
    std::cout << std::boolalpha;
    std::cout << "C'est un palindrome ? : " << verif_palindrome(palindrome) <<std::endl;
    return 0;
}