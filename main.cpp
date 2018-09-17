#include<iostream>
#include"Vector.h"
#include<vector>
#include<algorithm>
int main()
{
https://gist.github.com/jeetsukumaran/307264

	/*std::vector<double>varr;
	varr.push_back(23);

	std::cout << "max size: " << varr.max_size()<<std::endl;
	std::cout << " size: " << varr.size()<<std::endl;
	std::cout << "capacity: " << varr.capacity()<<std::endl;
	varr.reserve(41);
	std::cout << "after reserve" << std::endl;
	std::cout << "max size: " << varr.max_size() << std::endl;
	std::cout << " size: " << varr.size() << std::endl;
	std::cout << "capacity: " << varr.capacity() << std::endl;*/
	//std::vector<int>::c
	CVector<int>varr;
	int a = 5;
	//std::vector<int>::itera;

	varr.push_back(a);
	varr.push_back(6);
	varr.push_back(a);
	std::cout << "max size: " << varr.max_size() << std::endl;
	std::cout << " size: " << varr.size() << std::endl;
	std::cout << "capacity: " << varr.capacity() << std::endl;
	varr.reserve(41);
	std::cout << "after reserve" << std::endl;
	std::cout << "max size: " << varr.max_size() << std::endl;
	std::cout << " size: " << varr.size() << std::endl;
	std::cout << "capacity: " << varr.capacity() << std::endl;
//	CVector<int>:: k = varr.();
	//std::cout << *k;
	CVector<int>::const_iterator it= varr.cbegin();
	std::for_each(varr.begin(), varr.end(), [](int i) 
	{
		std::cout << i;
	});
}