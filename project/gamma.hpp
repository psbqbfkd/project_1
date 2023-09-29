#pragma once

#include<cmath>
#include<vector>

namespace my {

	const int IntNum = 1000;		//number of interval
	const double Delta = 0.001;	//length of interval

	std::vector<double> make_x()
	{
		std::vector<double> result(IntNum);	//크기 IntNum인 배열
		for (int i = 0; i < IntNum; ++i)
		{
			result[i] = i * Delta / (1 - i * Delta);	//x=t/(1-t)
		}
		return result;
	}
	const static auto x = make_x();	//t/(1-t)

	std::vector<double> make_exp()
	{
		std::vector<double> result(IntNum);	//크기 IntNum인 배열
		for (int i = 0; i < IntNum; ++i)
		{
			result[i] = std::exp(-1 * x[i]);	//exp(-x)
		}
		return result;
	}
	const static auto exp = make_exp();	//exp(-t/(1-t))

	/*
	p>=1 일 때 감마 함수의 값을 구함
	numerical integration 실행
	*/
	double gamma_impl(double p)
	{
		double result = 0;

		for (int i = 1; i < IntNum; ++i)
		{
			result += std::pow(x[i], p - 1) * exp[i] * Delta / (1 - i * Delta) / (1 - i * Delta);
		}

		return result;
	}


	double gamma(double p)
	{
		if (p <= 0) { return 0; }

		if (p < 1) { return gamma_impl(p + 1) / p; }

		return gamma_impl(p);
	}

}