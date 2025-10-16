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
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
