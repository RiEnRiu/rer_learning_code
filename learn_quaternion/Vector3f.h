#ifndef VECTOR3F_H
#define VECTOR3F_H

class tagVector3f
{
public:
    float x;
    float y;
    float z;
    tagVector3f();
    tagVector3f(const float &ex, const float &ey, const float &ez);
    ~tagVector3f();
    
    static tagVector3f Norm(const tagVector3f &v);//////////待优化
    static float Dot(const tagVector3f &a, const tagVector3f &b);
    static float Length(const tagVector3f &v);
    static tagVector3f Cross(const tagVector3f &a, const tagVector3f &b);

    void Set(const float &ex, const float &ey, const float &ez);
    void SetNorm();
    
    float GetLength() const;
    tagVector3f GetNorm() const;

    //friend bool operator==(const tagVector3f &lhs, const tagVector3f &rhs);

};



/*

#ifndef PI
#define PI 3.141592653589793       //圆周率 
#endif // !PI



struct tagQuaternionf
{
    float w;
    float x;
    float y;
    float z;
};


struct tagVector3f
{
    float x;
    float y;
    float z;
};




//四元数计算函数

const tagQuaternion Q_UNIT = { 1,0,0,0 };//


//四元数左乘，Q=Q1*Q2
tagQuaternion QPreMul(const tagQuaternion &Q1, const tagQuaternion &Q2);

//四元数取逆，Q=Q1^(-1)
tagQuaternion QInv(const tagQuaternion &Q1);

//四元数的向量内积
float QDot(const tagQuaternion &Q1, const tagQuaternion &Q2);

//四元数的模长
float QLength(const tagQuaternion &Q1);

//归一化四元数
tagQuaternion QNorm(const tagQuaternion &Q1);

//使四元数w为正
tagQuaternion QRegular(const tagQuaternion &Q1);

//四元数Q使P旋转
tagQuaternion QRotPoint(const tagQuaternion &Q, const tagQuaternion &P);
tagQuaternion QRotPoint(const tagQuaternion &Q, const tagQuaternion &P, const tagQuaternion &_Q);
tagVector QRotPoint(const tagQuaternion &Q, const tagVector &P);
tagVector QRotPoint(const tagQuaternion &Q, const tagVector &P, const tagQuaternion &_Q);



//调整Q的w
tagQuaternion QChangW(const tagQuaternion &Q, const float &w);


//获取两向量的旋转的四元数
tagQuaternion VectorRotation(const tagQuaternion &Qbegin, const tagQuaternion &Qend);
tagQuaternion VectorRotation(const tagVector &Qbegin, const tagVector &Qend);

//欧拉角(ZXY)转四元数，弧度制
tagQuaternion Eular2Quater(const tagVector &E);

//四元数转欧拉角(ZXY)，弧度制，x：[0,PI/2][3*PI/2,2*PI)    y：[0,2*PI)    z：[0,2*PI)
tagVector Quater2Eular(const tagQuaternion &Q);

//三维点的向量外积
tagQuaternion PointCross(const tagQuaternion &Q1, const tagQuaternion &Q2);
tagVector PointCross(const tagVector &V1, const tagVector &V2);

//三维点的向量内积
float PointDot(const tagQuaternion &Q1, const tagQuaternion &Q2);
float PointDot(const tagVector &V1, const tagVector &V2);

//三维点的模长
float PointLength(const tagQuaternion &Q1);
float PointLength(const tagVector &V1);

//归一化三维点
tagQuaternion PointNorm(const tagQuaternion &Q1);
tagVector PointNorm(const tagVector &V1);

//三维向量的夹角cos
float PointCosAngle(const tagQuaternion &Q1, const tagQuaternion &Q2);
float PointCosAngle(const tagVector &V1, const tagVector &V2);

//三维向量乘以常数
tagQuaternion PointTimes(const tagQuaternion &Q1, const float Times);

//三维向量取反
tagQuaternion PointNega(const tagQuaternion &Q1);
tagVector PointNega(const tagVector &V1);

//三维向量相加
tagQuaternion PointAdd(const tagQuaternion &Q1, const tagQuaternion &Q2);
tagVector PointAdd(const tagVector &V1, const tagVector &V2);
*/

#endif 