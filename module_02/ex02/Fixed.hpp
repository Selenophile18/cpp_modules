/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 23:13:47 by hhattaki          #+#    #+#             */
/*   Updated: 2023/05/23 17:58:36 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	store_fixed;
	static const int	fraction_store = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	
	Fixed& operator=(const Fixed& other);
	bool	operator>(const Fixed& other);
	bool	operator<(const Fixed& other);
	bool	operator>=(const Fixed& other);
	bool	operator<=(const Fixed& other);
	bool	operator==(const Fixed& other);
	bool	operator!=(const Fixed& other);
	
	Fixed operator*(const Fixed& other);
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator-();
	Fixed operator/(const Fixed& other);
	
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	
	static Fixed&	min(Fixed &one, Fixed &two);
	static Fixed&	max(Fixed &one, Fixed &two);
	static const Fixed&	min(const Fixed &one, const Fixed &two);
	static const Fixed&	max(const Fixed &one, const Fixed &two);
	
	float toFloat( void ) const;
	int toInt( void ) const;
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
	~Fixed();
};

std::ostream& operator<<(std::ostream &os, const Fixed& point);
