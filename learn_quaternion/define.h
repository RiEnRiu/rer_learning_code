
#ifndef DEFINE_H
#define DEFINE_H

#ifndef MAX
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef PI
#define PI  3.141592653589793 
#endif 

#ifndef RADIANS
#define RADIANS(x) (x*PI/180.0)
#endif 

#ifndef DEGREES
#define DEGREES(x) (x*180.0/PI)
#endif 

#ifndef Malloc
#define Malloc(type,n) (type *)malloc((n)*sizeof(type))
#endif


#endif // !DEFINE_H