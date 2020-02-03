#include"CArray.h"
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

inline void *new_carray(const size_t &typesize, va_list &arg)
{
    //ͳ�Ʋ���
    size_t demension = 0;   //�����ά��
    size_t a[64];           //����ά�ȵ�����,���63ά
    while (demension != 64)
    {
        a[demension] = va_arg(arg, size_t);
        if (a[demension] < 0)
        {
            return NULL;
        }
        else if (a[demension] == 0)
        {
            break;
        }
        else
        {
            demension++;
        }
    }
    if (demension == 64 || demension == 0)
    {
        return NULL;
    }
    else if (demension == 1)
    {
        return malloc(typesize *a[0]);
    }

    //ͳ����Ŀ
    size_t b[64];           //b[i] = �۳ˣ�a[i]��= b[i-1]*a[i]
    size_t c[64];           //c[i] = �ۼ�(b[i])
    double deta_b[64];            //�����Ƿ�����
    double deta_c[64];            //�����Ƿ�����
    size_t num_array = 0;   //�����ܸ���
    size_t num_ptr = 0;     //ָ���ܸ���
    size_t num_men = 0;     //�ڴ��С
    double deta_men;              //�����Ƿ�����
    b[0] = a[0];
    c[0] = b[0];
    deta_b[0] = a[0];
    deta_c[0] = deta_b[0];
    for (int i = 1; i < demension; ++i)
    {
        b[i] = b[i - 1] * a[i];
        c[i] = c[i - 1] + b[i];
        deta_b[i] = deta_b[i - 1] * a[i];
        deta_c[i] = deta_c[i - 1] + b[i];
        if (deta_b[i] > UINT_MAX || deta_c[i] > UINT_MAX)
        {
            return NULL;
        }
    }
    num_array = b[demension - 1];
    num_ptr = c[demension - 2];
    deta_men = num_array * typesize + num_ptr * sizeof(char *);
    if (deta_men > UINT_MAX)
    {
        return NULL;
    }
    num_men = num_array * typesize + num_ptr * sizeof(char *);

    //�����ڴ��
    char **ptr = (char **)malloc(num_men);
    if (ptr == NULL)
    {
        return NULL;
    }

    //����ָ��
    char** ptr_begin[64];               //����ָ�����
    size_t ptr_space[64];         //����ָ����
                                  //ptr_num[64] = b[64]
    ptr_begin[0] = ptr;
    ptr_space[0] = 1;
    for (int i = 1; i < demension - 1; ++i)
    {
        ptr_begin[i] = ptr_begin[i - 1] + b[i - 1];
        ptr_space[i] = a[i];
    }

    for (int i = 0; i < demension - 2; ++i)
    {
        for (int j = 0; j < b[i]; ++j)
        {
            ptr_begin[i][j] = (char *)(ptr_begin[i + 1] + j*ptr_space[i + 1]);
        }
    }

    char * type_begin = (char *)(ptr_begin[demension - 2] + b[demension - 2]);
    size_t type_space = typesize;
    for (int k = 0; k < b[demension - 2]; ++k)
    {
        ptr_begin[demension - 2][k] = (char *)(type_begin + k*typesize);
    }
    return ptr;
}

void * New_CArray(size_t typesize, ...)
{
    va_list arg;
    va_start(arg, typesize);
    void *ptr = new_carray(typesize, arg);
    va_end(arg);
    return ptr;
}


#include"MemLeakChecker.h"
void * New_CArray(const char* file, const char* func, int line, size_t typesize, ...)
{
    va_list arg;
    va_start(arg, typesize);
    void *ptr = new_carray(typesize, arg);
    va_end(arg);
    if (ptr != NULL)
    {
        MemLeakChecker::Insert(ptr, file, func, line);
    }
    return ptr;
}

void Delete_CArray(const char* file, const char* func, int line, void *ptr)
{
    if(ptr!=NULL)
    {
        free(ptr);
        MemLeakChecker::Delete(ptr);
    }
    return;
}


bool Fill_CArray(void *dest, const void *src, size_t n, ...)
{
    //ͳ�Ʋ���
    size_t demension = 0;   //�����ά��
    size_t a[64];           //����ά�ȵ�����,���63ά
    va_list arg;
    va_start(arg, dest);
    while (demension != 64)
    {
        a[demension] = va_arg(arg, size_t);
        if (a[demension] < 0)
        {
            va_end(arg);
            return false;
        }
        else if (a[demension] == 0)
        {
            break;
        }
        else
        {
            demension++;
        }
    }
    va_end(arg);
    if (demension == 64 || demension == 0)
    {
        return false;
    }

    //ͳ����Ŀ
    size_t b[64];           //b[i] = �۳ˣ�a[i]��= b[i-1]*a[i]
    size_t c[64];           //c[i] = �ۼ�(b[i])
    size_t num_array = 0;   //�����ܸ���
    size_t num_ptr = 0;     //ָ���ܸ���
    b[0] = a[0];
    c[0] = b[0];
    for (int i = 1; i < demension; ++i)
    {
        b[i] = b[i - 1] * a[i];
        c[i] = c[i - 1] + b[i];
    }
    num_array = b[demension - 1];
    num_ptr = c[demension - 2];
    void *ptr_arr = ((char **)dest) + num_ptr;

    //TODO���Ż��ڴ渴�Ʋ��ԡ�
    for (int i = 0; i < num_array; ++i)
    {
        memcpy(ptr_arr, src, n);
    }

    return true;
}