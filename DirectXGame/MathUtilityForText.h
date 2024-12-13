#include "Affine.h"
#include "Matrix4x4.h"
#include "Vector3.h"


Vector3 operator+(const Vector3& v);
Vector3 operator-(const Vector3& v);


Vector3& operator+=(Vector3& lhv, const Vector3& rhv);

Vector3& operator-=(Vector3& lhv, const Vector3& rhv);


Vector3& operator*=(Vector3& v, float s);

Vector3& operator/=(Vector3& v, float s);


const Vector3 operator+(const Vector3& v1, const Vector3& v2);

const Vector3 operator-(const Vector3& v1, const Vector3& v2);


const Vector3 operator*(const Vector3& v, float s);

const Vector3 operator*(float s, const Vector3& v);

const Vector3 operator/(const Vector3& v, float s);

float EaseInOut(float x1, float x2, float t);
float Lerp(float x1, float x2, float t);
Vector3 Leap(const Vector3& v1, const Vector3& v2, float t);


Vector3 TransformNormal(const Vector3& v, const Matrix4x4& m);

float Dot(const Vector3& v, const Vector3& v2);

float Length(const Vector3& v);

Vector3 Normalize(const Vector3& v);

Matrix4x4 PlayerAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);