#include "fixed.hpp"

Fixed::Fixed() {
	fixed = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) {
	fixed = num * 256;
	std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(float const num) {
	fixed = roundf(num * 256);
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		fixed = other.getRawBits();
	}
	return *this;
}

bool Fixed::operator<(const Fixed &other) const {
	if (this->toFloat() < other.toFloat()) {
		return (true);
	}
	return (false);
}

bool Fixed::operator>(const Fixed &other) const {
	if (this->toFloat() > other.toFloat()) {
		return (true);
	}
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const {
	if (this->toFloat() <= other.toFloat()) {
		return (true);
	}
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const {
	if (this->toFloat() >= other.toFloat()) {
		return (true);
	}
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const {
	if (this->toFloat() != other.toFloat()) {
		return (true);
	}
	return (false);
}

bool Fixed::operator==(const Fixed &other) const {
	if (this->toFloat() == other.toFloat()) {
		return (true);
	}
	return (false);
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

Fixed &Fixed::operator++() { fixed++; return *this; }       // ++a
Fixed Fixed::operator++(int) { Fixed tmp(*this); fixed++; return tmp; } // a++
Fixed &Fixed::operator--() { fixed--; return *this; }       // --a
Fixed Fixed::operator--(int) { Fixed tmp(*this); fixed--; return tmp; } // a--


Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f2);
	return (f1);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1 < f2)
		return (f2);
	return (f1);
}

const Fixed &Fixed::min(Fixed const &f1, Fixed const &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed::~Fixed() {
	std::cout << "destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getrawbits member function called" << std::endl;
	return this->fixed;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setrawbits member function called" << std::endl;
	this->fixed = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixed) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return static_cast<int>(this->fixed) / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

