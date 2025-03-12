#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>
#include <cmath>

//exos 1.1
std::string expression(){
    std::string calcul{};
    std::cout << "Quelle est votre expression arithemique ?" << std::endl;
    std::getline(std::cin, calcul);
    return calcul;
}

//exos 1.2 (fonction fournie)
std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

//exos 1.3
bool is_floating(std::string const& s){
    for (char c : s) {
        if (!(std::isdigit(c))){
            return false;
        }
    }
    return true;
}

//exos 1.4
float npi_evaluate(std::vector<std::string> const& tokens){
    std::stack<float> pile{};
    for (std::string element : tokens){
        if (is_floating(element)){
            float number{std::stof(element)};
            pile.push(number);
        }
        else{
            float number2{pile.top()};
            pile.pop();
            float number1{pile.top()};
            pile.pop();
            float resultat{};
            if (element == "+"){
                resultat= number1+number2;
            }            
            if (element == "-"){
                resultat= number1-number2;
            }
            if (element == "*"){
                resultat= number1*number2;
            }
            if (element == "/"){
                resultat= number1/number2;
            } 
            if (element == "^"){
                resultat= pow(number1,number2);
            }
            pile.push(resultat);
        }
    }
    return pile.top();
}



int main(){
    std::vector<std::string> separe{split_string(expression())};
    std::cout << npi_evaluate(separe);
    return 0;
}