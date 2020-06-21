//
// Created by Coco on 16/5/08.
//
#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_
#include "Alloc.h"
#include "Construct.h"
namespace Mystl
{
	template<class T>
	class Allocator
	{
	public:

		typedef T           value_type;
		typedef T*          pointer;
		typedef const T*    const_pointer;
		typedef T&          reference;
		typedef const T&    const_reference;
		typedef ptrdiff_t   difference_type;
		typedef size_t      size_type;

	public:

		static T* allocate();
		static T* allocate(size_t n);

		static void deallocate(T* ptr);
		static void deallocate(T* ptr,size_t n);
		static void construct(T* ptr);
		static void construct(T* ptr, const T& value);
		static void destroy(T* ptr);
		static void destroy(T* first, T* last);

	};
	template<class T>
	T* Allocator<T>::allocate()
	{
		return static_cast<T*>(Alloc::allocate(sizeof(T));
	}
	template<class T>
	T* Allocator<T>::allocate(size_t n)
	{
		if (n == 0)
		{
			return ;
		}
		return static_cast<T*>(Alloc::allocate(sizeof(T)*n);
	}
	template<class T>
	void allocator<T>::deallocate(T* ptr)
	{
		Alloc<T>::deallocate(static_cast<void*>(ptr),sizeof(T));
	}
	template<class T>
	void allocator<T>::deallocate(T* ptr, size_t n)
	{
		if (n == 0)
		{
			return ;
		}
		Alloc<T>::deallocate(static_cast<void*>(ptr),sizeof(T)*n);
	}
	template<class T>
	void allocator<T>::construct(T* ptr)
	{
		new(ptr)T();
	}
	template<class T>
	void allocator<T>::construct(T* ptr,const T& value)
	{
		new(ptr)T(value);
	}
	template<class T>
	void allocator<T>::destroy(T* ptr)
	{
		ptr->~T();
	}
	template<class T>
	void allocator<T>::destroy(T* first, T* last)
	{
		for (; first != last; ++first)
		{
			first->~T();
		}
	}
}
#endif
