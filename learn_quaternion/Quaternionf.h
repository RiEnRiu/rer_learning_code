#ifndef QUATERNIONF_H
#define QUATERNIONF_H

#ifndef OUT
#define OUT
#endif // !OUT

#ifndef IN
#define IN
#endif // !OUT

class tagVector3f;
enum EULER_ANGLE_ORDER{ XYX, XZX, YXY, YZY, ZXZ, ZYZ, XYZ, XZY, YXZ, YZX, ZXY, ZYX };

class tagQuaternionf
{
private:
    static const float epsilon;

    tagVector3f Euler(const float &cos_b, const float &sin_a, const float &cos_a, const float &sin_c, const float &cos_c) const;
    tagVector3f Cardano(const float &cos_b, const float &sin_a, const float &cos_a, const float &sin_c, const float &cos_c) const;
    tagVector3f EulerAngleXYX() const;
    tagVector3f EulerAngleXZX() const;
    tagVector3f EulerAngleYXY() const;
    tagVector3f EulerAngleYZY() const;
    tagVector3f EulerAngleZXZ() const;
    tagVector3f EulerAngleZYZ() const;
    tagVector3f EulerAngleXYZ() const;
    tagVector3f EulerAngleXZY() const;
    tagVector3f EulerAngleYXZ() const;
    tagVector3f EulerAngleYZX() const;
    tagVector3f EulerAngleZXY() const;
    tagVector3f EulerAngleZYX() const;
  
public:
    float w;
    float x;
    float y;
    float z;

    tagQuaternionf();
    //init by quaternion
    tagQuaternionf(const float &qw, const float &qx, const float &qy, const float &qz);
    //init by EulerAngle (not in radian) in order of "type"
    tagQuaternionf(const float &a, const float &b, const float &c, const EULER_ANGLE_ORDER type);
    //init by an angle (not in radian) and an axis 
    tagQuaternionf(const float &angle, const  tagVector3f &axis);

    static tagQuaternionf Unit();
    static float Dot(const tagQuaternionf &a, const tagQuaternionf &b);
    ////////////////“‘œ¬Œ¥≤‚ ‘
    //static float Angle(const tagQuaternionf &a, const tagQuaternionf &b);
    static tagVector3f RotatePoint(const tagQuaternionf &rotation, const tagVector3f& point);
    static tagVector3f RotatePoint(const tagVector3f& point, const tagQuaternionf &rotation);
    static tagQuaternionf FromToRotation(const tagVector3f &fromDirection, const tagVector3f &toDirection);
    static tagQuaternionf Lerp(const tagQuaternionf &a, const tagQuaternionf &b, const float &t);
    static tagQuaternionf Slerp(const tagQuaternionf &a, const tagQuaternionf &b, const float &t);


    const float Epsilon() const;
    float Length() const;
    tagQuaternionf Norm() const;
    tagQuaternionf RegularW() const;
    tagQuaternionf RegularX() const;
    tagQuaternionf RegularY() const;
    tagQuaternionf RegularZ() const;
    tagQuaternionf ChangeW(const float &qw) const;
    tagQuaternionf ChangeAngle(const float &angle) const;
    tagQuaternionf ChangeAxis(const tagVector3f &axis) const;
    void AngleAxis(OUT float &angle, OUT tagVector3f &axis) const;
    tagQuaternionf Inverse() const;
    //return (x y z), the euler angle in order of EULAR_ANGLE_ORDER(XYX XZX YXY YZY ZXZ ZYZ  XYZ XZY YXZ YZX ZXY ZYX)
    //while input "ZXY" the return (x,y,z) means: 
    //  frist rotate x degree around Z axis of local coordinates system
    //   then rotate y degree around X axis of local coordinates system
    //finally rotate z degree around Y axis of local coordinates system
    //  Euler type (XYX XZX YXY YZY ZXZ ZYZ) is in range of [-180,180] [ 0,180] [-180,180]
    //Cardano type (XYZ XZY YXZ YZX ZXY ZYX) is in range of [-180,180] [-90,90] [-180,180]
    tagVector3f EulerAngle(const EULER_ANGLE_ORDER type) const;

    tagQuaternionf operator-() const;
    friend tagQuaternionf operator+(const tagQuaternionf &lhs, const tagQuaternionf &rhs);
    friend tagQuaternionf operator-(const tagQuaternionf &lhs, const tagQuaternionf &rhs);
    friend tagQuaternionf operator*(const float &times, const tagQuaternionf &q);
    friend tagQuaternionf operator*(const tagQuaternionf &q, const float &times);
    friend tagQuaternionf operator*(const tagQuaternionf &lhs, const tagQuaternionf &rhs);
    friend tagQuaternionf operator/(const tagQuaternionf &lhs, const tagQuaternionf &rhs);
    friend tagQuaternionf operator/(const tagQuaternionf &q, const float &times);
    friend bool operator==(const tagQuaternionf &lhs, const tagQuaternionf &rhs);
    friend bool operator!=(const tagQuaternionf &lhs, const tagQuaternionf &rhs);
};





#endif 