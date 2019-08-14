#include "stdafx.h"
#include "xuLyDS.h"
using namespace std;

int xDisplayDS[6] = { 6, 21, 48, 55, 86, 94 };

void drawTable() {
	clrscr();
	gotoxy(7, 2); cout << "DANH SACH CAC DAU SACH TRONG THU VIEN THEO THE LOAI, TEN SACH TANG DAN THEO THE LOAI";
	setHighLightColor();
	//The Loai
	drawCell(5, 20, 3, 36);
	//ten sach
	drawCell(20, 47, 3, 36);
	//ISBN
	drawCell(47, 54, 3, 36);
	//tac gia
	drawCell(54, 85, 3, 36);
	//soTR
	drawCell(85, 93, 3, 36);
	//nam XB
	drawCell(93, 100, 3, 36);
	drawCell(5, 100, 3, 5);
	setDefaultColor();
	gotoxy(6, 4); cout << "THE LOAI";
	gotoxy(21, 4); cout << "TEN SACH";
	gotoxy(48, 4); cout << "ISBN";
	gotoxy(55, 4); cout << "TAC GIA";
	gotoxy(86, 4); cout << "SO TR";
	gotoxy(94, 4); cout << "NAM XB";
	drawEditDS(110, 3);
	drawNoti(110, 24);
}
void drawEditDS(int x, int y) {
	gotoxy(x + 10, y - 1); cout << "CAP NHAT DAU SACH";
	setHighLightColor();
	drawCell(x, x + 40, y, y + 19);
	//draw ISBN frame
	drawCell(x + 10, x + 39, y + 1, y + 3);
	//draw The loai
	drawCell(x + 10, x + 39, y + 4, y + 6);
	//draw Ten sach
	drawCell(x + 10, x + 39, y + 7, y + 9);
	//draw tac gia
	drawCell(x + 10, x + 39, y + 10, y + 12);
	//draw so trang
	drawCell(x + 10, x + 39, y + 13, y + 15);
	//draw namxb
	drawCell(x + 10, x + 39, y + 16, y + 18);

	setDefaultColor();
	gotoxy(x + 1, y + 2); cout << "ISBN:";
	gotoxy(x + 1, y + 5); cout << "THE LOAI:";
	gotoxy(x + 1, y + 8); cout << "TEN SACH:";
	gotoxy(x + 1, y + 11); cout << "TAC GIA:";
	gotoxy(x + 1, y + 14); cout << "SO TRANG:";
	gotoxy(x + 1, y + 17); cout << "NAM XB:";

}
void drawNoti(int x, int y) {
	gotoxy(x + 15, y); cout << "NOTIFICATION";
	setHighLightColor();
	drawCell(x, x + 40, y + 1, y + 12);
	veNetNgang(x + 1, x + 39, y + 3);
	setDefaultColor();
	gotoxy(x + 1, y + 4); cout << "ISBN toi da 6 ky tu\n";
	gotoxy(x + 1, y + 5); cout << "THE LOAI toi da 20 ky tu\n";
	gotoxy(x + 1, y + 6); cout << "TEN SACH toi da 20 ky tu\n";
	gotoxy(x + 1, y + 7); cout << "TAC GIA toi da 20 ky tu\n";
	gotoxy(x + 1, y + 8); cout << "SO TRANG toi da 6 ky tu\n";
	gotoxy(x + 1, y + 9); cout << "Nam XB toi da 4 ky tu";
}
void showListTL(LIST_DauSach lds) {
	string listTL[100] = {};
	getTheLoai(lds, listTL);
	for (int i = 0;; i++) {
		gotoxy(xD, yD + i);
		cout << listTL[i] << endl;
		if (listTL[i] == "") break;
	}
}
string getEventKey(string strKey) {

	return strKey;
}
void clearNoti() {
	gotoxy(XTB, YTB);
	SetColor(WHITE);
	cout << setw(28) << setfill(' ') << " ";
	setDefaultColor();
}
void inputDS(LIST_DauSach &lds,pDauSach &pDS, bool isEdited) {
	hienConTro();
	dauSach ds;
	Date dateHT;
	Today(dateHT);	//temp DS
	string ISBN = "";
	string tenSach = "";
	int soTrang = 0;
	string tacGia = "";
	int namXB = 0;
	string theLoai = "";

	int x = XINPUT;
	int y = YINPUT;
	int flag = 0;
	bool isSave = false;
	bool isEsc = false;

	if (isEdited)
	{
		ISBN = pDS->info.ISBN;
		theLoai = pDS->info.theLoai;
		tenSach = pDS->info.tenSach;
		tacGia = pDS->info.tacGia;
		soTrang = pDS->info.soTrang;
		namXB = pDS->info.namXuatBan;

		gotoxy(x + 11, y + 2);
		cout << ISBN;
		gotoxy(x + 11, y + 5);
		cout << theLoai;
		gotoxy(x + 11, y + 8);
		cout << tenSach;
		gotoxy(x + 11, y + 11);
		cout << tacGia;
		gotoxy(x + 11, y + 14);
		cout << soTrang;
		gotoxy(x + 11, y + 17);
		cout << namXB;
	}
	while (true) {
		switch (flag) {
		case 0:
			//clearNoti();
			gotoxy(x + 11, y + 2);
			nhapISBN(ISBN, flag, isSave, isEsc);
			break;
		case 1:
			//clearNoti();
			gotoxy(x + 11, y + 5);
			NhapTheLoaiSach(theLoai, flag, isSave, isEsc);
			break;
		case 2:
			//clearNoti();
			gotoxy(x + 11, y + 8);
			NhapTenSach(tenSach, flag, isSave, isEsc);
			break;
		case 3:
			//clearNoti();
			gotoxy(x + 11, y + 11);
			NhapTenTacGia(tacGia, flag, isSave, isEsc);
			break;
		case 4:
			//clearNoti();
			gotoxy(x + 11, y + 14);
			nhapSoTrang(soTrang, flag, isSave, isEsc);
			break;
		case 5:
			//clearNoti();
			gotoxy(x + 11, y + 17);
			NhapNamXuatBan(namXB, flag, isSave, isEsc);
			break;
		}

		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;
			// check rong;
			if (ISBN.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "ISBN khong duoc de trong!!! ";
				setDefaultColor();
				flag = 0;
				continue;
			}
			else if (theLoai.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "The Loai khong duoc de trong!!! ";
				setDefaultColor();
				flag = 1;
				continue;
			}
			else if (tenSach.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "Ten sach khong duoc de trong!!! ";
				setDefaultColor();
				flag = 2;
				continue;
			}
			else if (tacGia.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "Tac gia khong duoc de trong!!! ";
				setDefaultColor();
				flag = 3;
				continue;
			}
			else if (soTrang == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "So trang khong duoc de trong!!! ";
				setDefaultColor();
				flag = 4;
				continue;
			}
			else if (namXB == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "Nam XB khong duoc de trong!!! ";
				setDefaultColor();
				flag = 5;
				continue;
			}
			else if (namXB > dateHT.Nam)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "NamXB khong lon hon nam hien tai!";
				setDefaultColor();
				flag = 5;
				continue;
			}

			if (SearchISBN_DS(lds, ISBN))
			{
				if (pDS->info.ISBN != ISBN)
				{
					gotoxy(XTB, YTB);
					SetColor(BLUE);
					cout << "ISBN da ton tai !";
					setDefaultColor();
					flag = 0;
					continue;
				}
			}

			// import data vao info
			ChuanHoaString(ISBN).copy(ds.ISBN, ISBN.size() + 1);
			ChuanHoaString(theLoai).copy(ds.theLoai, theLoai.size() + 1);
			ChuanHoaString(tenSach).copy(ds.tenSach, tenSach.size() + 1);
			ChuanHoaString(tacGia).copy(ds.tacGia, tacGia.size() + 1);
			ds.namXuatBan = soTrang;
			ds.soTrang = namXB;

			if (isEdited)
			{
				pDS->info = ds;
				setDefaultColor();
				return;
			}
			else
			{
				initList_DMS(pDS->dms);
				pDS->info = ds;
				int temp = Insert_DauSach(lds, pDS);
				if (temp == 0)
				{
					for (int i = 0; i < 5; i++)
					{
						SetColor(RED);
						gotoxy(XTB, YTB);
						Sleep(100);
						cout << "Bo nho day, khong the them";
					}
				}
				else {
					SetColor(RED);
					gotoxy(XTB, YTB);
					Sleep(100);
					cout << "SUCCESSFULLY !!! ";
					clearInput();
				}
				setDefaultColor();
				return;
			}
		}

		// thoat	
		if (isEsc)
		{
			return;
		}
		anConTro();
	}
}
void clearInput() {
	SetColor(WHITE);
	gotoxy(XINPUT + 11, YINPUT + 2);
	cout << setw(28) << setfill(' ') << " ";
	gotoxy(XINPUT + 11, YINPUT + 5);
	cout << setw(28) << setfill(' ') << " ";
	gotoxy(XINPUT + 11, YINPUT + 8);
	cout << setw(28) << setfill(' ') << " ";
	gotoxy(XINPUT + 11, YINPUT + 11);
	cout << setw(28) << setfill(' ') << " ";
	gotoxy(XINPUT + 11, YINPUT + 14);
	cout << setw(28) << setfill(' ') << " ";
	gotoxy(XINPUT + 11, YINPUT + 17);
	cout << setw(28) << setfill(' ') << " ";
	setDefaultColor();
}
void menuDS(LIST_DauSach &lds, pDauSach &pDS, Tree &t) {
	drawTable();
	//showListTL(lds, pDS);
	//show hot key
	gotoxy(7, yHotkey);
	SetColor(WHITE);
	cout << "HotKey:  ESC - Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F5 - Luu File, F10 - Luu, PgUP, PgDn";
	setDefaultColor();
	//==============
	
	// thu tu trang
	string listTL[100] = {};
	int sizeTL = getTheLoai(lds, listTL);
	int choose,chooseTL;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (lds.n / NUMBER_LINES) + 1;
loop:
	showListTL(lds);
	int kb_hit;
	do
	{
		chooseTL = ChooseItemsTL(lds, tttrang, tongtrang, sizeTL);
		choose = ChooseItems_DS(lds, tttrang, tongtrang,listTL[chooseTL]);
		//if (_kbhit())
		//{
		//	kb_hit = _getch();
		//	if (kb_hit == 224 || kb_hit == 0)
		//		kb_hit = _getch();
		//	switch (kb_hit)
		//	{
		//	case PAGE_UP:
		//		if (tttrang > 1) {
		//			tttrang--;
		//		}
		//		else tttrang = tongtrang;
		//		OutputDS_PerPage(lds, tttrang);
		//		break;
		//	case PAGE_DOWN:
		//		if (tttrang < tongtrang) {
		//			tttrang++;
		//		}
		//		else tttrang = 1;
		//		OutputDS_PerPage(lds, tttrang);
		//		break;

		//	case KEY_F2:
		//		pDS = new DauSach;
		//		//pDS = nullptr;
		//		if (pDS == NULL)
		//			goto loop;
		//		inputDS(lds,pDS,false);
		//		goto loop;

		//	case  KEY_F3:
		//		choose = ChooseItemsTL(lds, tttrang, tongtrang);
		//		if (choose > lds.n)
		//			goto loop;
		//		inputDS(lds, lds.nodesDauSach[choose], true);
		//		goto loop;

		//	case KEY_F4:
		//		choose = ChooseItems_DS(lds, tttrang, tongtrang);
		//		if (choose > lds.n)
		//			goto loop;
		//		if (CheckDMS(lds.nodesDauSach[choose]->dms.pHeadDMS))
		//		{
		//			gotoxy(XTB, YTB);
		//			SetColor(RED);
		//			cout << "sach dang duoc muon, khong duoc xoa!";
		//			_getch();
		//			gotoxy(XTB, YTB);
		//			setDefaultColor();
		//			cout << "                                                      ";
		//			goto loop;
		//		}

		//		Delete_DauSach(lds, choose);
		//		goto loop;
		//	case KEY_F5:
		//		SaveDS(lds);
		//		goto loop;
		//	case ESC:
		//		xuLy(lds, t);
		//		break;
		//	}
		//}
		anConTro();
		gotoxy(33, 36);
		cout << "trang " << tttrang << " / " << tongtrang;

	} while (true);
	system("pause");

}

void OutputDS_PerPage(LIST_DauSach list)
{
	//LIST_DauSach ldsTemp = getDSByTL(lDS, theLoai);
	//Xoa_OutDS_29lines();
	SetColor(WHITE);
	if (list.n == -1)
		return;
	for (int i = 0; i < list.n; i++)
	{
		Output_DS(list.nodesDauSach[i]->info,i);
	}
}
void Output_DS(dauSach ds, int viTri)
{
	anConTro();
	gotoxy(xDisplayDS[1], yD + viTri);
	cout << ds.tenSach;
	gotoxy(xDisplayDS[2], yD + viTri);
	cout << ds.ISBN;
	gotoxy(xDisplayDS[3], yD + viTri);
	cout << ds.tacGia;
	gotoxy(xDisplayDS[4], yD + viTri);
	cout << ds.soTrang;
	gotoxy(xDisplayDS[5], yD + viTri);
	cout << ds.namXuatBan;
}
void XoaMotVung(int x, int y, int ndoc, int width)
{
	for (int i = 0; i < ndoc; i++)
	{
		gotoxy(x, y + i);
		XoaMotDong(width);
	}
}
void XoaMotDong(int width)
{
	SetBGColor(BLACK);
	cout << " " << setw(width) << setfill(' ') << " ";
}
void Xoa1lineDS(int viTri)
{
	gotoxy(xDisplayDS[0] + 1, yD+viTri);
	cout << setw(13) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[1] + 1, yD + viTri);
	cout << setw(25) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[2] + 1, yD + viTri);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] + 1, yD + viTri);
	cout << setw(29) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[4] + 1, yD + viTri);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[5] + 1, yD + viTri);
	cout << setw(6) << setfill(' ') << ' ';
}

void Xoa_OutDS_29lines()
{
	for (int i = 0; i < NUMBER_LINES; i++)
	{
		Xoa1lineDS(i);
	}
}
void nhapISBN(string &ISBN, int &flag, bool &isSave, bool &isEsc) {
	hienConTro();
	cout << ISBN;
	int count = (int)ISBN.length();
	int x, y;

	while (true)
	{
		x = wherex();
		y = wherey();

		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa. 
			// chi nhap ten toi da 6 ky tu, vi tu dai nhat tieng viet chi la 6.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)) && count < MAX_ISBN)
			{
				count++;
				clearNoti();
				gotoxy(x, y);

				// chuyen qua in hoa
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				ISBN += (char)kb_hit;
				//copy(ISBN.begin(), ISBN.end(), ISBN);

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 5;
					return;
				}
				else
				{
					flag = 1;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 1;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);

				count--;
				cout << "\b" << " " << "\b";

				ISBN.erase(ISBN.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "TOI DA 6 KY TU, CHI LAY KY TU CHU !!!";
				setDefaultColor();
				gotoxy(x, y);
			}
		}
	}
}
void NhapTheLoaiSach(string &theLoai, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	cout << theLoai;
	int count = (int)theLoai.length();
	int x, y;
	int nSpace = 0;

	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
				&& count < MAX_THELOAISACH && count >= 0)
			{
				clearNoti();
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					theLoai += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					theLoai += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 0;
					return;
				}
				else
				{
					flag = 2;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 2;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				theLoai.erase(theLoai.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "TOI DA 20 KY TU, CHI LAY KY TU CHU !!!";
				setDefaultColor();
				gotoxy(x, y);
			}
		}

	}


}
void NhapTenSach(string &tenSach, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	// bien dem so chu da duoc nhap vao cho result
	cout << tenSach;
	int count = (int)tenSach.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;

	while (true)
	{

		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();

			// chi nhan chu thuong hoac  chu in hoa va dau cach va so
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)
				|| (kb_hit >= 48 && kb_hit <= 57) || kb_hit == SPACE) && count < MAX_TENSACH && count >= 0)
			{
				clearNoti();
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					tenSach += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					tenSach += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 1;
					return;
				}
				else
				{
					flag = 3;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 3;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				tenSach.erase(tenSach.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "TOI DA 20 KY TU, GOM KY TU CHU VA SO";
				setDefaultColor();
				gotoxy(x, y);
			}
		}
	}
}
void NhapTenTacGia(string &tacGia, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	// bien dem so chu da duoc nhap vao cho result
	cout << tacGia;
	int count = (int)tacGia.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;

	while (true)
	{

		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();

			// chi nhan chu thuong hoac  chu in hoa va dau cach

			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
				&& count < MAX_TENTG && count >= 0)
			{
				clearNoti();
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					tacGia += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					tacGia += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 2;
					return;
				}
				else
				{
					flag = 4;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 4;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				tacGia.erase(tacGia.length() - 1, 1);


			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "TOI DA 20 KY TU, CHI LAY KY TU CHU";
				setDefaultColor();
				gotoxy(x, y);
			}
		}

	}


}
void nhapSoTrang(int &nTrang, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	// dem so chu so
	// cout << nTrang;
	int temp = nTrang;
	int count = 0;
	int x, y;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}

	if (count)
	{
		cout << nTrang;
	}
	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57 && count < 6)
			{
				clearNoti();
				gotoxy(x, y);


				int f = kb_hit - 48;
				cout << f;
				nTrang = nTrang * 10 + (f);
				count++;
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 3;
					return;
				}
				else
				{
					flag = 5;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 5;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				nTrang /= 10;
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "KY TU SO VA CHIEU DAI <= 6";
				setDefaultColor();
				gotoxy(x, y);
			}
		}
	}


}
void NhapNamXuatBan(int &namXB, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	// dem so chu so
	int temp = namXB;
	int count = 0;
	int x, y;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}
	if (count)
	{
		cout << namXB;
	}
	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57 && count <= 3)
			{
				clearNoti();
				gotoxy(x, y);

				int f = kb_hit - 48;
				cout << f;
				namXB = namXB * 10 + (f);
				count++;
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{

					flag = 4;
					return;
				}
				else
				{
					flag = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{

				flag = 0;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				namXB /= 10;
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "KY TU SO VA CHIEU DAI <= 4";
				setDefaultColor();
				gotoxy(x, y);
			}
		}
	}
}
int ChooseItems_DS(LIST_DauSach &lDS, int &tttrang, int tongtrang,string theLoai)
{
	Xoa_OutDS_29lines();
	LIST_DauSach list = getDSByTL(lDS, theLoai);
	OutputDS_PerPage(list);
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(YELLOW);
	gotoxy(xD + 15, yD + pos);
	cout << "<<";
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				// xoa muc truoc
				gotoxy(xD - 2, yD + pos);
				cout << "  ";
				(pos > 0) ? pos-- : pos = 29;

				// to mau muc moi
				gotoxy(xD - 2, yD + pos);
				cout << "<<";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(xD - 2, yD + pos);
				cout << "  ";
				(pos < 29) ? pos++ : pos = 0;

				// to mau muc moi
				gotoxy(xD - 2, yD  + pos);
				cout << "<<";
				break;

			case PAGE_UP:
				if (tttrang > 1)
				{
					tttrang--;
				}
				else
				{
					tttrang = tongtrang;
				}
				Xoa_OutDS_29lines();
				OutputDS_PerPage(lDS);
				pos = 0;
				SetColor(YELLOW);
				gotoxy(xD - 2, yD  + pos);
				cout << "<<";
				break;

			case PAGE_DOWN:
				if (tttrang < tongtrang)
				{
					tttrang++;
				}
				else
				{
					tttrang = 1;
				}
				Xoa_OutDS_29lines();
				OutputDS_PerPage(lDS);
				pos = 0;
				SetColor(YELLOW);
				gotoxy(xD - 2, yD + pos);
				cout << "<<";
				break;

			case ENTER:
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
			case ESC:
				return -1;
			}
		}
		anConTro();
		SetColor(WHITE);
		gotoxy(33, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
		setDefaultColor();
	}
}
int ChooseItemsTL(LIST_DauSach LTL, int &tttrang, int tongtrang,int sizeTL)
{
	int sizeOfList = sizeTL;
	int pos = 0;
	int kb_hit;
	SetColor(YELLOW);
	gotoxy(xD - 3, yD + pos);
	cout << "<<";
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				// xoa muc truoc
				gotoxy(xD - 3, yD + pos);
				cout << "  ";
				(pos > 0) ? pos-- : pos = sizeOfList - 1;

				// to mau muc moi
				gotoxy(xD - 3, yD + pos);
				cout << "<<";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(xD - 3, yD + pos);
				cout << "  ";
				(pos < sizeOfList - 1) ? pos++ : pos = 0;

				// to mau muc moi
				gotoxy(xD - 3, yD + pos);
				cout << "<<";
				break;

			case PAGE_UP:
				if (tttrang > 1)
				{
					tttrang--;
				}
				else
				{
					tttrang = tongtrang;
				}
				Xoa_OutDS_29lines();
//				OutputDS_PerPage(lds,);
				pos = 0;
				SetColor(YELLOW);
				gotoxy(xD - 3, yD + pos);
				cout << "<<";
				break;

			case PAGE_DOWN:
				if (tttrang < tongtrang)
				{
					tttrang++;
				}
				else
				{
					tttrang = 1;
				}
				Xoa_OutDS_29lines();
	//			OutputDS_PerPage(lds, tttrang);
				pos = 0;
				SetColor(YELLOW);
				gotoxy(xD - 3, yD + pos);
				cout << "<<";
				break;

			case ENTER:
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
			case ESC:
				return sizeOfList;
			}
		}
		anConTro();
		SetColor(WHITE);
		gotoxy(33, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
		setDefaultColor();
	}
}