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
	
	std::vector<int> aqq;
	aqq.push_back(12);
	aqq.push_back(22);
	aqq.push_back(142);
	aqq.push_back(112);
	aqq.push_back(1222);
//	aqq.assign(aqq.begin()+3,aqq.end());
	for (int a : aqq) 
	{
		std::cout << a << std::endl;
	}
	std::cout << "cap: " << aqq.capacity()<<std::endl;
	varr.assign(5, 1);
	for (int a : aqq)
	{
		std::cout << a << std::endl;
	}
//	varr.
}