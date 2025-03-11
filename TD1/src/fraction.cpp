#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// void Fraction::display() {
//     std::cout << numerator << "/" << denominator;
// }
std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}

// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }


// // Fraction add(Fraction const& f1, Fraction const& f2) {
// //     Fraction result {
// //         f1.numerator * f2.denominator + f2.numerator * f1.denominator
// //         f1.denominator * f2.denominator
// //     };

// //     return simplify(result);
// // }


// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }



//EXERCICE 3
bool operator==(Fraction const& f1, Fraction const& f2) {
    Fraction F1{simplify(f1)};
    Fraction F2 {simplify (f2)};
    if (F1.numerator==F2.numerator && F1.denominator==F2.denominator){
        return true;
    }
    return false;
}
//autre version
// bool operator==(Fraction const& f1, Fraction const& f2) {
//     if (f1.numerator*f2.denominator==f2.numerator*f1.denominator){
//         return true;}
//     return false;
// }
bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1==f2);  
}



//EXERRCICE 4
bool operator<(Fraction const& f1, Fraction const& f2) {
    if (f1.numerator*f2.denominator<f2.numerator*f1.denominator){
        return true;
    }
    return false;
}
bool operator>(Fraction const& f1, Fraction const& f2) {
    if (!(f1<f2) && f1!=f2){
        return true;
    }
    return false;
}
bool operator<=(Fraction const& f1, Fraction const& f2) {
    if ((f1<f2) || f1==f2){
        return true;
    }
    return false;
}
// bool operator<=(Fraction const& f1, Fraction const& f2) {
//     return !(f1>f2);
// }
bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1<f2);
}



//EXERCICE 5
Fraction& Fraction::operator+=(Fraction const& f) {
    numerator  = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;
    *this = simplify(*this);
    return *this;
}
Fraction& Fraction::operator-=(Fraction const& f) {
    numerator  = numerator * f.denominator - f.numerator * denominator;
    denominator = denominator * f.denominator;
    *this = simplify(*this);
    return *this;
}
Fraction& Fraction::operator*=(Fraction const& f) {
    numerator  *= f.numerator;
    denominator *= f.denominator;
    *this = simplify(*this);
    return *this;
}
Fraction& Fraction::operator/=(Fraction const& f) {
    numerator  *= f.denominator;
    denominator *= f.numerator;
    *this = simplify(*this);
    return *this;
}

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    Fraction f{f1};
    f+=f2;
    return simplify(f);
}
Fraction operator-(Fraction const& f1, Fraction const& f2) {
    Fraction f{f1};
    f-=f2;
    return simplify(f);
}
Fraction operator*(Fraction const& f1, Fraction const& f2) {
    Fraction f{f1};
    f*=f2;
    return simplify(f);
}
Fraction operator/(Fraction const& f1, Fraction const& f2) {
    Fraction f{f1};
    f/=f2;
    return simplify(f);
}

