#include "GUIMyFrame1.h"
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>

class Point4D
{
public:
	Point4D(double x, double y, double z, double f) : x(x), y(y), z(z), f(f) {}
private:
	double x, y, z, f;
};

std::vector<Point4D> data;

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::m_loadOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_loadOnButtonClick
	wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Text file (*.txt)|*.txt"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK)
	{
		std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
		if (in.is_open())
		{
			data.clear();
			while (!in.eof())
			{
				double x, y, z, f;
				in >> x >> y >> z >> f;
				data.push_back(Point4D(x, y, z, f));
			}
			in.close();
		}
	}
}

void GUIMyFrame1::m_saveOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_saveOnButtonClick
}

void GUIMyFrame1::m_slider2OnScroll( wxScrollEvent& event )
{
// TODO: Implement m_slider2OnScroll
}

void GUIMyFrame1::m_panelOnUpdateUI( wxUpdateUIEvent& event )
{
// TODO: Implement m_panelOnUpdateUI
}

void GUIMyFrame1::m_w1OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w1OnButtonClick
}

void GUIMyFrame1::m_w2OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w2OnButtonClick
}

void GUIMyFrame1::m_w3OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w3OnButtonClick
}

void GUIMyFrame1::m_w4OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w4OnButtonClick
}

void GUIMyFrame1::m_w5OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w5OnButtonClick
}

void GUIMyFrame1::m_w6OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w6OnButtonClick
}


void GUIMyFrame1::Repaint()
{
    wxClientDC dc(m_panel);
    wxBufferedDC dcBuff(&dc);
    dcBuff.SetBackground(*wxWHITE_BRUSH);
    dcBuff.Clear();
}