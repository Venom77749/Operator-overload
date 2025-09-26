#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;

    int gcd(int a, int b) const {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return (a < 0) ? -a : a;
    }

    void reduce() {
        int g = gcd(numerator_, denominator_);
        numerator_ /= g;
        denominator_ /= g;
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

public:
    Fraction(int numerator, int denominator)
        : numerator_(numerator), denominator_(denominator)
    {
        reduce();
    }

    Fraction operator+(const Fraction& f) const {
        Fraction res(numerator_ * f.denominator_ + f.numerator_ * denominator_,
            denominator_ * f.denominator_);
        res.reduce();
        return res;
    }

    Fraction operator-(const Fraction& f) const {
        Fraction res(numerator_ * f.denominator_ - f.numerator_ * denominator_,
            denominator_ * f.denominator_);
        res.reduce();
        return res;
    }

    Fraction operator*(const Fraction& f) const {
        Fraction res(numerator_ * f.numerator_, denominator_ * f.denominator_);
        res.reduce();
        return res;
    }

    Fraction operator/(const Fraction& f) const {
        Fraction res(numerator_ * f.denominator_, denominator_ * f.numerator_);
        res.reduce();
        return res;
    }

    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++() {
        numerator_ += denominator_;
        reduce();
        return *this;
    }

    // Постфиксный инкремент
    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--() {
        numerator_ -= denominator_;
        reduce();
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    void print() const {
        std::cout << numerator_ << "/" << denominator_ << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    Fraction a(6, 8);
    Fraction b(1, 6);

    std::cout << "a: "; a.print();
    std::cout << "b: "; b.print();

    std::cout << "a + b = "; (a + b).print();
    std::cout << "a - b = "; (a - b).print();
    std::cout << "a * b = "; (a * b).print();
    std::cout << "a / b = "; (a / b).print();

    std::cout << "-a = "; (-a).print();

    std::cout << "++a = "; (++a).print();
    std::cout << "a++ = "; (a++).print();
    std::cout << "a после a++ = "; a.print();

    std::cout << "--b = "; (--b).print();
    std::cout << "b-- = "; (b--).print();
    std::cout << "b после b-- = "; b.print();

    return 0;
}
