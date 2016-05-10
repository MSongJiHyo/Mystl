//
// Created by Coco on 16/4/28.
//

#ifndef _ALLOC_H
#define _ALLOC_H

#include <cstdlib>
namespace  Mystl
{
	class Alloc
	{
	private:
		union obj
		{
			union obj* free_link_list;
			char client_dada[1];
		};
		enum
		{
			Align = 8
		};
		enum
		{
			Max_Bytes = 128
		};
		enum
		{
			FreeLists = Max_Bytes / Align
		};
		enum
		{
			objs = 20
		};
		static  obj* free_list[FreeLists];
	private:
		static char*   start_free;//the start position of the memory
		static char*   end_free;
		static size_t  heap_size;
	private:
		//将bytes上调至8的倍数
		static size_t ROUND_UP(size_t bytes)
		{
			return ((bytes + Align - 1)&~(Align - 1));
		}
		//看使用哪一个free_list free_list有16号 0-15号 8-16-24-...
		static size_t FREELIST_INDEX(size_t bytes)
		{
			return ((bytes + Align - 1) / Align - 1);
		}
		static  void* refill(size_t n);

		static  char* chunk_alloc(size_t size, size_t& nobjs);

	public:
		static  void* allocate(size_t bytes);
		static  void  deallocate(void* ptr, size_t bytes);
		static  void* reallocate(void* ptr, size_t old_sz, size_t new_sz);
	};
}


#endif //MYSTL_ALLOC_H
