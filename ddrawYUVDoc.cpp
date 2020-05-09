// ddrawYUVDoc.cpp : implementation of the CDdrawYUVDoc class
//

#include "stdafx.h"
#include "ddrawYUV.h"

#include "ddrawYUVDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVDoc

IMPLEMENT_DYNCREATE(CDdrawYUVDoc, CDocument)

BEGIN_MESSAGE_MAP(CDdrawYUVDoc, CDocument)
	//{{AFX_MSG_MAP(CDdrawYUVDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVDoc construction/destruction

CDdrawYUVDoc::CDdrawYUVDoc()
{
	// TODO: add one-time construction code here

}

CDdrawYUVDoc::~CDdrawYUVDoc()
{
}

BOOL CDdrawYUVDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVDoc serialization

void CDdrawYUVDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVDoc diagnostics

#ifdef _DEBUG
void CDdrawYUVDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDdrawYUVDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVDoc commands
