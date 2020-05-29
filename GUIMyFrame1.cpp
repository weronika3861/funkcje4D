#include "GUIMyFrame1.h"
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include <iterator>


GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	IsFileLoaded = false;
	SliceImage.Create(m_panel->GetSize());
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
			XData.clear();
			YData.clear();
			ZData.clear();
			FData.clear();

			while (!in.eof())
			{
				double x, y, z, f;
				in >> x >> y >> z >> f;
				XData.push_back(x);
				YData.push_back(y);
				ZData.push_back(z);
				FData.push_back(f);
			}
			in.close();
		}
			double arg_min = XData[0];
			double arg_max = XData[XData.size() - 1];
			PointRange = arg_max - arg_min;

			FunMin = *std::min_element(std::begin(FData), std::end(FData));
			FunMax = *std::max_element(std::begin(FData), std::end(FData));

			IsFileLoaded = true;
	}
}

void GUIMyFrame1::m_saveOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_saveOnButtonClick
}

void GUIMyFrame1::m_slider2OnScroll( wxScrollEvent& event )
{
// TODO: Implement m_slider2OnScroll
	SliceNumber = m_slider2->GetValue();
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_panelOnUpdateUI( wxUpdateUIEvent& event )
{
// TODO: Implement m_panelOnUpdateUI
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w1OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w1OnButtonClick
	SliceVector = Vector3D(1, 0, 0);
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w2OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w2OnButtonClick
	SliceVector = Vector3D(0, 1, 0);
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w3OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w3OnButtonClick
	SliceVector = Vector3D(0, 0, 1);
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w4OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w4OnButtonClick
	SliceVector = Vector3D(1, 1, 0);
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w5OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w5OnButtonClick
	SliceVector = Vector3D(1, 0, 1);
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w6OnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_w6OnButtonClick
	SliceVector = Vector3D(0, 1, 1);
	DrawSlice();
	Repaint();
}


void GUIMyFrame1::Repaint()
{
	wxClientDC dc_(m_panel);
	wxBufferedDC dc(&dc_);
    dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();
	wxBitmap bitmap(SliceImage); 
	dc.DrawBitmap(bitmap, 0, 0); //rysowanie na ekranie aktualnego przekroju
}

void GUIMyFrame1::DrawSlice()
{
	if (IsFileLoaded == false)
		return;

	double arg_min = XData[0];
	double z = arg_min + SliceNumber / 100 * PointRange; //konwersja numeru przekroju (na sliderze) na wartoœæ któregoœ z argumentów

	int width = m_panel->GetSize().GetWidth();
	int height = m_panel->GetSize().GetHeight();
	int coord_range = std::min(width, height); //kwadratowy rozmiar wyswietlanego obrazu, dopasowany do rozmiaru okna

	unsigned char * rgb_data = (unsigned char*)malloc(coord_range * coord_range * 3); //tablica zawierajaca wartosci r, g, b dla kazdego piksela okna
	for (int i = 0; i < coord_range; i++)
		for (int j = 0; j < coord_range; j++)
		{
			//przeliczanie indeksow
			int r_pos = i * coord_range * 3 + j * 3 + 0; 
			int g_pos = i * coord_range * 3 + j * 3 + 1;
			int b_pos = i * coord_range * 3 + j * 3 + 2;

			//konwersja numeru piksela na wartosci argumentow na osiach
			double x = arg_min + i / coord_range * PointRange; 
			double y = arg_min + j / coord_range * PointRange;
			
			double f = ShepardMethod(x, y, z); //aproksymujemy wartosc funkcji

			//do mapy kolorow
			//int w = static_cast<int>((f - FunMin) / (FunMax - FunMin)) * 255;
			//rgb_data[r_pos] = rgb_data[g_pos] = rgb_data[b_pos] = w; 

			//to jest tylko testowe
			if (SliceVector == Vector3D(1, 0, 0))
			{
				rgb_data[r_pos] = 255;
				rgb_data[g_pos] = 0;
				rgb_data[b_pos] = 0;
			}
			else if (SliceVector == Vector3D(0, 1, 0))
			{
				rgb_data[r_pos] = 0;
				rgb_data[g_pos] = 255;
				rgb_data[b_pos] = 0;
			}
			else if (SliceVector == Vector3D(0, 0, 1))
			{
				rgb_data[r_pos] = 0;
				rgb_data[g_pos] = 0;
				rgb_data[b_pos] = 255;
			}
			else
			{
				rgb_data[r_pos] = 255;
				rgb_data[g_pos] = 255;
				rgb_data[b_pos] = 255;
			}
		}
	SliceImage = wxImage(coord_range, coord_range, rgb_data); //zapisuje obecny przekrój do SliceImage
}

double GUIMyFrame1::ShepardMethod(double x, double y, double z)
{
	//...
	return 1.0;
}
