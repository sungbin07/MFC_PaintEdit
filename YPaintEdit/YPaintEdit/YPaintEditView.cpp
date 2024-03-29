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
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYPaintEditView

IMPLEMENT_DYNCREATE(CYPaintEditView, CView)

BEGIN_MESSAGE_MAP(CYPaintEditView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_MENUDEFAULTTBUTTON, &CYPaintEditView::OnMenudefaulttbutton)
	ON_UPDATE_COMMAND_UI(ID_MENUDEFAULTTBUTTON, &CYPaintEditView::OnUpdateMenudefaulttbutton)
	ON_COMMAND(ID_MENULINEBUTTON, &CYPaintEditView::OnMenulinebutton)
	ON_UPDATE_COMMAND_UI(ID_MENULINEBUTTON, &CYPaintEditView::OnUpdateMenulinebutton)
	ON_COMMAND(ID_MENUPOLYLINEBUTTON, &CYPaintEditView::OnMenupolylinebutton)
	ON_UPDATE_COMMAND_UI(ID_MENUPOLYLINEBUTTON, &CYPaintEditView::OnUpdateMenupolylinebutton)
	ON_COMMAND(ID_MENURECTANGLEBUTTON, &CYPaintEditView::OnMenurectanglebutton)
	ON_UPDATE_COMMAND_UI(ID_MENURECTANGLEBUTTON, &CYPaintEditView::OnUpdateMenurectanglebutton)
	ON_COMMAND(ID_MENUELLIPSEBUTTON, &CYPaintEditView::OnMenuellipsebutton)
	ON_UPDATE_COMMAND_UI(ID_MENUELLIPSEBUTTON, &CYPaintEditView::OnUpdateMenuellipsebutton)
	ON_COMMAND(ID_MENUTEXTBUTTON, &CYPaintEditView::OnMenutextbutton)
	ON_UPDATE_COMMAND_UI(ID_MENUTEXTBUTTON, &CYPaintEditView::OnUpdateMenutextbutton)
	ON_COMMAND(ID_MENUFONTSIZE, &CYPaintEditView::OnMenufontsize)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTSIZE, &CYPaintEditView::OnUpdateMenufontsize)
	ON_COMMAND(ID_MENUFONT, &CYPaintEditView::OnMenufont)
	ON_UPDATE_COMMAND_UI(ID_MENUFONT, &CYPaintEditView::OnUpdateMenufont)
	ON_COMMAND(ID_TEXTEDITBUTTON, &CYPaintEditView::OnTexteditbutton)
	ON_UPDATE_COMMAND_UI(ID_TEXTEDITBUTTON, &CYPaintEditView::OnUpdateTexteditbutton)
	ON_COMMAND(ID_MENUFONTCOLOR, &CYPaintEditView::OnMenufontcolor)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTCOLOR, &CYPaintEditView::OnUpdateMenufontcolor)
	ON_COMMAND(ID_MENUFONTBKCOLOR, &CYPaintEditView::OnMenufontbkcolor)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTBKCOLOR, &CYPaintEditView::OnUpdateMenufontbkcolor)
	ON_COMMAND(ID_MENULINETHICK, &CYPaintEditView::OnMenulinethick)
	ON_UPDATE_COMMAND_UI(ID_MENULINETHICK, &CYPaintEditView::OnUpdateMenulinethick)
	ON_COMMAND(ID_MENULINEPATTERN, &CYPaintEditView::OnMenulinepattern)
	ON_UPDATE_COMMAND_UI(ID_MENULINEPATTERN, &CYPaintEditView::OnUpdateMenulinepattern)
	ON_COMMAND(ID_MENUSIDEPATTERN, &CYPaintEditView::OnMenusidepattern)
	ON_UPDATE_COMMAND_UI(ID_MENUSIDEPATTERN, &CYPaintEditView::OnUpdateMenusidepattern)
	ON_COMMAND(ID_MENULINECOLOR, &CYPaintEditView::OnMenulinecolor)
	ON_COMMAND(ID_MENUSIDECOLOR, &CYPaintEditView::OnMenusidecolor)
	ON_COMMAND(ID_GROUPSBUTTON, &CYPaintEditView::OnGroupsbutton)
	ON_UPDATE_COMMAND_UI(ID_GROUPSBUTTON, &CYPaintEditView::OnUpdateGroupsbutton)
	ON_COMMAND(ID_DELETEGROUPBUTTON, &CYPaintEditView::OnDeletegroupbutton)
	ON_UPDATE_COMMAND_UI(ID_DELETEGROUPBUTTON, &CYPaintEditView::OnUpdateDeletegroupbutton)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDIT_CUT, &CYPaintEditView::OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, &CYPaintEditView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CYPaintEditView::OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CYPaintEditView::OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &CYPaintEditView::OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &CYPaintEditView::OnUpdateEditPaste)
	ON_COMMAND(ID_EDIT_LINECOLOR, &CYPaintEditView::OnEditLinecolor)
	ON_UPDATE_COMMAND_UI(ID_EDIT_LINECOLOR, &CYPaintEditView::OnUpdateEditLinecolor)
	ON_COMMAND(ID_EDIT_SIDECOLOR, &CYPaintEditView::OnEditSidecolor)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SIDECOLOR, &CYPaintEditView::OnUpdateEditSidecolor)
	ON_COMMAND(ID_EDIT_FIGURESETTING, &CYPaintEditView::OnEditFiguresetting)
	ON_UPDATE_COMMAND_UI(ID_EDIT_FIGURESETTING, &CYPaintEditView::OnUpdateEditFiguresetting)
	ON_COMMAND(ID_EDIT_DELETE, &CYPaintEditView::OnEditDelete)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETE, &CYPaintEditView::OnUpdateEditDelete)
	ON_COMMAND(ID_EDIT_DELETEPOINT, &CYPaintEditView::OnEditDeletepoint)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETEPOINT, &CYPaintEditView::OnUpdateEditDeletepoint)
	ON_COMMAND(ID_EDITGROUP, &CYPaintEditView::OnEditgroup)
	ON_UPDATE_COMMAND_UI(ID_EDITGROUP, &CYPaintEditView::OnUpdateEditgroup)
	ON_COMMAND(ID_EDITDELETEGROUP, &CYPaintEditView::OnEditdeletegroup)
	ON_UPDATE_COMMAND_UI(ID_EDITDELETEGROUP, &CYPaintEditView::OnUpdateEditdeletegroup)
	ON_COMMAND(ID_BACK, &CYPaintEditView::OnBack)
	ON_COMMAND(ID_FRONTBACK, &CYPaintEditView::OnFrontback)
	ON_UPDATE_COMMAND_UI(ID_BACK, &CYPaintEditView::OnUpdateBack)
	ON_UPDATE_COMMAND_UI(ID_FRONTBACK, &CYPaintEditView::OnUpdateFrontback)
	ON_COMMAND(ID_MENUFONTDIA, &CYPaintEditView::OnMenufontdia)
	ON_UPDATE_COMMAND_UI(ID_MENUFONTDIA, &CYPaintEditView::OnUpdateMenufontdia)
	ON_UPDATE_COMMAND_UI(ID_MENULINECOLOR, &CYPaintEditView::OnUpdateMenulinecolor)
	ON_UPDATE_COMMAND_UI(ID_MENUSIDECOLOR, &CYPaintEditView::OnUpdateMenusidecolor)
	ON_COMMAND(ID_GROUPSIZECHANGEBUTTON, &CYPaintEditView::OnGroupsizechangebutton)
	ON_UPDATE_COMMAND_UI(ID_GROUPSIZECHANGEBUTTON, &CYPaintEditView::OnUpdateGroupsizechangebutton)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CYPaintEditView::OnEditSelectAll)

END_MESSAGE_MAP()

// CYPaintEditView 생성/소멸

CYPaintEditView::CYPaintEditView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	// 리본 메뉴 초기화 //
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;

	texts = _T("");
	font = _T("굴림");
	fontColor = RGB(0, 0, 0);
	bkColor = RGB(255, 255, 255);
	fontSize = 100;

	lineThick = 1;
	linePattern = 0;
	sidePattern = 0;
	sidePatternflag2 = FALSE;

	lineColor = RGB(0, 0, 0);
	sideColor = RGB(255, 255, 255);


	// 팝업 메뉴 초기화 //
	menu_Cut = FALSE;
	menu_Paste = FALSE;
	menu_Copy = FALSE;
	menu_CutCopyflag = FALSE;
	menu_CutPaste = FALSE;
	menu_LineColor = TRUE;
	menu_SideColor = TRUE;
	menu_Figure = FALSE;
	menu_Delete = FALSE;
	menu_DeletePoint = FALSE;
	menu_Group = FALSE;
	menu_DeleteGroup = FALSE;
	menu_FontDialog = FALSE;
	cutObj = NULL;
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
	
	POSITION pos;
	if (pDoc->grouping == TRUE){
		menu_LineColor = FALSE;
		menu_SideColor = FALSE;
		menu_Figure = FALSE;
		menu_Delete = FALSE;
		menu_DeletePoint = FALSE;
		menu_Group = TRUE;
		menu_DeleteGroup = FALSE;
	}
	else {
		if (pDoc->currentObj != NULL){

			switch (pDoc->currentObj->getType()){
			case line:
				menu_LineColor = TRUE;
				menu_SideColor = FALSE;
				menu_Figure = TRUE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;
				break;
			case polyline:
				menu_LineColor = TRUE;
				menu_SideColor = FALSE;
				menu_Figure = TRUE;
				menu_Delete = TRUE;
				menu_DeletePoint = TRUE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;

				pos = pDoc->obj_List.GetHeadPosition();
				while (pos) {
					pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
					if (pDoc->currentObj->checkRgn(point) == TRUE && pDoc->currentObj->getSelect() == TRUE){			//클릭한 점이 영역안에 있고 객체가 선택되어져 있는상황에서만 메뉴를 띄운다.
						//pDoc->currentObj->setSelect(TRUE);
						if (pDoc->currentObj->getType() == polyline){													//polyline 일 때만 한점지우기가 있으므로
							for (int i = 0; i < pDoc->pPolyLine->getPolyList()->GetSize(); i++){
								if (pDoc->pPolyLine->getMRect()[i].PtInRect(point)){
									pDoc->deletePosition = i;															//삭제할 위치 저장
									break;
								}
							}
						}
						break;
					}
				}
				break;
			case ellipse:
				menu_LineColor = TRUE;
				menu_SideColor = TRUE;
				menu_Figure = TRUE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;
				break;
			case rectangle:
				menu_LineColor = TRUE;
				menu_SideColor = TRUE;
				menu_Figure = TRUE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;
				break;
			case text:
				menu_LineColor = FALSE;
				menu_SideColor = FALSE;
				menu_Figure = FALSE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = FALSE;
				break;
			case group:
				menu_LineColor = FALSE;
				menu_SideColor = FALSE;
				menu_Figure = FALSE;
				menu_Delete = TRUE;
				menu_DeletePoint = FALSE;
				menu_Group = TRUE;
				menu_DeleteGroup = TRUE;
				break;
			default:
				break;
			}

		}
		else {
			menu_Cut = FALSE;
			menu_Copy = FALSE;
			menu_LineColor = FALSE;
			menu_SideColor = FALSE;
			menu_Figure = FALSE;
			menu_Delete = FALSE;
			menu_DeletePoint = FALSE;
			menu_Group = FALSE;
			menu_DeleteGroup = FALSE;
		}
	}
	ClientToScreen(&point);
	OnContextMenu(this, point);

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


// 화면에 출력하는 함수들 //
void CYPaintEditView::OnPaint() // 기능 : cdc객체 생성해서 메모리dc에 저장해서 출력하는 함수
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CBitmap bitmap;

	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);															//메모리 dc 생성
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());						//전체화면을 대상으로 bitmap 생성
	dcmem.SelectObject(&bitmap);															//비트맵 선택

	dcmem.SelectStockObject(NULL_PEN);
	dcmem.Rectangle(&rect);

	Paint(&dcmem);
	dc.BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &dcmem, 0, 0, SRCCOPY);		//메모리에 있던 비트맵을 그린다.
	dcmem.DeleteDC();
	bitmap.DeleteObject();

}
void CYPaintEditView::Paint(CDC* dc) // 기능 : 어떤 도형을 그릴지 판단
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	CYPaintEditDoc* pDoc = GetDocument();

	// 현재 리스트에 있는 도형을 그리는 부분
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
		tmp->draw(dc);
	}

	// 현재 그리고있는 선,다각선,타원,직사각형을 그리는 부분  
	if (pDoc->drawing){
		undoredoFlag = TRUE;
		pDoc->temp_AllList.RemoveAll();
		POSITION pos = pDoc->allList.GetHeadPosition();
		while (pos){
			YObject* temp = (YObject*)pDoc->allList.GetNext(pos);
			pDoc->temp_AllList.AddTail(temp);
		}
		switch (pDoc->yType){
		case line:
			pDoc->pLine->draw(dc);
			break;
		case polyline:
			pDoc->pPolyLine->draw(dc);
			break;
		case ellipse:
			pDoc->pEllipse->draw(dc);
			break;
		case rectangle:
			pDoc->pRectangle->draw(dc);
			break;
		case choice:
			if (pDoc->currentObj == NULL) break;
			switch (pDoc->currentObj->getType()){
			case line:
				pDoc->pLine = (YLine*)pDoc->currentObj;
				pDoc->pLine->draw(dc);
				break;
			case polyline:
				pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
				pDoc->pPolyLine->draw(dc);
				break;
			case ellipse:
				pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
				pDoc->pEllipse->draw(dc);
				break;
			case rectangle:
				pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
				pDoc->pRectangle->draw(dc);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

	// 현재 그리고있는 텍스트를 그리는 부분
	//////////////////////////////////////// Text //////////////////////////////////////////
	if (pDoc->textEditing){
		// 폰트 생성 및 적용
		CFont f;
		LOGFONT lf;
		if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
		else lf.lfWeight = FW_NORMAL;
		lf.lfWidth = 0;
		lf.lfHeight = pDoc->pText->getFontSize();						//높이 설정
		lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//취소선 설정
		lf.lfUnderline = pDoc->pText->getUnderLine();						//밑줄설정
		lf.lfItalic = pDoc->pText->getItalic();							//기울임
		lf.lfEscapement = 0;							//기울기 각도 초기화
		lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
		lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
		lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfCharSet = DEFAULT_CHARSET;
		wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());
		f.CreateFontIndirect(&lf);
		dc->SelectObject(&f);
		dc->SetBkColor(pDoc->pText->getBkColor());
		dc->SetTextColor(pDoc->pText->getFontColor());
		// 폰트를 반영한 문자열(텍스트)의 길이 생성 및 저장
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
		if (lf.lfWeight == FW_BOLD){
			s.cx += 50;
		}
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
		dc->SelectObject(&pen);
		CBrush brush(pDoc->pText->getBkColor());
		dc->SelectObject(&brush);

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
BOOL CYPaintEditView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//더블버퍼링해결 ( 윈도우 크기 조절 할 때)
	return TRUE;
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
			pDoc->pText->setRgn();
			pDoc->pText->setSelect(FALSE);
			pDoc->obj_List.AddTail(pDoc->pText);
			YText* text = new YText(pDoc->pText);
			pDoc->allList.AddTail(text);
			pDoc->temp_AllList.AddTail(text);
			pDoc->pText = NULL;
			pDoc->textEditing = FALSE;
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

	switch (pDoc->yType){
		// 각각의 케이스문  생성자 초기화 , doc의 각 객체포인터로 연결 ,타입 ,선택값(TRUE),drawing ,i
	case line:
	{
				 //초기화
				 pDoc->pLine = new YLine(point, point, lineColor, lineThick, linePattern);
				 pDoc->pLine->setOrder(pDoc->allNum++);
				 pDoc->pLine->setType(line);
				 pDoc->pLine->setSelect(TRUE);
				 pDoc->drawing = TRUE;
				 break;
	}
	case polyline:
	{
					 if (pDoc->clickPolyLine == FALSE){   //시작 생성
						 pDoc->pPolyLine = new YPolyLine(lineColor, lineThick, linePattern);
						 pDoc->pPolyLine->setOrder(pDoc->allNum++);
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
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
					 }
					 break;
	}
	case ellipse:
	{
					pDoc->pEllipse = new YEllipse(point, point, lineColor, lineThick, linePattern, sideColor, sidePattern, sidePatternflag2);
					pDoc->pEllipse->setOrder(pDoc->allNum++);
					pDoc->pEllipse->setSelect(TRUE);
					pDoc->pEllipse->setType(ellipse);
					pDoc->drawing = TRUE;
					break;
	}
	case rectangle:
	{
					  pDoc->pRectangle = new YRectangle(point, point, lineColor, lineThick, linePattern, sideColor, sidePattern, sidePatternflag2);
					  pDoc->pRectangle->setOrder(pDoc->allNum++);
					  pDoc->pRectangle->setSelect(TRUE);
					  pDoc->pRectangle->setType(rectangle);
					  pDoc->drawing = TRUE;
					  break;
	}
	case text:
	{
				 if (pDoc->textEditing == FALSE){
					 pDoc->pText = new YText(point, font, fontColor, bkColor, fontSize, underline, strikeout, bold, italic);
					 pDoc->pText->setOrder(pDoc->allNum++);
					 pDoc->pText->setType(text);
					 pDoc->pText->setSelect(TRUE);
					 pDoc->textEditing = TRUE;
				 }
				 else {
					 if (pDoc->pText->getText().GetLength() != 0){
						 pDoc->pText->setRgn();
						 pDoc->pText->setSelect(FALSE);
						 pDoc->obj_List.AddTail(pDoc->pText);
					 }
					 pDoc->pText = NULL;
					 pDoc->textEditing = FALSE;
					 pDoc->tmp.Empty();
					 HideCaret();
				 }
				 break;
	}
	case choice:
	{

				   // 4 // (선택된 도형이 있는 경우에서) 다시 선택할 때  - 기존에 선택한 도형을 선택할수도, 새로운 도형을 선택할수도, 빈공간을 선택할수도 있으므로 currentObj를 초기화하고, 좌표를 사용하여 다시 리스트 탐색
				   if (pDoc->grouping == FALSE && pDoc->currentObj != NULL)	{
					   
					   //모두 선택 후 빈공간을 클릭 했을때 영역을 다 지워서 출력한다.
					   POSITION pos = pDoc->obj_List.GetHeadPosition();
					  
						   while (pos){
							   YObject* temp = (YObject*)pDoc->obj_List.GetNext(pos);
							   temp->setSelect(FALSE);
						   }
						 

					   pDoc->currentObj->setSelect(FALSE);
					   pDoc->currentObj = NULL;
				   }


				   // 0 // 리스트에서 좌표에 해당하는 도형을 찾는 부분
				   POSITION pos = pDoc->obj_List.GetTailPosition();
				   while (pos) {
					   pDoc->currentObj = (YObject*)pDoc->obj_List.GetPrev(pos);

					   // 좌표에 해당하는 도형이 있을 경우
					   if (pDoc->currentObj->checkRgn(point) == TRUE){
						   pDoc->currentObj->setSelect(TRUE);
						   if (pDoc->grouping == TRUE){
							   YObject* tmp;
							   int flag = 0;
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   while (pos) {
								   tmp = (YObject*)pDoc->current_group.GetNext(pos);
								   if (tmp->getOrder() == pDoc->currentObj->getOrder()){
									   flag = 1;
									   break;
								   }
							   }
							   if (flag == 0)
								   pDoc->current_group.AddTail(pDoc->currentObj);
						   }
						   break;
					   }

					   // 도형이 선택되어 리젼과 끝점을 그려진 경우, 다시 선택했을때 끝점을 선택해도 선택되게 설정하는 부분
					   if (pDoc->currentObj == pDoc->pLine){
						   if (pDoc->pLine->getMRect()[0].PtInRect(point) || pDoc->pLine->getMRect()[1].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
					   else if (pDoc->currentObj == pDoc->pEllipse){
						   if (pDoc->pEllipse->getMRect()[0].PtInRect(point) || pDoc->pEllipse->getMRect()[1].PtInRect(point) ||
							   pDoc->pEllipse->getMRect()[2].PtInRect(point) || pDoc->pEllipse->getMRect()[3].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
					   else if (pDoc->currentObj == pDoc->pRectangle){
						   if (pDoc->pRectangle->getMRect()[0].PtInRect(point) || pDoc->pRectangle->getMRect()[1].PtInRect(point) ||
							   pDoc->pRectangle->getMRect()[2].PtInRect(point) || pDoc->pRectangle->getMRect()[3].PtInRect(point)) {
							   pDoc->currentObj->setSelect(TRUE);
							   break;
						   }
					   }
					   else if (pDoc->currentObj == pDoc->pGroup){
						   if (pDoc->resizing == TRUE){
							   if (pDoc->pGroup->getMRect()[0].PtInRect(point) || pDoc->pGroup->getMRect()[1].PtInRect(point) ||
								   pDoc->pGroup->getMRect()[2].PtInRect(point) || pDoc->pGroup->getMRect()[3].PtInRect(point)) {
								   pDoc->currentObj->setSelect(TRUE);
							   }
							   break;
						   }
					   }
				   }


				   // 1 // (리스트가 비어 있는 경우) 빈공간을 선택한 경우
				   if (pDoc->currentObj == NULL){ // 리스트 탐색을 진행하지 않았으므로 currentObj는 NULL이다.
					   menu_Cut = FALSE;
					   menu_Copy = FALSE;
					   break;
				   }


				   // 2 // (리스트에 항목이 있는 경우) 빈공간을 선택하여 리스트에서 도형을 찾지 못하는 경우
				   else if (pDoc->currentObj->getSelect() == FALSE){ // 자연스럽게 리스트의 마지막 요소가 currnetObj가 되고 그것은 항상 FALSE임을 이용
					   pDoc->currentObj = NULL;
					   menu_Cut = FALSE;
					   menu_Copy = FALSE;
				   }


				   // 3 // (리스트에 항목이 있는 경우) 리스트에서 도형을 찾은 경우  - 선택된 도형 설정
				   else if (pDoc->currentObj->getSelect() == TRUE){
					   pDoc->Original_Point = point;  //선 이동시 기준점이 되는 좌표
					   pDoc->drawing = TRUE;
					   //메뉴 초기화 (잘라내기 , 복사하기 , 붙여넣기)
					   menu_Cut = TRUE;
					   menu_Copy = TRUE;
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
									   //LBUtton Down이야
									   pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
									   //1사분면
									   if (pDoc->pEllipse->getMRect()[0].PtInRect(point)){  // 시작점 클릭
										   pDoc->pEllipse->setSPoint(point);
										   pDoc->pEllipse->setMoveMode(-1);  //시작점 이동체크
									   }
									   else if (pDoc->pEllipse->getMRect()[1].PtInRect(point)){	// 끝점 클릭 4사분면
										   pDoc->pEllipse->setEPoint(point);
										   pDoc->pEllipse->setMoveMode(1);  //끝점 이동체크
										   break;
									   }
									   else if (pDoc->pEllipse->getMRect()[2].PtInRect(point)){	//3사분면
										   pDoc->pEllipse->setMixPoint(point);

										   pDoc->pEllipse->setMoveMode(2);  //3사분면 이동체크
										   break;
									   }
									   else if (pDoc->pEllipse->getMRect()[3].PtInRect(point)){	// 2사분면

										   pDoc->pEllipse->setMixPoint(point);
										   pDoc->pEllipse->setMoveMode(3);  //2사분면 이동 체크
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
											 pDoc->pRectangle->setMoveMode(-1);  //시작점 이동체크
										 }
										 else if (pDoc->pRectangle->getMRect()[1].PtInRect(point)){	// 끝점 클릭 4사분면
											 pDoc->pRectangle->setEPoint(point);
											 pDoc->pRectangle->setMoveMode(1);  //끝점 이동체크
											 break;
										 }
										 else if (pDoc->pRectangle->getMRect()[2].PtInRect(point)){	//3사분면
											 pDoc->pRectangle->setMixPoint(point);

											 pDoc->pRectangle->setMoveMode(2);  //3사분면 이동체크
											 break;
										 }
										 else if (pDoc->pRectangle->getMRect()[3].PtInRect(point)){	// 2사분면

											 pDoc->pRectangle->setMixPoint(point);
											 pDoc->pRectangle->setMoveMode(3);  //2사분면 이동 체크
											 break;
										 }
										 else if (pDoc->pRectangle->checkRgn(point)) {		//그 외 영역 클릭
											 pDoc->pRectangle->setMoveMode(0); //전체이동
										 }

										 break;
					   }
					   case text:
					   {
									pDoc->pText = (YText*)pDoc->currentObj;
									break;
					   }
					   case group:
						   pDoc->pGroup = (YGroup*)pDoc->currentObj;
						   if (pDoc->pGroup->getMRect()[0].PtInRect(point)){
							   pDoc->pGroup->setSPoint(point);
							   pDoc->pGroup->setMoveMode(-1);  //시작점 2
						   }
						   else if (pDoc->pGroup->getMRect()[1].PtInRect(point)){
							   pDoc->pGroup->setEPoint(point);
							   pDoc->pGroup->setMoveMode(1);  //끝점 4
							   break;
						   }
						   else if (pDoc->pGroup->getMRect()[2].PtInRect(point)){
							   pDoc->pGroup->setMixPoint(point);

							   pDoc->pGroup->setMoveMode(2);  // 1
							   break;
						   }
						   else if (pDoc->pGroup->getMRect()[3].PtInRect(point)){

							   pDoc->pGroup->setMixPoint(point);
							   pDoc->pGroup->setMoveMode(3);  // 3
							   break;
						   }
						   else if (pDoc->pGroup->checkRgn(point)) {
							   pDoc->pGroup->setMoveMode(0); //전체이동
						   }
						   break;
					   default:
						   break;
					   }
				   }
				   // 그룹화 중 이동 못하게
				   if (pDoc->grouping == TRUE)
					   pDoc->currentObj = NULL;


				   Invalidate(FALSE);
				   UpdateMenu();
				   break;
	}
	default:
		break;
	}

	if (pDoc->resizing == TRUE){
		pDoc->Original_Point = point;
		YObject* tmp;
		POSITION pos = pDoc->current_group.GetHeadPosition();
		while (pos){
			tmp = pDoc->current_group.GetNext(pos);
			switch (tmp->getType()){
			case line:{
						  YLine* tmp2 = (YLine*)tmp;
						  if (tmp2->getMRect()[0].PtInRect(point))
							  pDoc->flag = 0; // 시작점
						  else if (tmp2->getMRect()[1].PtInRect(point))
							  pDoc->flag = 1; // 끝점
						  break;
			}
			case rectangle:{
							   YRectangle* tmp2 = (YRectangle*)tmp;
							   if (tmp2->getMRect()[0].PtInRect(point))
								   pDoc->flag = 0;
							   else if (tmp2->getMRect()[1].PtInRect(point))
								   pDoc->flag = 1;
							   else if (tmp2->getMRect()[2].PtInRect(point))
								   pDoc->flag = 2;
							   else if (tmp2->getMRect()[3].PtInRect(point))
								   pDoc->flag = 3;
							   break;
			}
			case ellipse:{
							 YEllipse* tmp2 = (YEllipse*)tmp;
							 if (tmp2->getMRect()[0].PtInRect(point))
								 pDoc->flag = 0; // 2사분면
							 else if (tmp2->getMRect()[1].PtInRect(point))
								 pDoc->flag = 1; // 4사분면
							 else if (tmp2->getMRect()[2].PtInRect(point))
								 pDoc->flag = 2; // 3사분면
							 else if (tmp2->getMRect()[3].PtInRect(point))
								 pDoc->flag = 3; // 1사분면
							 break;
			}
			default:
				break;
			}
		}
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
		case choice:
		{
					   CPoint t_point = point - pDoc->Original_Point; // 좌표 움직임
					   pDoc->Original_Point = point;
					   
					   if (pDoc->currentObj != NULL){
						   
						   switch (pDoc->currentObj->getType()){
						   case line:
						   {
										//pDoc->pLine = (YLine*)pDoc->currentObj;
										//선택되었을때 이동 변수에따라 다른 move실행
										lineMove = TRUE;
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
											polylineMove = TRUE;
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
										   ellipseMove = TRUE;
										   //pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
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
											 rectangleMove = TRUE;
											 //pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
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
						   case text:
						   {
										textMove = TRUE;
										pDoc->pText->setSPoint(pDoc->pText->getSPoint() + t_point);
										pDoc->pText->setEPoint(pDoc->pText->getEPoint() + t_point);
										pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
										pDoc->pText->setRgn();
										break;
						   }
						   case group:
							   groupMove = TRUE;
							   if (pDoc->resizing == FALSE){
								   if (pDoc->pGroup->getSelect()){
									   if (pDoc->pGroup->getMoveMode() == 0){  //전체이동
										   pDoc->pGroup->moveAll(t_point.x, t_point.y);
										   pDoc->pGroup->setORect(pDoc->pGroup->getSPoint().x, pDoc->pGroup->getSPoint().y, pDoc->pGroup->getEPoint().x, pDoc->pGroup->getEPoint().y);
									   }
									   else {
										   pDoc->pGroup->move(t_point.x, t_point.y);
										   pDoc->pGroup->setORect(pDoc->pGroup->getSPoint().x, pDoc->pGroup->getSPoint().y, pDoc->pGroup->getEPoint().x, pDoc->pGroup->getEPoint().y);
									   }
									   pDoc->pGroup->setRgn();
								   }
							   }
							   else{ // 그룹크기 조정일 때
								   
							   }


							   break;
						   default:
							   break;
						   }
					   }
					   else if (pDoc->resizing){
						   if (pDoc->flag == 0){ // 2
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   YObject* tmp;
							   while (pos){
								   tmp = pDoc->current_group.GetNext(pos);
								   switch (tmp->getType()){
								   case line:{
												 YLine* p = (YLine*)tmp;
												 p->setMoveMode(-1);
												 p->move(t_point.x, t_point.y);
												 break;
								   }
								   case rectangle:{
													  YRectangle* p = (YRectangle*)tmp;
													  p->setMoveMode(-1);
													  p->move(t_point.x, t_point.y);
													  break;
								   }
								   case ellipse:{
													YEllipse* p = (YEllipse*)tmp;
													p->setMoveMode(-1);
													p->move(t_point.x, t_point.y);
													break;
								   }
								   }
							   }
						   }
						   else if (pDoc->flag == 1){ // 4
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   YObject* tmp;
							   while (pos){
								   tmp = pDoc->current_group.GetNext(pos);
								   
								   switch (tmp->getType()){
								   case line:{
												 YLine* p = (YLine*)tmp;
												 p->setMoveMode(1);
												 p->move(t_point.x, t_point.y);
												 break;
								   }
								   case rectangle:{
													  YRectangle* p = (YRectangle*)tmp;
													  p->setMoveMode(1);
													  p->move(t_point.x, t_point.y);
													  break;
								   }
								   case ellipse:{
													YEllipse* p = (YEllipse*)tmp;
													p->setMoveMode(1);
													p->move(t_point.x, t_point.y);
													break;
								   }
								   }
							   }
						   }
						   else if (pDoc->flag == 2){ // 3
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   YObject* tmp;
							   while (pos){
								   tmp = pDoc->current_group.GetNext(pos);
								   switch (tmp->getType()){
								   case rectangle:{
													  YRectangle* p = (YRectangle*)tmp;
													  p->setMoveMode(2);
													  p->move(t_point.x, t_point.y);
													  break;
								   }
								   case ellipse:{
													YEllipse* p = (YEllipse*)tmp;
													p->setMoveMode(2);
													p->move(t_point.x, t_point.y);
													break;
								   }
								   }
							   }
						   }
						   else if (pDoc->flag == 3){ // 1
							   POSITION pos = pDoc->current_group.GetHeadPosition();
							   YObject* tmp;
							   while (pos){
								   tmp = pDoc->current_group.GetNext(pos);
								   switch (tmp->getType()){
								   case rectangle:{
													  YRectangle* p = (YRectangle*)tmp;
													  p->setMoveMode(3);
													  p->move(t_point.x, t_point.y);
													  break;
								   }
								   case ellipse:{
													YEllipse* p = (YEllipse*)tmp;
													p->setMoveMode(3);
													p->move(t_point.x, t_point.y);
													break;
								   }
								   }
							   }
						   }
					   } 
					   else // 빈곳을 클릭했을때 (예외상황)
						   break;
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
				 YLine* line = new YLine(pDoc->pLine);
				 pDoc->allList.AddTail(line);
				 pDoc->temp_AllList.AddTail(line);
				 pDoc->pLine = NULL;
				 pDoc->drawing = FALSE;
				 break;
	}
	case polyline:
	{
					 break;
	}
	case ellipse:
	{
					pDoc->pEllipse->setRgn();
					pDoc->pEllipse->setSelect(FALSE);
					pDoc->obj_List.AddTail(pDoc->pEllipse);
					YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
					pDoc->allList.AddTail(ellipse);
					pDoc->temp_AllList.AddTail(ellipse);
					pDoc->drawing = FALSE;
					ReleaseCapture();
					break;
	}
	case rectangle:
	{
					  pDoc->pRectangle->setRgn();
					  pDoc->pRectangle->setSelect(FALSE);
					  pDoc->obj_List.AddTail(pDoc->pRectangle);
					  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
					  pDoc->allList.AddTail(rectangle);
					  pDoc->temp_AllList.AddTail(rectangle);
					  pDoc->drawing = FALSE;
					  ReleaseCapture();
					  break;
	}
	case text:
	{
				 break;
	}
	case choice:
	{
				   if (pDoc->currentObj != NULL){
					   switch (pDoc->currentObj->getType()){
					   case line:
					   {
									if (lineMove){
										YLine* line = new YLine(pDoc->pLine);
										pDoc->allList.AddTail(line);
										pDoc->temp_AllList.AddTail(line);
										lineMove = FALSE;
									}
									break;

					   }
					   case polyline:
					   {
										if (polylineMove){
											YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
											pDoc->allList.AddTail(polyline);
											pDoc->temp_AllList.AddTail(polyline);
											polylineMove = FALSE;
										}
										break;
					   }
					   case ellipse:
					   {
									   if (ellipseMove){
										   YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
										   pDoc->allList.AddTail(ellipse);
										   pDoc->temp_AllList.AddTail(ellipse);
										   ellipseMove = FALSE;
									   }
					   }
					   case rectangle:
					   {
										 if (rectangleMove){
											 YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
											 pDoc->allList.AddTail(rectangle);
											 pDoc->temp_AllList.AddTail(rectangle);
											 rectangleMove = FALSE;
										 }
										 break;
					   }
					   case text:
					   {
									if (textMove){
										YText* text = new YText(pDoc->pText);
										pDoc->allList.AddTail(text);
										pDoc->temp_AllList.AddTail(text);
										textMove = FALSE;
									}
									break;
					   }
					   case group:
					   {
									 if (groupMove){
										 YGroup* group = new YGroup(pDoc->pGroup);
										 pDoc->allList.AddTail(group);
										 pDoc->temp_AllList.AddTail(group);
										 groupMove = FALSE;
									 }
									 break;
					   }
					   }
				   }
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

		if (pDoc->grouping == TRUE){

			// obj_List에서 그룹화된 도형을 꺼내는 부분
			YObject* search;
			POSITION tpos;
			POSITION pos = pDoc->current_group.GetHeadPosition();
			while (pos) {
				search = pDoc->current_group.GetNext(pos);
				POSITION pos2 = pDoc->obj_List.GetHeadPosition();
				while (pos2) {
					tpos = pos2;
					pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos2);
					if (pDoc->currentObj->getOrder() == search->getOrder()){
						pDoc->obj_List.RemoveAt(tpos);
						break;
					}
				}
			}

			// 그룹 객체 생성 및 obj_List에 연결하는 부분
			YGroup* tgroup = new YGroup(pDoc->current_group);
			tgroup->setRgn();
			tgroup->setType(group);
			tgroup->setOrder(pDoc->allNum++);
			tgroup->setSelect(TRUE);
			pDoc->currentObj = tgroup;
			pDoc->obj_List.AddTail(tgroup);

			// 그룹화 변수 초기화
			pDoc->current_group.RemoveAll();
			pDoc->grouping = FALSE;

			Invalidate();
		}
		if (pDoc->resizing){
			pDoc->resizing = FALSE;

			YObject* tmp;
			POSITION pos = pDoc->current_group.GetHeadPosition();
			while (pos) {
				tmp = (YObject*)pDoc->obj_List.GetNext(pos);
				tmp->setSelect(FALSE);
				tmp->setRgn();
			}

			pDoc->pGroup->setSelect(TRUE);
			pDoc->pGroup->setRgn();
			pDoc->pGroup->dsetResizing();

			pDoc->current_group.RemoveAll();
		}
	
	CView::OnLButtonDblClk(nFlags, point);
}


// 리본 메뉴 관련 함수들 //

// 도형 패널
void CYPaintEditView::UpdateMenu(){ //기능 : 객체 클릭 했을때 해당되는 속성으로 메뉴값 최신화
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();

	CMFCRibbonEdit* lineThick = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENULINETHICK);
	CMFCRibbonComboBox* sidePattern = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUSIDEPATTERN);
	CMFCRibbonComboBox* linePattern = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENULINEPATTERN);
	CMFCRibbonComboBox* fonts = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUFONT);
	CMFCRibbonEdit* fontsize = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENUFONTSIZE);
	CMFCRibbonColorButton* fontcolor = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUFONTCOLOR);

	if (pDoc->currentObj != NULL){
		switch (pDoc->currentObj->getType()){
		case line:
		{
					 CString str;
					 str.Format(_T("%d"), pDoc->pLine->getLineThick());
					 lineThick->SetEditText(str);
					 linePattern->OnSelectItem(pDoc->pLine->getLinePattern());
					 break;
		}
		case polyline:
		{
						 CString str;
						 str.Format(_T("%d"), pDoc->pPolyLine->getLineThick());
						 lineThick->SetEditText(str);
						 linePattern->OnSelectItem(pDoc->pPolyLine->getLinePattern());
						 break;
		}
		case ellipse:
		{
						CString str;
						str.Format(_T("%d"), pDoc->pEllipse->getLineThick());
						lineThick->SetEditText(str);
						linePattern->OnSelectItem(pDoc->pEllipse->getLinePattern());
						sidePattern->OnSelectItem(pDoc->pEllipse->getSidePattern());

						break;
		}
		case rectangle:
		{
						  CString str;
						  str.Format(_T("%d"), pDoc->pRectangle->getLineThick());
						  lineThick->SetEditText(str);
						  linePattern->OnSelectItem(pDoc->pRectangle->getLinePattern());
						  sidePattern->OnSelectItem(pDoc->pRectangle->getSidePattern());
						  break;
		}
		case text:
		{
					 CString str;
					 str.Format(_T("%d"), pDoc->pText->getFontSize() / 10);
					 fontsize->SetEditText(str);
					 fonts->SetEditText(pDoc->pText->getFont());
					 fontcolor->SetColor(pDoc->pText->getFontColor());
					 break;
		}
		default:
			break;
		}
	}
}
void CYPaintEditView::OnMenudefaulttbutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Select = TRUE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
	menu_FontDialog = TRUE;
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
void CYPaintEditView::OnUpdateMenudefaulttbutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Select);
}
void CYPaintEditView::OnMenulinebutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = TRUE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
	menu_FontDialog = FALSE;
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = line;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}
void CYPaintEditView::OnUpdateMenulinebutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Line);
}
void CYPaintEditView::OnMenupolylinebutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = TRUE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
	menu_FontDialog = FALSE;
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = polyline;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}
void CYPaintEditView::OnUpdateMenupolylinebutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_PolyLine);
}
void CYPaintEditView::OnMenurectanglebutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = TRUE;
	menu_Text = FALSE;
	menu_FontDialog = FALSE;
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = rectangle;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}
void CYPaintEditView::OnUpdateMenurectanglebutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Rectangle);
}
void CYPaintEditView::OnMenuellipsebutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = TRUE;
	menu_Rectangle = FALSE;
	menu_Text = FALSE;
	menu_FontDialog = FALSE;
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = ellipse;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
}
void CYPaintEditView::OnUpdateMenuellipsebutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(menu_Ellipse);
}
void CYPaintEditView::OnMenutextbutton()
{
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Select = FALSE;
	menu_Line = FALSE;
	menu_PolyLine = FALSE;
	menu_Ellipse = FALSE;
	menu_Rectangle = FALSE;
	menu_Text = TRUE;
	menu_FontDialog = TRUE;
	CYPaintEditDoc* pDoc = GetDocument();
	pDoc->yType = text;

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	while (pos) {
		pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos);
		if (pDoc->currentObj->getSelect() == TRUE) pDoc->currentObj->setSelect(FALSE);
	}
	pDoc->currentObj = NULL;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

}
void CYPaintEditView::OnUpdateMenutextbutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다
	pCmdUI->SetCheck(menu_Text);
}

// 텍스트속성 패널
void CYPaintEditView::OnMenufontsize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonEdit* fontsize = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENUFONTSIZE);
	fontSize = (_ttoi)(fontsize->GetEditText()) * 10;

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
		pDoc->pText->setFontSize(fontSize);

		// 글자크기변경 -> 끝점 변경,렉트변경,리젼변경
		CDC* dc = GetDC();
		CFont f;
		LOGFONT lf;
		if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
		else lf.lfWeight = FW_NORMAL;
		lf.lfWidth = 0;
		lf.lfHeight = pDoc->pText->getFontSize();						//높이 설정
		lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//취소선 설정
		lf.lfUnderline = pDoc->pText->getUnderLine();						//밑줄설정
		lf.lfItalic = pDoc->pText->getItalic();							//기울임
		lf.lfEscapement = 0;							//기울기 각도 초기화
		lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
		lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
		lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfCharSet = DEFAULT_CHARSET;
		wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

		f.CreateFontIndirect(&lf);
		dc->SelectObject(f);
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
		if (lf.lfWeight == FW_BOLD){
			s.cx += 50;
		}
		pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
		pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
		pDoc->pText->setRgn();
		YText* text = new YText(pDoc->pText);
		pDoc->allList.AddTail(text);
		pDoc->temp_AllList.AddTail(text);
		ReleaseDC(dc);
		Invalidate(FALSE);
	}
	else if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){

		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (YObject*)(*pL).GetNext(pos);
			if (tmp->getType() == text){
				pDoc->pText = (YText*)tmp;
				pDoc->pText->setFontSize(fontSize);

				// 글자크기변경 -> 끝점 변경,렉트변경,리젼변경
				CDC* dc = GetDC();
				CFont f;
				LOGFONT lf;
				if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
				else lf.lfWeight = FW_NORMAL;
				lf.lfWidth = 0;
				lf.lfHeight = pDoc->pText->getFontSize();                        //높이 설정
				lf.lfStrikeOut = pDoc->pText->getStrikeOut();                        //취소선 설정
				lf.lfUnderline = pDoc->pText->getUnderLine();                        //밑줄설정
				lf.lfItalic = pDoc->pText->getItalic();                            //기울임
				lf.lfEscapement = 0;                            //기울기 각도 초기화
				lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
				lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
				lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
				lf.lfQuality = DEFAULT_QUALITY;
				lf.lfCharSet = DEFAULT_CHARSET;
				wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

				f.CreateFontIndirect(&lf);
				dc->SelectObject(f);
				CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
				if (lf.lfWeight == FW_BOLD){
					s.cx += 40;
				}
				pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
				pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
				pDoc->pText->setRgn();

				pDoc->pGroup->setRgn();

				ReleaseDC(dc);
				Invalidate(FALSE);
			}
			else if (tmp->getType() == group){
				YObject* tmp2;
				tmp2 = pDoc->currentObj;
				pDoc->currentObj = tmp;
				OnMenufontsize();
				pDoc->currentObj = tmp2;
				pDoc->currentObj->setRgn();
				Invalidate(FALSE);
			}
		}
		pDoc->currentObj->setRgn();
		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnMenufont()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonComboBox* fonts = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUFONT);
	font = fonts->GetEditText();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
		pDoc->pText->setFont(font);

		// 글자크기변경 -> 끝점 변경,렉트변경,리젼변경
		CDC* dc = GetDC();
		CFont f;
		LOGFONT lf;
		if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
		else lf.lfWeight = FW_NORMAL;
		lf.lfWidth = 0;
		lf.lfHeight = pDoc->pText->getFontSize();						//높이 설정
		lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//취소선 설정
		lf.lfUnderline = pDoc->pText->getUnderLine();						//밑줄설정
		lf.lfItalic = pDoc->pText->getItalic();							//기울임
		lf.lfEscapement = 0;							//기울기 각도 초기화
		lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
		lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
		lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfCharSet = DEFAULT_CHARSET;
		wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

		f.CreateFontIndirect(&lf);
		dc->SelectObject(f);
		CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
		if (lf.lfWeight == FW_BOLD){
			s.cx += 50;
		}
		pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
		pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
		pDoc->pText->setRgn();
		YText* text = new YText(pDoc->pText);
		pDoc->allList.AddTail(text);
		pDoc->temp_AllList.AddTail(text);
		ReleaseDC(dc);
		Invalidate(FALSE);
	}
	else if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){

		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (YObject*)(*pL).GetNext(pos);
			if (tmp->getType() == text){
				pDoc->pText = (YText*)tmp;
				pDoc->pText->setFont(font);

				// 글자크기변경 -> 끝점 변경,렉트변경,리젼변경
				CDC* dc = GetDC();
				CFont f;
				LOGFONT lf;
				if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
				else lf.lfWeight = FW_NORMAL;
				lf.lfWidth = 0;
				lf.lfHeight = pDoc->pText->getFontSize();                        //높이 설정
				lf.lfStrikeOut = pDoc->pText->getStrikeOut();                        //취소선 설정
				lf.lfUnderline = pDoc->pText->getUnderLine();                        //밑줄설정
				lf.lfItalic = pDoc->pText->getItalic();                            //기울임
				lf.lfEscapement = 0;                            //기울기 각도 초기화
				lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
				lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
				lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
				lf.lfQuality = DEFAULT_QUALITY;
				lf.lfCharSet = DEFAULT_CHARSET;
				wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

				f.CreateFontIndirect(&lf);
				dc->SelectObject(f);
				CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());

				pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
				pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
				pDoc->pText->setRgn();
				ReleaseDC(dc);
				Invalidate(FALSE);
			}
			else if (tmp->getType() == group){
				YObject* tmp2;
				tmp2 = pDoc->currentObj;
				pDoc->currentObj = tmp;
				OnMenufont();
				pDoc->currentObj = tmp2;
				pDoc->currentObj->setRgn();
				Invalidate(FALSE);
			}
		}
		pDoc->currentObj->setRgn();
		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnTexteditbutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->pText != NULL)
		texts = pDoc->pText->getText();

	TextEditDialog dlg(texts);
	int result = dlg.DoModal();

	if (result == IDOK){
		if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
			pDoc->pText->setText(texts);

			// 글자크기변경 -> 끝점 변경,렉트변경,리젼변경
			CDC* dc = GetDC();
			CFont f;
			LOGFONT lf;
			if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
			else lf.lfWeight = FW_NORMAL;
			lf.lfWidth = 0;
			lf.lfHeight = pDoc->pText->getFontSize();						//높이 설정
			lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//취소선 설정
			lf.lfUnderline = pDoc->pText->getUnderLine();						//밑줄설정
			lf.lfItalic = pDoc->pText->getItalic();							//기울임
			lf.lfEscapement = 0;							//기울기 각도 초기화
			lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
			lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
			lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
			lf.lfQuality = DEFAULT_QUALITY;
			lf.lfCharSet = DEFAULT_CHARSET;
			wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

			f.CreateFontIndirect(&lf);
			dc->SelectObject(f);
			CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
			if (lf.lfWeight == FW_BOLD){
				s.cx += 50;
			}
			pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
			pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
			pDoc->pText->setRgn();
			YText* text = new YText(pDoc->pText);
			pDoc->allList.AddTail(text);
			pDoc->temp_AllList.AddTail(text);
			ReleaseDC(dc);
			Invalidate(FALSE);
		}
	}
}
void CYPaintEditView::OnMenufontcolor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonColorButton* fontcolor = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUFONTCOLOR);
	fontColor = fontcolor->GetColor();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
		pDoc->pText->setFontColor(fontColor);
		YText* text = new YText(pDoc->pText);
		pDoc->allList.AddTail(text);
		pDoc->temp_AllList.AddTail(text);
		Invalidate(FALSE);
	}
	else if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){
		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (YObject*)(*pL).GetNext(pos);
			if (tmp->getType() == text){
				pDoc->pText = (YText*)tmp;
				pDoc->pText->setFontColor(fontColor);
			}
			else if (tmp->getType() == group){
				YObject* tmp2;
				tmp2 = pDoc->currentObj;
				pDoc->currentObj = tmp;
				OnMenufontcolor();
				Invalidate(FALSE);
				pDoc->currentObj = tmp2;
			}
		}
		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnMenufontbkcolor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonColorButton* bkcolor = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUFONTBKCOLOR);
	bkColor = bkcolor->GetColor();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
		pDoc->pText->setBkColor(bkColor);
		YText* text = new YText(pDoc->pText);
		pDoc->allList.AddTail(text);
		pDoc->temp_AllList.AddTail(text);
		Invalidate(FALSE);
	}
	else if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){
		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (YObject*)(*pL).GetNext(pos);
			if (tmp->getType() == text){
				pDoc->pText = (YText*)tmp;
				pDoc->pText->setBkColor(bkColor);
			}
			else if (tmp->getType() == group){
				YObject* tmp2;
				tmp2 = pDoc->currentObj;
				pDoc->currentObj = tmp;
				OnMenufontbkcolor();
				Invalidate(FALSE);
				pDoc->currentObj = tmp2;
			}
		}
		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnMenufontdia()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	LOGFONT lf;
	int dialogFontSize;
	if (pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){

		if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
		else lf.lfWeight = FW_NORMAL;

		if (pDoc->pText->getFontSize() >= 300) dialogFontSize = pDoc->pText->getFontSize() / 3.8 + 1;
		else dialogFontSize = pDoc->pText->getFontSize() / 3.8;

		lf.lfHeight = dialogFontSize;						//높이 설정
		lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//취소선 설정
		lf.lfUnderline = pDoc->pText->getUnderLine();						//밑줄설정
		lf.lfItalic = pDoc->pText->getItalic();							//기울임
		lf.lfWidth = 0;
		lf.lfEscapement = 0;							//기울기 각도 초기화
		lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
		lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
		lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
		lf.lfQuality = DEFAULT_QUALITY;
		lf.lfCharSet = DEFAULT_CHARSET;
		wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());

		CFontDialog dlg(&lf);

		int result = dlg.DoModal();
		if (result == IDOK){

			LOGFONT lf;
			//다이얼로그에서 값가져오기
			dlg.GetCurrentFont(&lf);
			underline = dlg.IsUnderline();
			bold = dlg.IsBold();
			italic = dlg.IsItalic();
			strikeout = dlg.IsStrikeOut();
			font = lf.lfFaceName;
			fontSize = dlg.GetSize();
			fontColor = dlg.GetColor();

			pDoc->pText->setFont(font);
			pDoc->pText->setFontSize(fontSize);
			pDoc->pText->setFontColor(fontColor);
			pDoc->pText->setItalic(italic);
			pDoc->pText->setBold(bold);
			pDoc->pText->setUnderLine(underline);
			pDoc->pText->setStrikeOut(strikeout);

			if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == text){
				pDoc->pText->setFont(font);

				// 글자크기변경 -> 끝점 변경,렉트변경,리젼변경
				CDC* dc = GetDC();
				CFont f;
				if (bold) lf.lfWeight = FW_BOLD;
				else lf.lfWeight = FW_NORMAL;
				lf.lfWidth = 0;
				lf.lfHeight = fontSize;						//높이 설정
				lf.lfStrikeOut = strikeout;						//취소선 설정
				lf.lfUnderline = underline;						//밑줄설정
				lf.lfItalic = italic;							//기울임
				lf.lfEscapement = 0;							//글자 각도 초기화
				lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
				lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
				lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
				lf.lfQuality = DEFAULT_QUALITY;
				lf.lfCharSet = DEFAULT_CHARSET;
				wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), font);
				f.CreateFontIndirect(&lf);
				dc->SelectObject(f);

				CSize s = dc->GetTextExtent(pDoc->pText->getText(), pDoc->pText->getText().GetLength());
				if (lf.lfWeight == FW_BOLD){
					s.cx += 50;
				}
				pDoc->pText->setEPoint(CPoint(pDoc->pText->getSPoint().x + s.cx, pDoc->pText->getSPoint().y + s.cy));
				pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
				pDoc->pText->setRgn();

				pDoc->pText->setFontColor(fontColor);
				YText* text = new YText(pDoc->pText);
				pDoc->allList.AddTail(text);
				ReleaseDC(dc);
				Invalidate(FALSE);
			}
		}
	}
}
void CYPaintEditView::OnUpdateMenufontsize(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text || pDoc->currentObj->getType() == group) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}

}
void CYPaintEditView::OnUpdateMenufont(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text || pDoc->currentObj->getType() == group) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateTexteditbutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenufontcolor(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text || pDoc->currentObj->getType() == group) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenufontbkcolor(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text || pDoc->currentObj->getType() == group) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenufontdia(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == text) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == text || pDoc->yType == choice) pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
}

// 도형속성 패널
void CYPaintEditView::OnMenulinethick() //기능 : 선 굵기
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();

	CMFCRibbonEdit* thick = (CMFCRibbonEdit*)main->getRibbon()->FindByID(ID_MENULINETHICK);
	lineThick = (_ttoi)(thick->GetEditText());

	if (pDoc->currentObj != NULL){							//객체를 선택했을 때 
		switch (pDoc->currentObj->getType()){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->pLine->setLineThick(lineThick);
					 YLine* line = new YLine(pDoc->pLine);
					 pDoc->allList.AddTail(line);
					 pDoc->temp_AllList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLineThick(lineThick);
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLineThick(lineThick);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineThick(lineThick);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		case group:
		{
					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == line){
							  pDoc->pLine = (YLine*)tmp;
							  pDoc->pLine->setLineThick(lineThick);
						  }
						  else if (tmp->getType() == polyline){
							  pDoc->pPolyLine = (YPolyLine*)tmp;
							  pDoc->pPolyLine->setLineThick(lineThick);
						  }
						  else if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  pDoc->pEllipse->setLineThick(lineThick);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  pDoc->pRectangle->setLineThick(lineThick);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenulinethick();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }
					  YGroup* group = new YGroup(pDoc->pGroup);
					  pDoc->allList.AddTail(group);
					  pDoc->temp_AllList.AddTail(group);
					  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenulinethick(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == line || pDoc->currentObj->getType() == polyline || pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == line || pDoc->yType == polyline || pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnMenulinepattern() //기능 : 선 패턴
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();
	CMFCRibbonComboBox* pattern = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENULINEPATTERN);

	linePattern = pattern->GetCurSel();

	if (pDoc->currentObj != NULL){											//객체를 선택했을 때 
		switch (pDoc->currentObj->getType()){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->pLine->setLinePattern(linePattern);
					 YLine* line = new YLine(pDoc->pLine);
					 pDoc->allList.AddTail(line);
					 pDoc->temp_AllList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLinePattern(linePattern);
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLinePattern(linePattern);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLinePattern(linePattern);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		case group:
		{
					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == line){
							  pDoc->pLine = (YLine*)tmp;
							  pDoc->pLine->setLinePattern(linePattern);
						  }
						  else if (tmp->getType() == polyline){
							  pDoc->pPolyLine = (YPolyLine*)tmp;
							  pDoc->pPolyLine->setLinePattern(linePattern);
						  }
						  else if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  pDoc->pEllipse->setLinePattern(linePattern);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  pDoc->pRectangle->setLinePattern(linePattern);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenulinepattern();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }

					  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenulinepattern(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == line || pDoc->currentObj->getType() == polyline || pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == line || pDoc->yType == polyline || pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnMenusidepattern() //기능 : 면 패턴
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();
	CMFCRibbonComboBox* pattern = (CMFCRibbonComboBox*)main->getRibbon()->FindByID(ID_MENUSIDEPATTERN);

	sidePattern = pattern->GetCurSel();

	if (sidePattern == 0) sidePatternflag2 = FALSE;										//DEFAULT가 선택되었을때 flag값 조정
	else sidePatternflag2 = TRUE;

	if (pDoc->currentObj != NULL){																//객체를 선택했을 때 
		switch (pDoc->currentObj->getType()){
		case ellipse:
		{

						if (sidePatternflag2) pDoc->pEllipse->setPatternflag(TRUE);							//default일때 ellipse의 flag변수값 조정
						else pDoc->pEllipse->setPatternflag(FALSE);

						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setSidePattern(sidePattern);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  if (sidePatternflag2) pDoc->pRectangle->setPatternflag(TRUE);						//default일때 rectangle의 flag변수값 조정
						  else pDoc->pRectangle->setPatternflag(FALSE);

						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setSidePattern(sidePattern);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}

		case group:
		{


					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  if (sidePatternflag2) pDoc->pEllipse->setPatternflag(TRUE);							//default일때 ellipse의 flag변수값 조정
							  else pDoc->pEllipse->setPatternflag(FALSE);

							  pDoc->pEllipse->setSidePattern(sidePattern);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  if (sidePatternflag2) pDoc->pRectangle->setPatternflag(TRUE);						//default일때 rectangle의 flag변수값 조정
							  else pDoc->pRectangle->setPatternflag(FALSE);

							  pDoc->pRectangle->setSidePattern(sidePattern);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenusidepattern();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }

					  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenusidepattern(CCmdUI *pCmdUI) //기능 : 면 패턴 Update
{
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
	}

}

// 색 패널
void CYPaintEditView::OnMenulinecolor() //기능 : 선 색
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();
	CMFCRibbonColorButton* color = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENULINECOLOR);

	lineColor = color->GetColor();
	if (pDoc->currentObj != NULL){											//객체를 선택했을 때 
		switch (pDoc->currentObj->getType()){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->pLine->setLineColor(lineColor);
					 YLine* line = new YLine(pDoc->pLine);
					 pDoc->allList.AddTail(line);
					 pDoc->temp_AllList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLineColor(lineColor);
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
						 break;
		}
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLineColor(lineColor);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineColor(lineColor);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		case group:
		{
					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == line){
							  pDoc->pLine = (YLine*)tmp;
							  pDoc->pLine->setLineColor(lineColor);
						  }
						  else if (tmp->getType() == polyline){
							  pDoc->pPolyLine = (YPolyLine*)tmp;
							  pDoc->pPolyLine->setLineColor(lineColor);
						  }
						  else if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  pDoc->pEllipse->setLineColor(lineColor);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  pDoc->pRectangle->setLineColor(lineColor);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenulinecolor();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }

					  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnMenusidecolor() //기능 : 면 색
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();
	CMFCRibbonColorButton* color = (CMFCRibbonColorButton*)main->getRibbon()->FindByID(ID_MENUSIDECOLOR);

	sideColor = color->GetColor();

	if (pDoc->currentObj != NULL){										//객체를 선택했을때
		switch (pDoc->currentObj->getType()){
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setSideColor(sideColor);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setSideColor(sideColor);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		case group:
		{
					  pDoc->pGroup = (YGroup*)pDoc->currentObj;
					  CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();

					  POSITION pos = (*pL).GetHeadPosition();
					  while (pos) {
						  YObject* tmp = (YObject*)(*pL).GetNext(pos);
						  if (tmp->getType() == ellipse){
							  pDoc->pEllipse = (YEllipse*)tmp;
							  pDoc->pEllipse->setSideColor(sideColor);
						  }
						  else if (tmp->getType() == rectangle){
							  pDoc->pRectangle = (YRectangle*)tmp;
							  pDoc->pRectangle->setSideColor(sideColor);
						  }
						  else if (tmp->getType() == group){
							  YObject* tmp2;
							  tmp2 = pDoc->currentObj;
							  pDoc->currentObj = tmp;
							  OnMenusidecolor();
							  Invalidate(FALSE);
							  pDoc->currentObj = tmp2;
						  }

					  }

					  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnUpdateMenulinecolor(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == line || pDoc->currentObj->getType() == polyline || pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == line || pDoc->yType == polyline || pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
	}
}
void CYPaintEditView::OnUpdateMenusidecolor(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->currentObj != NULL){
		if (pDoc->currentObj->getType() == ellipse || pDoc->currentObj->getType() == rectangle || pDoc->currentObj->getType() == group)pCmdUI->Enable(TRUE);
		else pCmdUI->Enable(FALSE);
	}
	else {
		if (pDoc->yType == ellipse || pDoc->yType == rectangle || pDoc->yType == choice)pCmdUI->Enable(TRUE);
		else  pCmdUI->Enable(FALSE);
	}
}

// 그룹 패널
void CYPaintEditView::OnGroupsbutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	pDoc->grouping = TRUE;
	if (pDoc->currentObj != NULL)
		pDoc->current_group.AddTail(pDoc->currentObj);
}
void CYPaintEditView::OnUpdateGroupsbutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice)
		pCmdUI->Enable(TRUE);
	else
		pCmdUI->Enable(FALSE);

	if (pDoc->grouping == TRUE)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}
void CYPaintEditView::OnDeletegroupbutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj->getType() == group){
		// obj_List에서 그룹의 위치를 찾는 부분
		YObject* to;
		POSITION tpos=NULL;
		POSITION pos = pDoc->obj_List.GetHeadPosition();
		while (pos){
			tpos = pos;
			to = (YObject*)pDoc->obj_List.GetNext(pos);
			if (to->getOrder() == pDoc->currentObj->getOrder())
				break;
		}

		// 그룹에서 꺼내어 obj_List에 저장하는 부분
		CList<YObject*, YObject*>* tmp = ((YGroup*)pDoc->currentObj)->getList();
		pos = tmp->GetHeadPosition();
		while (pos){
			pDoc->obj_List.AddTail(tmp->GetNext(pos));
		}

		// obj_List에서 그룹을 제거하는 부분
		pDoc->obj_List.RemoveAt(tpos);

		pDoc->currentObj = NULL;

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateDeletegroupbutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){
		pCmdUI->Enable(TRUE);
	}
	else
		pCmdUI->Enable(FALSE);
}
void CYPaintEditView::OnGroupsizechangebutton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->resizing == FALSE){ // 시작
		pDoc->resizing = TRUE;

		pDoc->pGroup = (YGroup*)pDoc->currentObj;
		pDoc->pGroup->setSelect(FALSE);
		pDoc->pGroup->dsetRgn();
		pDoc->pGroup->setResizing();

		CList<YObject*, YObject*>* pL = pDoc->pGroup->getList();
		POSITION pos = (*pL).GetHeadPosition();
		while (pos) {
			YObject* tmp = (*pL).GetNext(pos);
			tmp->setSelect(TRUE);
			pDoc->current_group.AddTail(tmp);
		}
		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateGroupsizechangebutton(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->yType == choice && pDoc->currentObj != NULL && pDoc->currentObj->getType() == group){
		pCmdUI->Enable(TRUE);
		pCmdUI->SetCheck(pDoc->resizing);
	}
	else
		pCmdUI->Enable(FALSE);
}

// 클립보드 패널
void CYPaintEditView::OnEditCut()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Cut = FALSE;
	menu_Copy = FALSE;
	menu_Paste = TRUE;
	menu_CutCopyflag = TRUE;
	menu_CutPaste = TRUE;
	CYPaintEditDoc* pDoc = GetDocument();

	cutObj = NULL;

	if (pDoc->currentObj != NULL){
		cutObj = pDoc->currentObj;

		POSITION pos = pDoc->obj_List.GetHeadPosition();
		POSITION tpos=NULL;
		if (pDoc->obj_List.GetSize() == 1){									//객체가 하나만 남아있을때
			pDoc->obj_List.RemoveAll();

		}
		else {
			while (pos) {
				tpos = pos;													//위치를 저장한 후 에 다음 노드로 넘어간다.
				YObject* tmp = (YObject*)pDoc->obj_List.GetNext(pos);
				if (tmp == pDoc->currentObj) break;
			}
			pDoc->obj_List.RemoveAt(tpos);
		}
		pDoc->currentObj = NULL;

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnEditPaste()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


	if (cutObj != NULL && menu_CutPaste == TRUE){
		menu_Cut = TRUE;
		menu_Copy = TRUE;
		menu_Paste = FALSE;
		if (menu_CutCopyflag == TRUE) menu_CutPaste = FALSE;
		CYPaintEditDoc* pDoc = GetDocument();
		cutObj->setSelect(FALSE);

		switch (cutObj->getType()){
		case line:
		{
					 YLine* temp = (YLine*)cutObj;
					 pDoc->pLine = new YLine(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());
					 pDoc->pLine->setType(line);
					 pDoc->pLine->setSelect(TRUE);
					 if (menu_CutCopyflag == FALSE){			//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
						 pDoc->pLine->moveAll(20, 20);
						 menu_Paste = TRUE;
					 }
					 pDoc->pLine->setRgn();
					 pDoc->drawing = FALSE;
					 pDoc->obj_List.AddTail(pDoc->pLine);
					 cutObj = pDoc->pLine;
					 pDoc->currentObj = cutObj;
					 break;
		}
		case polyline:
		{
						 YPolyLine* temp = (YPolyLine*)cutObj;
						 pDoc->pPolyLine = new YPolyLine(temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());

						 POSITION pos = temp->getPolyList()->GetHeadPosition();
						 while (pos){
							 CPoint point = temp->getPolyList()->GetNext(pos);
							 pDoc->pPolyLine->addPoint(point);
							 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
							 pDoc->allList.AddTail(polyline);
							 pDoc->temp_AllList.AddTail(polyline);
						 }
						 pDoc->pPolyLine->setType(polyline);
						 pDoc->pPolyLine->setSelect(TRUE);
						 if (menu_CutCopyflag == FALSE) {			//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
							 pDoc->pPolyLine->moveAll(20, 20);
							 menu_Paste = TRUE;
						 }
						 pDoc->pPolyLine->setRgn();
						 pDoc->drawing = FALSE;
						 pDoc->obj_List.AddTail(pDoc->pPolyLine);
						 cutObj = pDoc->pPolyLine;
						 pDoc->currentObj = cutObj;
						 break;
		}
		case ellipse:
		{

						YEllipse* temp = (YEllipse*)cutObj;
						pDoc->pEllipse = new YEllipse(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern(), temp->getSideColor(), temp->getSidePattern(), temp->getPatternflag());
						pDoc->pEllipse->setType(ellipse);
						pDoc->pEllipse->setSelect(TRUE);
						if (menu_CutCopyflag == FALSE){				//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
							pDoc->pEllipse->moveAll(20, 20);
							menu_Paste = TRUE;
						}
						pDoc->pEllipse->setRgn();
						pDoc->obj_List.AddTail(pDoc->pEllipse);
						pDoc->drawing = FALSE;
						cutObj = pDoc->pEllipse;
						pDoc->currentObj = cutObj;
						break;
		}
		case rectangle:
		{
						  YRectangle* temp = (YRectangle*)cutObj;
						  pDoc->pRectangle = new YRectangle(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern(), temp->getSideColor(), temp->getSidePattern(), temp->getPatternflag());
						  pDoc->pRectangle->setType(rectangle);
						  pDoc->pRectangle->setSelect(TRUE);
						  if (menu_CutCopyflag == FALSE){						//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
							  pDoc->pRectangle->moveAll(20, 20);
							  menu_Paste = TRUE;
						  }
						  pDoc->pRectangle->setRgn();
						  pDoc->drawing = FALSE;
						  pDoc->obj_List.AddTail(pDoc->pRectangle);
						  cutObj = pDoc->pRectangle;
						  pDoc->currentObj = cutObj;
						  break;
		}
		case text:
		{
					 YText* temp = (YText*)cutObj;
					 pDoc->pText = new YText(temp->getSPoint(), temp->getFont(), temp->getFontColor(), temp->getBkColor(), temp->getFontSize(), temp->getUnderLine(), temp->getStrikeOut(), temp->getBold(), temp->getItalic());
					 pDoc->pText->setText(temp->getText());
					 pDoc->pText->setType(text);
					 pDoc->pText->setSelect(TRUE);
					 pDoc->pText->setEPoint(temp->getEPoint());

					 CFont f;
					 LOGFONT lf;

					 if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
					 else lf.lfWeight = FW_NORMAL;
					 lf.lfWidth = 0;
					 lf.lfHeight = pDoc->pText->getFontSize();						//높이 설정
					 lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//취소선 설정
					 lf.lfUnderline = pDoc->pText->getUnderLine();						//밑줄설정
					 lf.lfItalic = pDoc->pText->getItalic();							//기울임
					 lf.lfEscapement = 0;							//기울기 각도 초기화
					 lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
					 lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
					 lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
					 lf.lfQuality = DEFAULT_QUALITY;
					 lf.lfCharSet = DEFAULT_CHARSET;
					 wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());
					 f.CreateFontIndirect(&lf);

					 pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
					 pDoc->pText->setRgn();
					 pDoc->pText->setFontColor(fontColor);

					 if (menu_CutCopyflag == FALSE){								//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
						 pDoc->pText->moveAll(20, 20);
						 menu_Paste = TRUE;
					 }
					 pDoc->textEditing = FALSE;
					 pDoc->obj_List.AddTail(pDoc->pText);
					 cutObj = pDoc->pText;
					 pDoc->currentObj = cutObj;
					 break;
		}
		case group:
		{



					  YGroup* groups = (YGroup*)cutObj;
					  CList<YObject*, YObject*>* pL = groups->getList();
					  POSITION pos = (*pL).GetHeadPosition();

					  while (pos){
						  YObject* parent = (*pL).GetNext(pos);
						  switch (parent->getType())
						  {
						  case line:
						  {
									   YLine* temp = (YLine*)parent;
									   pDoc->pLine = new YLine(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());
									   pDoc->pLine->setType(line);
									   pDoc->pLine->setSelect(FALSE);
									   if (menu_CutCopyflag == FALSE){			//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
										   pDoc->pLine->moveAll(20, 20);
										   menu_Paste = TRUE;
									   }
									   pDoc->pLine->setRgn();
									   pDoc->drawing = FALSE;
									   pDoc->current_group.AddTail(pDoc->pLine);

									   break;
						  }
						  case polyline:
						  {
										   YPolyLine* temp = (YPolyLine*)parent;
										   pDoc->pPolyLine = new YPolyLine(temp->getLineColor(), temp->getLineThick(), temp->getLinePattern());

										   POSITION pos = temp->getPolyList()->GetHeadPosition();
										   while (pos){
											   CPoint point = temp->getPolyList()->GetNext(pos);
											   pDoc->pPolyLine->addPoint(point);
											   YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
											   pDoc->allList.AddTail(polyline);
											   pDoc->temp_AllList.AddTail(polyline);
										   }
										   pDoc->pPolyLine->setType(polyline);
										   pDoc->pPolyLine->setSelect(FALSE);
										   if (menu_CutCopyflag == FALSE) {			//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
											   pDoc->pPolyLine->moveAll(20, 20);
											   menu_Paste = TRUE;
										   }
										   pDoc->pPolyLine->setRgn();
										   pDoc->drawing = FALSE;
										   pDoc->current_group.AddTail(pDoc->pPolyLine);
										   break;
						  }
						  case ellipse:
						  {

										  YEllipse* temp = (YEllipse*)parent;
										  pDoc->pEllipse = new YEllipse(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern(), temp->getSideColor(), temp->getSidePattern(), temp->getPatternflag());
										  pDoc->pEllipse->setType(ellipse);
										  pDoc->pEllipse->setSelect(FALSE);
										  if (menu_CutCopyflag == FALSE){				//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
											  pDoc->pEllipse->moveAll(20, 20);
											  menu_Paste = TRUE;
										  }
										  pDoc->pEllipse->setRgn();
										  pDoc->drawing = FALSE;
										  pDoc->current_group.AddTail(pDoc->pEllipse);
										  break;
						  }
						  case rectangle:
						  {
											YRectangle* temp = (YRectangle*)parent;
											pDoc->pRectangle = new YRectangle(temp->getSPoint(), temp->getEPoint(), temp->getLineColor(), temp->getLineThick(), temp->getLinePattern(), temp->getSideColor(), temp->getSidePattern(), temp->getPatternflag());
											pDoc->pRectangle->setType(rectangle);
											pDoc->pRectangle->setSelect(FALSE);
											if (menu_CutCopyflag == FALSE){						//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
												pDoc->pRectangle->moveAll(20, 20);
												menu_Paste = TRUE;
											}
											pDoc->pRectangle->setRgn();
											pDoc->drawing = FALSE;
											pDoc->current_group.AddTail(pDoc->pRectangle);
											break;
						  }
						  case text:
						  {
									   YText* temp = (YText*)parent;
									   pDoc->pText = new YText(temp->getSPoint(), temp->getFont(), temp->getFontColor(), temp->getBkColor(), temp->getFontSize(), temp->getUnderLine(), temp->getStrikeOut(), temp->getBold(), temp->getItalic());
									   pDoc->pText->setText(temp->getText());
									   pDoc->pText->setType(text);
									   pDoc->pText->setSelect(FALSE);
									   pDoc->pText->setEPoint(temp->getEPoint());

									   CFont f;
									   LOGFONT lf;

									   if (pDoc->pText->getBold()) lf.lfWeight = FW_BOLD;
									   else lf.lfWeight = FW_NORMAL;
									   lf.lfWidth = 0;
									   lf.lfHeight = pDoc->pText->getFontSize();						//높이 설정
									   lf.lfStrikeOut = pDoc->pText->getStrikeOut();						//취소선 설정
									   lf.lfUnderline = pDoc->pText->getUnderLine();						//밑줄설정
									   lf.lfItalic = pDoc->pText->getItalic();							//기울임
									   lf.lfEscapement = 0;							//기울기 각도 초기화
									   lf.lfOutPrecision = OUT_CHARACTER_PRECIS;
									   lf.lfClipPrecision = CLIP_CHARACTER_PRECIS;
									   lf.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
									   lf.lfQuality = DEFAULT_QUALITY;
									   lf.lfCharSet = DEFAULT_CHARSET;
									   wcscpy_s((lf.lfFaceName), _countof(lf.lfFaceName), pDoc->pText->getFont());
									   f.CreateFontIndirect(&lf);

									   pDoc->pText->setRect(pDoc->pText->getSPoint(), pDoc->pText->getEPoint());
									   pDoc->pText->setRgn();
									   pDoc->pText->setFontColor(fontColor);

									   if (menu_CutCopyflag == FALSE){								//복사하기 일때 -> 이동하고 붙여넣기 탭 활성화
										   pDoc->pText->moveAll(20, 20);
										   menu_Paste = TRUE;
									   }
									   pDoc->textEditing = FALSE;
									   pDoc->current_group.AddTail(pDoc->pText);
									   break;
						  }
						  case group:
						  {
										YObject* tmp2;
										CList<YObject*, YObject*> pgroup;
										tmp2 = cutObj;
										cutObj = parent;
										//pgroup = pDoc->current_group;
										OnEditPaste();
										cutObj = tmp2;
										break;
						  }
						  default:
							  break;
						  }
					  }

					  YGroup* newgroup = new YGroup(pDoc->current_group);
					  newgroup->setRgn();
					  newgroup->setType(group);
					  newgroup->setOrder(pDoc->allNum++);
					  newgroup->setSelect(TRUE);
					  pDoc->currentObj = newgroup;
					  pDoc->obj_List.AddTail(newgroup);
					  // 그룹화 변수 초기화
					  pDoc->current_group.RemoveAll();
					  pDoc->grouping = FALSE;

					  break;
		}
		default:
			break;
		}
		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnEditCopy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Cut = TRUE;
	menu_Copy = TRUE;
	menu_Paste = TRUE;
	menu_CutCopyflag = FALSE;
	menu_CutPaste = TRUE;
	CYPaintEditDoc* pDoc = GetDocument();

	cutObj = NULL;

	if (pDoc->currentObj != NULL){
		cutObj = pDoc->currentObj;
	}
}
void CYPaintEditView::OnUpdateEditCut(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_Cut);
}
void CYPaintEditView::OnUpdateEditPaste(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_Paste);
}
void CYPaintEditView::OnUpdateEditCopy(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_Copy);
}
void CYPaintEditView::OnEditSelectAll()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CMainFrame* main = (CMainFrame*)AfxGetMainWnd();
	CYPaintEditDoc* pDoc = GetDocument();

	CMFCRibbonButton* selectAll = (CMFCRibbonButton*)main->getRibbon()->FindByID(ID_EDIT_SELECT_ALL);
	POSITION pos = pDoc->obj_List.GetHeadPosition();
	if (!selectAll->IsFocused()){
		while (pos){
			YObject* temp = (YObject*)pDoc->obj_List.GetNext(pos);
			temp->setSelect(TRUE);
		}
		Invalidate(FALSE);
	}
}


// 마우스 우클릭 메뉴 함수들 //
void CYPaintEditView::OnEditLinecolor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN);
	int result = dlg.DoModal();
	if (result == IDOK){
		lineColor = dlg.GetColor();

		switch (pDoc->currentObj->getType()){
		case line:
		{
					 pDoc->pLine = (YLine*)pDoc->currentObj;
					 pDoc->pLine->setLineColor(lineColor);
					 YLine* line = new YLine(pDoc->pLine);
					 pDoc->allList.AddTail(line);
					 pDoc->temp_AllList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
						 pDoc->pPolyLine->setLineColor(lineColor);
						 YPolyLine* polyline = new YPolyLine(pDoc->pPolyLine);
						 pDoc->allList.AddTail(polyline);
						 pDoc->temp_AllList.AddTail(polyline);
						 break;
		}

		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setLineColor(lineColor);
						YEllipse* ellipse = new YEllipse(pDoc->pEllipse);
						pDoc->allList.AddTail(ellipse);
						pDoc->temp_AllList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineColor(lineColor);
						  YRectangle* rectangle = new YRectangle(pDoc->pRectangle);
						  pDoc->allList.AddTail(rectangle);
						  pDoc->temp_AllList.AddTail(rectangle);
						  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateEditLinecolor(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_LineColor);
}
void CYPaintEditView::OnEditFiguresetting()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	menu_Figure = FALSE;

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
				 dlg.flag = FALSE;
				 break;
	}
	case polyline:
	{
					 pDoc->pPolyLine = (YPolyLine*)pDoc->currentObj;
					 dlg.lineThick = pDoc->pPolyLine->getLineThick();
					 dlg.linePattern = pDoc->pPolyLine->getLinePattern();
					 dlg.flag = FALSE;
					 break;
	}
	case ellipse:
	{
					pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
					dlg.lineThick = pDoc->pEllipse->getLineThick();
					dlg.linePattern = pDoc->pEllipse->getLinePattern();
					dlg.flag = TRUE;
					break;
	}
	case rectangle:
	{
					  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
					  dlg.flag = TRUE;
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
						pDoc->pEllipse->setSidePattern(dlg.SidePattern);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setLineThick(dlg.lineThick);
						  pDoc->pRectangle->setLinePattern(dlg.linePattern);
						  pDoc->pRectangle->setSidePattern(dlg.SidePattern);
						  break;
		}


		default:
			break;
		}

		Invalidate(FALSE);
		UpdateMenu();
	}
}
void CYPaintEditView::OnUpdateEditFiguresetting(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_Figure);
}
void CYPaintEditView::OnEditDelete()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	POSITION pos = pDoc->obj_List.GetHeadPosition();
	POSITION tpos=NULL;
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
void CYPaintEditView::OnUpdateEditDelete(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_Delete);
}
void CYPaintEditView::OnEditDeletepoint()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	CClientDC dc(this);
	if (pDoc->deletePosition != -1) {

		if (pDoc->pPolyLine->getPolyList()->GetSize() == 2){				// 점이 2개있는데 지울려고 점을 지울려고 할때 객체를 지우고 리스트에서도 제외 시킨다.
			pDoc->pPolyLine->getPolyList()->RemoveAll();

			POSITION pos = pDoc->obj_List.GetHeadPosition();
			POSITION tpos=NULL;

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
void CYPaintEditView::OnUpdateEditDeletepoint(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_DeletePoint);
}
void CYPaintEditView::OnEditSidecolor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	CColorDialog dlg(RGB(255, 0, 0), CC_FULLOPEN);
	int result = dlg.DoModal();
	if (result == IDOK){
		sideColor = dlg.GetColor();

		switch (pDoc->currentObj->getType()){
		case ellipse:
		{
						pDoc->pEllipse = (YEllipse*)pDoc->currentObj;
						pDoc->pEllipse->setSideColor(sideColor);
						break;
		}
		case rectangle:
		{
						  pDoc->pRectangle = (YRectangle*)pDoc->currentObj;
						  pDoc->pRectangle->setSideColor(sideColor);
						  break;
		}
		default:
			break;
		}

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateEditSidecolor(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_SideColor);
}
void CYPaintEditView::OnEditgroup()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->grouping == TRUE){

		// obj_List에서 그룹화된 도형을 꺼내는 부분
		YObject* search;
		POSITION tpos;
		POSITION pos = pDoc->current_group.GetHeadPosition();
		while (pos) {
			search = pDoc->current_group.GetNext(pos);
			POSITION pos2 = pDoc->obj_List.GetHeadPosition();
			while (pos2) {
				tpos = pos2;
				pDoc->currentObj = (YObject*)pDoc->obj_List.GetNext(pos2);
				if (pDoc->currentObj->getOrder() == search->getOrder()){
					pDoc->obj_List.RemoveAt(tpos);
					break;
				}
			}
		}

		// 그룹 객체 생성 및 obj_List에 연결하는 부분
		YGroup* tgroup = new YGroup(pDoc->current_group);
		tgroup->setRgn();
		tgroup->setType(group);
		tgroup->setOrder(pDoc->allNum++);
		tgroup->setSelect(TRUE);
		pDoc->currentObj = tgroup;
		pDoc->obj_List.AddTail(tgroup);

		// 그룹화 변수 초기화
		pDoc->current_group.RemoveAll();
		pDoc->grouping = FALSE;

		Invalidate();
	}
}
void CYPaintEditView::OnUpdateEditgroup(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_Group);
}
void CYPaintEditView::OnEditdeletegroup()
{
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->currentObj->getType() == group){
		// obj_List에서 그룹의 위치를 찾는 부분
		YObject* to;
		POSITION tpos=NULL;
		POSITION pos = pDoc->obj_List.GetHeadPosition();
		while (pos){
			tpos = pos;
			to = (YObject*)pDoc->obj_List.GetNext(pos);
			if (to->getOrder() == pDoc->currentObj->getOrder())
				break;
		}

		// 그룹에서 꺼내어 obj_List에 저장하는 부분
		CList<YObject*, YObject*>* tmp = ((YGroup*)pDoc->currentObj)->getList();
		pos = tmp->GetHeadPosition();
		while (pos){
			pDoc->obj_List.AddTail(tmp->GetNext(pos));
		}

		// obj_List에서 그룹을 제거하는 부분
		pDoc->obj_List.RemoveAt(tpos);

		pDoc->currentObj = NULL;

		Invalidate(FALSE);
	}
}
void CYPaintEditView::OnUpdateEditdeletegroup(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(menu_DeleteGroup);
}


// Undo, Redo //
void CYPaintEditView::OnBack()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	POSITION pos;
	YObject* temp;
	YObject* lastObject=NULL;
	YObject* original;
	BOOL find;																		//obj_List에 같은 객체가 있는 판별하는 flag변수
	undoredoFlag = FALSE;
	pos = pDoc->allList.GetTailPosition();
	if (pDoc->currentObj == NULL){													//객체가 클릭 안되었을때 동작가능하도록 설정
		if (pos != NULL && pDoc->allList.GetSize() > 1){
			temp = (YObject*)pDoc->allList.GetTail();								//마지막꺼 지우고
			pDoc->allList.RemoveTail();

			POSITION rpos = pDoc->allList.GetTailPosition();						//마지막꺼 지우고 다시탐색
			while (rpos) {
				lastObject = (YObject*)pDoc->allList.GetPrev(rpos);
				if (temp->getOrder() == lastObject->getOrder()){
					find = TRUE;
					break;
				}
				find = FALSE;
			}
			if (find){																// order가 똑같은 것이 obj_List에 있을 경우
				POSITION opos = pDoc->obj_List.GetTailPosition();
				while (opos) {
					POSITION t;
					t = opos;
					original = (YObject*)pDoc->obj_List.GetPrev(opos);
					if (lastObject->getOrder() == original->getOrder()){
						pDoc->obj_List.SetAt(t, lastObject);
						break;
					}
				}
			}
			else {																	// 같은것이 없으면 obj_List에서 제거해 주어여한다.
				POSITION opos = pDoc->obj_List.GetTailPosition();
				while (opos) {
					POSITION t;
					t = opos;
					original = (YObject*)pDoc->obj_List.GetPrev(opos);
					if (temp->getOrder() == original->getOrder()){
						pDoc->obj_List.RemoveAt(t);
						break;
					}
				}
			}
		}
		else {
			pDoc->allList.RemoveAll();
			pDoc->obj_List.RemoveAll();
		}
		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnFrontback()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	POSITION pos;				//allList의 position
	YObject* temp;				//다시 보여질 객체를 저장할 변수
	if (!undoredoFlag){  // 뒤로가기를 했을경우에만 실행

		int count = pDoc->allList.GetSize();
		pos = pDoc->temp_AllList.GetHeadPosition();
		for (int i = 0; i < count; i++){
			pDoc->temp_AllList.GetNext(pos);
		}
		temp = (YObject*)pDoc->temp_AllList.GetNext(pos);
		switch (temp->getType()){
		case line:
		{
					 YLine* line = new YLine((YLine*)temp);
					 pDoc->allList.AddTail(line);
					 break;
		}
		case polyline:
		{
						 YPolyLine* polyline = new YPolyLine((YPolyLine*)temp);
						 pDoc->allList.AddTail(polyline);
						 break;
		}
		case ellipse:
		{
						YEllipse* ellipse = new YEllipse((YEllipse*)temp);
						pDoc->allList.AddTail(ellipse);
						break;
		}
		case rectangle:
		{
						  YRectangle* rectangle = new YRectangle((YRectangle*)temp);
						  pDoc->allList.AddTail(rectangle);
						  break;
		}
		case text:
		{
					 YText* text = new YText((YText*)temp);
					 pDoc->allList.AddTail(text);
					 break;
		}
		}
		//obj_List에 객체를 다시 추가하는 과정
		POSITION tpos = pDoc->obj_List.GetTailPosition();
		POSITION changepos;
		BOOL check = FALSE;
		while (tpos){
			changepos = tpos;
			YObject* original = (YObject*)pDoc->obj_List.GetPrev(tpos);

			if (temp->getOrder() == original->getOrder()){
				pDoc->obj_List.SetAt(changepos, temp);
				check = TRUE;
				break;
			}
		}
		if (!check){ // 탐색을 다했는데 같은 객체가 없으면 객체를 추가해주어야한다.
			pDoc->obj_List.AddTail(temp);
		}

		Invalidate(FALSE);
	}

}
void CYPaintEditView::OnUpdateBack(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();

	if (pDoc->allList.GetCount() == 0) pCmdUI->Enable(FALSE);
	else pCmdUI->Enable(TRUE);
}
void CYPaintEditView::OnUpdateFrontback(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CYPaintEditDoc* pDoc = GetDocument();
	if (pDoc->allList.GetCount() == pDoc->temp_AllList.GetCount()) pCmdUI->Enable(FALSE);
	else pCmdUI->Enable(TRUE);

}

