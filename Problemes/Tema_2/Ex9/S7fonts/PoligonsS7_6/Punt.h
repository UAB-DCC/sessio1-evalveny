#pragma once
class Punt
{
public:
	Punt();
	~Punt();
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
private:
	float m_x;
	float m_y;
};

