#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// YFigureDialog 대화 상자입니다.

class YFigureDialog : public CDialog
{
	DECLARE_DYNAMIC(YFigureDialog)

public:
	YFigureDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~YFigureDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	BOOL flag;
	CSpinButtonCtrl thick;
	CComboBox patternIndex;
	CComboBox SidePatternIndex;
	int linePattern;
	int SidePattern;
	int lineThick;

	
	virtual BOOL OnInitDialog();
};
