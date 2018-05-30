#include "Exemplar.h"
#include <forward_list>
class Llibre
{
public:
	Llibre() { m_nExemplars = 0;};
	Llibre(const string &titol, const string &autor, int nExemplars);
	~Llibre();

	void setTitol(const string &titol) { m_titol = titol; }
	void setAutor(const string &autor) { m_autor = autor; }
	void setNExemplars(int nExemplars);
	void addExemplar();
	string &getTitol() { return m_titol; }
	string &getAutor() { return m_autor; }
	int getNExemplars() { return m_nExemplars; }

	bool prestar(const string &data, int &codiExemplar);
	bool retornar(const string &data, int codiExemplar);
	Llibre& operator=(const Llibre& l);

private:
	string m_titol;
	string m_autor;
	int m_nExemplars;
	std::forward_list<Exemplar> m_exemplars;
};

