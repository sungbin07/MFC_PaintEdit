// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를 
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된 
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해 
// 추가적으로 제공되는 내용입니다.  
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.  
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// YPaintEditView.cpp : CYPaintEditView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "YPaintEdit.h"
#endif

#include "YPaintEditDoc.h"
#include "YPaintEditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYPaintEditView

IMPLEMENT_DYNCREATE(CYPaintEditView, CView)

BEGIN_MESSAGE_MAP(CYPaintEditView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_COMMAND(ID_BUTTON3, &CYPaintEditView::MenuLineButton)
	ON_COMMAND(ID_BUTTON2, &CYPaintEditView::MenuDefaultButton)
	ON_COMMAND(ID_BUTTON7, &CYPaintEditView::MenuTextButton)
	ON_COMMAND(ID_BUTTON6, &CYPaintEditView::MenuEllipseButton)
	ON_COMMAND(ID_32793, &CYPaintEditView::RMenuColorButton)
	ON_COMMAND(ID_32794, &CYPaintEditView::FigureSettingButton)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_BUTTON5, &CYPaintEditView::MenuPolyLineButton)
	ON_COMMAND(ID_32797, &CYPaintEditView::OnDeleteClick)
	ON_COMMAND(ID_BUTTON4, &CYPaintEditView::OnRectangleButton)
	ON_UPDATE_COMMAND_UI(ID_BUTTON2, &CYPaintEditView::UpdateMenuDefaultButton)
	ON_UPDATE_COMMAND_UI(ID_BUTTON3, &CYPaintEditView::UpdateMenuLineButton)
	ON_UPDATE_COMMAND_UI(ID_BUTTON5, &CYPaintEditView::UpdateMenuPolyLineButton)
	ON_UPDATE_COMMAND_UI(ID_BUTTON4, &CYPaintEditView::UpdateOnRectangleButton)
	ON_UPDATE_COMMAND_UI(ID_BUTTON6, &CYPaintEditView::UpdateMenuEllipseButton)
	ON_UPDATE_COMMAND_UI(ID_BUTTON7, &CYPaintEditView::UpdateMenuTextButton)
	ON_UPDATE_COMMAND_UI(ID_32797, &CYPaintEditView::UpdateOnDeleteClick)
	ON_UPDATE_COMMAND_UI(ID_32794, &CYPaintEditView::UpdateFigureSettingButton)
	ON_UPDATE_COMMAND_UI(ID_32793, &CYPaintEditView::UpdateRMenuColorButton)
	ON_COMMAND(ID_32798, &CYPaintEditView::DeletePointButton)
	ON_UPDATE_COMMAND_UI(ID_32798, &CYPaintEditView::UpdateDeletePointButton)
	ON_COMMAND(ID_32799, &CYPaintEditView::RMenuInColorButton)
END_MESSAGE_MAP()

// CYPaintEditView 생성/소멸

CYPaintEditView::CYPaintEditView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	//메뉴 비활성화
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
}

CYPaintEditView::~CYPaintEditView()
{
}

BOOL CYPaintEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CYPaintEditView 그리기

void CYPaintEditView::OnDraw(CDC* /*pDC*/)
{
	CYPaintEditDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CYPaintEditView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	CYPaintEditDoc* pDoc = GetDocument();


	// 클릭한 지점에 객체가 없다면 팝업메뉴를 안띄움
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->checkRgn(point) == TRUE && pDoc->currentObj->getSelect() == TRUE){			//클릭한 점이 영역안에 있고 객체가 선택되어져 있는상황에서만 메뉴를 띄운다.
			pDoc->currentObj->setSelect(TRUE);

			if (pDoc->currentObj->getType() == polyline){																//polyline 일 때만 한점지우기가 있으므로
				for (int i = 0; i < pDoc->pPolyLine->getPolyList()->GetSize(); i++){
					if (pDoc->pPolyLine->getMRect()[i].PtInRect(point)){
						pDoc->deletePosition = i;							//삭제할 위치 저장
						break;
					}
				}
			}
			ClientToScreen(&point);
			OnContextMenu(this, point);
			break;
		}
	}

}

void CYPaintEditView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CYPaintEditView 진단

#ifdef _DEBUG
void CYPaintEditView::AssertValid() const
{
	CView::AssertValid();
}

void CYPaintEditView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CYPaintEditDoc* CYPaintEditView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CYPaintEditDoc)));
	return (CYPaintEditDoc*)m_pDocument;
}
#endif //_DEBUG



////////////////////////////// CYPaintEditView 메시지 처리기 //////////////////////////////



// 기능 : cdc객체 생성해서 메모리dc에 저장해서 출력하는 함수
void CYPaintEditView::OnPaint()
{
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);
	CBitmap bitmap;

	bitmap.CreateBitmap(rect.Width(), rect.Height(), 1, 1, NULL);			//전체화면을 대상으로 bitmap 생성

	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);											//메모리 dc 생성
	dcmem.SelectObject(&bitmap);											//비트맵 선택
	
	dcmem.SelectStockObject(NULL_PEN);
	dcmem.Rectangle(&rect);

	Paint(&dcmem);

	dc.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &dcmem,0,0, SRCCOPY);		//메모리에 있던 비트맵을 그린다.

	bitmap.DeleteObject();
	dcmem.DeleteDC();


}

// 기능 : 어떤 도형을 그릴지 판단
void CYPaintEditView::Paint(CDC* dc)
{

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	CYPaintEditDoc* pDoc = GetDocument();
	POSITION pos = pDoc->obj_List.GetHeadPosition();

	while (pos) {
		YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		tmp->draw(dc);
	}

	if (pDoc->drawing){			// 마우스 움직이는 도중 계속 실행되는 함수
		switch (pDoc->yType){
		case line:
		{
			pDoc->pLine->setSPoint(pDoc->pLine->getSPoint());
			pDoc->pLine->setEPoint(pDoc->pLine->getEPoint());
			pDoc->pLine->draw(dc);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine->setEPoint(pDoc->pPolyLine->getEPoint());
			pDoc->pPolyLine->draw(dc);
			break;
		}
		case ellipse:
		{
			pDoc->pEllipse->setSPoint(pDoc->pEllipse->getSPoint());
			pDoc->pEllipse->setEPoint(pDoc->pEllipse->getEPoint());
			pDoc->pEllipse->draw(dc);
			break;
		}

		case rectangle:
		{
			pDoc->pRectangle->setSPoint(pDoc->pRectangle->getSPoint());
			pDoc->pRectangle->setEPoint(pDoc->pRectangle->getEPoint());
			pDoc->pRectangle->draw(dc);
			break;


		}
		case choice:
		{

			if (pDoc->currentObj == NULL) break;

			switch (pDoc->currentObj->getType()){
			case line:
			{
				pDoc->pLine = (YLine*)pDoc->currentObj;
				pDoc->pLine->draw(dc);
				break;
			}
			case polyline:
			{
				pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
				pDoc->pPolyLine->draw(dc);
				break;
			}
			case ellipse:
			{
				pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
				pDoc->pEllipse->draw(dc);
				break;
			}
			case rectangle:
			{
				pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
				pDoc->pRectangle->draw(dc);
				break;
			}


			default:
				break;
			}
			break;
		}
		default:
			break;
		}

	}

	//////////////////////////////////////// Text //////////////////////////////////////////
	if (pDoc->textEditing){
		// 폰트 생성 및 적용
		CFont f;
		f.CreatePointFont(pDoc->pText->getFontSize(), pDoc->pText->getFont());
		dc->SelectObject(f);
		dc->SetBkColor(pDoc->pText->getBkColor());
		dc->SetTextColor(pDoc->pText->getFontColor());

		// 폰트를 반영한 문자열(텍스트)의 길이 생성 및 저장
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

		// 초기 텍스트 박스 모형을 위한 코드
		CString cInitial = _T("t");
		CSize sInitial = dc->GetTextExtent(cInitial, cInitial.GetLength());

		// ePoint 및 rect 설정
		if (pDoc->pText->getText().GetLength() == 0)
			pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + sInitial.cx, pDoc->pText->getSPoint().y + sInitial.cy));
		else
			pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
		pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());

		// 출력용 리젼 생성
		CRect r(pDoc->pText->getSPoint().x - 1, pDoc->pText->getSPoint().y - 1, pDoc->pText->getEPoint().x + 1, pDoc->pText->getEPoint().y + 1);
		// 출력용 리젼을 위한 펜 및 브러시 생성 및 적용
		CPen pen(PS_DOT, 1, RGB(0, 0, 0));
		dc->SelectObject(pen);
		CBrush brush(pDoc->pText->getBkColor());
		dc->SelectObject(brush);

		// 리젼 및 텍스트 출력
		dc->Rectangle(r);
		dc->DrawText(pDoc->pText->getText(), pDoc->pText->getRect(), NULL);

		// 캐럿 생성 및 출력
		if (pDoc->pText->getText().GetLength() == 0)
			CreateSolidCaret(5, sInitial.cy);
		else
			CreateSolidCaret(5, s.cy);
		SetCaretPos(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y));
		ShowCaret();
	}
}

// 키보드 입력을 받는 함수 // 
void CYPaintEditView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) // Text
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->textEditing == TRUE){
		if (nChar == _T('\b')){ // 지우기 (delete 키)
			if (pDoc->pText->getText().GetLength() > 0){
				pDoc->tmp.GetBufferSetLength(pDoc->tmp.GetLength() - 1);
				pDoc->pText->setText(pDoc->tmp);
			}
		}
		else if (nChar == VK_RETURN){ // 입력 종료 (enter 키)
			pDoc->textEditing = FALSE;
			pDoc->obj_List.AddTail(pDoc->pText);
			pDoc->tmp.Empty();
			HideCaret();
		}
		else{ // 입력
			pDoc->tmp.AppendChar(nChar);
			pDoc->pText->setText(pDoc->tmp);
		}
		Invalidate(FALSE);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}

// 마우스 클릭, 이벤트 처리 함수들 //
void CYPaintEditView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	//pDoc->drawing = FALSE;

	switch (pDoc->yType){
		// 각각의 케이스문  생성자 초기화 , doc의 각 객체포인터로 연결 ,타입 ,선택값(TRUE),drawing ,i
	case line:
	{
		//초기화
		pDoc->pLine = new YLine(point, point, 1, 1, PS_SOLID);
		pDoc->pLine->setType(line);
		pDoc->pLine->setSelect(TRUE);
		pDoc->drawing = TRUE;
		break;
	}
	case polyline:
	{
		if (pDoc->clickPolyLine == FALSE){   //시작 생성
			pDoc->pPolyLine = new YPolyLine(1, 1, PS_SOLID);
			pDoc->pPolyLine->setSelect(TRUE);
			pDoc->pPolyLine->addPoint(point);
			pDoc->pPolyLine->setType(polyline);
			pDoc->pPolyLine->setEPoint(point);
			pDoc->pPolyLine->setDrawPolyLine(TRUE);
			pDoc->drawing = TRUE;
			pDoc->clickPolyLine = TRUE;

		}
		else{   //시작점생성후 클릭할때 마다
			pDoc->drawing = TRUE;
			pDoc->pPolyLine->addPoint(point);
		}
		break;
	}
	case text:
	{
		if (pDoc->textEditing == FALSE){
			pDoc->pText = new YText(point);
			pDoc->pText->setType(text);
			pDoc->textEditing = TRUE;
		}
		else {
			pDoc->obj_List.AddTail(pDoc->pText);
			pDoc->tmp.Empty();
			pDoc->textEditing = FALSE;
			HideCaret();
		}
		break;
	}
	case ellipse:
	{
		pDoc->pEllipse = new YEllipse(point, point, 1, 1, PS_SOLID,RGB(255,255,255));
		pDoc->pEllipse->setSelect(TRUE);
		pDoc->pEllipse->setType(ellipse);
		pDoc->drawing = TRUE;
		break;
	}

	case rectangle:
	{
		pDoc->pRectangle = new YRectangle(point, point, 1, 1, PS_SOLID);
		pDoc->pRectangle->setSelect(TRUE);
		pDoc->pRectangle->setType(rectangle);
		pDoc->drawing = TRUE;
		break;

	}
	case choice:
	{

		//List에서 선택된 객체 하나가 나오면 TRUE로바꾸고 끝냄 (그룹화하게되면 배열또는 리스트 로설정해야할꺼같음)
		//리젼없애는 단계
		if (pDoc->currentObj != NULL)	{
			pDoc->currentObj->setSelect(FALSE);
			pDoc->currentObj = NULL;
		}


	
		//현재 선택한 객체 찾기
		POSITION pos = pDoc->obj_List.GetTailPosition();
		while (pos) {
			pDoc->currentObj = (YObject*)pDoc->obj_List.GetPrev(pos);
			if (pDoc->currentObj->checkRgn(point) == TRUE){
				pDoc->currentObj->setSelect(TRUE);
				break;
			}
			
			//라인의 끝점은 라인 영역 밖에 있으므로 한번더 검색해줘야한다.
			if (pDoc->currentObj != NULL){
				if (pDoc->currentObj == pDoc->pLine){
					if (pDoc->pLine->getMRect()[0].PtInRect(point) || pDoc->pLine->getMRect()[1].PtInRect(point)) {
						pDoc->currentObj->setSelect(TRUE);
						break;
					}
				}

				else if (pDoc->currentObj == pDoc->pEllipse){
					if (pDoc->pEllipse->getMRect()[0].PtInRect(point) || pDoc->pEllipse->getMRect()[1].PtInRect(point)) {
						pDoc->currentObj->setSelect(TRUE);
						break;
					}
				}

				else if (pDoc->currentObj == pDoc->pRectangle){
					if (pDoc->pRectangle->getMRect()[0].PtInRect(point) || pDoc->pRectangle->getMRect()[1].PtInRect(point)) {
						pDoc->currentObj->setSelect(TRUE);
						break;
					}
				}
			}
			

		}

		if (pDoc->currentObj == NULL) break;   //현재 선택된 객체를 찾았는데도 객체가 없으면 아무것도 실행안되고 끝나야함 (예외처리)

		//선택된 객체에대해서 행할 행동의 정의
		if (pDoc->currentObj->getSelect() == TRUE){
			pDoc->drawing = TRUE;
			pDoc->Original_Point = point;  //선 이동시 기준점이 되는 좌표
			switch (pDoc->currentObj->getType()){
			case line:
			{
				pDoc->pLine = (YLine*)pDoc->currentObj;
				if (pDoc->pLine->getMRect()[0].PtInRect(point)){  // 시작점 클릭
					pDoc->pLine->setSPoint(point);
					pDoc->pLine->setMoveMode(-1);  //시작점이동
				}
				else if (pDoc->pLine->getMRect()[1].PtInRect(point)){	// 끝점 클릭
					pDoc->pLine->setEPoint(point);
					pDoc->pLine->setMoveMode(1);  //끝점이동
					break;
				}
				else if (pDoc->pLine->checkRgn(point)) {		//그 외 영역 클릭
					pDoc->pLine->setMoveMode(0); //전체이동
				}
				break;
			}
			case polyline:
			{
				pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;

				for (int i = 0; i < pDoc->pPolyLine->getPolyList()->GetSize(); i++){
					if (pDoc->pPolyLine->getMRect()[i].PtInRect(point)){
						pDoc->pPolyLine->setIndex(i);
						pDoc->pPolyLine->setMoveMode(1);  //한점이동
						break;
					}
					else pDoc->pPolyLine->setMoveMode(0);  //전체이동
				}
				break;
			}
			case ellipse:
			{
				//타원 연장 하기
				pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
				if (pDoc->pEllipse->getMRect()[0].PtInRect(point)){  // 시작점 클릭
					pDoc->pEllipse->setSPoint(point);
					pDoc->pEllipse->setMoveMode(-1);  //시작점이동
				}
				else if (pDoc->pEllipse->getMRect()[1].PtInRect(point)){	// 끝점 클릭
					pDoc->pEllipse->setEPoint(point);
					pDoc->pEllipse->setMoveMode(1);  //끝점이동
					break;
				}
				else if (pDoc->pEllipse->checkRgn(point)) {		//그 외 영역 클릭
					pDoc->pEllipse->setMoveMode(0); //전체이동
				}
				break;

			}


			case rectangle:
			{

				pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
				if (pDoc->pRectangle->getMRect()[0].PtInRect(point)){  // 시작점 클릭
					pDoc->pRectangle->setSPoint(point);
					pDoc->pRectangle->setMoveMode(-1);  //시작점이동
				}
				else if (pDoc->pRectangle->getMRect()[1].PtInRect(point)){	// 끝점 클릭
					pDoc->pRectangle->setEPoint(point);
					pDoc->pRectangle->setMoveMode(1);  //끝점이동
					break;
				}
				else if (pDoc->pRectangle->checkRgn(point)) {		//그 외 영역 클릭
					pDoc->pRectangle->setMoveMode(0); //전체이동
				}
				break;
			}
			case text:
			{
				break;
			}
			case choice:
			{
				break;
			}
			default:
				break;
			}
			Invalidate(FALSE);
		}
	}
	default:
		break;
	}

	CView::OnLButtonDown(nFlags, point);
}

void CYPaintEditView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	if (nFlags & MK_LBUTTON || pDoc->clickPolyLine){

		switch (pDoc->yType){
		case line:
		{
			pDoc->pLine->setEPoint(point);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine->setEPoint(point);
			break;
		}
		case ellipse:
		{
			pDoc->pEllipse->setEPoint(point);
			break;
		}

		case rectangle:
		{

			pDoc->pRectangle->setEPoint(point);
			break;

		}
		case text:
		{
			break;
		}

		//선택 일떄 이동 시키려구
		case choice:
		{
			if (pDoc->currentObj == NULL) break;  //빈곳을 클릭했을때 (예외상황)


			CPoint t_point = point - pDoc->Original_Point; //좌표 움직임
			pDoc->Original_Point = point;
			switch (pDoc->currentObj->getType()){
			case line:
			{
				pDoc->pLine = (YLine*)pDoc->currentObj;
				//선택되었을때 이동 변수에따라 다른 move실행
				if (pDoc->pLine->getSelect()){
					if (pDoc->pLine->getMoveMode() == 0){  //전체이동
						pDoc->pLine->moveAll(t_point.x, t_point.y);
						pDoc->pLine->setRgn();
					}
					else {
						pDoc->pLine->move(t_point.x, t_point.y);
						pDoc->pLine->setRgn();
					}
				}
				break;
			}
			case polyline:
			{
				pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
				if (pDoc->pPolyLine->getMoveMode() == 0){
					if (pDoc->pPolyLine->getSelect()){
						pDoc->pPolyLine->moveAll(t_point.x, t_point.y);
						pDoc->pPolyLine->setRgn();
					}
				}
				else {
					pDoc->pPolyLine->move(t_point.x, t_point.y);
					pDoc->pPolyLine->setRgn();
				}
				break;
			}
			case ellipse:
			{
				pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
				//선택되었을때 이동 변수에따라 다른 move실행
				if (pDoc->pEllipse->getSelect()){
					if (pDoc->pEllipse->getMoveMode() == 0){  //전체이동
						pDoc->pEllipse->moveAll(t_point.x, t_point.y);
						pDoc->pEllipse->setRgn();
					}
					else {
						pDoc->pEllipse->move(t_point.x, t_point.y);
						pDoc->pEllipse->setRgn();
					}
				}
				break;
			}

			case rectangle:
			{
				pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
				//선택되었을때 이동 변수에따라 다른 move실행
				if (pDoc->pRectangle->getSelect()){
					if (pDoc->pRectangle->getMoveMode() == 0){  //전체이동
						pDoc->pRectangle->moveAll(t_point.x, t_point.y);
						pDoc->pRectangle->setRgn();
					}
					else {
						pDoc->pRectangle->move(t_point.x, t_point.y);
						pDoc->pRectangle->setRgn();
					}
				}
				break;

			}
			default:
				break;
			}
		}
		default:
			break;
		}
		Invalidate(FALSE);
	}
	CView::OnMouseMove(nFlags, point);
}

void CYPaintEditView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);

	switch (pDoc->yType){
	case line:
	{
		pDoc->pLine->setRgn();
		pDoc->pLine->setSelect(FALSE);
		pDoc->obj_List.AddTail(pDoc->pLine);
		pDoc->pLine = NULL;
		pDoc->drawing = FALSE;
		break;

	}
	case polyline:
	{
		break;
	}
	case text:
	{
		break;
	}

	case ellipse:
	{
		pDoc->pEllipse->setRgn();
		pDoc->pEllipse->setSelect(FALSE);
		pDoc->obj_List.AddTail(pDoc->pEllipse);
		pDoc->drawing = FALSE;
		ReleaseCapture();
		break;
	}
	case rectangle:
	{
		pDoc->pRectangle->setRgn();
		pDoc->pRectangle->setSelect(FALSE);
		pDoc->obj_List.AddTail(pDoc->pRectangle);
		pDoc->drawing = FALSE;
		ReleaseCapture();
		break;


	}

	case choice:
	{
		break;
	}
	default:
		break;
	}
	Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}

void CYPaintEditView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->yType == polyline){
		pDoc->clickPolyLine = FALSE;
		pDoc->drawing = FALSE;
		pDoc->pPolyLine->setDrawPolyLine(FALSE);
		pDoc->pPolyLine->setRgn(); // 리젼설정
		pDoc->pPolyLine->setSelect(FALSE);
		pDoc->pPolyLine->setType(polyline);
		pDoc->obj_List.AddTail(pDoc->pPolyLine);
		pDoc->pPolyLine = NULL;
		Invalidate(FALSE);
	}
	CView::OnLButtonDblClk(nFlags, point);
}

// 리본 메뉴, 에벤트 처리 함수들 //
void CYPaintEditView::MenuLineButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Select = FALSE;
	menu_Line = TRUE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = line;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);

	}
}

void CYPaintEditView::MenuPolyLineButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = TRUE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
	
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = polyline;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);

	}
}

void CYPaintEditView::MenuEllipseButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = TRUE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = ellipse;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);

	}
}

void CYPaintEditView::OnRectangleButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = TRUE;
	menu_Text = FALSE;
	
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = rectangle;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);

	}
}

void CYPaintEditView::MenuTextButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = TRUE;
	
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = text;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);

	}
}

void CYPaintEditView::MenuDefaultButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	menu_Select = TRUE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = choice;

	//선택을 누름으로써 모든 객체 선택여부를 FALSE로
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos){
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}

void CYPaintEditView::UpdateMenuLineButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Line);
}

void CYPaintEditView::UpdateMenuPolyLineButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_PolyLine);
}

void CYPaintEditView::UpdateOnRectangleButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Rectangle);
}

void CYPaintEditView::UpdateMenuEllipseButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Ellipse);
}

void CYPaintEditView::UpdateMenuTextButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Text);
}

void CYPaintEditView::UpdateMenuDefaultButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Select);
}



// 마우스 우클릭 메뉴, 이벤트 처리 함수들 //
//기능 : 팝업메뉴 -> 색변경
void CYPaintEditView::RMenuColorButton() //마우스 오른쪽버튼 클릭후 -> 색 클릭시
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN);
	int color; // 다이얼로그에서 가져온 색깔을 저장할 변수
	int result = dlg.DoModal();
	if (result == IDOK){
		color = dlg.GetColor();

		switch (pDoc->currentObj->getType()){
		case line:
		{
			pDoc->pLine = (YLine*)pDoc->currentObj;
			pDoc->pLine->setLineColor(color);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
			pDoc->pPolyLine->setLineColor(color);
			break;
		}

		case ellipse:
		{
			pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
			pDoc->pEllipse->setLineColor(color);
			break;
		}
		case rectangle:
		{
			pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
			pDoc->pRectangle->setLineColor(color);
			break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}

//기능 : 팝업메뉴 -> 면색변경
void CYPaintEditView::RMenuInColorButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN);
	int color; // 다이얼로그에서 가져온 색깔을 저장할 변수
	int result = dlg.DoModal();
	if (result == IDOK){
		color = dlg.GetColor();

		switch (pDoc->currentObj->getType()){
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->ChangeinColor(color);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->ChangeinColor(color);
						  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}

//기능 : 팝업메뉴 -> 도형서식
void CYPaintEditView::FigureSettingButton() //마우스 오른쪽 버튼 클릭후 -> 도형 서식 바꾸기
{
	menu_Figiure = FALSE;

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	YFigureDialog dlg;
	//객체의 선두꼐 패턴정보를 가져오는 단계 (다이얼로그를 띄우기전에)
	switch (pDoc->currentObj->getType()){
	case line:
	{
		pDoc->pLine = (YLine*)pDoc->currentObj;
		dlg.lineThick = pDoc->pLine->getLineThick();
		dlg.linePattern = pDoc->pLine->getLinePattern();
		break;
	}
	case polyline:
	{
		pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
		dlg.lineThick = pDoc->pPolyLine->getLineThick();
		dlg.linePattern = pDoc->pPolyLine->getLinePattern();
		break;
	}
	case ellipse:
	{
		pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
		dlg.lineThick = pDoc->pEllipse->getLineThick();
		dlg.linePattern = pDoc->pEllipse->getLinePattern();
		break;
	}
	case rectangle:
	{
		pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
		dlg.lineThick = pDoc->pRectangle->getLineThick();
		dlg.linePattern = pDoc->pRectangle->getLinePattern();
		break;
	}


	default:
		break;
	}

	int result = dlg.DoModal();  //모달띄우기
	if (result == IDOK){

		switch (pDoc->currentObj->getType()){
		case line:
		{
			pDoc->pLine = (YLine*)pDoc->currentObj;
			pDoc->pLine->setLineThick(dlg.lineThick);
			pDoc->pLine->setLinePattern(dlg.linePattern);
			break;
		}
		case polyline:
		{
			pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
			pDoc->pPolyLine->setLineThick(dlg.lineThick);
			pDoc->pPolyLine->setLinePattern(dlg.linePattern);
			break;
		}
		case ellipse:
		{
			pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
			pDoc->pEllipse->setLineThick(dlg.lineThick);
			pDoc->pEllipse->setLinePattern(dlg.linePattern);
			break;
		}
		case rectangle:
		{
			pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
			pDoc->pRectangle->setLineThick(dlg.lineThick);
			pDoc->pRectangle->setLinePattern(dlg.linePattern);
			break;
		}


		default:
			break;
		}

		Invalidate(FALSE);
	}

}

//기능 : 팝업메뉴 -> 삭제
void CYPaintEditView::OnDeleteClick()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CPtrList tempList;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	POSITION tpos;
	if (pDoc->obj_List.GetSize() == 1){									//객체가 하나만 남아있을때
 		pDoc->obj_List.RemoveAll();
		
	}
	else {
		while (pos) {
			tpos = pos;													//위치를 저장한 후 에 다음 노드로 넘어간다.
			YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
			if (tmp->getSelect() == TRUE) break;						//선택된 객체가 있으면 반복을 종료하고 빠져나옴
		}
		pDoc->obj_List.RemoveAt(tpos);
	}
	pDoc->currentObj = NULL;
	Invalidate(FALSE);

}

//기능 : 팝업메뉴 -> 점삭제
void CYPaintEditView::DeletePointButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);
	if (pDoc->deletePosition != -1) {

		if (pDoc->pPolyLine->getPolyList()->GetSize() == 2){				// 점이 2개있는데 지울려고 점을 지울려고 할때 객체를 지우고 리스트에서도 제외 시킨다.
			pDoc->pPolyLine->getPolyList()->RemoveAll();

			POSITION pos = pDoc->obj_List.GetHeadPosition();
			POSITION tpos;

			while (pos) {
				tpos = pos;													//위치를 저장한 후 에 다음 노드로 넘어간다.
				YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
				if (tmp->getSelect() == TRUE) break;						//선택된 객체가 있으면 반복을 종료하고 빠져나옴
			}
			pDoc->obj_List.RemoveAt(tpos);
			pDoc->currentObj = NULL;
		}
		else {
			pDoc->pPolyLine->getPolyList()->RemoveAt(pDoc->pPolyLine->getPolyList()->FindIndex(pDoc->deletePosition));
			pDoc->deletePosition = -1;
			pDoc->pPolyLine->setRgn();
		}
		Invalidate(FALSE);
	}

}

void CYPaintEditView::UpdateRMenuColorButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}

void CYPaintEditView::UpdateFigureSettingButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(FALSE);  //팝업 비활성 하는 방법
}

void CYPaintEditView::UpdateOnDeleteClick(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	
}

void CYPaintEditView::UpdateDeletePointButton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
}



