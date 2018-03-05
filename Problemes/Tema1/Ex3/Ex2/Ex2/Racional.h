
class NombreRacional
{
public:
	NombreRacional();
	void setNumerador(int numerador);
	void setDenominador(int denominador);
	int getNumerador();
	int getDenominador();
	bool esValid();
	float decimal();
	void suma(NombreRacional b);
	void multiplica(NombreRacional b);
	void resta(NombreRacional b);
	void divideix(NombreRacional b);
	
private:
	int _numerador;
	int _denominador;
};

