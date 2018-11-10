#ifndef VECTOR_H
#define VECTOR_H


#include<stdexcept>
#include<mutex>
#include<iterator>
#include"itearator.h"
#include"reverse_iterator.h"
#include"const_iterator.h"
#include<memory>
template<class Type, class Allocator = std::allocator<Type>>
class CVector
{
	private:
		Allocator *m_pAllocator;
		std::recursive_timed_mutex m_pMtx;
		const static size_t DEFAULT_SIZE_ARRAY = 100;
		const static size_t MAX_SIZE=64936;
		size_t m_current_sizem;
		size_t m_count;
		Type*m_aArray;
		
		void destroy();
		void new_memory(const size_t&size = DEFAULT_SIZE_ARRAY);
		void new_alloc();

	public:
		using allocator_type = Allocator;
		using const_iterator = const_iterator<Type>;
		using iterator = iterator<Type>;
		using  const_reverse_iterator = reverse_iterator<const Type>;
		using  reverse_iterator = reverse_iterator<Type>;
	
		CVector();
		~CVector();
		Type* data()noexcept;
		Type&back();
		Type&front();
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
		size_t size();
		size_t max_size();
		size_t capacity();
		allocator_type get_allocator() const;
		bool is_empty();
		void assign(size_t &size, const Type& value);
		void reserve(const size_t&);
		void push_back(const Type& value);
	
};

template<class Type,class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::allocator_type CVector<Type, Allocator>::get_allocator() const
{
	return m_pAllocator;
}

template<class Type, class Allocator = std::allocator<Type>>
void CVector<Type, Allocator>::new_alloc()
{
	if(!m_pAllocator)
	m_pAllocator = new allocator_type;
}


template<class Type, class Allocator = std::allocator<Type>>
Type*CVector<Type, Allocator>::data()noexcept
{
	return &m_aArray;
}

template<class Type, class Allocator = std::allocator<Type>>
Type& CVector<Type, Allocator>::back()
{
	return m_aArray + (m_count-1);
}

template<class Type, class Allocator = std::allocator<Type>>
Type& CVector<Type, Allocator>::front()
{
	return m_aArray[0];
}

template<class Type, class Allocator = std::allocator<Type>>
Type& CVector<Type, Allocator>::operator[](const size_t& pos)
{
	return m_aArray[pos];
}

template<class Type, class Allocator = std::allocator<Type>>
Type& CVector<Type, Allocator>::operator[](const size_t& pos) const
{
	return m_aArray[pos];
}

template<class Type, class Allocator = std::allocator<Type>>
void CVector<Type, Allocator>::destroy()
{
	m_pAllocator->destroy(m_aArray);
	m_aArray = nullptr;
}

template<class Type, class Allocator = std::allocator<Type>>
void CVector<Type, Allocator>::new_memory(const size_t& size )
{
	new_mem:
	if (m_aArray == nullptr)
	{
		m_aArray = m_pAllocator->allocate(size);
		m_current_sizem = size;
	}

	else
	{
		destroy();
		goto new_mem;
	}
}

template<class Type, class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::const_reverse_iterator CVector<Type, Allocator>::rcend()
{
	return const_reverse_iterator(m_aArray);
}

template<class Type, class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::const_reverse_iterator CVector<Type, Allocator>::rcbegin()
{
	return const_reverse_iterator(m_aArray + (m_count - 1));
}

template<class Type, class Allocator = std::allocator<Type>>
CVector<Type, Allocator>::~CVector()
{
	destroy();
}

template<class Type, class Allocator = std::allocator<Type>>
void CVector<Type, Allocator>::assign(size_t& size, const Type& value)
{
	new_memory(size);
	for (size_t i = 0; i < size; i++)
	{
		m_aArray[m_count] = value;
	}
}

template<class Type, class Allocator = std::allocator<Type>>
Type& CVector<Type, Allocator>::at(const size_t& pos)
{
	if (!(pos < size()))
		throw new std::out_of_range("out of range");
	return m_aArray[pos];
}

template<class Type, class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::reverse_iterator CVector<Type, Allocator>::rend()const
{
    return reverse_iterator(m_aArray);
}

template <class Type, class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::reverse_iterator CVector<Type, Allocator>::rbegin()const
{
   return reverse_iterator(m_aArray+(m_count-1));
}

template <class Type, class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::iterator CVector<Type, Allocator>::begin()const
{
    return iterator(m_aArray);
}

template<class Type, class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::iterator CVector<Type, Allocator>::end()const
{
    return iterator(m_aArray + m_count);
}

template <class Type, class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::const_iterator CVector<Type, Allocator>::cbegin()const
{
     return const_iterator(m_aArray);
}

template<class Type, class Allocator = std::allocator<Type>>
typename CVector<Type, Allocator>::const_iterator CVector<Type, Allocator>::cend()const
{
    return const_iterator(m_aArray);
}

template<class Type, class Allocator = std::allocator<Type>>
CVector<Type, Allocator>::CVector() : m_current_sizem(DEFAULT_SIZE_ARRAY),m_count(0)
{
	new_memory();
	new_alloc();

}
template<class Type, class Allocator = std::allocator<Type>>
bool CVector<Type, Allocator>::is_empty()
{
	return !m_count;
}

template<class Type, class Allocator = std::allocator<Type>>
size_t CVector<Type, Allocator>::size()
{
	return m_count;
}

template<class Type, class Allocator = std::allocator<Type>>
size_t CVector<Type, Allocator>::capacity()
{
	return m_current_sizem;
}


template<class Type, class Allocator = std::allocator<Type>>
size_t CVector<Type, Allocator>::max_size()
{
	return MAX_SIZE;
}

template<class Type, class Allocator = std::allocator<Type>>
void CVector<Type, Allocator>::reserve(const size_t& size)
{
	if (size > max_size())
		throw std::length_error("length was less than capacity");

	else
	{
		m_current_sizem = size;
		Type *tmp = m_allocator->allocate(size);
		for (size_t i = 0; i < m_count; i++)
		{
			tmp[i] = m_aArray[i];
		}
		m_allocator->deallocate(m_aArray);
		m_aArray = tmp;
	}
}

template<class Type, class Allocator = std::allocator<Type>>
void CVector<Type, Allocator>::push_back(const Type& value)
{
	m_pMtx.lock();
	if (m_count == m_current_sizem)
	{
		Type*tmp = m_pAllocator->allocate(m_count+1);
		++m_count;
		for (size_t i = 0; i < m_count; i++)
		{
			tmp[i] = m_aArray[i];
		}
		tmp[m_count] = value;
		m_pAllocator->deallocate(m_aArray, m_count);
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

