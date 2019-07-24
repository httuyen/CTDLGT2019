#include "stdafx.h"
#include "DauSach.h"

void initList_DMS(LIST_DMS &l)
{
	l.n = 0;
	l.pHeadDMS = l.pTailDMS = nullptr;
}
void AddTailList_DMS(LIST_DMS &l, DMS data)
{
	// tao Node
	NODE_DMS *p = GetNode_DMS(data);
	if (l.pHeadDMS == nullptr) {
		l.pHeadDMS = l.pTailDMS = p;
	}
	else
	{
		l.pTailDMS->pNext = p;
		l.pTailDMS = p;
	}
	l.n++;
}

NODE_DMS* GetNode_DMS(DMS DATA)
{
	NODE_DMS *p = new NODE_DMS;
	if (p == nullptr) {
		return nullptr;
	}
	p->data = DATA;
	p->pNext = nullptr;
	return (p);
}
int Full_DauSach(LIST_DauSach  l)
{
	return l.n == MAX_DAUSACH;
}
void initDS(dauSach &ds) {
	ds.ISBN[6] = {};
	ds.namXuatBan = NULL;
	ds.soTrang = NULL;
	ds.tacGia = "";
	ds.tenSach = "";
	ds.theLoai = "";
}
void initListDS(LIST_DauSach &lds) {
	
	lds.n = 0;
	initList_DMS(lds.nodesDauSach[0]->dms);
	lds.nodesDauSach[0]->dms.pHeadDMS = lds.nodesDauSach[0]->dms.pTailDMS = nullptr;
}
pDauSach searchTen_DS(LIST_DauSach lds, string theLoai){
	pDauSach temp = NULL;
	for (int i = 0; i <= lds.n; i++)
	{
		temp = lds.nodesDauSach[i];
		if (temp->info.tenSach == theLoai)
			return temp;
	}
	return NULL;
}
int Insert_DauSach(LIST_DauSach &lds, pDauSach &pDS)
{
	if (Full_DauSach(lds))
	{
		return 0;
	}
	lds.nodesDauSach[lds.n++] = pDS;
	return 1;
}