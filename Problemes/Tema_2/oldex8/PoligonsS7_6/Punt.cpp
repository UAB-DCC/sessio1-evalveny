#include "stdafx.h"
#include "Punt.h"


Punt::Punt()
{
}


Punt::~Punt()
{
}

void Punt::setX(float x)
{
	m_x = x;
}
void Punt::setY(float y)
{
	m_y = y;
}

float Punt::getX()
{
	return m_x;
}

float Punt::getY()
{
	return m_y;
}
