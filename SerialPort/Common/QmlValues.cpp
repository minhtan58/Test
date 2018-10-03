#include "QmlValues.h"

QmlValues::QmlValues(QObject *parent) : QObject(parent)
  , m_screenWidth(SCREEN_WIDTH)
  , m_screenHeight(SCREEN_HEIGHT)
  , m_backgroundZ(Z_BACKGROUND)
{}

int QmlValues::screenWidth() const
{
    return m_screenWidth;
}

int QmlValues::screenHeight() const
{
    return m_screenHeight;
}

int QmlValues::backgroundZ() const
{
    return m_backgroundZ;
}
