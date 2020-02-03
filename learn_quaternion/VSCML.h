#ifndef VSCML_H
#define VSCML_H

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>
#define VS_CheckMemoryLeak _CrtSetDbgFlag( _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG )| _CRTDBG_LEAK_CHECK_DF)
#else

#define VS_CheckMemoryLeak 

#endif

#endif 