#include "headers/quiz.h"
#include <wx/wx.h>
#include "wx/xml/xml.h"
#include "wx/xrc/xmlres.h"


Quiz::Quiz()
{
}

Quiz::Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1)
{
	this->qActive	= qActive;
	this->qIndex	= qIndex;
	this->qSetTitle	= qSetTitle;
	this->qTitle	= qTitle;
	this->qText		= qText;
	this->qAText1	= qAText1;
	this->qCBValid1 = qCBValid1;

}
Quiz::Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1, wxString qAText2, int qCBValid2)
{
	this->qActive	= qActive;
	this->qIndex	= qIndex;
	this->qSetTitle	= qSetTitle;
	this->qTitle	= qTitle;
	this->qText		= qText;
	this->qAText1	= qAText1;
	this->qCBValid1 = qCBValid1;
	this->qAText2	= qAText2;
	this->qCBValid2 = qCBValid2;

}
Quiz::Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1, wxString qAText2, int qCBValid2, wxString qAText3, int qCBValid3)
{
	this->qActive	= qActive;
	this->qIndex	= qIndex;
	this->qSetTitle	= qSetTitle;
	this->qTitle	= qTitle;
	this->qText		= qText;
	this->qAText1	= qAText1;
	this->qCBValid1 = qCBValid1;
	this->qAText2	= qAText2;
	this->qCBValid2 = qCBValid2;
	this->qAText3	= qAText3;
	this->qCBValid3 = qCBValid3;
}
Quiz::Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1, int qCBValid1, wxString qAText2, int qCBValid2, wxString qAText3, int qCBValid3, wxString qAText4, int qCBValid4)
{	
	this->qActive	= qActive;
	this->qIndex	= qIndex;
	this->qSetTitle	= qSetTitle;
	this->qTitle	= qTitle;
	this->qText		= qText;
	this->qAText1	= qAText1;
	this->qCBValid1 = qCBValid1;
	this->qAText2	= qAText2;
	this->qCBValid2 = qCBValid2;
	this->qAText3	= qAText3;
	this->qCBValid3 = qCBValid3;
	this->qAText4	= qAText4;
	this->qCBValid4 = qCBValid4;
}
Quiz::Quiz(int qActive, int qIndex, wxString qTitle, wxString qText, wxString qAText1,  int qCBValid1, wxString qAText2, int qCBValid2, wxString qAText3, int qCBValid3, wxString qAText4, int qCBValid4, wxString qAText5, int qCBValid5)
{
	this->qActive	= qActive;
	this->qIndex	= qIndex;
	this->qSetTitle	= qSetTitle;
	this->qTitle	= qTitle;
	this->qText		= qText;
	this->qAText1	= qAText1;
	this->qCBValid1 = qCBValid1;
	this->qAText2	= qAText2;
	this->qCBValid2 = qCBValid2;
	this->qAText3	= qAText3;
	this->qCBValid3 = qCBValid3;
	this->qAText4	= qAText4;
	this->qCBValid4 = qCBValid4;
	this->qAText5	= qAText5;
	this->qCBValid5 = qCBValid5;
}

void Quiz::fillQuiz()
{
	
}

void Quiz::save(int lType)
{

#if wxUSE_XML
  
    wxXmlDocument *XmlDoc = new wxXmlDocument();

		wxXmlNode *XmlQActive = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QActive")); 	
			wxXmlNode *XmlQActiveValue = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QActive_value"), wxString::Format(wxT("%d"), this->qActive));
		XmlQActive->AddChild ( XmlQActiveValue );

		wxXmlNode *XmlQIndex = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QIndex")); 	
			wxXmlNode *XmlQIndexValue = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QIndex_value"), wxString::Format(wxT("%d"), this->qIndex));
		XmlQIndex->AddChild ( XmlQIndexValue );

		wxXmlNode *XmlTitle = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QTitle")); 	
			wxXmlNode *XmlTitleValue = new wxXmlNode(wxXML_TEXT_NODE ,wxT("Title_text"),this->qTitle);
		XmlTitle->AddChild ( XmlTitleValue );
			
			
		wxXmlNode *XmlQText = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QText")); 
			wxXmlNode *XmlQTextValue = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QText_value"),this->qText ); 
		XmlQText->AddChild ( XmlQTextValue );

		wxXmlNode *XmlQAText1 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText1")); 
			wxXmlNode *XmlQAText1Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText1_value"),this->qAText1 ); 
		XmlQAText1->AddChild ( XmlQAText1Value );

		wxXmlNode *XmlcbValid1 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid1")); 
			wxXmlNode *XmlcbValid1Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid1_value"), wxString::Format(wxT("%d"), this->qCBValid1)); 
		XmlcbValid1->AddChild ( XmlcbValid1Value );
		
		wxXmlNode *XmlQAText2 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText2")); 
			wxXmlNode *XmlQAText2Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText2_value"),this->qAText2 ); 
		XmlQAText2->AddChild ( XmlQAText2Value );

		wxXmlNode *XmlcbValid2 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid2")); 
			wxXmlNode *XmlcbValid2Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid2_value"), wxString::Format(wxT("%d"), this->qCBValid2)); 
		XmlcbValid2->AddChild ( XmlcbValid2Value );

		wxXmlNode *XmlQAText3 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText3")); 
			wxXmlNode *XmlQAText3Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText3_value"),this->qAText3 ); 
		XmlQAText3->AddChild ( XmlQAText3Value );

		wxXmlNode *XmlcbValid3 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid3")); 
			wxXmlNode *XmlcbValid3Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid3_value"), wxString::Format(wxT("%d"), this->qCBValid3)); 
		XmlcbValid3->AddChild ( XmlcbValid3Value );

		wxXmlNode *XmlQAText4 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText4")); 
			wxXmlNode *XmlQAText4Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText4_value"),this->qAText4 ); 
		XmlQAText4->AddChild ( XmlQAText4Value );

		wxXmlNode *XmlcbValid4 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid4")); 
			wxXmlNode *XmlcbValid4Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid4_value"), wxString::Format(wxT("%d"), this->qCBValid4)); 
		XmlcbValid4->AddChild ( XmlcbValid4Value );

		wxXmlNode *XmlQAText5 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText5")); 
			wxXmlNode *XmlQAText5Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText5_value"),this->qAText5 ); 
		XmlQAText5->AddChild ( XmlQAText5Value );

		wxXmlNode *XmlcbValid5 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid5")); 
			wxXmlNode *XmlcbValid5Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid5_value"), wxString::Format(wxT("%d"), this->qCBValid5)); 
		XmlcbValid5->AddChild ( XmlcbValid5Value );

		wxXmlNode *XmlQ = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("Q_"+wxString::Format(wxT("%d"), lType)));
		wxXmlNode *XmlQSet= new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("q_set") );

   		
		
		XmlTitle->AddChild( XmlQIndex );
		XmlTitle->AddChild( XmlQActive );
		XmlTitle->AddChild( XmlQText  ); 
		XmlQText->AddChild( XmlQAText1 ); 
		XmlQAText1->AddChild( XmlcbValid1 );
		XmlQText->AddChild( XmlQAText2 ); 
		XmlQAText2->AddChild( XmlcbValid2 );
		XmlQText->AddChild( XmlQAText3 ); 
		XmlQAText3->AddChild( XmlcbValid3 );
		XmlQText->AddChild( XmlQAText4 ); 
		XmlQAText4->AddChild( XmlcbValid4 );
		XmlQText->AddChild( XmlQAText5 ); 
		XmlQAText5->AddChild( XmlcbValid5 );
		
		XmlQ->AddChild( XmlTitle  );
		XmlQSet->AddChild( XmlQ );

		XmlDoc->SetRoot( XmlQSet ); 

		XmlDoc->Save(wxT("LiverType_"+wxString::Format(wxT("%d"), lType)+".xml"));
		
#endif

}

void Quiz::append(int lType)
{
	wxXmlDocument *doc = new wxXmlDocument();

	doc->Load("LiverType_"+wxString::Format(wxT("%d"), lType)+".xml");

		
		wxXmlNode *XmlQActive = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QActive")); 	
			wxXmlNode *XmlQActiveValue = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QActive_value"), wxString::Format(wxT("%d"), this->qActive));
		XmlQActive->AddChild ( XmlQActiveValue );

		wxXmlNode *XmlQIndex = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QIndex")); 	
			wxXmlNode *XmlQIndexValue = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QIndex_value"), wxString::Format(wxT("%d"), this->qIndex));
		XmlQIndex->AddChild ( XmlQIndexValue );

		wxXmlNode *XmlTitle = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QTitle")); 	
			wxXmlNode *XmlTitleValue = new wxXmlNode(wxXML_TEXT_NODE ,wxT("Title_text"),this->qTitle);
		XmlTitle->AddChild ( XmlTitleValue );
			
			
		wxXmlNode *XmlQText = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QText")); 
			wxXmlNode *XmlQTextValue = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QText_value"),this->qText ); 
		XmlQText->AddChild ( XmlQTextValue );

		wxXmlNode *XmlQAText1 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText1")); 
			wxXmlNode *XmlQAText1Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText1_value"),this->qAText1 ); 
		XmlQAText1->AddChild ( XmlQAText1Value );

		wxXmlNode *XmlcbValid1 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid1")); 
			wxXmlNode *XmlcbValid1Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid1_value"), wxString::Format(wxT("%d"), this->qCBValid1)); 
		XmlcbValid1->AddChild ( XmlcbValid1Value );
		
		wxXmlNode *XmlQAText2 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText2")); 
			wxXmlNode *XmlQAText2Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText2_value"),this->qAText2 ); 
		XmlQAText2->AddChild ( XmlQAText2Value );

		wxXmlNode *XmlcbValid2 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid2")); 
			wxXmlNode *XmlcbValid2Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid2_value"), wxString::Format(wxT("%d"), this->qCBValid2)); 
		XmlcbValid2->AddChild ( XmlcbValid2Value );

		wxXmlNode *XmlQAText3 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText3")); 
			wxXmlNode *XmlQAText3Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText3_value"),this->qAText3 ); 
		XmlQAText3->AddChild ( XmlQAText3Value );

		wxXmlNode *XmlcbValid3 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid3")); 
			wxXmlNode *XmlcbValid3Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid3_value"), wxString::Format(wxT("%d"), this->qCBValid3)); 
		XmlcbValid3->AddChild ( XmlcbValid3Value );

		wxXmlNode *XmlQAText4 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText4")); 
			wxXmlNode *XmlQAText4Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText4_value"),this->qAText4 ); 
		XmlQAText4->AddChild ( XmlQAText4Value );

		wxXmlNode *XmlcbValid4 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid4")); 
			wxXmlNode *XmlcbValid4Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid4_value"), wxString::Format(wxT("%d"), this->qCBValid4)); 
		XmlcbValid4->AddChild ( XmlcbValid4Value );

		wxXmlNode *XmlQAText5 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("QAText5")); 
			wxXmlNode *XmlQAText5Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("QAText5_value"),this->qAText5 ); 
		XmlQAText5->AddChild ( XmlQAText5Value );

		wxXmlNode *XmlcbValid5 = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("cbValid5")); 
			wxXmlNode *XmlcbValid5Value = new wxXmlNode(wxXML_TEXT_NODE ,wxT("cbValid5_value"), wxString::Format(wxT("%d"), this->qCBValid5)); 
		XmlcbValid5->AddChild ( XmlcbValid5Value );

		wxXmlNode *XmlQ = new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("Q_"+wxString::Format(wxT("%d"), lType)));
		//wxXmlNode *XmlQSet= new wxXmlNode(wxXML_ELEMENT_NODE ,wxT("q_set") );

   		
		
		XmlTitle->AddChild( XmlQIndex );
		XmlTitle->AddChild( XmlQActive );
		XmlTitle->AddChild( XmlQText  ); 
		XmlQText->AddChild( XmlQAText1 ); 
		XmlQAText1->AddChild( XmlcbValid1 );
		XmlQText->AddChild( XmlQAText2 ); 
		XmlQAText2->AddChild( XmlcbValid2 );
		XmlQText->AddChild( XmlQAText3 ); 
		XmlQAText3->AddChild( XmlcbValid3 );
		XmlQText->AddChild( XmlQAText4 ); 
		XmlQAText4->AddChild( XmlcbValid4 );
		XmlQText->AddChild( XmlQAText5 ); 
		XmlQAText5->AddChild( XmlcbValid5 );
		
		XmlQ->AddChild( XmlTitle  );
//		XmlQSet->AddChild( XmlQ );

	//	XmlDoc->SetRoot( XmlQSet ); 

    
	//	XmlQSet->AddChild( XmlQActive );
	//	XmlQSet->AddChild( XmlQIndex );

	doc->GetRoot()->AddChild(XmlQ);
	//doc->GetRoot()->AddChild(XmlQIndex);

//create title node
//wxXmlNode nodeTitle = doc.CreateElement("Title");
//add value for it
//nodeTitle.InnerText = "This title is created by code";

//create Url node
//XmlNode nodeUrl = doc.CreateElement("Url");
//nodeUrl.InnerText = @"http://forums.microsoft.com/MSDN/ShowPost.aspx?PostID=659406&SiteID=1";

//add to parent node
//node.AppendChild(nodeTitle);
//node.AppendChild(nodeUrl);

//add to elements collection
//doc.DocumentElement.AppendChild(node);

//save back
	doc->Save("LiverType_"+wxString::Format(wxT("%d"), lType)+".xml");



}
