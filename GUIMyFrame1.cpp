#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}

void GUIMyFrame1::m_loadOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_loadOnButtonClick
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