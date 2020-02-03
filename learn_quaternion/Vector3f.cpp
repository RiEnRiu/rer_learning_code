#include"Vector3f.h"
#include"define.h"
#include<math.h>

tagVector3f::tagVector3f()
{
}
tagVector3f::tagVector3f(const float &ex, const float &ey, const float &ez)
{
    x = ex;
    y = ey;
    z = ez;
}

tagVector3f::~tagVector3f()
{
}

float tagVector3f::Dot(const tagVector3f &a, const tagVector3f &b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

float tagVector3f::Length(const tagVector3f &v)
{
    return sqrtf(Dot(v, v));
}

tagVector3f tagVector3f::Cross(const tagVector3f &a, const tagVector3f &b)
{
    tagVector3f r;
    r.x = a.y*b.z - a.z*b.y;
    r.y = a.z*b.x - a.x*b.z;
    r.z = a.x*b.y - a.y*b.x;
    return r;
}

tagVector3f tagVector3f::Norm(const tagVector3f &v)
{
    tagVector3f V;
    float l = Length(v);
    V.x = v.x / l;
    V.y = v.y / l;
    V.z = v.z / l;
    return V;
}

void tagVector3f::Set(const float &ex, const float &ey, const float &ez)
{
    x = ex;
    y = ey;
    z = ez;
    return;
}

void tagVector3f::SetNorm()
{
    *this = Norm(*this);
    return;
}

float tagVector3f::GetLength()const
{
    return Length(*this);
}

tagVector3f tagVector3f::GetNorm()const
{
    return Norm(*this);
}

/*
tagQuaternion QPreMul(const tagQuaternion &Q1, const tagQuaternion &Q2)

{
    tagQuaternion Q;

    Q.w = Q1.w*Q2.w - Q1.x*Q2.x - Q1.y*Q2.y - Q1.z*Q2.z;

    Q.x = Q1.x*Q2.w + Q1.w*Q2.x - Q1.z*Q2.y + Q1.y*Q2.z;

    Q.y = Q1.y*Q2.w + Q1.w*Q2.y + Q1.z*Q2.x - Q1.x*Q2.z;

    Q.z = Q1.w*Q2.z + Q1.z*Q2.w + Q1.x*Q2.y - Q1.y*Q2.x;

    return Q;

}


tagQuaternion QInv(const tagQuaternion &Q1)

{
    tagQuaternion Q;

    Q.w = Q1.w;

    Q.x = -Q1.x;

    Q.y = -Q1.y;

    Q.z = -Q1.z;

    return Q;

}


float QDot(const tagQuaternion &Q1, const tagQuaternion &Q2)
{
    return Q1.w*Q2.w + Q1.x*Q2.x + Q1.y*Q2.y + Q1.z*Q2.z;
}


float QLength(const tagQuaternion &Q1)
{
    return sqrt(QDot(Q1, Q1));
}


tagQuaternion QNorm(const tagQuaternion &Q1)
{
    tagQuaternion Q;
    float Length = QLength(Q1);
    Q.w = Q1.w / Length;
    Q.x = Q1.x / Length;
    Q.y = Q1.y / Length;
    Q.z = Q1.z / Length;
    return Q;
}

tagQuaternion QRegular(const tagQuaternion &Q1)
{
    if (Q1.w < 0)
    {
        tagQuaternion Q;
        Q.w = -Q1.w;
        Q.x = -Q1.x;
        Q.y = -Q1.y;
        Q.z = -Q1.z;
        return Q;
    }
    else
    {
        return Q1;
    }
}



tagQuaternion PointCross(const tagQuaternion &Q1, const tagQuaternion &Q2)
{
    tagQuaternion Q;
    Q.w = 0;
    Q.x = Q1.y*Q2.z - Q1.z*Q2.y;
    Q.y = Q1.z*Q2.x - Q1.x*Q2.z;
    Q.z = Q1.x*Q2.y - Q1.y*Q2.x;
    return Q;
}
tagVector PointCross(const tagVector &V1, const tagVector &V2)
{
    tagVector V;
    V.x = V1.y*V2.z - V1.z*V2.y;
    V.y = V1.z*V2.x - V1.x*V2.z;
    V.z = V1.x*V2.y - V1.y*V2.x;
    return V;
}

float PointCosAngle(const tagQuaternion &Q1, const tagQuaternion &Q2)
{
    float a = PointDot(Q1, Q2);
    float b = PointLength(Q1);
    b *= PointLength(Q2);
    return a / b;
}

float PointCosAngle(const tagVector &V1, const tagVector &V2)
{
    float a = PointDot(V1, V2);
    float b = PointLength(V1);
    b *= PointLength(V2);
    return a / b;
}


tagQuaternion PointNorm(const tagQuaternion &Q1)
{
    tagQuaternion Q = { 0,Q1.x,Q1.y,Q1.z };
    return QNorm(Q);
}

tagVector PointNorm(const tagVector &V1)
{
    double a = V1.x*V1.x + V1.y*V1.y + V1.z*V1.z;
    a = sqrt(a);
    tagVector V = { V1.x / a,V1.y / a ,V1.z / a };
    return V;
}




tagQuaternion QChangW(const tagQuaternion &Q, const float &w)
{
    tagQuaternion q;

    double a = sqrt(Q.x*Q.x + Q.y*Q.y + Q.z*Q.z);
    double sin_half_angle = sqrt(1 - w*w);
    q.w = w;
    q.x = Q.x / a*sin_half_angle;
    q.y = Q.y / a*sin_half_angle;
    q.z = Q.z / a*sin_half_angle;
    return q;
}


tagQuaternion VectorRotation(const tagQuaternion &Qbegin, const tagQuaternion &Qend)
{
    double cos_angle = PointCosAngle(Qbegin, Qend);
    tagQuaternion Q = PointCross(Qbegin, Qend);
    float Qw = sqrt((cos_angle + 1) / 2);
    return QChangW(Q, Qw);
}
tagQuaternion VectorRotation(const tagVector &Qbegin, const tagVector &Qend)
{
    double cos_angle = PointCosAngle(Qbegin, Qend);
    tagVector V = PointCross(Qbegin, Qend);
    float Qw = sqrt((cos_angle + 1) / 2);
    double a = sqrt(V.x*V.x + V.y*V.y + V.z*V.z);
    double sin_half_angle = sqrt(1 - Qw*Qw);
    tagQuaternion Q = { 
        Qw,
        V.x / a * sin_half_angle,
        V.y / a * sin_half_angle,
        V.z / a * sin_half_angle };
    return Q;
}


tagQuaternion Eular2Quater(const tagVector &E)
{
    float cx = cos(E.x / 2);
    float sx = sin(E.x / 2);
    float cy = cos(E.y / 2);
    float sy = sin(E.y / 2);    
    float cz = cos(E.z / 2);
    float sz = sin(E.z / 2);

    tagQuaternion q;
    q.w = cx*cy*cz + sx*sy*sz;
    q.x = sx*cy*cz + cx*sy*sz;
    q.y = cx*sy*cz - sx*cy*sz;
    q.z = cx*sy*sz - sx*cy*cz;

    return q;
}


tagVector Quater2Eular(const tagQuaternion &Q)
{
    float error = 1.0e-6f;
    const float &w = Q.w;
    const float &x = Q.x;
    const float &y = Q.y;
    const float &z = Q.z;
    float sx = 2 * (w*x - y*z);
    float sy = 2 * (w*y + x*z);
    float cy = 2 * (w*w + z*z) - 1;
    float sz = 2 * (w*z + x*y);
    float cz = 2 * (w*w + y*y) - 1;

    tagVector eular;
    eular.x = asinf(sx);
    if (sx < 0)
    {
        eular.x += 2 * PI;
    }

    if (0 <= cy&&cy < error)
    {
        eular.y = PI / 2;
    }
    else if (-error < cy&&cy < 0)
    {
        eular.y = 1.5f*PI;
    }
    else
    {
        eular.y = atan2f(cy, sy);
    }
    if (cy < 0)
    {
        eular.y += PI;
    }
    else if (sy < 0)
    {
        eular.y += 2 * PI;
    }

    if (0 <= cz&&cz < error)
    {
        eular.z = PI / 2;
    }
    else if (-error < cz&&cz < 0)
    {
        eular.z = 1.5f*PI;
    }
    else
    {
        eular.z = atan2f(cz, sz);
    }
    if (cz < 0)
    {
        eular.z += PI;
    }
    else if (sz < 0)
    {
        eular.z += 2 * PI;
    }

    return eular;
}



float PointDot(const tagQuaternion &Q1, const tagQuaternion &Q2)
{
    return Q1.x*Q2.x + Q1.y*Q2.y + Q1.z*Q2.z;
}

float PointDot(const tagVector &V1, const tagVector &V2)
{
    return V1.x*V2.x + V1.y*V2.y + V1.z*V2.z;
}


float PointLength(const tagQuaternion &Q1)
{
    return sqrt(PointDot(Q1, Q1));
}
float PointLength(const tagVector &V1)
{
    return sqrt(PointDot(V1, V1));
}


tagQuaternion PointTimes(const tagQuaternion &Q1, const float Times)
{
    tagQuaternion Q;
    Q.w = 0;
    Q.x = Q1.x*Times;
    Q.y = Q1.y*Times;
    Q.z = Q1.z*Times;
    return Q;
}


tagQuaternion PointNega(const tagQuaternion &Q1)
{
    tagQuaternion Q;
    Q.w = 0;
    Q.x = -Q1.x;
    Q.y = -Q1.y;
    Q.z = -Q1.z;
    return Q;
}

tagVector PointNega(const tagVector &V1)
{
    tagVector V;
    V.x = -V1.x;
    V.y = -V1.y;
    V.z = -V1.z;
    return V;
}

tagQuaternion PointAdd(const tagQuaternion &Q1, const tagQuaternion &Q2)
{
    tagQuaternion Q;
    Q.w = 0;
    Q.x = Q1.x + Q2.x;
    Q.y = Q1.y + Q2.y;
    Q.z = Q1.z + Q2.z;
    return Q;
}
tagVector PointAdd(const tagVector &V1, const tagVector &V2)
{
    tagVector V;
    V.x = V1.x + V2.x;
    V.y = V1.y + V2.y;
    V.z = V1.z + V2.z;
    return V;
}


tagQuaternion QRotPoint(const tagQuaternion &Q, const tagQuaternion &P)
{
    tagQuaternion _Q = QInv(Q);
    return QRotPoint(Q, P, _Q);
}
tagQuaternion QRotPoint(const tagQuaternion &Q, const tagQuaternion &P, const tagQuaternion &_Q)
{
    tagQuaternion p1 = QPreMul(Q, P);
    p1 = QPreMul(p1, _Q);
    p1.w = 0;
    return p1;
}

tagVector QRotPoint(const tagQuaternion &Q, const tagVector &P)
{
    tagQuaternion _Q = QInv(Q);
    return QRotPoint(Q, P, _Q);
}
tagVector QRotPoint(const tagQuaternion &Q, const tagVector &P, const tagQuaternion &_Q)
{
    tagQuaternion p1 = { 0, P.x,P.y,P.z };
    p1 = QPreMul(Q, p1);
    p1 = QPreMul(p1, _Q);
    tagVector p = { p1.x,p1.y,p1.z };
    return p;
}

*/