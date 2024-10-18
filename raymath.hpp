#if !defined(RAYMATH_HPP)
#define RAYMATH_HPP
/**
 * @file   raymath.hpp
 * @brief  C++ raymath.
 * @author Alicia Amarilla (smushyaa@gmail.com)
 * @date   October 16, 2024
*/
#include <raymath.h>
#if !defined(RAYMATH_CPP_NO_STDLIB)
    #include <utility>
#endif

template<typename V, typename RLV, int...Indexes>
class Swizzler {
    static const int Count = sizeof...(Indexes);
    float v[Count];
public:
    V& operator=( const V& rhs ) {
        int indexes[] = { Indexes... };
        for( int i = 0; i < Count; ++i ) {
            v[indexes[i]] = rhs[i];
        }
        return *(V*)this;
    }
    operator
    V() const {
        return V( v[Indexes]... );
    }
    operator
    RLV() const {
        return RLV{ v[Indexes]... };
    }
};

struct Vec2 {
    union {
        float array[2];
        struct { float x = 0.0f, y = 0.0f; };
        Swizzler<Vec2, Vector2, 0, 0> xx;
        Swizzler<Vec2, Vector2, 1, 1> yy;
        Swizzler<Vec2, Vector2, 0, 1> xy;
        Swizzler<Vec2, Vector2, 1, 0> yx;
    };

    Vec2() {}
    Vec2( float x, float y ) : x(x), y(y) {}
    Vec2( const Vector2& v ) : Vec2( v.x, v.y ) {}

    inline
    operator Vector2() const {
        return *(Vector2*)this;
    }
    inline
    float operator[]( size_t idx ) const {
        return array[idx];
    }
    inline
    float& operator[]( size_t idx ) {
        return array[idx];
    }

    inline
    Vec2& operator+=( Vector2 v2 ) {
        return *this = this->Add( v2 );
    }
    inline
    Vec2& operator-=( Vector2 v2 ) {
        return *this = this->Subtract( v2 );
    }
    inline
    Vec2& operator*=( float value ) {
        return *this = this->Scale( value );
    }
    inline
    Vec2& operator/=( float value ) {
        return *this = this->Scale( 1.0f / value );
    }
    inline
    Vec2 operator-() const {
        return this->Negate();
    }

    static inline
    Vec2 Zero() {
        return Vector2Zero();
    }
    static inline
    Vec2 One() {
        return Vector2One();
    }

    inline
    Vec2 Add( Vector2 v2 ) const {
        return Vector2Add( *this, v2 );
    }
    inline
    Vec2 AddValue( float add ) const {
        return Vector2AddValue( *this, add );
    }
    inline
    Vec2 Subtract( Vector2 v2 ) const {
        return Vector2Subtract( *this, v2 );
    }
    inline
    Vec2 SubtractValue( float sub ) const {
        return Vector2SubtractValue( *this, sub );
    }
    inline
    float Length() const {
        return Vector2Length( *this );
    }
    inline
    float LengthSqr() const {
        return Vector2LengthSqr( *this );
    }
    inline
    float DotProduct( Vector2 v2 ) const {
        return Vector2DotProduct( *this, v2 );
    }
    inline
    float Distance( Vector2 v2 ) const {
        return Vector2Distance( *this, v2 );
    }
    inline
    float DistanceSqr( Vector2 v2 ) const {
        return Vector2DistanceSqr( *this, v2 );
    }
    inline
    float Angle( Vector2 v2 ) const {
        return Vector2Angle( *this, v2 );
    }
    inline
    Vec2 Scale( float scale ) const {
        return Vector2Scale( *this, scale );
    }
    inline
    Vec2 Multiply( Vector2 v2 ) const {
        return Vector2Multiply( *this, v2 );
    }
    inline
    Vec2 Negate() const {
        return Vector2Negate( *this );
    }
    inline
    Vec2 Divide( Vector2 v2 ) const {
        return Vector2Divide( *this, v2 );
    }
    inline
    Vec2 Normalize() const {
        return Vector2Normalize( *this );
    }
    inline
    Vec2 Transform( const Matrix& mat ) const {
        return Vector2Transform( *this, mat );
    }
    inline
    Vec2 Lerp( Vector2 v2, float amount ) const {
        return Vector2Lerp( *this, v2, amount );
    }
    inline
    Vec2 Reflect( Vector2 normal ) const {
        return Vector2Reflect( *this, normal );
    }
    inline
    Vec2 Rotate( float angle ) const {
        return Vector2Rotate( *this, angle );
    }
    inline
    Vec2 MoveToward( Vector2 target, float maxDistance ) const {
        return Vector2MoveTowards( *this, target, maxDistance );
    }
    inline
    Vec2 Invert() const {
        return Vector2Invert( *this );
    }
    inline
    Vec2 Clamp( Vector2 min, Vector2 max ) const {
        return Vector2Clamp( *this, min, max );
    }
    inline
    Vec2 ClampValue( float min, float max ) const {
        return Vector2ClampValue( *this, min, max );
    }
    inline
    bool Equals( Vector2 q ) const {
        return Vector2Equals( *this, q );
    }
};
inline
Vec2 operator+( Vector2 v1, Vector2 v2 ) {
    return Vector2Add( v1, v2 );
}
inline
Vec2 operator-( Vector2 v1, Vector2 v2 ) {
    return Vector2Subtract( v1, v2 );
}
inline
Vec2 operator*( Vector2 v1, float scale ) {
    return Vector2Scale( v1, scale );
}
inline
Vec2 operator*( float scale, Vector2 v1 ) {
    return Vector2Scale( v1, scale );
}
inline
Vec2 operator/( Vector2 v1, float scale ) {
    return Vector2Scale( v1, 1.0f / scale );
}
inline
bool operator==( Vector2 p, Vector2 q ) {
    return Vector2Equals( p, q );
}
inline
bool operator!=( Vector2 p, Vector2 q ) {
    return !( p == q );
}
inline
float Length( Vector2 v ) {
    return Vector2Length( v );
}
inline
float LengthSqr( Vector2 v ) {
    return Vector2LengthSqr( v );
}
inline
float DotProduct( Vector2 v1, Vector2 v2 ) {
    return Vector2DotProduct( v1, v2 );
}
inline
float Distance( Vector2 v1, Vector2 v2 ) {
    return Vector2Distance( v1, v2 );
}
inline
float DistanceSqr( Vector2 v1, Vector2 v2 ) {
    return Vector2DistanceSqr( v1, v2 );
}
inline
float Angle( Vector2 v1, Vector2 v2 ) {
    return Vector2Angle( v1, v2 );
}
inline
Vec2 Normalize( Vector2 v ) {
    return Vector2Normalize( v );
}
inline
Vec2 Lerp( Vector2 v1, Vector2 v2, float amount ) {
    return Vector2Lerp( v1, v2, amount );
}
inline
Vec2 Reflect( Vector2 v, Vector2 normal ) {
    return Vector2Reflect( v, normal );
}
inline
Vec2 Rotate( Vector2 v, float angle ) {
    return Vector2Rotate( v, angle );
}
inline
Vec2 Clamp( Vector2 v, Vector2 min, Vector2 max ) {
    return Vector2Clamp( v, min, max );
}
inline
Vec2 Clamp( Vector2 v, float min, float max ) {
    return Vector2ClampValue( v, min, max );
}

struct Vec3 {
    union {
        float array[3];
        struct { float x = 0.0f, y = 0.0f, z = 0.0f; };

        Swizzler<Vec2, Vector2, 0, 0> xx;
        Swizzler<Vec2, Vector2, 1, 1> yy;
        Swizzler<Vec2, Vector2, 0, 1> xy;
        Swizzler<Vec2, Vector2, 1, 0> yx;

        Swizzler<Vec3, Vector3, 0, 1, 2> xyz;
        Swizzler<Vec3, Vector3, 0, 2, 1> xzy;
        Swizzler<Vec3, Vector3, 1, 2, 0> yzx;
        Swizzler<Vec3, Vector3, 1, 0, 2> yxz;
        Swizzler<Vec3, Vector3, 2, 0, 1> zxy;
        Swizzler<Vec3, Vector3, 2, 1, 0> zyx;
        Swizzler<Vec3, Vector3, 0, 0, 0> xxx;
        Swizzler<Vec3, Vector3, 1, 0, 0> yxx;
        Swizzler<Vec3, Vector3, 0, 1, 0> xyx;
        Swizzler<Vec3, Vector3, 0, 0, 1> xxy;
        Swizzler<Vec3, Vector3, 2, 0, 0> zxx;
        Swizzler<Vec3, Vector3, 0, 2, 0> xzx;
        Swizzler<Vec3, Vector3, 0, 0, 2> xxz;
        Swizzler<Vec3, Vector3, 1, 1, 1> yyy;
        Swizzler<Vec3, Vector3, 0, 1, 1> xyy;
        Swizzler<Vec3, Vector3, 1, 0, 1> yxy;
        Swizzler<Vec3, Vector3, 1, 1, 0> yyx;
        Swizzler<Vec3, Vector3, 2, 1, 1> zyy;
        Swizzler<Vec3, Vector3, 1, 2, 1> yzy;
        Swizzler<Vec3, Vector3, 1, 1, 2> yyz;
        Swizzler<Vec3, Vector3, 2, 2, 2> zzz;
        Swizzler<Vec3, Vector3, 0, 2, 2> xzz;
        Swizzler<Vec3, Vector3, 2, 0, 2> zxz;
        Swizzler<Vec3, Vector3, 2, 2, 0> zzx;
        Swizzler<Vec3, Vector3, 1, 2, 2> yzz;
        Swizzler<Vec3, Vector3, 2, 1, 2> zyz;
        Swizzler<Vec3, Vector3, 2, 2, 1> zzy;
    };

    Vec3() {}
    Vec3( float x, float y, float z ) : x(x), y(y), z(z) {}
    Vec3( const Vector3& v ) : Vec3( v.x, v.y, v.z ) {}

    inline
    operator Vector3() const {
        return *(Vector3*)this;
    }
    inline
    float operator[]( size_t idx ) const {
        return array[idx];
    }
    inline
    float& operator[]( size_t idx ) {
        return array[idx];
    }

    inline
    Vec3& operator+=( Vec3 v2 ) {
        return *this = this->Add( v2 );
    }
    inline
    Vec3& operator-=( Vec3 v2 ) {
        return *this = this->Subtract( v2 );
    }
    inline
    Vec3& operator*=( float value ) {
        return *this = this->Scale( value );
    }
    inline
    Vec3& operator/=( float value ) {
        return *this = this->Scale( 1.0f / value );
    }
    inline
    Vec3 operator-() const {
        return this->Negate();
    }

    static inline
    Vec3 Zero() {
        return Vector3Zero();
    }
    static inline
    Vec3 One() {
        return Vector3One();
    }

    inline
    Vec3 Add( Vector3 v2 ) const {
        return Vector3Add( *this, v2 );
    }
    inline
    Vec3 AddValue( float add ) const {
        return Vector3AddValue( *this, add );
    }
    inline
    Vec3 Subtract( Vector3 v2 ) const {
        return Vector3Subtract( *this, v2 );
    }
    inline
    Vec3 SubtractValue( float sub ) const {
        return Vector3SubtractValue( *this, sub );
    }
    inline
    Vec3 Scale( float scalar ) const {
        return Vector3Scale( *this, scalar );
    }
    inline
    Vec3 Multiply( Vector3 v2 ) const {
        return Vector3Multiply( *this, v2 );
    }
    inline
    Vec3 CrossProduct( Vector3 v2 ) const {
        return Vector3CrossProduct( *this, v2 );
    }
    inline
    Vec3 Perpendicular() const {
        return Vector3Perpendicular( *this );
    }
    inline
    float Length() const {
        return Vector3Length( *this );
    }
    inline
    float LengthSqr() const {
        return Vector3LengthSqr( *this );
    }
    inline
    float DotProduct( Vector3 v2 ) const {
        return Vector3DotProduct( *this, v2 );
    }
    inline
    float Distance( Vector3 v2 ) const {
        return Vector3Distance( *this, v2 );
    }
    inline
    float DistanceSqr( Vector3 v2 ) const {
        return Vector3DistanceSqr( *this, v2 );
    }
    inline
    float Angle( Vector3 v2 ) const {
        return Vector3Angle( *this, v2 );
    }
    inline
    Vec3 Negate() const {
        return Vector3Negate( *this );
    }
    inline
    Vec3 Divide( Vector3 v2 ) const {
        return Vector3Divide( *this, v2 );
    }

    inline
    Vec3 Normalize() const {
        return Vector3Normalize( *this );
    }
    inline
    void OrthoNormalize( Vector3 *v2 ) {
        Vector3OrthoNormalize( (Vector3*)this, v2 );
    }
    inline
    Vec3 Transform( const Matrix& mat ) const {
        return Vector3Transform( *this, mat );
    }
    inline
    Vec3 Rotate( Quaternion q ) const {
        return Vector3RotateByQuaternion( *this, q );
    }
    inline
    Vec3 Rotate( Vector3 axis, float angle ) const {
        return Vector3RotateByAxisAngle( *this, axis, angle );
    }
    inline
    Vec3 MoveTowards( Vector3 target, float maxDistance ) const {
        return Vector3MoveTowards( *this, target, maxDistance );
    }
    inline
    Vec3 Lerp( Vector3 v2, float amount ) const {
        return Vector3Lerp( *this, v2, amount );
    }
    inline
    Vec3 Reflect( Vector3 normal ) const {
        return Vector3Reflect( *this, normal );
    }
    inline
    Vec3 Min( Vector3 v2 ) const {
        return Vector3Min( *this, v2 );
    }
    inline
    Vec3 Max( Vector3 v2 ) const {
        return Vector3Max( *this, v2 );
    }
    inline
    Vec3 Barycenter( Vector3 a, Vector3 b, Vector3 c ) const {
        return Vector3Barycenter( *this, a, b, c );
    }
    inline
    Vec3 Unproject( const Matrix& projection, const Matrix& view ) const {
        return Vector3Unproject( *this, projection, view );
    }
    inline
    float3 ToFloatV() const {
        return Vector3ToFloatV( *this );
    }
    inline
    Vec3 Invert() const {
        return Vector3Invert( *this );
    }
    inline
    Vec3 Clamp( Vector3 min, Vector3 max ) const {
        return Vector3Clamp( *this, min, max );
    }
    inline
    Vec3 ClampValue( float min, float max ) const {
        return Vector3ClampValue( *this, min, max );
    }
    inline
    bool Equals( Vector3 q ) const {
        return Vector3Equals( *this, q );
    }
    inline
    Vec3 Refract( Vector3 n, float r ) const {
        return Vector3Refract( *this, n, r );
    }
};
inline
Vec3 operator+( Vector3 v1, Vector3 v2 ) {
    return Vector3Add( v1, v2 );
}
inline
Vec3 operator-( Vector3 v1, Vector3 v2 ) {
    return Vector3Subtract( v1, v2 );
}
inline
Vec3 operator*( Vector3 v1, float scale ) {
    return Vector3Scale( v1, scale );
}
inline
Vec3 operator*( float scale, Vector3 v1 ) {
    return Vector3Scale( v1, scale );
}
inline
Vec3 operator*( Vector3 lhs, const Matrix& rhs ) {
    return Vector3Transform( lhs, rhs );
}
inline
Vec3 operator/( Vector3 v1, float scale ) {
    return Vector3Scale( v1, 1.0f / scale );
}
inline
bool operator==( Vector3 p, Vector3 q ) {
    return Vector3Equals( p, q );
}
inline
bool operator!=( Vector3 p, Vector3 q ) {
    return !( p == q );
}
inline
float Length( Vector3 v ) {
    return Vector3Length( v );
}
inline
float LengthSqr( Vector3 v ) {
    return Vector3LengthSqr( v );
}
inline
float DotProduct( Vector3 v1, Vector3 v2 ) {
    return Vector3DotProduct( v1, v2 );
}
inline
Vec3 CrossProduct( Vector3 v1, Vector3 v2 ) {
    return Vector3CrossProduct( v1, v2 );
}
inline
float Distance( Vector3 v1, Vector3 v2 ) {
    return Vector3Distance( v1, v2 );
}
inline
float DistanceSqr( Vector3 v1, Vector3 v2 ) {
    return Vector3DistanceSqr( v1, v2 );
}
inline
float Angle( Vector3 v1, Vector3 v2 ) {
    return Vector3Angle( v1, v2 );
}
inline
Vec3 Normalize( Vector3 v ) {
    return Vector3Normalize( v );
}
inline
Vec3 MoveTowards( Vector3 v, Vector3 target, float maxDistance ) {
    return Vector3MoveTowards( v, target, maxDistance );
}
inline
Vec3 Lerp( Vector3 v1, Vector3 v2, float amount ) {
    return Vector3Lerp( v1, v2, amount );
}
inline
Vec3 Reflect( Vector3 v, Vector3 normal ) {
    return Vector3Reflect( v, normal );
}
inline
Vec3 Rotate( Vector3 v, Quaternion q ) {
    return Vector3RotateByQuaternion( v, q );
}
inline
Vec3 Rotate( Vector3 v, Vector3 axis, float angle ) {
    return Vector3RotateByAxisAngle( v, axis, angle );
}
inline
Vec3 Clamp( Vector3 v, Vector3 min, Vector3 max ) {
    return Vector3Clamp( v, min, max );
}
inline
Vec3 Clamp( Vector3 v, float min, float max ) {
    return Vector3ClampValue( v, min, max );
}

struct Vec4 {
    union {
        float array[4];
        struct { float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f; };
        // TODO(alicia): swizzle? there are 256 permutations . . .
    };
    Vec4() {}
    Vec4( float x, float y, float z, float w ) : x(x), y(y), z(z), w(w) {}
    Vec4( const Vector4& v ) : Vec4( v.x, v.y, v.z, v.w ) {}

    inline
    operator Vector4() const {
        return *(Vector4*)this;
    }
    inline
    float operator[]( size_t idx ) const {
        return array[idx];
    }
    inline
    float& operator[]( size_t idx ) {
        return array[idx];
    }

    inline
    Vec4& operator+=( Vec4 v2 ) {
        return *this = this->Add( v2 );
    }
    inline
    Vec4& operator-=( Vec4 v2 ) {
        return *this = this->Subtract( v2 );
    }
    inline
    Vec4& operator*=( float value ) {
        return *this = this->Scale( value );
    }
    inline
    Vec4& operator/=( float value ) {
        return *this = this->Scale( 1.0f / value );
    }
    inline
    Vec4 operator-() const {
        return this->Negate();
    }

    static inline
    Vec4 Zero() {
        return Vector4Zero();
    }
    static inline
    Vec4 One() {
        return Vector4One();
    }

    inline
    Vec4 Add( Vector4 v2 ) const {
        return Vector4Add( *this, v2 );
    }
    inline
    Vec4 AddValue( float add ) const {
        return Vector4AddValue( *this, add );
    }
    inline
    Vec4 Subtract( Vector4 v2 ) const {
        return Vector4Subtract( *this, v2 );
    }
    inline
    Vec4 SubtractValue( float sub ) const {
        return Vector4SubtractValue( *this, sub );
    }
    inline
    Vec4 Scale( float scalar ) const {
        return Vector4Scale( *this, scalar );
    }
    inline
    Vec4 Multiply( Vector4 v2 ) const {
        return Vector4Multiply( *this, v2 );
    }
    inline
    float Length() const {
        return Vector4Length( *this );
    }
    inline
    float LengthSqr() const {
        return Vector4LengthSqr( *this );
    }
    inline
    float DotProduct( Vector4 v2 ) const {
        return Vector4DotProduct( *this, v2 );
    }
    inline
    float Distance( Vector4 v2 ) const {
        return Vector4Distance( *this, v2 );
    }
    inline
    float DistanceSqr( Vector4 v2 ) const {
        return Vector4DistanceSqr( *this, v2 );
    }
    inline
    Vec4 Negate() const {
        return Vector4Negate( *this );
    }
    inline
    Vec4 Divide( Vector4 v2 ) const {
        return Vector4Divide( *this, v2 );
    }
    inline
    Vec4 Normalize() const {
        return Vector4Normalize( *this );
    }
    inline
    void OrthoNormalize( Vector3 *v2 ) {
        Vector3OrthoNormalize( (Vector3*)this, v2 );
    }
    inline
    Vec4 MoveTowards( Vector4 target, float maxDistance ) const {
        return Vector4MoveTowards( *this, target, maxDistance );
    }
    inline
    Vec4 Lerp( Vector4 v2, float amount ) const {
        return Vector4Lerp( *this, v2, amount );
    }
    inline
    Vec4 Min( Vector4 v2 ) const {
        return Vector4Min( *this, v2 );
    }
    inline
    Vec4 Max( Vector4 v2 ) const {
        return Vector4Max( *this, v2 );
    }
    inline
    Vec4 Invert() const {
        return Vector4Invert( *this );
    }
    inline
    bool Equals( Vector4 q ) const {
        return Vector4Equals( *this, q );
    }
};
inline
Vec4 operator+( Vec4 v1, Vec4 v2 ) {
    return Vector4Add( v1, v2 );
}
inline
Vec4 operator-( Vec4 v1, Vec4 v2 ) {
    return Vector4Subtract( v1, v2 );
}
inline
Vec4 operator*( Vec4 v1, float scale ) {
    return Vector4Scale( v1, scale );
}
inline
Vec4 operator*( float scale, Vec4 v1 ) {
    return Vector4Scale( v1, scale );
}
inline
Vec4 operator/( Vec4 v1, float scale ) {
    return Vector4Scale( v1, 1.0f / scale );
}
inline
bool operator==( Vec4 p, Vec4 q ) {
    return Vector4Equals( p, q );
}
inline
bool operator!=( Vec4 p, Vec4 q ) {
    return !( p == q );
}
inline
float Length( Vector4 v ) {
    return Vector4Length( v );
}
inline
float LengthSqr( Vector4 v ) {
    return Vector4LengthSqr( v );
}
inline
float DotProduct( Vector4 v1, Vector4 v2 ) {
    return Vector4DotProduct( v1, v2 );
}
inline
float Distance( Vector4 v1, Vector4 v2 ) {
    return Vector4Distance( v1, v2 );
}
inline
float DistanceSqr( Vector4 v1, Vector4 v2 ) {
    return Vector4DistanceSqr( v1, v2 );
}
inline
Vec4 Normalize( Vector4 v ) {
    return Vector4Normalize( v );
}
inline
Vec4 MoveTowards( Vector4 v, Vector4 target, float maxDistance ) {
    return Vector4MoveTowards( v, target, maxDistance );
}
inline
Vec4 Lerp( Vector4 v1, Vector4 v2, float amount ) {
    return Vector4Lerp( v1, v2, amount );
}

struct Mat4 {
    union {
        float  array[16];
        Matrix m;
        struct {
            float m0 = 0.0f, m4 = 0.0f,  m8 = 0.0f, m12 = 0.0f; 
            float m1 = 0.0f, m5 = 0.0f,  m9 = 0.0f, m13 = 0.0f; 
            float m2 = 0.0f, m6 = 0.0f, m10 = 0.0f, m14 = 0.0f;
            float m3 = 0.0f, m7 = 0.0f, m11 = 0.0f, m15 = 0.0f;
        };
    };

    Mat4() {}
    Mat4(
        float m0, float m4, float  m8, float m12, 
        float m1, float m5, float  m9, float m13, 
        float m2, float m6, float m10, float m14,
        float m3, float m7, float m11, float m15
    ) :
        m0(m0), m4(m4),   m8(m8), m12(m12), 
        m1(m1), m5(m5),   m9(m9), m13(m13), 
        m2(m2), m6(m6), m10(m10), m14(m14),
        m3(m3), m7(m7), m11(m11), m15(m15)
    {}
#if defined(RAYMATH_CPP_NO_STDLIB)
    Mat4( const Matrix& mat ) {
        *this = *(const Mat4*)&mat;
    }
#else
    Mat4( const Matrix& mat ) : m( std::move(mat) ) {}
#endif

    inline
    operator const Matrix&() const {
        return *(Matrix*)this;
    }
    inline
    operator Matrix&() {
        return *(Matrix*)this;
    }
    inline
    float operator[]( size_t idx ) const {
        return array[idx];
    }
    inline
    float& operator[]( size_t idx ) {
        return array[idx];
    }


    static inline
    Mat4 Identity() {
        return MatrixIdentity();
    }
    static inline
    Mat4 Translate( float x, float y, float z ) {
        return MatrixTranslate( x, y, z );
    }
    static inline
    Mat4 Translate( Vector3 translate ) {
        return MatrixTranslate( translate.x, translate.y, translate.z );
    }
    static inline
    Mat4 Rotate( Vector3 axis, float angle ) {
        return MatrixRotate( axis, angle );
    }
    static inline
    Mat4 RotateX( float angle ) {
        return MatrixRotateX( angle );
    }
    static inline
    Mat4 RotateY( float angle ) {
        return MatrixRotateY( angle );
    }
    static inline
    Mat4 RotateZ( float angle ) {
        return MatrixRotateZ( angle );
    }
    static inline
    Mat4 RotateXYZ( Vector3 angle ) {
        return MatrixRotateXYZ( angle );
    }
    static inline
    Mat4 RotateZYX( Vector3 angle ) {
        return MatrixRotateZYX( angle );
    }
    static inline
    Mat4 Scale( float x, float y, float z ) {
        return MatrixScale( x, y, z );
    }
    static inline
    Mat4 Scale( Vector3 scale ) {
        return MatrixScale( scale.x, scale.y, scale.z );
    }
    static inline
    Mat4 Frustum(
        double left, double right,
        double bottom, double top,
        double nearPlane, double farPlane
    ) {
        return MatrixFrustum(
            left, right,
            bottom, top,
            nearPlane, farPlane );
    }
    static inline
    Mat4 Perspective( double fovY, double aspect, double nearPlane, double farPlane ) {
        return MatrixPerspective( fovY, aspect, nearPlane, farPlane );
    }
    static inline
    Mat4 Ortho(
        double left, double right,
        double bottom, double top,
        double nearPlane, double farPlane
    ) {
        return MatrixOrtho(
            left, right,
            bottom, top,
            nearPlane, farPlane );
    }
    static inline
    Mat4 LookAt( Vector3 eye, Vector3 target, Vector3 up ) {
        return MatrixLookAt( eye, target, up );
    }

    inline
    float Determinant() const {
        return MatrixDeterminant( *this );
    }
    inline
    float Trace() const {
        return MatrixTrace( *this );
    }
    inline
    Mat4 Transpose() const {
        return MatrixTranspose( *this );
    }
    inline
    Mat4 Invert() const {
        return MatrixInvert( *this );
    }
    inline
    Mat4 Add( const Matrix& right ) const {
        return MatrixAdd( *this, right );
    }
    inline
    Mat4 Subtract( const Matrix& right ) const {
        return MatrixSubtract( *this, right );
    }
    inline
    Mat4 Multiply( const Matrix& right ) const {
        const Matrix& left = *this;

        Matrix result = {};

        // NOTE(alicia): copied from raymath.h
        // this is to avoid making a copy of left and right matrices.
        result.m0 = left.m0*right.m0 + left.m1*right.m4 + left.m2*right.m8 + left.m3*right.m12;
        result.m1 = left.m0*right.m1 + left.m1*right.m5 + left.m2*right.m9 + left.m3*right.m13;
        result.m2 = left.m0*right.m2 + left.m1*right.m6 + left.m2*right.m10 + left.m3*right.m14;
        result.m3 = left.m0*right.m3 + left.m1*right.m7 + left.m2*right.m11 + left.m3*right.m15;
        result.m4 = left.m4*right.m0 + left.m5*right.m4 + left.m6*right.m8 + left.m7*right.m12;
        result.m5 = left.m4*right.m1 + left.m5*right.m5 + left.m6*right.m9 + left.m7*right.m13;
        result.m6 = left.m4*right.m2 + left.m5*right.m6 + left.m6*right.m10 + left.m7*right.m14;
        result.m7 = left.m4*right.m3 + left.m5*right.m7 + left.m6*right.m11 + left.m7*right.m15;
        result.m8 = left.m8*right.m0 + left.m9*right.m4 + left.m10*right.m8 + left.m11*right.m12;
        result.m9 = left.m8*right.m1 + left.m9*right.m5 + left.m10*right.m9 + left.m11*right.m13;
        result.m10 = left.m8*right.m2 + left.m9*right.m6 + left.m10*right.m10 + left.m11*right.m14;
        result.m11 = left.m8*right.m3 + left.m9*right.m7 + left.m10*right.m11 + left.m11*right.m15;
        result.m12 = left.m12*right.m0 + left.m13*right.m4 + left.m14*right.m8 + left.m15*right.m12;
        result.m13 = left.m12*right.m1 + left.m13*right.m5 + left.m14*right.m9 + left.m15*right.m13;
        result.m14 = left.m12*right.m2 + left.m13*right.m6 + left.m14*right.m10 + left.m15*right.m14;
        result.m15 = left.m12*right.m3 + left.m13*right.m7 + left.m14*right.m11 + left.m15*right.m15;

        return result;
    }
    inline
    float16 ToFloatV() const {
        return MatrixToFloatV( *this );
    }
};
inline
Mat4 operator+( const Matrix& left, const Matrix& right ) {
    return MatrixAdd( left, right );
}
inline
Mat4 operator-( const Matrix& left, const Matrix& right ) {
    return MatrixSubtract( left, right );
}
inline
Mat4 operator*( const Matrix& left, const Matrix& right ) {
    Matrix result = {};

    // NOTE(alicia): copied from raymath.h
    // this is to avoid making a copy of left and right matrices.
    result.m0 = left.m0*right.m0 + left.m1*right.m4 + left.m2*right.m8 + left.m3*right.m12;
    result.m1 = left.m0*right.m1 + left.m1*right.m5 + left.m2*right.m9 + left.m3*right.m13;
    result.m2 = left.m0*right.m2 + left.m1*right.m6 + left.m2*right.m10 + left.m3*right.m14;
    result.m3 = left.m0*right.m3 + left.m1*right.m7 + left.m2*right.m11 + left.m3*right.m15;
    result.m4 = left.m4*right.m0 + left.m5*right.m4 + left.m6*right.m8 + left.m7*right.m12;
    result.m5 = left.m4*right.m1 + left.m5*right.m5 + left.m6*right.m9 + left.m7*right.m13;
    result.m6 = left.m4*right.m2 + left.m5*right.m6 + left.m6*right.m10 + left.m7*right.m14;
    result.m7 = left.m4*right.m3 + left.m5*right.m7 + left.m6*right.m11 + left.m7*right.m15;
    result.m8 = left.m8*right.m0 + left.m9*right.m4 + left.m10*right.m8 + left.m11*right.m12;
    result.m9 = left.m8*right.m1 + left.m9*right.m5 + left.m10*right.m9 + left.m11*right.m13;
    result.m10 = left.m8*right.m2 + left.m9*right.m6 + left.m10*right.m10 + left.m11*right.m14;
    result.m11 = left.m8*right.m3 + left.m9*right.m7 + left.m10*right.m11 + left.m11*right.m15;
    result.m12 = left.m12*right.m0 + left.m13*right.m4 + left.m14*right.m8 + left.m15*right.m12;
    result.m13 = left.m12*right.m1 + left.m13*right.m5 + left.m14*right.m9 + left.m15*right.m13;
    result.m14 = left.m12*right.m2 + left.m13*right.m6 + left.m14*right.m10 + left.m15*right.m14;
    result.m15 = left.m12*right.m3 + left.m13*right.m7 + left.m14*right.m11 + left.m15*right.m15;

    return result;
}

struct Quat {
    union {
        float array[4];
        struct { float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f; };
    };

    Quat() {}
    Quat( float x, float y, float z, float w ) : x(x), y(y), z(z), w(w) {}
    explicit Quat( float pitch, float yaw, float roll ) : Quat( FromEuler(pitch, yaw, roll)) {}
    explicit Quat( Vector3 from, Vector3 to ) : Quat( FromVector3ToVector3( from, to ) ) {}
    explicit Quat( Vector3 axis, float angle ) : Quat( FromAxisAngle( axis, angle ) ) {}
    explicit Quat( const Matrix& mat ) : Quat( FromMatrix( mat ) ) {}
    Quat( const Quaternion& q ) : Quat( q.x, q.y, q.z, q.w ) {}

    static inline
    Quat Identity() {
        return QuaternionIdentity();
    }
    static inline
    Quat FromVector3ToVector3( Vector3 from, Vector3 to ) {
        return QuaternionFromVector3ToVector3( from, to );
    }
    static inline
    Quat FromMatrix( const Matrix& mat ) {
        return QuaternionFromMatrix( mat );
    }
    static inline
    Quat FromAxisAngle( Vector3 axis, float angle ) {
        return QuaternionFromAxisAngle( axis, angle );
    }
    static inline
    Quat FromEuler( float pitch, float yaw, float roll ) {
        return QuaternionFromEuler( pitch, yaw, roll );
    }

    inline
    operator Quaternion() const {
        return *(Quaternion*)this;
    }
    inline
    float operator[]( size_t idx ) const {
        return array[idx];
    }
    inline
    float& operator[]( size_t idx ) {
        return array[idx];
    }

    inline
    Quat Add( Quaternion q2 ) const {
        return QuaternionAdd( *this, q2 );
    }
    inline
    Quat AddValue( float add ) const {
        return QuaternionAddValue( *this, add );
    }
    inline
    Quat Subtract( Quaternion q2 ) const {
        return QuaternionSubtract( *this, q2 );
    }
    inline
    Quat SubtractValue( float add ) const {
        return QuaternionSubtractValue( *this, add );
    }
    inline
    float Length() const {
        return QuaternionLength( *this );
    }
    inline
    Quat Normalize() const {
        return QuaternionNormalize( *this );
    }
    inline
    Quat Invert() const {
        return QuaternionInvert( *this );
    }
    inline
    Quat Multiply( Quaternion q2 ) const {
        return QuaternionMultiply( *this, q2 );
    }
    inline
    Quat Scale( float mul ) const {
        return QuaternionScale( *this, mul );
    }
    inline
    Quat Divide( Quaternion q2 ) const {
        return QuaternionDivide( *this, q2 );
    }
    inline
    Quat Lerp( Quaternion q2, float amount ) const {
        return QuaternionLerp( *this, q2, amount );
    }
    inline
    Quat Nlerp( Quaternion q2, float amount ) const {
        return QuaternionNlerp( *this, q2, amount );
    }
    inline
    Quat Slerp( Quaternion q2, float amount ) const {
        return QuaternionSlerp( *this, q2, amount );
    }
    inline
    Mat4 ToMatrix() const {
        return QuaternionToMatrix( *this );
    }
    inline
    void ToAxisAngle( Vector3* outAxis, float* outAngle ) const {
        QuaternionToAxisAngle( *this, outAxis, outAngle );
    }
    inline
    void ToAxisAngle( Vec3* outAxis, float* outAngle ) const {
        QuaternionToAxisAngle( *this, (Vector3*)outAxis, outAngle );
    }
    inline
    Vec3 ToEuler() const {
        return QuaternionToEuler( *this );
    }
    inline
    Quat Transform( const Matrix& mat ) const {
        return QuaternionTransform( *this, mat );
    }
    inline
    bool Equals( Quaternion q ) const {
        return QuaternionEquals( *this, q );
    }
};
inline
Quat operator+( Quaternion v1, Quaternion v2 ) {
    return QuaternionAdd( v1, v2 );
}
inline
Quat operator-( Quaternion v1, Quaternion v2 ) {
    return QuaternionSubtract( v1, v2 );
}
inline
Quat operator*( Quaternion v1, float scale ) {
    return QuaternionScale( v1, scale );
}
inline
Quat operator*( float scale, Quaternion v1 ) {
    return QuaternionScale( v1, scale );
}
inline
Quat operator*( Quaternion lhs, const Matrix& rhs ) {
    return QuaternionTransform( lhs, rhs );
}
inline
Quat operator/( Quaternion v1, float scale ) {
    return QuaternionScale( v1, 1.0f / scale );
}
inline
bool operator==( Quaternion p, Quaternion q ) {
    return QuaternionEquals( p, q );
}
inline
bool operator!=( Quaternion p, Quaternion q ) {
    return !( p == q );
}
inline
Quat Nlerp( Quaternion q1, Quaternion q2, float amount ) {
    return QuaternionNlerp( q1, q2, amount );
}
inline
Quat Slerp( Quaternion q1, Quaternion q2, float amount ) {
    return QuaternionSlerp( q1, q2, amount );
}
// NOTE(alicia):
// Lerp, Normalize,
// Length and LengthSqr already implemented from Vector4

#endif /* header guard */
