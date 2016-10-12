#include "Vector2.h"

template <class rarestpepe>
Vector2<rarestpepe>::Vector2(rarestpepe _x,rarestpepe _y)
{
    //ctor
    x=_x;
    y=_y;
}

template <class rarestpepe>
Vector2<rarestpepe>::Vector2()
{
    //default ctor
    x=0;
    y=0;
}

template <class rarestpepe>
Vector2<rarestpepe>::~Vector2()
{
    //dtor
}

template <class rarestpepe>
void Vector2<rarestpepe>::operator=(const Vector2 rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
}

template class Vector2<int>;
template class Vector2<float>;
template class Vector2<double>;
template class Vector2<char>;
template class Vector2<bool>;
