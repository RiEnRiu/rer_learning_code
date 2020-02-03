import numpy as np
import math


QUTERNION_EPSILON = 1E-06

AXIS_DICT = {'X':np.array([1,0,0]),
             'Y':np.array([0,1,0]),
             'Z':np.array([0,0,1]),
             'x':np.array([1,0,0]),
             'y':np.array([0,1,0]),
             'z':np.array([0,0,1])}


def quternion_mul(q1,q2):
    qw = q1[0]*q2[0] - q1[1]*q2[1] - q1[2]*q2[2] - q1[3]*q2[3]
    qx = q1[1]*q2[0] + q1[0]*q2[1] - q1[3]*q2[2] + q1[2]*q2[3]
    qy = q1[2]*q2[0] + q1[0]*q2[2] + q1[3]*q2[1] - q1[1]*q2[3]
    qz = q1[0]*q2[3] + q1[3]*q2[0] + q1[1]*q2[2] - q1[2]*q2[1]
    return np.array([qw,qx,qy,qz])

def normalize(vector):
    squared = vector*vector
    vector_length = math.sqrt(squared.sum())
    if vector_length < QUTERNION_EPSILON:
        raise ValueError('vector length = {0} < {1}'.format(vector_length,QUTERNION_EPSILON))
    elif -QUTERNION_EPSILON < vector_length-1 and  vector_length-1 < QUTERNION_EPSILON:
        return np.array(vector)
    else:
        return vector/vector_length

def make_quaternion(radian,normalized_axis):
    half_radian = radian / 2.0
    cos_half_radian = math.cos(half_radian)
    sin_half_radian = math.sin(half_radian)
    w = cos_half_radian
    x = sin_half_radian *normalized_axis[0]
    y = sin_half_radian *normalized_axis[1]
    z = sin_half_radian *normalized_axis[2]
    return np.array([w,x,y,z])
   
def to_quaternion(euler_radian,euler_type='ZXY'):
    q = np.array([1,0,0,0])
    for r,t in zip(euler_radian,euler_type):
        tmp_q = make_quaternion(r,AXIS_DICT[t])
        q = quternion_mul(q,tmp_q)
    return q


def _to_euler(cos_b,sin_a,cos_a,sin_c,cos_c):
    ea = math.atan2(sin_a, cos_a)
    ec = math.atan2(sin_c, cos_c)
    if cos_b < -1.0:
        eb = math.acos(-1.0)
    elif cos_b > 1.0:
        eb = math.acos(1.0)
    else:
        eb = math.acos(cos_b)
    return np.array([ea,eb,ec])

def _to_cardano(sin_b,sin_a,cos_a,sin_c,cos_c):
    ea = math.atan2(sin_a, cos_a)
    ec = math.atan2(sin_c, cos_c)
    if sin_b < -1.0:
        eb = math.asin(-1.0)
    elif sin_b > 1.0:
        eb = math.asin(1.0)
    else:
        eb = math.asin(sin_b)
    return np.array([ea,eb,ec])

# return (a b c), the euler angle in order of (XYX XZX YXY YZY ZXZ ZYZ  XYZ XZY YXZ YZX ZXY ZYX)
# while input "ZXY" the return (a,b,c) means: 
#   frist rotate a degree around Z axis of local coordinates system
#    then rotate b degree around X axis of local coordinates system
# finally rotate c degree around Y axis of local coordinates system
#    Euler type (XYX XZX YXY YZY ZXZ ZYZ) is in range of [-180,180] [ 0,180] [-180,180]
#  Cardano type (XYZ XZY YXZ YZX ZXY ZYX) is in range of [-180,180] [-90,90] [-180,180]
def to_euler(quaternion,euler_type='ZXY'):
    euler_type = euler_type.upper()
    w,x,y,z = quaternion
    if euler_type == 'XYX':
        cos_b = 2 * (w*w + x*x) - 1
        sin_a = 2 * (w*z + x*y)
        cos_a = 2 * (w*y - x*z)
        sin_c = 2 * (x*y - w*z)
        cos_c = 2 * (w*y + x*z)
        return _to_euler(cos_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'XZX':
        cos_b = 2 * (w*w + x*x) - 1
        sin_a = 2 * (x*z - w*y)
        cos_a = 2 * (w*z + x*y)
        sin_c = 2 * (w*y + x*z)
        cos_c = 2 * (w*z - x*y)
        return _to_euler(cos_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'YXY':
        cos_b = 2 * (w*w + y*y) - 1
        sin_a = 2 * (x*y - w*z)
        cos_a = 2 * (w*x + y*z)
        sin_c = 2 * (w*z + x*y)
        cos_c = 2 * (w*x - y*z)
        return _to_euler(cos_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'YZY':
        cos_b = 2 * (w*w + y*y) - 1
        sin_a = 2 * (w*x + y*z)
        cos_a = 2 * (w*z - x*y)
        sin_c = 2 * (y*z - w*x)
        cos_c = 2 * (w*z + x*y)
        return _to_euler(cos_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'ZXZ':
        cos_b = 2 * (w*w + z*z) - 1
        sin_a = 2 * (w*y + x*z)
        cos_a = 2 * (w*x - y*z)
        sin_c = 2 * (x*z - w*y)
        cos_c = 2 * (w*x + y*z)
        return _to_euler(cos_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'ZYZ':
        cos_b = 2 * (w*w + z*z) - 1
        sin_a = 2 * (y*z - w*x)
        cos_a = 2 * (w*y + x*z)
        sin_c = 2 * (w*x + y*z)
        cos_c = 2 * (w*y - x*z)
        return _to_euler(cos_b,sin_a,cos_a,sin_c,cos_c)
    elif euler_type == 'XYZ':
        sin_b = 2 * (w*y + x*z)
        sin_a = 2 * (w*x - y*z)
        cos_a = 2 * (w*w + z*z) - 1
        sin_c = 2 * (w*z - x*y)
        cos_c = 2 * (w*w + x*x) - 1
        return _to_cardano(sin_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'XZY':
        sin_b = 2 * (w*z - x*y)
        sin_a = 2 * (w*x + y*z)
        cos_a = 2 * (w*w + y*y) - 1
        sin_c = 2 * (w*y + x*z)
        cos_c = 2 * (w*w + x*x) - 1
        return _to_cardano(sin_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'YXZ':
        sin_b = 2 * (w*x - y*z)
        sin_a = 2 * (w*y + x*z)
        cos_a = 2 * (w*w + z*z) - 1
        sin_c = 2 * (w*z + x*y)
        cos_c = 2 * (w*w + y*y) - 1
        return _to_cardano(sin_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'YZX':
        sin_b = 2 * (w*z + x*y)
        sin_a = 2 * (w*y - x*z)
        cos_a = 2 * (w*w + x*x) - 1
        sin_c = 2 * (w*x - y*z)
        cos_c = 2 * (w*w + y*y) - 1
        return _to_cardano(sin_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'ZXY':
        sin_b = 2 * (w*x + y*z)
        sin_a = 2 * (w*z - x*y)
        cos_a = 2 * (w*w + y*y) - 1
        sin_c = 2 * (w*y - x*z)
        cos_c = 2 * (w*w + z*z) - 1
        return _to_cardano(sin_b, sin_a, cos_a, sin_c, cos_c)
    elif euler_type == 'ZYX':
        sin_b = 2 * (w*y - x*z)
        sin_a = 2 * (w*z + x*y)
        cos_a = 2 * (w*w + x*x) - 1
        sin_c = 2 * (w*x + y*z)
        cos_c = 2 * (w*w + z*z) - 1
        return _to_cardano(sin_b, sin_a, cos_a, sin_c, cos_c)

def inverse_quaternion(q):
    ans = q.copy()
    ans[1:] = -q[1:]
    return ans

def point_to_quaternion(p):
    ans = np.zeros(4)
    ans[1:] = p
    return ans

def quaternion_rotate_point(q,p):
    # q * p * q^-1
    tmp = quternion_mul(q,point_to_quaternion(p))
    ans = quternion_mul(tmp,inverse_quaternion(q))
    return ans

def lerp(q1,q2,a):
    return normalize((1.0 - a)*q1 + a* q2)

def slerp(q1,q2,a):
    qdot =  abs((a*b).sum())
    radian = math.acos(qdot)
    a1 = math.sin((1.0 - a)*radian)
    a2 = math.sin(a*radian)
    return normalize(a1*q1+a2*q2)

def analyse_quaternion(q):
    radian = math.acos(w)*2.0
    axis = normalize(q[1:])
    return radian,axis
    
    
    


