
class Complex
{
private:
	float m_real;
	float m_img;
public:
	Complex();
	~Complex();
	void setReal(float);
	void setImg(float);
	float getReal();
	float getImg();
	void suma(Complex *suma);
	void conjugat();
	void mostraComplex();
};