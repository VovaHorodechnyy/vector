#include<iostream>
#include"Vector.h"
#include<vector>
#include<algorithm>
#include<memory>
class myalloc :public std::allocator<int>
{
};
int main()
{
	CVector<int, myalloc>a;
	for (size_t i = 0; i < 12; i++)
	{
		a.push_back(12+i);
	}
	for (int numb : a) 
	{
		std::cout << numb<<std::endl;
	}



}
