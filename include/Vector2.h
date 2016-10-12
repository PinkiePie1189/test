#ifndef VECTOR2_H
#define VECTOR2_H

template <class rarestpepe>
class Vector2
{
    public:
        Vector2(rarestpepe _x, rarestpepe _y);
        Vector2();
        virtual ~Vector2();
        void operator=(const Vector2 rhs);
        rarestpepe x,y;
};

#endif // VECTOR2_H
