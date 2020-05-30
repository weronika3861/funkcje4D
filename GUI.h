///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:
		wxBoxSizer* bSizer4;

	protected:
		wxButton* m_load;
		wxButton* m_save;
		wxStaticText* X_position;
		wxStaticText* Y_position;
		wxStaticText* Z_position;
		wxPanel* m_panel;
		wxButton* m_w1;
		wxButton* m_w2;
		wxButton* m_w3;
		wxButton* m_w4;
		wxButton* m_w5;
		wxButton* m_w6;

		// Virtual event handlers, overide them in your derived class
		virtual void m_loadOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_saveOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider2OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_panelOnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_w1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_w2OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_w3OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_w4OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_w5OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_w6OnButtonClick( wxCommandEvent& event ) { event.Skip(); }



	public:
		wxSlider* m_slider2;

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Funkcje 4D"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 740, 550 ), long style = wxDEFAULT_FRAME_STYLE |wxTAB_TRAVERSAL);

		virtual ~MyFrame1();

};

