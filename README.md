Raymath C++ Extension -- ARCHIVED
======================

[!WARNING]
It seems that raymath now has C++ operator overloading so
this is no longer necessary.

This is a header that implements
swizzling, function overloading and
operator overloading for Raymath types.

In order to not collide with C raymath types,
the C++ versions are named slightly differently.

| raymath.h name | C++ name |
| -------------- | -------- |
| Vector2        | Vec2     |
| Vector3        | Vec3     |
| Vector4        | Vec4     |
| Matrix         | Mat4     |
| Quaternion     | Quat     |

All types have their associated functions implemented as methods.
Some common functions such as Lerp or Normalize have an overload so
for example, you don't have to type out Vector2Lerp.

Vec2 and Vec3 have GLSL-style swizzling implemented so you can do things like this:
```cpp
Vec2 a = { 1.0, 2.0 };
Vec2 b = a.xx;                // { 1.0, 1.0 }
Vec2 c = a.yx;                // { 2.0, 1.0 }

Vec3 d = { 3.0, 4.0, 5.0 };
Vec3 e = c.yxz                // { 4.0, 3.0, 5.0 }
Vec3 f = c.zzy                // { 5.0, 5.0, 4.0 }
```

Links
------
- [raylib](https://www.raylib.com)

