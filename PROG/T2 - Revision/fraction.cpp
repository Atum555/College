#include <iostream>

class Fraction {
  private:
    int num;
    int den;

  public:
    Fraction() : Fraction(0) {}

    Fraction(int a, int b = 1) : num(a), den(b) { normalise(); }

    int numerator() const { return num; }

    int denominator() const { return den; }

    Fraction sum(const Fraction &a) const {
        Fraction f(a);
        f.num *= den;
        return Fraction(num * f.den + f.num, den * f.den);
    }

    Fraction sub(const Fraction &f) const { return sum(Fraction(-f.num, f.den)); }

    Fraction mul(const Fraction &f) const { return Fraction(num * f.num, den * f.den); }

    Fraction div(const Fraction &f) const { return mul(Fraction(f.den, f.num)); }

    void write() const { std::cout << num << '/' << den; }

  private:
    void normalise() {
        int g  = gcd(num, den);
        num   /= g;
        den   /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            int tmp = a;
            a       = b;
            b       = tmp % b;
        }
        return a;
    }
};
