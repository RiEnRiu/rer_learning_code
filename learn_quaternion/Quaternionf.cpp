#include"Quaternionf.h"
#include"Vector3f.h"
#include"define.h"
#include<math.h>

const float tagQuaternionf::epsilon = 1E-06f;

tagVector3f tagQuaternionf::Euler(const float &cos_b, const float &sin_a, 
    const float &cos_a, const float &sin_c, const float &cos_c) const
{
    tagVector3f euler;
    euler.x = DEGREES(atan2f(sin_a, cos_a));
    euler.z = DEGREES(atan2f(sin_c, cos_c));
    if (cos_b < -1.0f)
    {
        euler.y = DEGREES(acosf(-1.0f));
    }
    else if (cos_b > 1.0f)
    {
        euler.y = DEGREES(acosf(1.0f));
    }
    else
    {
        euler.y = DEGREES(acosf(cos_b));
    }
    return euler;
}

tagVector3f tagQuaternionf::Cardano(const float &sin_b, const float &sin_a,
    const float &cos_a, const float &sin_c, const float &cos_c) const
{
    tagVector3f euler;
    euler.x = DEGREES(atan2f(sin_a, cos_a));
    euler.z = DEGREES(atan2f(sin_c, cos_c));
    if (sin_b < -1.0f)
    {
        euler.y = DEGREES(asinf(-1.0f));
    }
    else if (sin_b > 1.0f)
    {
        euler.y = DEGREES(asinf(1.0f));
    }
    else
    {
        euler.y = DEGREES(asinf(sin_b));
    }
    return euler;
}

tagVector3f tagQuaternionf::EulerAngleXYX() const
{
    float cos_b = 2 * (w*w + x*x) - 1;
    float sin_a = 2 * (w*z + x*y);
    float cos_a = 2 * (w*y - x*z);
    float sin_c = 2 * (x*y - w*z);
    float cos_c = 2 * (w*y + x*z);
    return Euler(cos_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleXZX() const
{
    float cos_b = 2 * (w*w + x*x) - 1;
    float sin_a = 2 * (x*z - w*y);
    float cos_a = 2 * (w*z + x*y);
    float sin_c = 2 * (w*y + x*z);
    float cos_c = 2 * (w*z - x*y);
    return Euler(cos_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleYXY() const
{
    float cos_b = 2 * (w*w + y*y) - 1;
    float sin_a = 2 * (x*y - w*z);
    float cos_a = 2 * (w*x + y*z);
    float sin_c = 2 * (w*z + x*y);
    float cos_c = 2 * (w*x - y*z);
    return Euler(cos_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleYZY() const
{
    float cos_b = 2 * (w*w + y*y) - 1;
    float sin_a = 2 * (w*x + y*z);
    float cos_a = 2 * (w*z - x*y);
    float sin_c = 2 * (y*z - w*x);
    float cos_c = 2 * (w*z + x*y);
    return Euler(cos_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleZXZ() const
{
    float cos_b = 2 * (w*w + z*z) - 1;
    float sin_a = 2 * (w*y + x*z);
    float cos_a = 2 * (w*x - y*z);
    float sin_c = 2 * (x*z - w*y);
    float cos_c = 2 * (w*x + y*z);
    return Euler(cos_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleZYZ() const
{
    float cos_b = 2 * (w*w + z*z) - 1;
    float sin_a = 2 * (y*z - w*x);
    float cos_a = 2 * (w*y + x*z);
    float sin_c = 2 * (w*x + y*z);
    float cos_c = 2 * (w*y - x*z);
    return Euler(cos_b,sin_a,cos_a,sin_c,cos_c);
}

tagVector3f tagQuaternionf::EulerAngleXYZ() const
{
    float sin_b = 2 * (w*y + x*z);
    float sin_a = 2 * (w*x - y*z);
    float cos_a = 2 * (w*w + z*z) - 1;
    float sin_c = 2 * (w*z - x*y);
    float cos_c = 2 * (w*w + x*x) - 1;
    return Cardano(sin_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleXZY() const
{
    float sin_b = 2 * (w*z - x*y);
    float sin_a = 2 * (w*x + y*z);
    float cos_a = 2 * (w*w + y*y) - 1;
    float sin_c = 2 * (w*y + x*z);
    float cos_c = 2 * (w*w + x*x) - 1;
    return Cardano(sin_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleYXZ() const
{
    float sin_b = 2 * (w*x - y*z);
    float sin_a = 2 * (w*y + x*z);
    float cos_a = 2 * (w*w + z*z) - 1;
    float sin_c = 2 * (w*z + x*y);
    float cos_c = 2 * (w*w + y*y) - 1;
    return Cardano(sin_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleYZX() const
{
    float sin_b = 2 * (w*z + x*y);
    float sin_a = 2 * (w*y - x*z);
    float cos_a = 2 * (w*w + x*x) - 1;
    float sin_c = 2 * (w*x - y*z);
    float cos_c = 2 * (w*w + y*y) - 1;
    return Cardano(sin_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleZXY() const
{
    float sin_b = 2 * (w*x + y*z);
    float sin_a = 2 * (w*z - x*y);
    float cos_a = 2 * (w*w + y*y) - 1;
    float sin_c = 2 * (w*y - x*z);
    float cos_c = 2 * (w*w + z*z) - 1;
    return Cardano(sin_b, sin_a, cos_a, sin_c, cos_c);
}

tagVector3f tagQuaternionf::EulerAngleZYX() const
{
    float sin_b = 2 * (w*y - x*z);
    float sin_a = 2 * (w*z + x*y);
    float cos_a = 2 * (w*w + x*x) - 1;
    float sin_c = 2 * (w*x + y*z);
    float cos_c = 2 * (w*w + z*z) - 1;
    return Cardano(sin_b, sin_a, cos_a, sin_c, cos_c);
}

tagQuaternionf::tagQuaternionf()
{
}

tagQuaternionf::tagQuaternionf(const float &qw, const float &qx, const float &qy, const float &qz)
{
    w = qw;
    x = qx;
    y = qy;
    z = qz;
}

tagQuaternionf::tagQuaternionf(const float &a, const float &b, const float &c, const EULER_ANGLE_ORDER type)
{
    tagQuaternionf q1;
    tagQuaternionf q2;
    tagQuaternionf q3;
    tagQuaternionf q;
    switch (type)
    {
    case XYX:
        q1 = { cosf(RADIANS(a / 2.0f)),sinf(RADIANS(a / 2.0f)),0.0f,0.0f };
        q2 = { cosf(RADIANS(b / 2.0f)),0.0f,sinf(RADIANS(b / 2.0f)),0.0f };
        q3 = { cosf(RADIANS(c / 2.0f)),sinf(RADIANS(c / 2.0f)),0.0f,0.0f };
    case XZX:
        q1 = { cosf(RADIANS(a / 2.0f)),sinf(RADIANS(a / 2.0f)),0.0f,0.0f };
        q2 = { cosf(RADIANS(b / 2.0f)),0.0f,0.0f,sinf(RADIANS(b / 2.0f)) };
        q3 = { cosf(RADIANS(c / 2.0f)),sinf(RADIANS(c / 2.0f)),0.0f,0.0f };
    case YXY:
        q1 = { cosf(RADIANS(a / 2.0f)),0.0f,sinf(RADIANS(a / 2.0f)),0.0f };
        q2 = { cosf(RADIANS(b / 2.0f)),sinf(RADIANS(b / 2.0f)),0.0f,0.0f };
        q3 = { cosf(RADIANS(c / 2.0f)),0.0f,sinf(RADIANS(c / 2.0f)),0.0f };
    case YZY:
        q1 = { cosf(RADIANS(a / 2.0f)),0.0f,sinf(RADIANS(a / 2.0f)),0.0f };
        q2 = { cosf(RADIANS(b / 2.0f)),0.0f,0.0f,sinf(RADIANS(b / 2.0f)) };
        q3 = { cosf(RADIANS(c / 2.0f)),0.0f,sinf(RADIANS(c / 2.0f)),0.0f };
    case ZXZ:
        q1 = { cosf(RADIANS(a / 2.0f)),0.0f,0.0f,sinf(RADIANS(a / 2.0f)) };
        q2 = { cosf(RADIANS(b / 2.0f)),sinf(RADIANS(b / 2.0f)),0.0f,0.0f };
        q3 = { cosf(RADIANS(c / 2.0f)),0.0f,0.0f,sinf(RADIANS(c / 2.0f)) };
    case ZYZ:
        q1 = { cosf(RADIANS(a / 2.0f)),0.0f,0.0f,sinf(RADIANS(a / 2.0f)) };
        q2 = { cosf(RADIANS(b / 2.0f)),0.0f,sinf(RADIANS(b / 2.0f)),0.0f };
        q3 = { cosf(RADIANS(c / 2.0f)),0.0f,0.0f,sinf(RADIANS(c / 2.0f)) };
    case XYZ:
        q1 = { cosf(RADIANS(a / 2.0f)),sinf(RADIANS(a / 2.0f)),0.0f,0.0f };
        q2 = { cosf(RADIANS(b / 2.0f)),0.0f,sinf(RADIANS(b / 2.0f)),0.0f };
        q3 = { cosf(RADIANS(c / 2.0f)),0.0f,0.0f,sinf(RADIANS(c / 2.0f)) };
    case XZY:
        q1 = { cosf(RADIANS(a / 2.0f)),sinf(RADIANS(a / 2.0f)),0.0f,0.0f };
        q2 = { cosf(RADIANS(b / 2.0f)),0.0f,0.0f,sinf(RADIANS(b / 2.0f)) };
        q3 = { cosf(RADIANS(c / 2.0f)),0.0f,sinf(RADIANS(c / 2.0f)),0.0f };
    case YXZ:
        q1 = { cosf(RADIANS(a / 2.0f)),0.0f,sinf(RADIANS(a / 2.0f)),0.0f };
        q2 = { cosf(RADIANS(b / 2.0f)),sinf(RADIANS(b / 2.0f)),0.0f,0.0f };
        q3 = { cosf(RADIANS(c / 2.0f)),0.0f,0.0f,sinf(RADIANS(c / 2.0f)) };
    case YZX:
        q1 = { cosf(RADIANS(a / 2.0f)),0.0f,sinf(RADIANS(a / 2.0f)),0.0f };
        q2 = { cosf(RADIANS(b / 2.0f)),0.0f,0.0f,sinf(RADIANS(b / 2.0f)) };
        q3 = { cosf(RADIANS(c / 2.0f)),sinf(RADIANS(c / 2.0f)),0.0f,0.0f };
    case ZXY:
        q1 = { cosf(RADIANS(a / 2.0f)),0.0f,0.0f,sinf(RADIANS(a / 2.0f)) };
        q2 = { cosf(RADIANS(b / 2.0f)),sinf(RADIANS(b / 2.0f)),0.0f,0.0f };
        q3 = { cosf(RADIANS(c / 2.0f)),0.0f,sinf(RADIANS(c / 2.0f)),0.0f };
    case ZYX:
        q1 = { cosf(RADIANS(a / 2.0f)),0.0f,0.0f,sinf(RADIANS(a / 2.0f)) };
        q2 = { cosf(RADIANS(b / 2.0f)),0.0f,sinf(RADIANS(b / 2.0f)),0.0f };
        q3 = { cosf(RADIANS(c / 2.0f)),sinf(RADIANS(c / 2.0f)),0.0f,0.0f };
    default:w = 1.0f; x = 0.0f; y = 0.0f; z = 0.0f; return;
    }
    q = q1 * q2 * q3;
    w = q.w;
    x = q.x;
    y = q.y;
    z = q.z;
}

tagQuaternionf::tagQuaternionf(const float &angle, const  tagVector3f &axis)
{
    float half_radian = RADIANS(angle) / 2.0f;
    float cos_half_angle = cosf(half_radian);
    float sin_half_angle = sinf(half_radian);
    tagVector3f V = axis.GetNorm();
    w = cos_half_angle;
    x = sin_half_angle *V.x;
    y = sin_half_angle *V.y;
    z = sin_half_angle *V.z;
}

tagQuaternionf tagQuaternionf::Unit()
{
    return tagQuaternionf(1, 0, 0, 0);
}

float tagQuaternionf::Dot(const tagQuaternionf &a, const tagQuaternionf &b)
{
    return a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z;
}

tagVector3f tagQuaternionf::RotatePoint(const tagQuaternionf &rotation, const tagVector3f& point)
{
    const float ss = rotation.w*rotation.w;
    const float sa2 = rotation.w*rotation.x;
    const float sb2 = rotation.w*rotation.y;
    const float sc2 = rotation.w*rotation.z;
    const float aa = rotation.x*rotation.x;
    const float ab2 = rotation.x*rotation.y;
    const float ac2 = rotation.x*rotation.z;
    const float bb = rotation.y*rotation.y;
    const float bc2 = rotation.y*rotation.z;
    const float cc = rotation.z*rotation.z;

    const float &x = point.x;
    const float &y = point.y;
    const float &z = point.z;

    tagVector3f v;
    v.x = (aa - bb - cc + ss)*x + (ab2 - sc2)*y + (ac2 + sb2)*z;
    v.y = (ab2 + sc2)*x + (-aa + bb - cc + ss)*y + +(bc2 + sa2)*z;
    v.z = (ac2 - sb2)*x + (bc2 + sa2)*y + (-aa - bb + cc + ss)*z;
    return v;
}

tagVector3f tagQuaternionf::RotatePoint(const tagVector3f& point, const tagQuaternionf &rotation)
{
    const float ss = rotation.w*rotation.w;
    const float sa2 = rotation.w*rotation.x;
    const float sb2 = rotation.w*rotation.y;
    const float sc2 = rotation.w*rotation.z;
    const float aa = rotation.x*rotation.x;
    const float ab2 = rotation.x*rotation.y;
    const float ac2 = rotation.x*rotation.z;
    const float bb = rotation.y*rotation.y;
    const float bc2 = rotation.y*rotation.z;
    const float cc = rotation.z*rotation.z;

    const float &x = point.x;
    const float &y = point.y;
    const float &z = point.z;

    tagVector3f v;
    v.x = (aa - bb - cc + ss)*x + (ab2 - sc2)*y + (ac2 + sb2)*z;
    v.y = (ab2 + sc2)*x + (-aa + bb - cc + ss)*y + +(bc2 + sa2)*z;
    v.z = (ac2 - sb2)*x + (bc2 + sa2)*y + (-aa - bb + cc + ss)*z;
    return v;
}

tagQuaternionf tagQuaternionf::FromToRotation(const tagVector3f &fromDirection, const tagVector3f &toDirection)
{
    float Vdot = tagVector3f::Dot(fromDirection, toDirection);
    float cos_angle = Vdot / fromDirection.GetLength() / toDirection.GetLength();
    tagVector3f axis = tagVector3f::Cross(fromDirection, toDirection);
    axis.SetNorm();
    float cos_half_angle = sqrtf((cos_angle + 1.0f) / 2.0f);
    float sin_half_angle = sqrtf((1.0f - cos_angle) / 2.0f);
    return tagQuaternionf(cos_half_angle, sin_half_angle*axis.x, sin_half_angle*axis.y, sin_half_angle*axis.z);
}

tagQuaternionf tagQuaternionf::Lerp(const tagQuaternionf &a, const tagQuaternionf &b, const float &t)
{
    tagQuaternionf r = (1.0f - t)*a + t* b;
    return r.Norm();
}

tagQuaternionf tagQuaternionf::Slerp(const tagQuaternionf &a, const tagQuaternionf &b, const float &t)
{
    float Qdot = fabsf(Dot(a, b));
    float radian = acosf(Qdot);
    float sin_1_t_radian = sin((1.0f - t)*radian);
    float sin_t_radian = sin(t*radian);
    tagQuaternionf r = sin_1_t_radian*a + sin_t_radian*b;
    return r.Norm();
}

const float tagQuaternionf::Epsilon() const
{
    return epsilon;
}

float tagQuaternionf::Length() const 
{
    return sqrtf(Dot((*this), (*this)));
}

tagQuaternionf tagQuaternionf::Norm() const
{
    float l = Length();
    if (-epsilon < l&&l < epsilon)
    {
        return tagQuaternionf(0, 0, 0, 0);
    }
    return (*this) / l;
}

tagQuaternionf tagQuaternionf::RegularW() const
{
    if (w < 0)
    {
        return -(*this);
    }
    else
    {
        return (*this);
    }
}

tagQuaternionf tagQuaternionf::RegularX() const
{
    if (x < 0)
    {
        return -(*this);
    }
    else
    {
        return (*this);
    }
}

tagQuaternionf tagQuaternionf::RegularY() const
{
    if (y < 0)
    {
        return -(*this);
    }
    else
    {
        return (*this);
    }
}

tagQuaternionf tagQuaternionf::RegularZ() const
{
    if (z< 0)
    {
        return -(*this);
    }
    else
    {
        return (*this);
    }
}

tagQuaternionf tagQuaternionf::ChangeW(const float &qw) const
{
    float a = sqrtf(x*x + y*y + z*z);
    if (-epsilon < a&&a < epsilon)
    {
        return tagQuaternionf(1, 0, 0, 0);
    }
    float sin_half_angle = sqrtf(1 - qw*qw);
    float b = sin_half_angle / a;
    return tagQuaternionf(qw, x*b, y*b, z*b);
}



tagQuaternionf tagQuaternionf::ChangeAngle(const float &angle) const
{
    float cos_half_angle = cosf(RADIANS(angle) / 2.0f);
    return ChangeW(cos_half_angle);
}

tagQuaternionf tagQuaternionf::ChangeAxis(const tagVector3f &axis) const
{
    float l = tagVector3f::Length(axis);
    if (-epsilon < l&&l < epsilon)
    {
        return tagQuaternionf(1, 0, 0, 0);
    }
    float b = sqrtf(1 - w*w);
    return tagQuaternionf(w, axis.x*b, axis.y*b, axis.z*b);
}

void tagQuaternionf::AngleAxis(OUT float &angle, OUT tagVector3f &axis) const
{
    angle = acosf(w)*2.0f;
    axis.Set(x, y, z);
    axis.SetNorm();
    angle = DEGREES(angle);
    return;
}

tagQuaternionf tagQuaternionf::Inverse() const
{
    return tagQuaternionf(w, -x, -y, -z);
}

tagVector3f tagQuaternionf::EulerAngle(const EULER_ANGLE_ORDER type) const
{
    switch (type)
    {
    case XYX:return EulerAngleXYX();
    case XZX:return EulerAngleXZX();
    case YXY:return EulerAngleYXY();
    case YZY:return EulerAngleYZY();
    case ZXZ:return EulerAngleZXZ();
    case ZYZ:return EulerAngleZYZ();
    case XYZ:return EulerAngleXYZ();
    case XZY:return EulerAngleXZY();
    case YXZ:return EulerAngleYXZ();
    case YZX:return EulerAngleYZX();
    case ZXY:return EulerAngleZXY();
    case ZYX:return EulerAngleZYX();
    default:return tagVector3f(0.0f, 0.0f, 0.0f);
    }
}

tagQuaternionf tagQuaternionf::operator-() const
{
    return tagQuaternionf(-w, -x, -y, -z);
}

tagQuaternionf operator+(const tagQuaternionf &lhs, const tagQuaternionf &rhs)
{
    return tagQuaternionf(lhs.w + rhs.w, lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}


tagQuaternionf operator-(const tagQuaternionf &lhs, const tagQuaternionf &rhs)
{
    return tagQuaternionf(lhs.w - rhs.w, lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

tagQuaternionf operator*(const tagQuaternionf &lhs, const tagQuaternionf &rhs)
{
    tagQuaternionf Q;
    Q.w = lhs.w*rhs.w - lhs.x*rhs.x - lhs.y*rhs.y - lhs.z*rhs.z;
    Q.x = lhs.x*rhs.w + lhs.w*rhs.x - lhs.z*rhs.y + lhs.y*rhs.z;
    Q.y = lhs.y*rhs.w + lhs.w*rhs.y + lhs.z*rhs.x - lhs.x*rhs.z;
    Q.z = lhs.w*rhs.z + lhs.z*rhs.w + lhs.x*rhs.y - lhs.y*rhs.x;
    return Q;
}

tagQuaternionf operator*(const float &times, const tagQuaternionf &q)
{
    return tagQuaternionf(times*q.w, times*q.x, times*q.y, times*q.z);
}

tagQuaternionf operator*(const tagQuaternionf &q, const float &times)
{
    return tagQuaternionf(times*q.w, times*q.x, times*q.y, times*q.z);
}

tagQuaternionf operator/(const tagQuaternionf &lhs, const tagQuaternionf &rhs)
{
    return lhs*rhs.Inverse();
}

tagQuaternionf operator/(const tagQuaternionf &q, const float &times)
{
    float t = 1 / times;
    return q*t;
}

bool operator==(const tagQuaternionf &lhs, const tagQuaternionf &rhs)
{
    const float &kk = MAX(lhs.Epsilon(), rhs.Epsilon());
    if (fabsf(lhs.w - rhs.w) > kk)
    {
        return false;
    }
    if (fabsf(lhs.x - rhs.x) > kk)
    {
        return false;
    }
    if (fabsf(lhs.y - rhs.y) > kk)
    {
        return false;
    }
    if (fabsf(lhs.z - rhs.z) > kk)
    {
        return false;
    }
    return true;
}

bool operator!=(const tagQuaternionf &lhs, const tagQuaternionf &rhs)
{
    const float &kk = MAX(lhs.Epsilon(), rhs.Epsilon());
    if (fabsf(lhs.w - rhs.w) > kk)
    {
        return true;
    }
    if (fabsf(lhs.x - rhs.x) > kk)
    {
        return true;
    }
    if (fabsf(lhs.y - rhs.y) > kk)
    {
        return true;
    }
    if (fabsf(lhs.z - rhs.z) > kk)
    {
        return true;
    }
    return false;
}









