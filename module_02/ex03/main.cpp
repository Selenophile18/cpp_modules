/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:44:34 by hhattaki          #+#    #+#             */
/*   Updated: 2023/05/24 16:41:45 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 30.0f);
    Point c(20.0f, 0.0f);

    Point inside(10.0f, 15.0f);

    Point outside(30.0f, 15.0f);

    bool Inside = bsp(a, b, c, inside);
    std::cout << "is it inside the triangle: " << Inside << std::endl;

    Inside = bsp(a, b, c, outside);
    std::cout << "is it inside the triangle: " << Inside << std::endl;

    Point edge(20.0f, 0.0f);

    Inside = bsp(a, b, c, edge);
    std::cout << "is it inside the triangle: " << Inside << std::endl;

    return 0;
}