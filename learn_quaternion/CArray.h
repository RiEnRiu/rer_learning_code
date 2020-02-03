#ifndef CARRAY_H
#define CARRAY_H

void * New_CArray(size_t typesize, ...);
bool Fill_CArray(void *dest, const void *src, size_t n, ...);

#ifndef FillCArray
#define FillCArray(dest,src,n,...) Fill_CArray(dest,src,n,##__VA_ARGS__,0)
#endif  

#ifdef _DEBUG
void * New_CArray(const char* file, const char* func, int line, size_t typesize, ...);
void Delete_CArray(const char* file, const char* func, int line, void *ptr);
#ifndef NewCArray
#define NewCArray(type,...) New_CArray(__FILE__,__FUNCTION__,__LINE__,sizeof(type),##__VA_ARGS__,0)
#endif 
#ifndef DeleteCArray
#define DeleteCArray(ptr) Delete_CArray(__FILE__,__FUNCTION__,__LINE__,ptr)
#endif 
#else
#ifndef NewCArray
#define NewCArray(type,...) New_CArray(sizeof(type),##__VA_ARGS__,0)
#endif 
#ifndef DeleteCArray
#define DeleteCArray(ptr) free(ptr)
#endif 
#endif 

#endif




