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


// exos 2.1
enum class Operator { ADD, SUB, MUL, DIV, PUI};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};
Token make_token(float value){
    Token token{};
    token.type = TokenType::OPERAND;
    token.value = value;
    return token;
}
Token make_token(Operator op){
    Token token{};
    token.type = TokenType::OPERATOR;
    token.op = op;
    return token;
}

// exos 2.2
std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> vector{};
    for (std::string mot : words){
        Token token{};
        if (is_floating(mot)){
            float value{std::stof(mot)};
            token = make_token(value);
        }
        else{
            Operator op{};
            if (mot == "+"){
                op=Operator::ADD;
            }            
            if (mot == "-"){
                op=Operator::SUB;
            }
            if (mot == "*"){
                op=Operator::MUL;
            }
            if (mot == "/"){
                op=Operator::DIV;
            }
            if (mot == "^"){
                op=Operator::PUI;
            }
            token = make_token(op);
        }
        vector.push_back(token); 
    }
    return vector;
}

//exos 2.3
float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> pile{};
    for (Token element : tokens){
        if (element.type == TokenType::OPERAND){
            float number{element.value};
            pile.push(number);
        }
        else{
            float number2{pile.top()};
            pile.pop();
            float number1{pile.top()};
            pile.pop();
            float resultat{};
            if (element.op == Operator::ADD){
                resultat= number1+number2;
            }            
            if (element.op == Operator::SUB){
                resultat= number1-number2;
            }
            if (element.op == Operator::MUL){
                resultat= number1*number2;
            }
            if (element.op == Operator::DIV){
                resultat= number1/number2;
            } 
            if (element.op == Operator::PUI){
                resultat= pow(number1,number2);
            }
            pile.push(resultat);
        }
    }
    return pile.top();
}



int main(){
    std::cout << npi_evaluate(tokenize(split_string(expression())));
    return 0;
}