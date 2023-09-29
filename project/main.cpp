#include<cmath>
#include<iostream>
#include"gamma.hpp"

int main()
{
	/*
	* 문제 (b)
	* gamma(p) = sqrt(2)
	* p=?
	*/
	const double root_2 = std::sqrt(2);

	double p_old = 1, p_new = 0;
	while (true)
	{
		double gamma_prime = (my::gamma(p_old + 0.001) - my::gamma(p_old)) / 0.001;
		p_new = p_old + (root_2 - my::gamma(p_old)) / gamma_prime;

		if (std::abs(p_new - p_old) < 0.001) break;
		p_old = p_new;
	}
	double solution_1 = p_new;

	p_old = 2;
	while (true)
	{
		double gamma_prime = (my::gamma(p_old + 0.001) - my::gamma(p_old)) / 0.001;
		p_new = p_old + (root_2 - my::gamma(p_old)) / gamma_prime;

		if (std::abs(p_new - p_old) < 0.001) break;
		p_old = p_new;
	}
	double solution_2 = p_new;

	std::cout << "(b)\tgamma(p)=sqrt(2) at p=" << solution_1 << " or " << solution_2 << '\n';

	/*
	* 문제 (c)
	* minimum value
	*/
	double p_min = 0.1;
	while (true)
	{
		if (my::gamma(p_min) <= my::gamma(p_min + 0.001))break;

		p_min += 0.001;
	}

	std::cout << "\n(c)\tgamma(p) has minimum value at p=" << p_min
		<< "\n\tminimum value=" << my::gamma(p_min);
}