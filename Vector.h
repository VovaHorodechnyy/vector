#ifndef VECTOR_H
#define VECTOR_H
//https://gist.github.com/jeetsukumaran/307264

#include<stdexcept>
#include<iterator>
#include"itearator.h"
#include"reverse_iterator.h"
#include"const_iterator.h"

template<class Type>
class CVector
{
	private:

		const static size_t DEFAULT_SIZE_ARRAY = 100;
		const size_t MAX_SIZE=64936;
		size_t m_current_sizem;
		size_t m_count;
		Type*m_aArray;
		
	public:
//	typedef const_iterator const_iterator;
	//typedef iterator iterator;
	//typedef iterator<Type> iterator;
	using const_iterator = const_iterator<Type>;
	using iterator = iterator<Type>;
	using  const_reverse_iterator = reverse_iterator<const Type>;
	using  reverse_iterator = reverse_iterator<Type>;
	
	
	
	


	CVector();
    ~CVector()
	{
		destroy();
	}
	void destroy() 
	{
		delete[]m_aArray;
		m_aArray = nullptr;
	}
	void new_memory(size_t size= DEFAULT_SIZE_ARRAY)
	{
		new_mem:
		if (m_aArray == nullptr) 
		{
			m_aArray = new Type[size];
			m_current_sizem = size;
		}
			
		else
		{
			destroy();
			goto new_mem;
		}
	}

	void assign(size_t size,const Type& value) 
	{
		new_memory(size);
		for (size_t i = 0; i < size; i++)
		{
			m_aArray[m_count] = value;
		}
	}

	Type& at(size_t pos) 
	{
		if (!(pos < size()))
			throw new out_of_range("out of range");
		return m_aArray[pos];
	}

	reverse_iterator rbegin() 
	{
		return reverse_iterator(m_aArray+(m_count-1));
	}

	iterator begin()
	{
		return iterator(m_aArray);
	}

	iterator end()
	{
		return iterator(m_aArray + m_count);
	}

	const_iterator cbegin() const
	{
		return const_iterator(m_aArray);
	}

	const_iterator cend() const
	{
		return const_iterator(m_aArray + m_count);
	}
	bool is_empty();
	size_t size();
	size_t max_size();
	size_t capacity();
	void reserve(size_t);
	void push_back(const Type& value);
};
template<class Type>
CVector<Type>::CVector() :m_count(0), m_current_sizem(DEFAULT_SIZE_ARRAY)
{
	new_memory();

}
template<class Type>
bool CVector<Type>::is_empty()
{
	return !m_count;
}

template<class Type>
size_t CVector<Type>::size()
{
	return m_count;
}

template<class Type>
size_t CVector<Type>::capacity()
{
	return m_current_sizem;
}


template<class Type>
size_t CVector<Type>::max_size()
{
	return MAX_SIZE;
}

template<class Type>
void CVector<Type>::reserve(size_t size)
{
	if (size > max_size())
		throw std::length_error("length was less than capacity");

	else
	{
		m_current_sizem = size;
		Type *tmp = new Type[size];
		for (size_t i = 0; i < m_count; i++)
		{
			tmp[i] = m_aArray[i];
		}
		delete[]m_aArray;
		m_aArray = tmp;
	}
}

template<class Type>
void CVector<Type>::push_back(const Type& value)
{
	if (m_count == m_current_sizem)
	{
		Type*tmp = new Type[m_count + 1];
		++m_count;
		for (size_t i = 0; i < m_count; i++)
		{
			tmp[i] = m_aArray[i];
		}
		tmp[m_count] = value;
		delete[]m_aArray;
		m_aArray = tmp;

	}
	else
	{

		m_aArray[m_count] = value;
		++m_count;
	}

}
#endif  VECTOR_H// !VECTOR_H

