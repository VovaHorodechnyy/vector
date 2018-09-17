
#ifndef VECTOR_H
#define VECTOR_H
//https://gist.github.com/jeetsukumaran/307264

#include<stdexcept>
#include<iterator>
template<class Type>
class CVector
{
private:

	const size_t DEFAULT_SIZE_ARRAY = 100;
	const size_t MAX_SIZE=64936;
	size_t m_current_sizem;
	size_t m_count;
	Type*m_aArray;

public:
//	typedef const_iterator const_iterator;
	//typedef iterator iterator;
	
	

	class const_iterator : public std::iterator<std::input_iterator_tag, Type>
	{

	public:
		typedef std::forward_iterator_tag iterator_category;
		const_iterator(Type* aPtr) :m_pPtr(aPtr) {}
		const_iterator operator++() { const_iterator it = *this; ++m_pPtr; return it; }
		const_iterator operator++(int junk) { ++m_pPtr; return *this; }
		const Type& operator*() const { return *m_pPtr; }
		const Type* operator->() const { return m_pPtr; }
		bool operator==(const const_iterator &cit) const { return m_pPtr == cit.m_pPtr; }
		bool operator!=(const const_iterator &cit)  const { return m_pPtr != cit.m_pPtr; }
	private:
		Type* m_pPtr;

	};

	class iterator : public std::iterator<std::input_iterator_tag, Type>
	{
	public:

		typedef std::forward_iterator_tag iterator_category;
		iterator(Type* aPtr) : m_pPtr(aPtr) { }
		iterator operator++() { iterator i = *this; ++m_pPtr; return i; }
		iterator operator++(int junk) { ++m_pPtr; return *this; }
		Type& operator*() { return *m_pPtr; }
		Type& operator*()const { return *m_pPtr; }
		Type* operator->() { return m_pPtr; }
		Type* operator->()const { return m_pPtr; }
		bool operator==(const iterator& rhs)const { return m_pPtr == rhs.m_pPtr; }
		bool operator!=(const iterator& rhs)const { return m_pPtr != rhs.m_pPtr; }
	private:
		Type*  m_pPtr;
	};
	class reverse_iterator :public std::iterator<std::random_access_iterator_tag, Type> 
	{
	
	};


	CVector();
    ~CVector()
	{
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
	m_aArray = new Type[DEFAULT_SIZE_ARRAY];

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

