#ifndef CONST_ITERATOR_H
#define CONST_ITERATOR_H
template<class ItType>
class const_iterator : public std::iterator<std::input_iterator_tag, ItType>
{

public:
	typedef std::forward_iterator_tag iterator_category;
	const_iterator(ItType* aPtr) :m_pPtr(aPtr) {}
	const_iterator operator++() { const_iterator it = *this; ++m_pPtr; return it; }
	const_iterator operator++(int junk) { ++m_pPtr; return *this; }
	const ItType& operator*() const { return *m_pPtr; }
	const ItType* operator->() const { return m_pPtr; }

	bool operator==(const const_iterator &cit) const { return m_pPtr == cit.m_pPtr; }
	bool operator!=(const const_iterator &cit)  const { return m_pPtr != cit.m_pPtr; }
private:
	ItType* m_pPtr;

};
#endif // !CONST_ITERATOR_H

