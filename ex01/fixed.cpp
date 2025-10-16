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
		this->fixed = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
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

