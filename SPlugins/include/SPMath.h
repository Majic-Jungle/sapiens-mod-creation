
#ifndef SPMath_h
#define SPMath_h

#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define SP_METERS_TO_PRERENDER(_meters_) ((_meters_) / 8388608.0)
#define SP_RENDER_SCALE 100000.0
#define SP_SUBDIVISIONS 22

#ifndef MJ_EXPORT
#if defined(_MSC_VER)
#define MJ_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define MJ_EXPORT __attribute__((visibility("default")))
#else
#define MJ_EXPORT
#endif
#endif

typedef struct SPVec2 {
	double x;
	double y;
} SPVec2;

typedef struct SPVec3 {
	double x;
	double y;
	double z;
} SPVec3;

typedef struct SPVec4 {
	double x;
	double y;
	double z;
	double w;
} SPVec4;


typedef struct SPMat3 {
	double m0;
	double m1;
	double m2;
	double m3;
	double m4;
	double m5;
	double m6;
	double m7;
	double m8;
} SPMat3;

typedef struct SPMat4 {
	double m0;
	double m1;
	double m2;
	double m3;
	double m4;
	double m5;
	double m6;
	double m7;
	double m8;
	double m9;
	double m10;
	double m11;
	double m12;
	double m13;
	double m14;
	double m15;
} SPMat4;

static const SPMat3 spMat3IdentityMatrix = {
	1.0,
	0.0,
	0.0,
	0.0,
	1.0,
	0.0,
	0.0,
	0.0,
	1.0
};

MJ_EXPORT double spMin(double x, double y);
MJ_EXPORT double spMax(double x, double y);
MJ_EXPORT double spClamp(double x, double minVal, double maxVal);
MJ_EXPORT double spMix(double x, double y, double a);
MJ_EXPORT double spSmoothStep(double edge0, double edge1, double x);

MJ_EXPORT SPVec2 spVec2Add(SPVec2 a, SPVec2 b);
MJ_EXPORT SPVec2 spVec2Sub(SPVec2 a, SPVec2 b);
MJ_EXPORT SPVec2 spVec2Mul(SPVec2 a, double b);
MJ_EXPORT SPVec2 spVec2MulVec2(SPVec2 a, SPVec2 b);
MJ_EXPORT SPVec2 spVec2Div(SPVec2 a, double b);
MJ_EXPORT SPVec2 spVec2Neg(SPVec2 a);

MJ_EXPORT SPVec3 spVec3Add(SPVec3 a, SPVec3 b);
MJ_EXPORT SPVec3 spVec3Sub(SPVec3 a, SPVec3 b);
MJ_EXPORT SPVec3 spVec3Mul(SPVec3 a, double b);
MJ_EXPORT SPVec3 spVec3MulVec3(SPVec3 a, SPVec3 b);
MJ_EXPORT SPVec3 spVec3Div(SPVec3 a, double b);
MJ_EXPORT SPVec3 spVec3Neg(SPVec3 a);

MJ_EXPORT SPVec4 spVec4Add(SPVec4 a, SPVec4 b);
MJ_EXPORT SPVec4 spVec4Sub(SPVec4 a, SPVec4 b);
MJ_EXPORT SPVec4 spVec4MulVec4(SPVec4 a, SPVec4 b);
MJ_EXPORT SPVec4 spVec4Mul(SPVec4 a, double b);
MJ_EXPORT SPVec4 spVec4Div(SPVec4 a, double b);
MJ_EXPORT SPVec4 spVec4Neg(SPVec4 a);

MJ_EXPORT SPVec3 spVec3Normalize(SPVec3 v);
MJ_EXPORT double spVec3Dot(SPVec3 a, SPVec3 b);
MJ_EXPORT SPVec3 spVec3Cross(SPVec3 a, SPVec3 b);
MJ_EXPORT double spVec3Length(SPVec3 v);
MJ_EXPORT double spVec3Length2(SPVec3 v);
MJ_EXPORT double spVec3Distance(SPVec3 a, SPVec3 b);
MJ_EXPORT double spVec3Distance2(SPVec3 a, SPVec3 b);
MJ_EXPORT SPVec3 spVec3xMat3(SPVec3 v, SPMat3 m);

MJ_EXPORT SPVec4 spVec4Normalize(SPVec4 v);

MJ_EXPORT SPVec4 spQuatCast(SPMat3* m);
MJ_EXPORT void spMat3Cast(SPVec4* qP, SPMat3* result);
MJ_EXPORT SPVec4 spQuatSlerp(SPVec4 a, SPVec4 b, double x);

MJ_EXPORT SPMat3 spMat3Identity(void);
MJ_EXPORT SPMat3 spMat3Rotate(SPMat3 m, double angle, SPVec3 axis);
MJ_EXPORT SPMat3 spMat3Inverse(SPMat3 m);
MJ_EXPORT SPMat3 spMat3Multiply(SPMat3 a, SPMat3 b);
MJ_EXPORT SPMat3 spMat3Slerp(SPMat3 a, SPMat3 b, double fraction);
MJ_EXPORT SPVec3 spMat3GetRow(SPMat3 m, int rowIndex);
MJ_EXPORT SPMat3 spMat3FromVec3s(SPVec3 a, SPVec3 b, SPVec3 c);
MJ_EXPORT SPMat3 spMat3LookAtInverse(SPVec3 look, SPVec3 up);


MJ_EXPORT void spMat3RotatePtr(SPMat3* m, double angle, SPVec3* axis, SPMat3* result);
MJ_EXPORT void spMat3LookAtInversePtr(SPVec3* look, SPVec3* up, SPMat3* result);
MJ_EXPORT void spMat3InversePtr(SPMat3* m, SPMat3* result);
MJ_EXPORT void spMat3SlerpPtr(SPMat3* a, SPMat3* b, double fraction, SPMat3* result);

MJ_EXPORT bool spPointIsLeftOfLine(SPVec3 p1, SPVec3 a, SPVec3 b);

MJ_EXPORT void spMat4InversePtr(SPMat4* m, SPMat4* result);


#endif
