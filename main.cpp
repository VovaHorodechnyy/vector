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

	varr.push_back(67);
	varr.push_back(6);
	varr.push_back(2435);
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
	std::vector<int >qwe = { 12,2,3,5 };
	std::vector<int >::iterator i = qwe.begin();
	i[1] = 5;
	//std::cout << qwe.begin()[2];
	CVector<int>::iterator it= varr.begin();
	std::vector<int> asd = { 1,2,3 };
	auto it_const = asd.rbegin();
	std::for_each(varr.begin(), varr.end(), [](int i) 
	{
		std::cout << i;
	});
	//std::cout << it[1];
	//it[1] = 5;
	//std::cout << it[1];
	CVector<int>::reverse_iterator c_it = varr.rbegin();
	std::cout<< std::endl;
	++c_it;
	std::cout << *(c_it)<<std::endl;
//	varr.
}