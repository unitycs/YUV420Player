// ddrawYUVView.cpp : implementation of the CDdrawYUVView class
//

#include "stdafx.h"
#include "ddrawYUV.h"

#include "ddrawYUVDoc.h"
#include "ddrawYUVView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVView

IMPLEMENT_DYNCREATE(CDdrawYUVView, CView)

BEGIN_MESSAGE_MAP(CDdrawYUVView, CView)
	//{{AFX_MSG_MAP(CDdrawYUVView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVView construction/destruction

CDdrawYUVView::CDdrawYUVView()
{
	// TODO: add construction code here

}

CDdrawYUVView::~CDdrawYUVView()
{
}

BOOL CDdrawYUVView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVView drawing

void CDdrawYUVView::OnDraw(CDC* pDC)
{
	CDdrawYUVDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVView printing

BOOL CDdrawYUVView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDdrawYUVView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDdrawYUVView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVView diagnostics

#ifdef _DEBUG
void CDdrawYUVView::AssertValid() const
{
	CView::AssertValid();
}

void CDdrawYUVView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDdrawYUVDoc* CDdrawYUVView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDdrawYUVDoc)));
	return (CDdrawYUVDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDdrawYUVView message handlers
