/*
FALTA TEST SET
*/


class PiramideQuadrada
{
public:
	PiramideQuadrada();
	void setLongitud(float longitud);
	void setAlcada(float alcada);
	bool esValid();
	float volum();
	float area();

private:
	float _longitud;
	float _alcada;
};

