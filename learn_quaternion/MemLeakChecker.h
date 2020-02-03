
#ifndef MEMLEAKCHECKER_H
#define MEMLEAKCHECKER_H

#include<stdlib.h>
#include<stdio.h>


struct MemInfo;
static class MemLeakChecker
{
private:
    MemLeakChecker();
    ~MemLeakChecker();
    MemLeakChecker(const MemLeakChecker&);
    MemLeakChecker& operator=(const MemLeakChecker&);
    static MemInfo *head;
    class Clearer
    {
    public:
        Clearer();
        ~Clearer();
    };
    static Clearer clearer;
    static void ClearInfo();
public:
    static void Insert(void* ptr, const char* file, const char *func, int line);
    static void Delete(void* ptr);
    static void Print();
    static void Report();
};

/////////////////////////////////////////////////////////////////////


//new 操作符 —— new (a0, a1, ...) T(b0, b1, ...) —— 的行为是固定的：
//new.1.调用 operator new(a0, a1, ...) 函数获得内存
//new.2.在该内存上使用 T(b0, b1, ...) 构造
//
//delete 操作符 —— delete (c0, c1, ...) p —— 的行为也是固定的：
//delete.1.调用 p->~T()
//delete.2.调用 operator delete(c0, c1, ...) 函数释放内存
//
//operator new / delete只能控制 new.1与delete.2 的行为，并且，与自动内存管理完全没有关系……
//如果new操作符对应的operator new函数有匹配的operator delete函数，编译器会产生代码，保证如果new.1成功，new.2失败的情况下会执行delete.2
//
//但是这边的delete.2只有在new.2出现异常的时候才会被编译器变程序中。那么需要怎么做才能让编译主动的去使用delete.2（自己重载的delete）。
//
//placement delete是不能直接被调用的，只能通过operator delete(p, file, line)显示调用，但是这样只释放的内存，并没有执行析构。
////////////////////////////////////////////////////////////////////////////




#ifdef _DEBUG
void* operator new(size_t size, const char* file, const char* func, int line);
void* operator new[](size_t size, const char* file, const char* func, int line);
void operator delete(void* ptr);
void operator delete[](void* ptr);
#define MLC_New new(__FILE__,__FUNCTION__ ,__LINE__)
#define MLC_Print MemLeakChecker::Print()
#define MLC_Report MemLeakChecker::Report()

#else
#define MLC_New new
#define MLC_Print 
#define MLC_Report 

#endif

#endif // !MEMLEAKCHECKER_H


