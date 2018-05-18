#pragma once



class AssignaturaExpedient
{
public:
	AssignaturaExpedient() { m_nConvocatories = 0; }
	AssignaturaExpedient(int codi, int nCredits) { m_codi = codi; m_nCredits = nCredits; m_nConvocatories = 0; }
	int getCodi() const { return m_codi; }
	int getCredits() const { return m_nCredits; }
private:
	static const int MAX_CONVOCATORIES = 3;
	int m_codi;
	int m_nCredits;
	int m_notes[MAX_CONVOCATORIES];
	int m_nConvocatories;
};

