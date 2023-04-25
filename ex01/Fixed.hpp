/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:41:06 by makacem           #+#    #+#             */
/*   Updated: 2023/04/25 12:02:27 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int FixedPoint;
    static const int FractionalBits = 8;
public:
    Fixed(void);
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &otherObject);
    Fixed   &operator=(const Fixed &other);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream   &operator<<(std::ostream &output, Fixed const &src);



#endif