// ddrawYUVDoc.h : interface of the CDdrawYUVDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDRAWYUVDOC_H__78218B62_8264_47D1_B78B_DE9F31799D20__INCLUDED_)
#define AFX_DDRAWYUVDOC_H__78218B62_8264_47D1_B78B_DE9F31799D20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDdrawYUVDoc : public CDocument
{
protected: // create from serialization only
	CDdrawYUVDoc();
	DECLARE_DYNCREATE(CDdrawYUVDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDdrawYUVDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDdrawYUVDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDdrawYUVDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDRAWYUVDOC_H__78218B62_8264_47D1_B78B_DE9F31799D20__INCLUDED_)
