#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

template<class ItType>
class reverse_iterator :public std::iterator<std::random_access_iterator_tag, ItType>
{
public:
	using  iterator_categoregy= std::random_access_iterator_tag;
	reverse_iterator(ItType*aPtr) :m_pPtr(aPtr) {}
	reverse_iterator operator++() { reverse_iterator it = *this; --m_pPtr; return it; }
	reverse_iterator operator++(int junk) { --m_pPtr; return *this; }
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
	bool operator==(const reverse_iterator&rhs)const 
	{
		return rhs.m_pPtr == m_pPtr;
	}
	bool operator!=(const reverse_iterator&rhs)const
	{
		return rhs.m_pPtr != m_pPtr;
	}
private:
	ItType*  m_pPtr;
};

#endif // !REVERSE_ITERATOR_H

