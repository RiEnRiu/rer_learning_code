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
    
    static tagVector3f Norm(const tagVector3f &v);//////////���Ż�
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
#define PI 3.141592653589793       //Բ���� 
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




//��Ԫ�����㺯��

const tagQuaternion Q_UNIT = { 1,0,0,0 };//


//��Ԫ����ˣ�Q=Q1*Q2
tagQuaternion QPreMul(const tagQuaternion &Q1, const tagQuaternion &Q2);

//��Ԫ��ȡ�棬Q=Q1^(-1)
tagQuaternion QInv(const tagQuaternion &Q1);

//��Ԫ���������ڻ�
float QDot(const tagQuaternion &Q1, const tagQuaternion &Q2);

//��Ԫ����ģ��
float QLength(const tagQuaternion &Q1);

//��һ����Ԫ��
tagQuaternion QNorm(const tagQuaternion &Q1);

//ʹ��Ԫ��wΪ��
tagQuaternion QRegular(const tagQuaternion &Q1);

//��Ԫ��QʹP��ת
tagQuaternion QRotPoint(const tagQuaternion &Q, const tagQuaternion &P);
tagQuaternion QRotPoint(const tagQuaternion &Q, const tagQuaternion &P, const tagQuaternion &_Q);
tagVector QRotPoint(const tagQuaternion &Q, const tagVector &P);
tagVector QRotPoint(const tagQuaternion &Q, const tagVector &P, const tagQuaternion &_Q);



//����Q��w
tagQuaternion QChangW(const tagQuaternion &Q, const float &w);


//��ȡ����������ת����Ԫ��
tagQuaternion VectorRotation(const tagQuaternion &Qbegin, const tagQuaternion &Qend);
tagQuaternion VectorRotation(const tagVector &Qbegin, const tagVector &Qend);

//ŷ����(ZXY)ת��Ԫ����������
tagQuaternion Eular2Quater(const tagVector &E);

//��Ԫ��תŷ����(ZXY)�������ƣ�x��[0,PI/2][3*PI/2,2*PI)    y��[0,2*PI)    z��[0,2*PI)
tagVector Quater2Eular(const tagQuaternion &Q);

//��ά����������
tagQuaternion PointCross(const tagQuaternion &Q1, const tagQuaternion &Q2);
tagVector PointCross(const tagVector &V1, const tagVector &V2);

//��ά��������ڻ�
float PointDot(const tagQuaternion &Q1, const tagQuaternion &Q2);
float PointDot(const tagVector &V1, const tagVector &V2);

//��ά���ģ��
float PointLength(const tagQuaternion &Q1);
float PointLength(const tagVector &V1);

//��һ����ά��
tagQuaternion PointNorm(const tagQuaternion &Q1);
tagVector PointNorm(const tagVector &V1);

//��ά�����ļн�cos
float PointCosAngle(const tagQuaternion &Q1, const tagQuaternion &Q2);
float PointCosAngle(const tagVector &V1, const tagVector &V2);

//��ά�������Գ���
tagQuaternion PointTimes(const tagQuaternion &Q1, const float Times);

//��ά����ȡ��
tagQuaternion PointNega(const tagQuaternion &Q1);
tagVector PointNega(const tagVector &V1);

//��ά�������
tagQuaternion PointAdd(const tagQuaternion &Q1, const tagQuaternion &Q2);
tagVector PointAdd(const tagVector &V1, const tagVector &V2);
*/

#endif 