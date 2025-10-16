#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int fixed;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(int const num);
		Fixed(float const num);
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed &operator=(const Fixed &other);
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		static Fixed &min(Fixed &n1, Fixed &n2);
		static const Fixed &min(Fixed const &n1, Fixed const &n2);
		static Fixed &max(Fixed &n1, Fixed &n2);
		static const Fixed &max(Fixed const &n1, Fixed const &n2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
