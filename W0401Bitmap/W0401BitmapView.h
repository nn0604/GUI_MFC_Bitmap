
// W0401BitmapView.h: CW0401BitmapView 클래스의 인터페이스
//

#pragma once


class CW0401BitmapView : public CView
{
protected: // serialization에서만 만들어집니다.
	CW0401BitmapView() noexcept;
	DECLARE_DYNCREATE(CW0401BitmapView)

// 특성입니다.
public:
	CW0401BitmapDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CW0401BitmapView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // W0401BitmapView.cpp의 디버그 버전
inline CW0401BitmapDoc* CW0401BitmapView::GetDocument() const
   { return reinterpret_cast<CW0401BitmapDoc*>(m_pDocument); }
#endif

