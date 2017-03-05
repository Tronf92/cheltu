
// cheltuView.cpp : implementation of the CcheltuView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "cheltu.h"
#endif

#include "cheltuDoc.h"
#include "cheltuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcheltuView

IMPLEMENT_DYNCREATE(CcheltuView, CView)

BEGIN_MESSAGE_MAP(CcheltuView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CcheltuView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CcheltuView construction/destruction

CcheltuView::CcheltuView()
{
	// TODO: add construction code here

}

CcheltuView::~CcheltuView()
{
}

BOOL CcheltuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CcheltuView drawing

void CcheltuView::OnDraw(CDC* /*pDC*/)
{
	CcheltuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CcheltuView printing


void CcheltuView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CcheltuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CcheltuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CcheltuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CcheltuView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcheltuView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcheltuView diagnostics

#ifdef _DEBUG
void CcheltuView::AssertValid() const
{
	CView::AssertValid();
}

void CcheltuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcheltuDoc* CcheltuView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcheltuDoc)));
	return (CcheltuDoc*)m_pDocument;
}
#endif //_DEBUG


// CcheltuView message handlers
