// ddrawYUVView.h : interface of the CDdrawYUVView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDRAWYUVVIEW_H__C91CE1FC_C04B_4797_BC57_8CEED665F50D__INCLUDED_)
#define AFX_DDRAWYUVVIEW_H__C91CE1FC_C04B_4797_BC57_8CEED665F50D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDdrawYUVView : public CView
{
protected: // create from serialization only
	CDdrawYUVView();
	DECLARE_DYNCREATE(CDdrawYUVView)

// Attributes
public:
	CDdrawYUVDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDdrawYUVView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDdrawYUVView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDdrawYUVView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ddrawYUVView.cpp
inline CDdrawYUVDoc* CDdrawYUVView::GetDocument()
   { return (CDdrawYUVDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDRAWYUVVIEW_H__C91CE1FC_C04B_4797_BC57_8CEED665F50D__INCLUDED_)
