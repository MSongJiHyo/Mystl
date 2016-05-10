#ifndef _CONSTRUCT_H_
#define _CONSTRUCT_H_
#include <new>
#include <Type_Traits.h>
namespace Mystl{
	template<class T1, class T2>
	inline void construct(T1* ptr, const T2& value)
	{
		new (ptr)T1(value);
	}
	template<class T>
	inline void destroy(T* ptr)
	{
		ptr->~T();
	}
	template<class FowardIterator>
	inline void _destroy(FowardIterator first, FowardIterator last, _true_type)
	{

	}
	template<class FowardIterator>
	inline void _destroy(FowardIterator first, FowardIterator last, _false_type)
	{
		for (; first != last; first++)
		{
			destroy(&*first);
		}
	}
	template<class FowardIterator>
	inline void _destroy(FowardIterator first, FowardIterator last)
	{
		typedef _type_traits<FowardIterator>::is_POD_type is_POD_type;
		_destroy(first, last, is_POD_type);
	}
}
#endif
