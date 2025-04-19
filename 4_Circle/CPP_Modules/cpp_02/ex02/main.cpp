/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:32:42 by takwak            #+#    #+#             */
/*   Updated: 2025/04/19 23:40:12 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "=== 기본 생성자 & 전위/후위 테스트 ===" << std::endl;
	Fixed a1;
	std::cout << "a1      : " << a1 << std::endl;
	std::cout << "++a1    : " << ++a1 << std::endl;
	std::cout << "a1      : " << a1 << std::endl;
	std::cout << "a1++    : " << a1++ << std::endl;
	std::cout << "a1      : " << a1 << std::endl;

	std::cout << "\n=== 상수 객체와 곱셈 테스트 ===" << std::endl;
	Fixed const b1(Fixed(5.05f) * Fixed(2));
	std::cout << "b1      : " << b1 << std::endl;
	std::cout << "max(a1, b1) : " << Fixed::max(a1, b1) << std::endl;

	std::cout << "\n=== 사칙연산 테스트 ===" << std::endl;
	Fixed c1(5);
	std::cout << "c1 = " << c1 << ", b1 = " << b1 << std::endl;
	std::cout << "c1 + b1 : " << c1 + b1 << std::endl;
	std::cout << "c1 - b1 : " << c1 - b1 << std::endl;
	std::cout << "c1 / b1 : " << c1 / b1 << std::endl;
	std::cout << "c1 * b1 : " << c1 * b1 << std::endl;

	std::cout << "\n=== 비교 연산자 테스트 ===" << std::endl;
	if (c1 < b1) std::cout << "c1 is smaller than b1" << std::endl;
	if (c1 > b1) std::cout << "c1 is b1igger than b1" << std::endl;
	if (c1 == c1) std::cout << "c1 is equal to c1" << std::endl;
	std::cout << "min(c1, b1): " << Fixed::min(c1, b1) << std::endl;

	std::cout << "\n=== 0.5 + 0.5 테스트 (소수 계산 정확도 확인) ===" << std::endl;
	Fixed d(0.5f);
	Fixed e(0.5f);
	std::cout << "0.5 + 0.5 : " << d + e << std::endl;
	std::cout << "0.5 - 0.5 : " << d - e << std::endl;
	std::cout << "0.5 * 0.5 : " << d * e << std::endl;
	std::cout << "0.5 / 0.5 : " << d / e << std::endl;

	std::cout << "\n=== RawBits 확인 테스트 ===" << std::endl;
	Fixed f(3.5f);
	Fixed g(2);
	std::cout << "3.5 raw = " << f.getRawBits() << std::endl;
	std::cout << "2 raw   = " << g.getRawBits() << std::endl;
	std::cout << "3.5 / 2 = " << f / g << std::endl;

	std::cout << "\n=== 큰 수 연산 테스트 (오버플로우 가능성) ===" << std::endl;
	Fixed f1(100000);
	Fixed g1(2);
	std::cout << "100000 raw = " << f1.getRawBits() << std::endl;
	std::cout << "2 raw      = " << g1.getRawBits() << std::endl;
	std::cout << "100000 / 2 = " << f1 / g1 << std::endl;
	std::cout << "100000 * 2 = " << f1 * g1 << std::endl;

	std::cout << "\n=== 자기 자신 비교 & min/max ===" << std::endl;
	std::cout << "min(c1, c1): " << Fixed::min(c1, c1) << std::endl;
	std::cout << "max(b1, b1): " << Fixed::max(b1, b1) << std::endl;

	std::cout << "\n=== 후위 증가/감소 & 전위 감소 테스트 ===" << std::endl;
	Fixed x(10);
	std::cout << "x      : " << x << std::endl;
	std::cout << "x++    : " << x++ << std::endl;
	std::cout << "x      : " << x << std::endl;
	std::cout << "--x    : " << --x << std::endl;
	std::cout << "x--    : " << x-- << std::endl;
	std::cout << "x      : " << x << std::endl;

	return 0;
}
