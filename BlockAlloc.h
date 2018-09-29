#ifndef BLOCK_ALLOC_H
#define BLOCK_ALLOC_H

template<class T>
class BlockAlloc
{
public:
	static void* operator new(size_t s) {
		if (s != sizeof(T)) {
			return ::operator new(s);
		}
		return pool.AllocBlock();
	}
	static void operator delete(void* m, size_t s) {
		if (s != sizeof(T)) {
			::operator delete(m);
		}
		else if (m != std::nullptr) {
			pool.FreeBlock(m);
		}
	}

	
	static void* operator new(size_t, void* m) {
		return m;
	}
	
	static void operator delete(void*, void*) {
	}

private:
	static BlockPool<T> pool;
};
template<class T> BlockPool<T> BlockAlloc<T>::pool;

#endif // !BLOCK_ALLOC_H

