
// W0401BitmapView.cpp: CW0401BitmapView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "W0401Bitmap.h"
#endif

#include "W0401BitmapDoc.h"
#include "W0401BitmapView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CW0401BitmapView

IMPLEMENT_DYNCREATE(CW0401BitmapView, CView)

BEGIN_MESSAGE_MAP(CW0401BitmapView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CW0401BitmapView 생성/소멸

CW0401BitmapView::CW0401BitmapView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CW0401BitmapView::~CW0401BitmapView()
{
}

BOOL CW0401BitmapView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CW0401BitmapView 그리기

void CW0401BitmapView::OnDraw(CDC* pDC)
{
	CW0401BitmapDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CDC bmpDC;
	bmpDC.CreateCompatibleDC(pDC);

	CBitmap bmp;
	bmp.LoadBitmapW(IDB_BITMAP1);

	BITMAP info;
	bmp.GetBitmap(&info);

	CBitmap* old = bmpDC.SelectObject(&bmp);
	pDC->BitBlt(0, 0,
		info.bmWidth, info.bmHeight,
		&bmpDC,
		0, 0,
		SRCCOPY);
	bmpDC.SelectObject(old);
}


// CW0401BitmapView 인쇄

BOOL CW0401BitmapView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CW0401BitmapView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CW0401BitmapView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CW0401BitmapView 진단

#ifdef _DEBUG
void CW0401BitmapView::AssertValid() const
{
	CView::AssertValid();
}

void CW0401BitmapView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CW0401BitmapDoc* CW0401BitmapView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CW0401BitmapDoc)));
	return (CW0401BitmapDoc*)m_pDocument;
}
#endif //_DEBUG


// CW0401BitmapView 메시지 처리기
