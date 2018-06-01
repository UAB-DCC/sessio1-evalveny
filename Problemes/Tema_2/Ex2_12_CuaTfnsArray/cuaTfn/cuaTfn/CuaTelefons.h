#include <string>
using namespace std;

class CuaTelefons
{
public:
	CuaTelefons();
	~CuaTelefons();
	void eliminaTot();
	void addTfn(string tfn);
	string& getTfn();
	int getNumTelefons() { return m_numElements; }
private:
	static const int MIDAINICIAL = 10;
	int m_mida;
	int m_posIni;
	int m_posFi;
	int m_numElements;
	string* m_telefons;
};
