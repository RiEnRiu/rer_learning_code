
#include"MemLeakChecker.h"
#include<stdio.h>
#include<stdlib.h>

struct MemInfo
{
    void *ptr;
    const char *file;
    const char *func;
    int line;
    MemInfo *next;
};

MemLeakChecker::MemLeakChecker()
{
}

MemLeakChecker::~MemLeakChecker()
{
}

MemLeakChecker::MemLeakChecker(const MemLeakChecker&)
{
}

MemLeakChecker& MemLeakChecker::operator=(const MemLeakChecker&)
{
    MemLeakChecker t;
    return t;
}

MemInfo *MemLeakChecker::head = NULL;

MemLeakChecker::Clearer MemLeakChecker::clearer;

void MemLeakChecker::Insert(void* ptr, const char* file, const char *func, int line)
{
    int begin = 0;
    for (int i = 0; file[i] != '\0'; ++i)
    {
        if (file[i] == '\\')

        {
            begin = i + 1;
        }
    }

    MemInfo* node = (MemInfo*) malloc(sizeof(MemInfo));
    node->ptr = ptr;
    node->file = &file[begin];
    node->func = func;
    node->line = line;
    node->next = head;
    head = node;
    return;
}


void MemLeakChecker::Delete(void* ptr)
{
    MemInfo* node = head;
    MemInfo* pre = NULL;
    while (node != NULL && node->ptr != ptr)
    {
        pre = node;
        node = node->next;
    }
    if (node != NULL)
    {
        if (pre == NULL)
            head = node->next;
        else
            pre->next = node->next;
        free(node);
    }

}

void MemLeakChecker::Print()
{

    printf("***************************************************\n");
    printf("%s    %s\n\n", __DATE__, __TIME__);
    MemInfo* node = head;
    while (node != NULL)
    {
        printf("Memory : %p      Line : %d      Function : %s      File : %s\n", node->ptr,
            node->line, node->func, node->file);
        node = node->next;
    }
    printf("***************************************************\n");
    return;
}


void MemLeakChecker::ClearInfo()
{
    MemInfo *node = head;
    head = NULL;
    MemInfo cache;
    while (node != NULL)
    {
        cache = *node;
        free(node);
        node = cache.next;
    }
    //printf("ÇåÀíÁËInfo\n");
    //getchar();
    return;
}

void MemLeakChecker::Report()
{
    const char *path_fname = "MLI_Report.txt";
    if (head != NULL)
    {

        FILE *fp;
        errno_t err = fopen_s(&fp, path_fname, "w");
        if (err != 0)
        {
            return;
        }
        fprintf(fp, "%s    %s\n\n" __DATE__, __TIME__);
        MemInfo* node = head;
        while (node != NULL)
        {
            fprintf(fp, "Memory : %p      Line : %d      Function : %s      File : %s\n", node->ptr, node->line, node->func, node->file);
            node = node->next;

        }
        fclose(fp);
    }
    return;
}

#ifdef _DEBUG
#include<stdlib.h>

void* operator new(size_t size, const char* file, const char* func, int line)
{
    void* ptr = malloc(size);
    if (ptr != NULL)
    { 
        MemLeakChecker::Insert(ptr, file, func, line);
    }
    return ptr;
}

void* operator new[](size_t size, const char* file, const char* func, int line)
{
    return operator new(size, file, func, line);
}

void operator delete(void* ptr)
{
    if(ptr!=NULL)
    {
        free(ptr);
        MemLeakChecker::Delete(ptr);
    }
    return;
}

void operator delete[](void* ptr)
{
    operator delete(ptr);
}

#endif



MemLeakChecker::Clearer::Clearer()
{
}

MemLeakChecker::Clearer::~Clearer()
{
    ClearInfo();
}


