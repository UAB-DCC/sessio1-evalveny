#include "AvaluadorPostfix.h"

AvaluadorPostfix::AvaluadorPostfix()
{

}
AvaluadorPostfix::~AvaluadorPostfix()
{

}

float AvaluadorPostfix::avaluar(string expressio)
{
	int i = 0;
	while (i < expressio.length())
	{
		size_t pos = expressio.find(" ");
		string str3 = expressio.substr(i,pos);
		float op1, op2;

		if (str3 == "-")
		{
			if (!m_operands.empty())
			{
				op2 = m_operands.top();
			}
			m_operands.pop();
			if (!m_operands.empty())
			{
				op1 = m_operands.top();
			}
			m_operands.pop();
			m_operands.push(op1 - op2);
		}
		else
			if (str3 == "+")
			{
				if (!m_operands.empty())
				{
					op2 = m_operands.top();
				}
				m_operands.pop();
				if (!m_operands.empty())
				{
					op1 = m_operands.top();
				}
				m_operands.pop();
				m_operands.push(op1 + op2);
			}
			else
				if (str3 == "*")
				{
					if (!m_operands.empty())
					{
						op2 = m_operands.top();
					}
					m_operands.pop();
					if (!m_operands.empty())
					{
						op1 = m_operands.top();
					}
					m_operands.pop();
					m_operands.push(op1 * op2);
				}
				else
					if (str3 == "/")
					{
						if (!m_operands.empty())
						{
							op2 = m_operands.top();
						}
						m_operands.pop();
						if (!m_operands.empty())
						{
							op1 = m_operands.top();
						}
						m_operands.pop();
						m_operands.push(op1 / op2);
					}
					else
					{
						double d = stof(str3);
						m_operands.push(d);
					}
		
		
		if(pos+1 <= expressio.length())
			expressio = expressio.substr(pos+1);
	}
	
	float res= m_operands.top();
	m_operands.pop();

	return res;
}