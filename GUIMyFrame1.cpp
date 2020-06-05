#include "GUIMyFrame1.h"
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include <iterator>
#include <memory>
#include <wx/log.h> 
#include <cstdlib>
#include <ctime>
#include <wx\wx.h>


GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	IsFileLoaded = false;
	SliceImage.Create(m_panel->GetSize());
	SliceImage.Clear(255);
	//srand(time(NULL));
}

void GUIMyFrame1::m_loadOnButtonClick(wxCommandEvent& event)
{
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
			double arg_min = XData[0];
			double arg_max = XData[XData.size() - 1];
			PointRange = arg_max - arg_min;

			FunMin = *std::min_element(std::begin(FData), std::end(FData));
			FunMax = *std::max_element(std::begin(FData), std::end(FData));
			
			XAxisArg = &YData;
			YAxisArg = &ZData;
			ZAxisArg = &XData;
			
			IsFileLoaded = true;
			IsColor = true;
			DrawSlice();
			Repaint();
		}
		else {
			wxMessageDialog *dial2 = new wxMessageDialog(NULL, wxT("Error loading file"), wxT("Error"), wxOK | wxICON_ERROR);
			dial2->ShowModal();
			delete dial2;
		}
	}
}

void GUIMyFrame1::m_saveOnButtonClick(wxCommandEvent& event)
{
	std::unique_ptr<wxFileDialog> file_dialog(new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("BMP files (*.BMP)|*.BMP"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT));

	if (file_dialog->ShowModal() == wxID_OK) {
		wxLogDebug(_("Selected File: ") + file_dialog->GetPath());
		SliceImage.SaveFile(file_dialog->GetPath(), wxBITMAP_TYPE_BMP);
	}
}

void GUIMyFrame1::m_slider2OnScroll(wxScrollEvent& event)
{
	SliceNumber = m_slider2->GetValue();
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_panelOnUpdateUI(wxUpdateUIEvent& event)
{
	Repaint();
}

void GUIMyFrame1::m_w1OnButtonClick(wxCommandEvent& event)
{
	XAxisArg = &YData;
	YAxisArg = &ZData;
	ZAxisArg = &XData;

	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w2OnButtonClick(wxCommandEvent& event)
{
	XAxisArg = &XData;
	YAxisArg = &ZData;
	ZAxisArg = &YData;
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w3OnButtonClick(wxCommandEvent& event)
{
	XAxisArg = &XData;
	YAxisArg = &YData;
	ZAxisArg = &ZData;
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w4OnButtonClick(wxCommandEvent& event)
{
	/* wektor (1,1,0) jest normalny do powierzchni wyznaczonej przez wektory (0,0,1) oraz (1,-1,0) */

	Xnew.clear(); 
	Ynew.clear();
	Znew.clear();

	for (auto x : XData) {
		for (auto y : YData) {
			for (auto z : ZData) {
				Xnew.push_back(x - y); // oœ X w programie: znormalizowana suma wektorowa (1,0,0) i (0,-1,0) czyli wektor (1,-1,0)
				Ynew.push_back(z); // oœ Y w programie: jak wektor (0,0,1)
				Znew.push_back(x + y); // oœ Z w programie: znormalizowana suma wektorowa (1,0,0) i (0,1,0) czyli wektor (1,1,0) /*normalny*/
			}
		}
	}

	XAxisArg = &Xnew;
	YAxisArg = &Ynew;
	ZAxisArg = &Znew;
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w5OnButtonClick(wxCommandEvent& event)
{
	/* wektor (1,0,1) jest normalny do powierzchni wyznaczonej przez wektory (0,1,0) oraz (1,0,-1) */

	Xnew.clear();
	Ynew.clear();
	Znew.clear();

	for (auto x : XData) {
		for (auto y : YData) {
			for (auto z : ZData) {
				Xnew.push_back(x - z); // oœ X w programie: znormalizowana suma wektorowa (1,0,0) i (0,0,-1) czyli wektor (1,0,-1)
				Ynew.push_back(y); // oœ Y w programie: jak wektor (0,1,0)
				Znew.push_back(x + z); // oœ Z w programie: znormalizowana suma wektorowa (1,0,0) i (0,0,1) czyli wektor (1,0,1) /*normalny*/
			}
		}
	}

	XAxisArg = &Xnew;
	YAxisArg = &Ynew;
	ZAxisArg = &Znew;
	DrawSlice();
	Repaint();
}

void GUIMyFrame1::m_w6OnButtonClick(wxCommandEvent& event)
{
	/* wektor (0,1,1) jest normalny do powierzchni wyznaczonej przez wektory (1,0,0) oraz (0,1,-1) */

	Xnew.clear();
	Ynew.clear();
	Znew.clear();

	for (auto x : XData) {
		for (auto y : YData) {
			for (auto z : ZData) {
				Xnew.push_back(y - z); // oœ X w programie: znormalizowana suma wektorowa (0,1,0) i (0,0,-1) czyli wektor (0,1,-1)
				Ynew.push_back(x); // oœ Y w programie: jak wektor (1,0,0)
				Znew.push_back(y + z); // oœ Z w programie: znormalizowana suma wektorowa (0,1,0) i (0,0,1) czyli wektor (0,1,1) /*normalny*/
			}
		}
	}

	XAxisArg = &Xnew;
	YAxisArg = &Ynew;
	ZAxisArg = &Znew;
	DrawSlice();
	Repaint();
}


void GUIMyFrame1::m_ColorOnButtonClick(wxCommandEvent& event) 
{
	IsColor = true;
	DrawSlice();
	Repaint();
}


void GUIMyFrame1::m_GrayOnButtonClick(wxCommandEvent& event)
{
	IsColor = false;
	DrawSlice();
	Repaint();
}


void GUIMyFrame1::Repaint()
{
	int min_size = std::min(m_panel->GetSize().GetWidth(), m_panel->GetSize().GetHeight());
	wxSize panel_square_size(min_size, min_size);
	if (SliceImage.GetSize() != panel_square_size)
		DrawSlice();
	wxBitmap bitmap(SliceImage);
	wxClientDC dc_(m_panel);
	wxBufferedDC dc(&dc_);
	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();
	dc.DrawBitmap(bitmap, 0, 0); //rysowanie na ekranie aktualnego przekroju
}

void GUIMyFrame1::DrawSlice()
{
	if (IsFileLoaded && XAxisArg && YAxisArg && ZAxisArg)
	{
		double arg_min = XData[0];
		double z_axis_val = arg_min + (double)SliceNumber / 100 * PointRange; //konwersja numeru przekroju (na sliderze) na wartoœæ któregoœ z argumentów

		int width = m_panel->GetSize().GetWidth();
		int height = m_panel->GetSize().GetHeight();
		int coord_range = std::min(width, height); //kwadratowy rozmiar wyswietlanego obrazu, dopasowany do rozmiaru okna

		unsigned char* rgb_data = (unsigned char*)malloc(coord_range * coord_range * 3); //tablica zawierajaca wartosci r, g, b dla kazdego piksela okna
		for (int i = 0; i < coord_range; i++)
			for (int j = 0; j < coord_range; j++)
			{
				//przeliczanie indeksow
				int r_pos = i * coord_range * 3 + j * 3 + 0;
				int g_pos = i * coord_range * 3 + j * 3 + 1;
				int b_pos = i * coord_range * 3 + j * 3 + 2;

				//konwersja numeru piksela na wartosci argumentow na osiach
				double x_axis_val = arg_min + i / (double)coord_range * PointRange;
				double y_axis_val = arg_min + j / (double)coord_range * PointRange;

				int N = XData.size();
				
				double f = ShepardMethod(N, x_axis_val, y_axis_val, z_axis_val); //aproksymujemy wartosc funkcji
				int w = static_cast<int>((f - FunMin) / (FunMax - FunMin) * 255);
				//int w = rand() % 256;

				if (IsColor) { //czerwono-niebieski
					rgb_data[r_pos] = w;
					rgb_data[g_pos] = 0;
					rgb_data[b_pos] = 1 - w;
				}
				else { //odcienie szaroœci
					rgb_data[r_pos] = w;
					rgb_data[g_pos] = w;
					rgb_data[b_pos] = w;
				}
			}
		SliceImage = wxImage(coord_range, coord_range, rgb_data); //zapisuje obecny przekrój do SliceImage
	}
}

double GUIMyFrame1::ShepardMethod(int n, double x, double y, double z)
{
	double a = 0;
	double b = 0;
	for (int k = 0; k < n; k++) {
		if ((*XAxisArg)[k] == x && (*YAxisArg)[k] == y && (*ZAxisArg)[k] == z)
			return FData[k];
		double wag = 1.0 / fabs(pow(x - (*XAxisArg)[k],2) + pow(y - (*YAxisArg)[k], 2) + pow(z - (*ZAxisArg)[k], 2));
		a += FData[k] * wag;  
		b += wag;
	}
	return a / b;
}
