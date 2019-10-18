#include "CSquareCalculation.h"
#include <iostream>

using namespace std;

void CSquareCalculation::PrintInfo(vector<string>& stream) const
{
	if (m_shape->GetShapeType() == "RECTANGLE")
	{
		//vector<float> size = m_shape->GetSize();
		stream.push_back(" S=" + to_string(m_shape->GetSize().at(0) * m_shape->GetSize().at(1)));
		m_shape->PrintInfo(stream);
	}
	else if (m_shape->GetShapeType() == "CIRCLE")
	{
		//vector<float> radius = m_shape->GetSize();
		stream.push_back(" S=" + to_string(3.14 * m_shape->GetSize().at(0) * m_shape->GetSize().at(0)));
		m_shape->PrintInfo(stream);
	}
	else if (m_shape->GetShapeType() == "TRIANGLE")
	{
		int p = (m_shape->GetSize().at(0) + m_shape->GetSize().at(1) + (m_shape->GetSize().at(2))) / 2;
		int square = sqrt(p * (p - m_shape->GetSize().at(0)) * (p - m_shape->GetSize().at(1)) * (m_shape->GetSize().at(2)));
		stream.push_back(" S=" + to_string(square));
		m_shape->PrintInfo(stream);
	}
}

string CSquareCalculation::GetShapeType() const
{
	if (m_shape->GetShapeType() == "RECTANGLE")
	{
		return "RECTANGLE";
	}
	else if (m_shape->GetShapeType() == "CIRCLE")
	{
		return "CIRCLE";
	}
	else if (m_shape->GetShapeType() == "TRIANGLE")
	{
		return "TRIANGLE";
	}
	else
	{
		return "UNKNOWN";
	}
}

vector<int> CSquareCalculation::GetSize() const
{
	return m_shape->GetSize();
}

void CSquareCalculation::SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const
{
	m_shape->SetTrianglePoint(point1, point2, point3);
}