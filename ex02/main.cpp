#include "fixed.hpp"

int main( void ) {
	std::cout << "==== CONSTRUCTORES ====" << std::endl;
    Fixed a;                 // Default
    Fixed b(10);             // Desde int
    Fixed c(42.42f);         // Desde float
    Fixed d(b);              // Copia
    Fixed e;                 
    e = c;                   // Asignación

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;

    std::cout << "\n==== CONVERSIONES ====" << std::endl;
    std::cout << "b as int: " << b.toInt() << std::endl;
    std::cout << "c as float: " << c.toFloat() << std::endl;

    std::cout << "\n==== COMPARACIONES ====" << std::endl;
    Fixed x(10.5f);
    Fixed y(42.42f);

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x < y  ? " << (x < y) << std::endl;
    std::cout << "x > y  ? " << (x > y) << std::endl;
    std::cout << "x <= y ? " << (x <= y) << std::endl;
    std::cout << "x >= y ? " << (x >= y) << std::endl;
    std::cout << "x == y ? " << (x == y) << std::endl;
    std::cout << "x != y ? " << (x != y) << std::endl;

    std::cout << "\n==== ARITMÉTICA ====" << std::endl;
    Fixed sum = x + y;
    std::cout << x << " + " << y << " = " << sum << std::endl;
    Fixed diff = y - x;
    std::cout << y << " - " << x << " = " << diff << std::endl;
    Fixed prod = x * y;
    std::cout << x << " * " << y << " = " << prod << std::endl;
    Fixed div = y / x;
    std::cout << y << " / " << x << " = " << div << std::endl;

    std::cout << "\n==== INCREMENTOS / DECREMENTOS ====" << std::endl;
    Fixed z;

    std::cout << "z = " << z << std::endl;
    std::cout << "++z = " << ++z << " (prefijo)" << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "z++ = " << z++ << " (postfijo)" << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "--z = " << --z << " (prefijo)" << std::endl;
    std::cout << "z = " << z << std::endl;
    std::cout << "z-- = " << z-- << " (postfijo)" << std::endl;
    std::cout << "z = " << z << std::endl;

    std::cout << "\n==== MIN / MAX ====" << std::endl;
    Fixed a1(5.5f);
    Fixed a2(10.1f);

    std::cout << "a1 = " << a1 << ", a2 = " << a2 << std::endl;
    std::cout << "min(a1, a2) = " << Fixed::min(a1, a2) << std::endl;
    std::cout << "max(a1, a2) = " << Fixed::max(a1, a2) << std::endl;

    std::cout << "\n==== COMBINACIÓN DE OPERACIONES ====" << std::endl;
    Fixed result = (a1 + a2) * Fixed(2) - Fixed(3.5f);
    std::cout << "(a1 + a2) * 2 - 3.5 = " << result << std::endl;

    std::cout << "\n==== TODO FUNCIONA 😄 ====" << std::endl;
    return 0;
}
