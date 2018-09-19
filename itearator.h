#ifndef ITERATOR_H
#define ITERATOR_H

template<class ItType>
class iterator : public std::iterator<std::input_iterator_tag, ItType>
{
public:

	using  iterator_category = std::forward_iterator_tag;
	iterator(ItType* aPtr) : m_pPtr(aPtr) { }
	iterator operator++() { iterator it = *this; ++m_pPtr; return it; }
	iterator operator++(int junk) { ++m_pPtr; return *this; }
	ItType& operator*() { return *m_pPtr; }
	ItType& operator*()const { return *m_pPtr; }
	ItType* operator->() { return m_pPtr; }
	ItType* operator->()const { return m_pPtr; }
	ItType& operator[](size_t ix) const
	{
		return *(m_pPtr + ix);
	}
	ItType& operator[](size_t ix)
	{
		return *(m_pPtr + ix);
	}

	bool operator==(const iterator& rhs)const;
	bool operator!=(const iterator& rhs)const { return m_pPtr != rhs.m_pPtr; }
private:
	ItType*  m_pPtr;
};
template<class Type>
bool iterator<Type>::operator==(const iterator& rhs)const 
{
	 return m_pPtr == rhs.m_pPtr; 
}
#endif // !ITERATOR_H

