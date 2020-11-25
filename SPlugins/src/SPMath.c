

#include "SPMath.h"
#include <float.h>

double spMin(double x, double y)
{
	return (x < y ? x : y);
}

double spMax(double x, double y)
{
	return (x > y ? x : y);
}

double spClamp(double x, double minVal, double maxVal)
{
	return spMin(spMax(x, minVal), maxVal);
}

double spMix(double x, double y, double a)
{
	return x + a * (y - x);
}

double spSmoothStep(double edge0, double edge1, double x)
{
	double tmp = spClamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
	return tmp * tmp * (3.0 - 2.0 * tmp);
}


SPVec2 spVec2Add(SPVec2 a, SPVec2 b)
{
	SPVec2 result = { a.x + b.x, a.y + b.y };
	return result;
}

SPVec2 spVec2Sub(SPVec2 a, SPVec2 b)
{
	SPVec2 result = { a.x - b.x, a.y - b.y };
	return result;
}

SPVec2 spVec2Mul(SPVec2 a, double b)
{
	SPVec2 result = { a.x * b, a.y * b };
	return result;
}

SPVec2 spVec2MulVec2(SPVec2 a, SPVec2 b)
{
	SPVec2 result = { a.x * b.x, a.y * b.y };
	return result;
}

SPVec2 spVec2Div(SPVec2 a, double b)
{
	SPVec2 result = { a.x / b, a.y / b };
	return result;
}

SPVec2 spVec2Neg(SPVec2 a)
{
	SPVec2 result = { -a.x, -a.y };
	return result;
}

SPVec3 spVec3Add(SPVec3 a, SPVec3 b)
{
	SPVec3 result = { a.x + b.x, a.y + b.y, a.z + b.z };
	return result;
}

SPVec3 spVec3Sub(SPVec3 a, SPVec3 b)
{
	SPVec3 result = { a.x - b.x, a.y - b.y, a.z - b.z };
	return result;
}

SPVec3 spVec3Mul(SPVec3 a, double b)
{
	SPVec3 result = { a.x * b, a.y * b, a.z * b };
	return result;
}

SPVec3 spVec3MulVec3(SPVec3 a, SPVec3 b)
{
	SPVec3 result = { a.x * b.x, a.y * b.y, a.z * b.z };
	return result;
}

SPVec3 spVec3Div(SPVec3 a, double b)
{
	SPVec3 result = { a.x / b, a.y / b, a.z / b };
	return result;
}

SPVec3 spVec3Neg(SPVec3 a)
{
	SPVec3 result = { -a.x, -a.y, -a.z };
	return result;
}

SPVec3 spVec3Normalize(SPVec3 v)
{
	return spVec3Div(v, sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double spVec3Dot(SPVec3 a, SPVec3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

SPVec3 spVec3Cross(SPVec3 a, SPVec3 b)
{
	SPVec3 result = { a.y * b.z - b.y * a.z,
		a.z * b.x - b.z * a.x,
		a.x * b.y - b.x * a.y };
	return result;
}

double spVec3Length(SPVec3 v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double spVec3Length2(SPVec3 v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

double spVec3Distance(SPVec3 a, SPVec3 b)
{
	SPVec3 v = { a.x - b.x, a.y - b.y, a.z - b.z };
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double spVec3Distance2(SPVec3 a, SPVec3 b)
{
	SPVec3 v = { a.x - b.x, a.y - b.y, a.z - b.z };
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

SPVec3 spVec3xMat3(SPVec3 v, SPMat3 m3)
{
	double* m = &(m3.m0);
	SPVec3 result = {
		m[0] * v.x + m[1] * v.y + m[2] * v.z,
		m[3] * v.x + m[4] * v.y + m[5] * v.z,
		m[6] * v.x + m[7] * v.y + m[8] * v.z
	};
	return result;
}



SPVec4 spVec4Add(SPVec4 a, SPVec4 b)
{
	SPVec4 result = { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	return result;
}

SPVec4 spVec4Sub(SPVec4 a, SPVec4 b)
{
	SPVec4 result = { a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
	return result;
}

SPVec4 spVec4Mul(SPVec4 a, double b)
{
	SPVec4 result = { a.x * b, a.y * b, a.z * b, a.w * b };
	return result;
}

SPVec4 spVec4MulVec4(SPVec4 a, SPVec4 b)
{
	SPVec4 result = { a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
	return result;
}

SPVec4 spVec4Div(SPVec4 a, double b)
{
	SPVec4 result = { a.x / b, a.y / b, a.z / b, a.w / b };
	return result;
}

SPVec4 spVec4Neg(SPVec4 a)
{
	SPVec4 result = { -a.x, -a.y, -a.z, -a.w };
	return result;
}

SPVec4 spVec4Normalize(SPVec4 v)
{
	return spVec4Div(v, sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w));
}


SPVec4 spQuatCast(SPMat3* m3)
{
	double* m = (double*)m3;

	double fourXSquaredMinus1 = m[0] - m[4] - m[8];
	double fourYSquaredMinus1 = m[4] - m[0] - m[8];
	double fourZSquaredMinus1 = m[8] - m[0] - m[4];
	double fourWSquaredMinus1 = m[0] + m[4] + m[8];

	int biggestIndex = 0;
	double fourBiggestSquaredMinus1 = fourWSquaredMinus1;
	if(fourXSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourXSquaredMinus1;
		biggestIndex = 1;
	}
	if(fourYSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourYSquaredMinus1;
		biggestIndex = 2;
	}
	if(fourZSquaredMinus1 > fourBiggestSquaredMinus1)
	{
		fourBiggestSquaredMinus1 = fourZSquaredMinus1;
		biggestIndex = 3;
	}

	double biggestVal = sqrt(fourBiggestSquaredMinus1 + 1.0) * 0.5;
	double mult = 0.25 / biggestVal;


	switch(biggestIndex)
	{
		case 0:
		{
			SPVec4 result = { (m[5] - m[7]) * mult, (m[6] - m[2]) * mult, (m[1] - m[3]) * mult, biggestVal};
			return result;
		}
		break;
		case 1:
		{
			SPVec4 result = { biggestVal, (m[1] + m[3]) * mult, (m[6] + m[2]) * mult, (m[5] - m[7]) * mult };
			return result;
		}
		break;
		case 2:
		{
			SPVec4 result = { (m[1] + m[3]) * mult, biggestVal, (m[5] + m[7]) * mult, (m[6] - m[2]) * mult };
			return result;
		}
		break;
		default:
		{
			SPVec4 result = { (m[6] + m[2]) * mult, (m[5] + m[7]) * mult, biggestVal, (m[1] - m[3]) * mult };
			return result;
		}
		break;
	}
}

void spMat3Cast(SPVec4* qP, SPMat3* result)
{
	SPVec4 q = *qP;

	double qxx = q.x * q.x;
	double qyy = q.y * q.y;
	double qzz = q.z * q.z;
	double qxz = q.x * q.z;
	double qxy = q.x * q.y;
	double qyz = q.y * q.z;
	double qwx = q.w * q.x;
	double qwy = q.w * q.y;
	double qwz = q.w * q.z;

	double* m = (double*)result;

	m[0] = 1.0 - 2.0 * (qyy +  qzz);
	m[1] = 2.0 * (qxy + qwz);
	m[2] = 2.0 * (qxz - qwy);

	m[3] = 2.0 * (qxy - qwz);
	m[4] = 1.0 - 2.0 * (qxx +  qzz);
	m[5] = 2.0 * (qyz + qwx);

	m[6] = 2.0 * (qxz + qwy);
	m[7] = 2.0 * (qyz - qwx);
	m[8] = 1.0 - 2.0 * (qxx +  qyy);
}

SPVec4 spQuatSlerp(SPVec4 a, SPVec4 b, double fraction)
{
	SPVec4 z = b;

	double cosTheta = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;

	if (cosTheta < 0.0)
	{
		z.x = -b.x;
		z.y = -b.y;
		z.z = -b.z;
		z.w = -b.w;
		cosTheta = -cosTheta;
	}

	if(cosTheta > 1.0 - DBL_EPSILON)
	{
		SPVec4 result = {
			spMix(a.x, z.x, fraction),
			spMix(a.y, z.y, fraction),
			spMix(a.z, z.z, fraction),
			spMix(a.w, z.w, fraction),
		};
		return result;
	}
	else
	{
		double angle = acos(cosTheta);
		double aMult = sin((1.0 - fraction) * angle);
		double bMult = sin(fraction * angle);
		double sinAngle = sin(angle);

		return spVec4Div(spVec4Add(spVec4Mul(a, aMult), spVec4Mul(z, bMult)), sinAngle);
	}
}

SPMat3 spMat3Identity()
{
	return spMat3IdentityMatrix;
}

SPMat3 spMat3Rotate(SPMat3 incoming, double a, SPVec3 axis)
{
	double c = cos(a);
	double s = sin(a);

	SPVec3 temp = spVec3Mul(axis, 1.0 - c);

	SPMat3 rotationMatrix;
	double* rm = &(rotationMatrix.m0);

	rm[0] = c + temp.x * axis.x;
	rm[1] = temp.x * axis.y + s * axis.z;
	rm[2] = temp.x * axis.z - s * axis.y;

	rm[3] = temp.y * axis.x - s * axis.z;
	rm[4] = c + temp.y * axis.y;
	rm[5] = temp.y * axis.z + s * axis.x;

	rm[6] = temp.z * axis.x + s * axis.y;
	rm[7] = temp.z * axis.y - s * axis.x;
	rm[8] = c + temp.z * axis.z;

	SPMat3 result;
	double* resm = &(result.m0);

	SPVec3 incomingA = {incoming.m0, incoming.m1, incoming.m2};
	SPVec3 incomingB = {incoming.m3, incoming.m4, incoming.m5};
	SPVec3 incomingC = {incoming.m6, incoming.m7, incoming.m8};

	SPVec3 ra = spVec3Add(spVec3Add(spVec3Mul(incomingA, rm[0]), spVec3Mul(incomingB, rm[1])), spVec3Mul(incomingC, rm[2]));
	SPVec3 rb = spVec3Add(spVec3Add(spVec3Mul(incomingA, rm[3]), spVec3Mul(incomingB, rm[4])), spVec3Mul(incomingC, rm[5]));
	SPVec3 rc = spVec3Add(spVec3Add(spVec3Mul(incomingA, rm[6]), spVec3Mul(incomingB, rm[7])), spVec3Mul(incomingC, rm[8]));

	resm[0] = ra.x;
	resm[1] = ra.y;
	resm[2] = ra.z;
	resm[3] = rb.x;
	resm[4] = rb.y;
	resm[5] = rb.z;
	resm[6] = rc.x;
	resm[7] = rc.y;
	resm[8] = rc.z;

	return result;
}


void spMat3RotatePtr(SPMat3* m, double angle, SPVec3* axisP, SPMat3* result)
{
	double c = cos(angle);
	double s = sin(angle);

	SPVec3 axis = *axisP;

	SPVec3 temp = spVec3Mul(axis, 1.0 - c);

	SPMat3 rotationMatrix;
	double* rm = &(rotationMatrix.m0);

	rm[0] = c + temp.x * axis.x;
	rm[1] = temp.x * axis.y + s * axis.z;
	rm[2] = temp.x * axis.z - s * axis.y;

	rm[3] = temp.y * axis.x - s * axis.z;
	rm[4] = c + temp.y * axis.y;
	rm[5] = temp.y * axis.z + s * axis.x;

	rm[6] = temp.z * axis.x + s * axis.y;
	rm[7] = temp.z * axis.y - s * axis.x;
	rm[8] = c + temp.z * axis.z;

	double* resm = (double*)result;
	double* incoming = (double*)m;

	SPVec3 incomingA = {incoming[0], incoming[1], incoming[2]};
	SPVec3 incomingB = {incoming[3], incoming[4], incoming[5]};
	SPVec3 incomingC = {incoming[6], incoming[7], incoming[8]};

	SPVec3 ra = spVec3Add(spVec3Add(spVec3Mul(incomingA, rm[0]), spVec3Mul(incomingB, rm[1])), spVec3Mul(incomingC, rm[2]));
	SPVec3 rb = spVec3Add(spVec3Add(spVec3Mul(incomingA, rm[3]), spVec3Mul(incomingB, rm[4])), spVec3Mul(incomingC, rm[5]));
	SPVec3 rc = spVec3Add(spVec3Add(spVec3Mul(incomingA, rm[6]), spVec3Mul(incomingB, rm[7])), spVec3Mul(incomingC, rm[8]));

	resm[0] = ra.x;
	resm[1] = ra.y;
	resm[2] = ra.z;
	resm[3] = rb.x;
	resm[4] = rb.y;
	resm[5] = rb.z;
	resm[6] = rc.x;
	resm[7] = rc.y;
	resm[8] = rc.z;
}

SPMat3 spMat3Inverse(SPMat3 mat)
{
	double* m = &(mat.m0);

	double oneOverDeterminant = 1.0 / (
		+ m[0] * (m[4] * m[8] - m[7] * m[5])
		- m[3] * (m[1] * m[8] - m[7] * m[2])
		+ m[6] * (m[1] * m[5] - m[4] * m[2]));

	SPMat3 result;

	double* inverse = &(result.m0);

	inverse[0] = + (m[4] * m[8] - m[7] * m[5]) * oneOverDeterminant;
	inverse[3] = - (m[3] * m[8] - m[6] * m[5]) * oneOverDeterminant;
	inverse[6] = + (m[3] * m[7] - m[6] * m[4]) * oneOverDeterminant;
	inverse[1] = - (m[1] * m[8] - m[7] * m[2]) * oneOverDeterminant;
	inverse[4] = + (m[0] * m[8] - m[6] * m[2]) * oneOverDeterminant;
	inverse[7] = - (m[0] * m[7] - m[6] * m[1]) * oneOverDeterminant;
	inverse[2] = + (m[1] * m[5] - m[4] * m[2]) * oneOverDeterminant;
	inverse[5] = - (m[0] * m[5] - m[3] * m[2]) * oneOverDeterminant;
	inverse[8] = + (m[0] * m[4] - m[3] * m[1]) * oneOverDeterminant;

	return result;
}

void spMat3InversePtr(SPMat3* mat, SPMat3* result)
{
	double* m = (double*)mat;

	double oneOverDeterminant = 1.0 / (
		+ m[0] * (m[4] * m[8] - m[7] * m[5])
		- m[3] * (m[1] * m[8] - m[7] * m[2])
		+ m[6] * (m[1] * m[5] - m[4] * m[2]));

	double* inverse = (double*)result;

	inverse[0] = + (m[4] * m[8] - m[7] * m[5]) * oneOverDeterminant;
	inverse[3] = - (m[3] * m[8] - m[6] * m[5]) * oneOverDeterminant;
	inverse[6] = + (m[3] * m[7] - m[6] * m[4]) * oneOverDeterminant;
	inverse[1] = - (m[1] * m[8] - m[7] * m[2]) * oneOverDeterminant;
	inverse[4] = + (m[0] * m[8] - m[6] * m[2]) * oneOverDeterminant;
	inverse[7] = - (m[0] * m[7] - m[6] * m[1]) * oneOverDeterminant;
	inverse[2] = + (m[1] * m[5] - m[4] * m[2]) * oneOverDeterminant;
	inverse[5] = - (m[0] * m[5] - m[3] * m[2]) * oneOverDeterminant;
	inverse[8] = + (m[0] * m[4] - m[3] * m[1]) * oneOverDeterminant;
}

SPMat3 spMat3Multiply(SPMat3 a, SPMat3 b)
{
	double* m1 = &(a.m0);
	double* m2 = &(b.m0);

	double srcA00 = m1[0];
	double srcA01 = m1[1];
	double srcA02 = m1[2];
	double srcA10 = m1[3];
	double srcA11 = m1[4];
	double srcA12 = m1[5];
	double srcA20 = m1[6];
	double srcA21 = m1[7];
	double srcA22 = m1[8];

	double srcB00 = m2[0];
	double srcB01 = m2[1];
	double srcB02 = m2[2];
	double srcB10 = m2[3];
	double srcB11 = m2[4];
	double srcB12 = m2[5];
	double srcB20 = m2[6];
	double srcB21 = m2[7];
	double srcB22 = m2[8];

	SPMat3 result;
	double* r = &(result.m0);

	r[0] = srcA00 * srcB00 + srcA10 * srcB01 + srcA20 * srcB02;
	r[1] = srcA01 * srcB00 + srcA11 * srcB01 + srcA21 * srcB02;
	r[2] = srcA02 * srcB00 + srcA12 * srcB01 + srcA22 * srcB02;
	r[3] = srcA00 * srcB10 + srcA10 * srcB11 + srcA20 * srcB12;
	r[4] = srcA01 * srcB10 + srcA11 * srcB11 + srcA21 * srcB12;
	r[5] = srcA02 * srcB10 + srcA12 * srcB11 + srcA22 * srcB12;
	r[6] = srcA00 * srcB20 + srcA10 * srcB21 + srcA20 * srcB22;
	r[7] = srcA01 * srcB20 + srcA11 * srcB21 + srcA21 * srcB22;
	r[8] = srcA02 * srcB20 + srcA12 * srcB21 + srcA22 * srcB22;

	return result;
}

SPMat3 spMat3Slerp(SPMat3 a, SPMat3 b, double fraction)
{
	SPVec4 slerpedQuat = spVec4Normalize(spQuatSlerp(spQuatCast(&a), spQuatCast(&b), spClamp(fraction, 0.0, 1.0)));
	SPMat3 result;
	spMat3Cast(&slerpedQuat, &result);
	return result;
}

void spMat3SlerpPtr(SPMat3* a, SPMat3* b, double fraction, SPMat3* result)
{
	SPVec4 slerpedQuat = spVec4Normalize(spQuatSlerp(spQuatCast(a), spQuatCast(b), spClamp(fraction, 0.0, 1.0)));
	spMat3Cast(&slerpedQuat, result);
}

SPVec3 spMat3GetRow(SPMat3 mat, int rowIndex)
{
	double* m = &(mat.m0);
	int startIndex = rowIndex * 3;

	SPVec3 result = {m[startIndex], m[startIndex + 1], m[startIndex + 2]};
	return result;
}

SPMat3 spMat3FromVec3s(SPVec3 a, SPVec3 b, SPVec3 c)
{
	SPMat3 result;
	double* m = &(result.m0);

	m[0] = a.x;
	m[1] = a.y;
	m[2] = a.z;
	m[3] = b.x;
	m[4] = b.y;
	m[5] = b.z;
	m[6] = c.x;
	m[7] = c.y;
	m[8] = c.z;

	return result;
}

SPMat3 spMat3LookAtInverse(SPVec3 look, SPVec3 up)
{
	double dp = spVec3Dot(look, up);
	if(dp >= 1.0 || dp <= -1.0)
	{
		return spMat3IdentityMatrix;
	}

	SPMat3 result;
	double* m = &(result.m0);

	SPVec3 right = spVec3Normalize(spVec3Cross(up, look));
	SPVec3 finalUp = spVec3Cross(look, right);

	m[0] = right.x;
	m[1] = right.y;
	m[2] = right.z;
	m[3] = finalUp.x;
	m[4] = finalUp.y;
	m[5] = finalUp.z;
	m[6] = look.x;
	m[7] = look.y;
	m[8] = look.z;

	return result;
}

void spMat3LookAtInversePtr(SPVec3* lookP, SPVec3* upP, SPMat3* result)
{
	SPVec3 look = *lookP;
	SPVec3 up = *upP;
	double dp = spVec3Dot(look, up);
	if(dp >= 1.0 || dp <= -1.0)
	{
		*result = spMat3IdentityMatrix;
		return;
	}

	double* m = (double*)result;

	SPVec3 right = spVec3Normalize(spVec3Cross(up, look));
	SPVec3 finalUp = spVec3Cross(look, right);

	m[0] = right.x;
	m[1] = right.y;
	m[2] = right.z;
	m[3] = finalUp.x;
	m[4] = finalUp.y;
	m[5] = finalUp.z;
	m[6] = look.x;
	m[7] = look.y;
	m[8] = look.z;
}

bool spPointIsLeftOfLine(SPVec3 p1, SPVec3 a, SPVec3 b)
{
	SPVec3 faceNormal = spVec3Cross(a, b);
	return (spVec3Dot(faceNormal, p1) >= 0);
}

void spMat4InversePtr(SPMat4* mat, SPMat4* result)
{
	double* m = (double*)mat;

	double coef00 = m[10] * m[15] - m[14] * m[11];
	double coef02 = m[6] * m[15] - m[14] * m[7];
	double coef03 = m[6] * m[11] - m[10] * m[7];

	double coef04 = m[9] * m[15] - m[13] * m[11];
	double coef06 = m[5] * m[15] - m[13] * m[7];
	double coef07 = m[5] * m[11] - m[9] * m[7];

	double coef08 = m[9] * m[14] - m[13] * m[10];
	double coef10 = m[5] * m[14] - m[13] * m[6];
	double coef11 = m[5] * m[10] - m[9] * m[6];

	double coef12 = m[8] * m[15] - m[12] * m[11];
	double coef14 = m[4] * m[15] - m[12] * m[7];
	double coef15 = m[4] * m[11] - m[8] * m[7];

	double coef16 = m[8] * m[14] - m[12] * m[10];
	double coef18 = m[4] * m[14] - m[12] * m[6];
	double coef19 = m[4] * m[10] - m[8] * m[6];

	double coef20 = m[8] * m[13] - m[12] * m[9];
	double coef22 = m[4] * m[13] - m[12] * m[5];
	double coef23 = m[4] * m[9] - m[8] * m[5];

	SPVec4 fac0 = {coef00, coef00, coef02, coef03};
	SPVec4 fac1 = {coef04, coef04, coef06, coef07};
	SPVec4 fac2 = {coef08, coef08, coef10, coef11};
	SPVec4 fac3 = {coef12, coef12, coef14, coef15};
	SPVec4 fac4 = {coef16, coef16, coef18, coef19};
	SPVec4 fac5 = {coef20, coef20, coef22, coef23};

	SPVec4 mvec0 = {m[4], m[0], m[0], m[0]};
	SPVec4 mvec1 = {m[5], m[1], m[1], m[1]};
	SPVec4 mvec2 = {m[6], m[2], m[2], m[2]};
	SPVec4 mvec3 = {m[7], m[3], m[3], m[3]};

	SPVec4 inv0 = spVec4Add(spVec4Sub(spVec4MulVec4(mvec1, fac0), spVec4MulVec4(mvec2, fac1)), spVec4MulVec4(mvec3, fac2));
	SPVec4 inv1 = spVec4Add(spVec4Sub(spVec4MulVec4(mvec0, fac0), spVec4MulVec4(mvec2, fac3)), spVec4MulVec4(mvec3, fac4));
	SPVec4 inv2 = spVec4Add(spVec4Sub(spVec4MulVec4(mvec0, fac1), spVec4MulVec4(mvec1, fac3)), spVec4MulVec4(mvec3, fac5));
	SPVec4 inv3 = spVec4Add(spVec4Sub(spVec4MulVec4(mvec0, fac2), spVec4MulVec4(mvec1, fac4)), spVec4MulVec4(mvec2, fac5));

	SPVec4 signA = {+1, -1, +1, -1};
	SPVec4 signB = {-1, +1, -1, +1};

	SPVec4 invMat0 = spVec4MulVec4(inv0, signA);
	SPVec4 invMat1 = spVec4MulVec4(inv1, signB);
	SPVec4 invMat2 = spVec4MulVec4(inv2, signA);
	SPVec4 invMat3 = spVec4MulVec4(inv3, signB);

	SPVec4 baseRow0 = {m[0],m[1],m[2],m[3]};
	SPVec4 invRow0 = {invMat0.x, invMat1.x, invMat2.x, invMat3.x};

	SPVec4 dot0 = spVec4MulVec4(baseRow0, invRow0);

	double dot1 = (dot0.x + dot0.y) + (dot0.z + dot0.w);

	double oneOverDeterminant = 1.0 / dot1;

	double* inverse = (double*)result;

	inverse[0] =  invMat0.x * oneOverDeterminant;
	inverse[1] =  invMat0.y * oneOverDeterminant;
	inverse[2] =  invMat0.z * oneOverDeterminant;
	inverse[3] =  invMat0.w * oneOverDeterminant;

	inverse[4] =  invMat1.x * oneOverDeterminant;
	inverse[5] =  invMat1.y * oneOverDeterminant;
	inverse[6] =  invMat1.z * oneOverDeterminant;
	inverse[7] =  invMat1.w * oneOverDeterminant;

	inverse[8] =  invMat2.x * oneOverDeterminant;
	inverse[9] =  invMat2.y * oneOverDeterminant;
	inverse[10] = invMat2.z * oneOverDeterminant;
	inverse[11] = invMat2.w * oneOverDeterminant;

	inverse[12] = invMat3.x * oneOverDeterminant;
	inverse[13] = invMat3.y * oneOverDeterminant;
	inverse[14] = invMat3.z * oneOverDeterminant;
	inverse[15] = invMat3.w * oneOverDeterminant;


}