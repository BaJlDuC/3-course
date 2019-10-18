#include "CPerimeterCalculation.h"
#include <iostream>

using namespace std;

void CPerimeterCalculation::PrintInfo(vector<string>& stream) const
{
	if (m_shape->GetShapeType() == "RECTANGLE")
	{
		//vector<float> size = m_shape->GetSize();
		stream.push_back(" P=" + to_string((m_shape->GetSize().at(0) + m_shape->GetSize().at(1)) * 2) + ';');
		m_shape->PrintInfo(stream);
	}
	else if (m_shape->GetShapeType() == "CIRCLE")
	{
		//vector<float> radius = m_shape->GetSize();
		stream.push_back(" P=" + to_string(2 * 3.14 * m_shape->GetSize().at(0)) + ';');
		m_shape->PrintInfo(stream);
	}
	else if (m_shape->GetShapeType() == "TRIANGLE")
	{
		stream.push_back(" P=" + to_string(m_shape->GetSize().at(0) + m_shape->GetSize().at(1) + m_shape->GetSize().at(2)) + ';');
		m_shape->PrintInfo(stream);
	}
	else
	{
		return;
	}
}

string CPerimeterCalculation::GetShapeType() const
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

vector<int> CPerimeterCalculation::GetSize() const
{
	return m_shape->GetSize();
}

void CPerimeterCalculation::SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const
{
	m_shape->SetTrianglePoint(point1, point2, point3);
}