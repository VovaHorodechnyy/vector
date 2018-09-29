#ifndef VECTOR_H
#define VECTOR_H


#include<stdexcept>
#include<mutex>
#include<iterator>
#include"itearator.h"
#include"reverse_iterator.h"
#include"const_iterator.h"

template<class Type>
class CVector
{
	private:
		std::recursive_timed_mutex m_pMtx;
		const static size_t DEFAULT_SIZE_ARRAY = 100;
		const static size_t MAX_SIZE=64936;
		size_t m_current_sizem;
		size_t m_count;
		Type*m_aArray;
		
		void destroy();
		void new_memory(const size_t&size = DEFAULT_SIZE_ARRAY);

	public:

	using const_iterator = const_iterator<Type>;
	using iterator = iterator<Type>;
	using  const_reverse_iterator = reverse_iterator<const Type>;
	using  reverse_iterator = reverse_iterator<Type>;
	
	
	
	


	CVector();
	~CVector();
	Type* data()noexcept;
	Type&back();
	Type&front();
	void assign(size_t &size, const Type& value);
	Type& at(const size_t& pos);
	Type&operator[](const size_t& );
	Type&operator[](const size_t& )const;
	const_reverse_iterator rcend();
	const_reverse_iterator rcbegin();
    reverse_iterator rend()const;
    reverse_iterator rbegin() const;
    iterator begin()const;
    iterator end()const;
    const_iterator cbegin() const;
    const_iterator cend()const ;
	bool is_empty();
	size_t size();
	size_t max_size();
	size_t capacity();
	void reserve(const size_t&);
	void push_back(const Type& value);
};

template<class Type>
Type*CVector<Type>::data()noexcept 
{
	return &m_aArray;
}

template<class Type>
Type& CVector<Type>::back() 
{
	return m_aArray + (m_count-1);
}

template<class Type>
Type& CVector<Type>::front() 
{
	return m_aArray[0];
}

template<class Type>
Type& CVector<Type>::operator[](const size_t& pos) 
{
	return m_aArray[pos];
}

template<class Type>
Type& CVector<Type>::operator[](const size_t& pos) const
{
	return m_aArray[pos];
}

template<class Type>
void CVector<Type>::destroy()
{
	delete[]m_aArray;
	m_aArray = nullptr;
}

template<class Type>
void CVector<Type>::new_memory(const size_t& size = DEFAULT_SIZE_ARRAY)
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

template<class Type>
typename CVector<Type>::const_reverse_iterator CVector<Type>::rcend()
{
	return const_reverse_iterator(m_aArray);
}

template<class Type>
typename CVector<Type>::const_reverse_iterator CVector<Type>::rcbegin()
{
	return const_reverse_iterator(m_aArray + (m_count - 1));
}

template<class Type>
CVector<Type>::~CVector() 
{
	destroy();
}

template<class Type>
void CVector<Type>::assign(size_t& size, const Type& value)
{
	new_memory(size);
	for (size_t i = 0; i < size; i++)
	{
		m_aArray[m_count] = value;
	}
}

template<class Type>
Type& CVector<Type>::at(const size_t& pos) 
{
	if (!(pos < size()))
		throw new std::out_of_range("out of range");
	return m_aArray[pos];
}

template<class Type>
typename CVector<Type>::reverse_iterator CVector<Type>::rend()const
{
    return reverse_iterator(m_aArray);
}

template <class Type>
typename CVector<Type>::reverse_iterator CVector<Type>::rbegin()const
{
   return reverse_iterator(m_aArray+(m_count-1));
}

template <class Type>
typename CVector<Type>::iterator CVector<Type>::begin()const
{
    return iterator(m_aArray);
}

template<class Type>
typename CVector<Type>::iterator CVector<Type>::end()const
{
    return iterator(m_aArray + m_count);
}

template <class Type>
typename CVector<Type>::const_iterator CVector<Type>::cbegin()const
{
     return const_iterator(m_aArray);
}

template<class Type>
typename CVector<Type>::const_iterator CVector<Type>::cend()const
{
    return const_iterator(m_aArray);
}

template<class Type>
CVector<Type>::CVector() : m_current_sizem(DEFAULT_SIZE_ARRAY),m_count(0)
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
void CVector<Type>::reserve(const size_t& size)
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
	m_pMtx.lock();
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
	m_pMtx.unlock();

}
#endif  // !VECTOR_H

