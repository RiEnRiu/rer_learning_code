
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


//new ������ ���� new (a0, a1, ...) T(b0, b1, ...) ���� ����Ϊ�ǹ̶��ģ�
//new.1.���� operator new(a0, a1, ...) ��������ڴ�
//new.2.�ڸ��ڴ���ʹ�� T(b0, b1, ...) ����
//
//delete ������ ���� delete (c0, c1, ...) p ���� ����ΪҲ�ǹ̶��ģ�
//delete.1.���� p->~T()
//delete.2.���� operator delete(c0, c1, ...) �����ͷ��ڴ�
//
//operator new / deleteֻ�ܿ��� new.1��delete.2 ����Ϊ�����ң����Զ��ڴ������ȫû�й�ϵ����
//���new��������Ӧ��operator new������ƥ���operator delete��������������������룬��֤���new.1�ɹ���new.2ʧ�ܵ�����»�ִ��delete.2
//
//������ߵ�delete.2ֻ����new.2�����쳣��ʱ��Żᱻ������������С���ô��Ҫ��ô�������ñ���������ȥʹ��delete.2���Լ����ص�delete����
//
//placement delete�ǲ���ֱ�ӱ����õģ�ֻ��ͨ��operator delete(p, file, line)��ʾ���ã���������ֻ�ͷŵ��ڴ棬��û��ִ��������
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


