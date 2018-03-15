
const int RANG_NOTES = 11;

class HistogramaNotes
{
public:
	HistogramaNotes();
	
	bool registra(float valor);

	int getValor(int posicio) const;

private:
	int m_notes[RANG_NOTES];
};

