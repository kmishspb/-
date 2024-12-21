//---------------------------------------------------------------------------
#define MAX_BOCHKA_COUNT 1000
#include <vcl.h>
#pragma hdrstop
#include <limits>
#include "visual_f.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TVisualForm *VisualForm;
 extern int NBEER;   //счетчик обьектов в массиве на пока
extern StorageItem** storageArray;    //массив указателей на базовый класс
int triangles=0;
int startX;
int startY;
bool itGen=false;
PantBox * pb;
TCanvas * cnv;
//---------------------------------------------------------------------------
__fastcall TVisualForm::TVisualForm(TComponent* Owner)
	: TForm(Owner)
{
	srand(time(NULL));
	cnv=ext_pb->Canvas;
	pb=new PantBox(cnv);
	cellSize = ext_pb->Width / 16; // Размер ячейки
	labelOffset = 0; // Отступ для меток
	itemSize = 0.6 * cellSize; // Размер объекта внутри ячейки

}
//---------------------------------------------------------------------------





void __fastcall TVisualForm::DrawLegend(TObject *Sender)
{  TCanvas *canvas = legend_pb->Canvas;

	TCanvas *c=legend_pb->Canvas;
	c->Brush->Color=clWhite;
	TRect r(0,0,legend_pb->Width,legend_pb->Height);
	c->FillRect(r);

	double yo=((TPaintBox*)Sender)->Width/20;

	PaPoint p0 (0,10);
	PaPoint p1 (0,10);
	PaPoint p2 (0,10);
	PaPoint p3 (1,10);

	c->Rectangle (yo,legend_pb->Height-yo,legend_pb->Width-yo,yo);



	canvas->TextOut(9*yo, 2*yo, L"Легенда");

PaPoint triangleP1(6*yo, 27*yo);
PaPoint triangleP2(6*yo, 29*yo);
PaPoint triangleP3(8*yo, 29*yo);
canvas->MoveTo(triangleP1.x, triangleP1.y);
canvas->LineTo(triangleP2.x, triangleP2.y);
canvas->LineTo(triangleP3.x, triangleP3.y);
canvas->LineTo(triangleP1.x, triangleP1.y);
canvas->TextOut(9*yo, 28*yo, L"Препятствие");



PaPoint STopL(6*yo, 11*yo);
PaPoint SBottomR(8*yo, 13*yo);
c->Rectangle(STopL.x, STopL.y, SBottomR.x, SBottomR.y);
canvas->TextOut(9*yo, 12*yo, L"Коробка");


PaPoint CTopL(6*yo, 15*yo);
PaPoint CBottomR(8*yo, 17*yo);
c->Ellipse(CTopL.x, CTopL.y, CBottomR.x, CBottomR.y);
canvas->TextOut(9*yo, 16*yo, L"Бочка");

// Крестик с подписью
PaPoint crossStart(6*yo, 19*yo);
PaPoint crossEnd(8*yo, 21*yo);
canvas->MoveTo(crossStart.x, crossStart.y);
canvas->LineTo(crossEnd.x, crossEnd.y);
canvas->MoveTo(crossStart.x, crossEnd.y);
canvas->LineTo(crossEnd.x, crossStart.y);
canvas->TextOut(9*yo, 20*yo, L"Поддон");

// Квадрат с крестиком и подписью
PaPoint SCrossTopL(6*yo, 23*yo);
PaPoint SCrossBottomR(8*yo, 25*yo);
c->Rectangle(SCrossTopL.x, SCrossTopL.y, SCrossBottomR.x, SCrossBottomR.y);
canvas->MoveTo(SCrossTopL.x, SCrossTopL.y);
canvas->LineTo(SCrossBottomR.x, SCrossBottomR.y);
canvas->MoveTo(SCrossTopL.x, SCrossBottomR.y);
canvas->LineTo(SCrossBottomR.x, SCrossTopL.y);
canvas->TextOut(9*yo, 24*yo, L"Погрузчик");



}
//---------------------------------------------------------------------------

	bool  isUnique(int randomItem, PantBox* pantBox) {
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (pantBox->cells[i][j]->getItem() == randomItem) {
					return false;
				}
			}
		}
		return true;
	}


 void fillField(PantBox* &pantBox, int numTriangles) {
	int availableItems[] = {0, 1, 2, 3, 4}; // 0 - квадрат, 1 - круг, 2 - крестик, 3 - квадрат с крестиком, 4 - треугольник
	int numAvailableItems = sizeof(availableItems) / sizeof(availableItems[0]);
	 int row;
	 int col;
	// Заполняем 4 клетки разными типами
	for (int i = 0; i < 4; i++) {
		int randomItemIndex;
		int randomItem;

		bool isUniqueItem = false;

		while (!isUniqueItem) {
			randomItemIndex = rand() % numAvailableItems;
			randomItem = availableItems[randomItemIndex];
			row = rand() % ROWS;
			col = rand() % COLS;
			if(pantBox->cells[row][col]->isOccupied) continue;
			if (randomItem != 4) {
				if (isUnique(randomItem, pantBox))
				{
					isUniqueItem = true;
					pantBox->cells[row][col]->setItem( randomItem);
					pantBox->cells[row][col]->isOccupied = true; // Установка флага isOccupied
				if(randomItem	==3)
				{
				  startX=col;
				  startY=row;
				}
				}
			}
		}

	}

	for(int i = 0; i < numTriangles; i++) {
		row = rand() % ROWS;
		col = rand() % COLS;
		if(pantBox->cells[row][col]->isOccupied) {
			i--;
			continue;
		}
		pantBox->cells[row][col]->setItem (4);
		pantBox->cells[row][col]->isOccupied = true; // Установка флага isOccupied для треугольника
	}

}







void __fastcall TVisualForm::DrawField(TObject *Sender)
{



	// Рисуем элементы на холсте
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pb->cells[i][j]->draw(cnv, j * cellSize, i * cellSize, cellSize, labelOffset, itemSize);
		}
	}


}


//---------------------------------------------------------------------------


void Cell::draw(TCanvas* canvas, int x, int y, int cellSize, int labelOffset, int itemSize)
	 {

int triangleOffset = (cellSize - itemSize) / 2; // Сдвиг треугольника, чтобы он был в центре ячейки

// Вершины треугольника
int triangleTopX = x + triangleOffset;
int triangleTopY = y + triangleOffset;
int triangleBottomRightX = x + triangleOffset + itemSize;
int triangleBottomRightY = y + triangleOffset + itemSize;



	if (isOccupied) {
		switch (item) {
			case 0: // Квадрат
				canvas->Rectangle(x + (cellSize - itemSize) / 2, y + (cellSize - itemSize) / 2, x + (cellSize + itemSize) / 2, y + (cellSize + itemSize) / 2);

				break;
			case 1: // Круг
				canvas->Ellipse(x + (cellSize - itemSize) / 2, y + (cellSize - itemSize) / 2, x + (cellSize + itemSize) / 2, y + (cellSize + itemSize) / 2);

				break;
			case 2: // Крестик
				canvas->MoveTo(x + (cellSize - itemSize) / 2, y + (cellSize - itemSize) / 2);
				canvas->LineTo(x + (cellSize + itemSize) / 2, y + (cellSize + itemSize) / 2);
				canvas->MoveTo(x + (cellSize - itemSize) / 2, y + (cellSize + itemSize) / 2);
				canvas->LineTo(x + (cellSize + itemSize) / 2, y + (cellSize - itemSize) / 2);

				break;
			case 3: // Квадрат с крестиком
				canvas->Rectangle(x + (cellSize - itemSize) / 2, y + (cellSize - itemSize) / 2, x + (cellSize + itemSize) / 2, y + (cellSize + itemSize) / 2);
				canvas->MoveTo(x + (cellSize - itemSize) / 2, y + (cellSize - itemSize) / 2);
				canvas->LineTo(x + (cellSize + itemSize) / 2, y + (cellSize + itemSize) / 2);
				canvas->MoveTo(x + (cellSize - itemSize) / 2, y + (cellSize + itemSize) / 2);
				canvas->LineTo(x + (cellSize + itemSize) / 2, y + (cellSize - itemSize) / 2);
				 break;
	case 4: // Прямоугольный треугольник в центре ячейки




	// Рисуем прямоугольный треугольник
	canvas->MoveTo(triangleTopX, triangleTopY);
	canvas->LineTo(triangleTopX, triangleBottomRightY);
	canvas->LineTo(triangleBottomRightX, triangleBottomRightY);
	canvas->LineTo(triangleTopX, triangleTopY);
	break;
	default:
	// Ничего не рисуем, так как нет предмета
	break;
		}
	}        }


template <typename T>
double calculateDistance(T& item1, T& item2) {
	return std::sqrt(std::pow(item1.placing[0] - item2.placing[0], 2) + std::pow(item1.placing[1] - item2.placing[1], 2));
}

template <typename T>
T findNearestNeighbor(T& currentBochka, T** remainingBochki, int numBochki, bool* visited) {
	double minDistance = std::numeric_limits<double>::max();
	T nearestBochka;
	int nearestIndex = -1;

	for (int i = 0; i < numBochki; i++) {
		if (visited[i] || remainingBochki[i]->placing[0] == currentBochka.placing[0] && remainingBochki[i]->placing[1] == currentBochka.placing[1]) {
			continue; // Пропускаем уже посещенные элементы
		}

		double distance = calculateDistance(currentBochka, *remainingBochki[i]);

		if (distance < minDistance) {
			minDistance = distance;
			nearestBochka = *remainingBochki[i];
			nearestIndex = i;
		}
	}

	visited[nearestIndex] = true;

	return nearestBochka;
}


template <typename T>
void processItems(StorageItem** STA, int NBEER) {

	using ItemType = T; // Внутренний тип данных, соответствующий типу T
	int bochkiCount = 0;
	ItemType** bochki = new ItemType*[NBEER];
	bool* visited = new bool[NBEER]{false};

	for (int i = 0; i < NBEER; i++) {
		T* bochkaPtr = dynamic_cast<T*>(STA[i]);
		if (bochkaPtr) {
			bochki[bochkiCount] = bochkaPtr;
			bochkiCount++;
		}
	}

	T startBochka = *bochki[0];
	T currentBochka = startBochka;
	visited[0] = true;
		 AnsiString item0Text = startBochka.productname + IntToStr(0) + ": (" + IntToStr(startBochka.placing[0]) + ", " + IntToStr(startBochka.placing[1]) + ")";
	 TListItem* item0 = VisualForm->InventoryV->Items->Add();
			item0->Caption = item0Text;
	for (int i = 1; i < bochkiCount; i++) {
		T nearestBochka = findNearestNeighbor(currentBochka, bochki, bochkiCount, visited);

			AnsiString itemText = nearestBochka.productname + IntToStr(i) + ": (" + IntToStr(nearestBochka.placing[0]) + ", " + IntToStr(nearestBochka.placing[1]) + ")";
			TListItem* item =VisualForm-> InventoryV->Items->Add();
			item->Caption = itemText;

		currentBochka = nearestBochka;
	}

	delete[] bochki;

	delete[] visited;

}


void __fastcall TVisualForm::Invent(TObject *Sender)
{
	if(!NBEER) return;

   VisualForm->InventoryV->Clear();

   switch (ComboBox1->ItemIndex) {
	case 0:
	   processItems<Bochka>(storageArray, NBEER);
		break;
	case 1:
		processItems<Poddon>(storageArray, NBEER);
		break;
	case 2:
	processItems<Corob>(storageArray, NBEER);
		break;
	default: return;
}


}



void __fastcall TVisualForm::Startin(TObject *Sender, System::WideChar &Key)
{
	if (Key == 13) // Если нажата клавиша Enter
	{
		if( (StrToInt( OkParty->Text)>=0) && (StrToInt( OkParty->Text)<=21) )
		{
			triangles = StrToInt( OkParty->Text);
			pb->SetPantBox();
			fillField(pb, triangles);
			(ext_pb)->Repaint();
			itGen=true;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TVisualForm::FormClose(TObject *Sender, TCloseAction &Action)
{
//delete pb;
}





void __fastcall TVisualForm::Button1Click(TObject *Sender)
{
	if(!itGen) return;
    if (startY - 1 >= 0) {
		if (pb->cells[(startY - 1)][startX]->getItem() != 4) {
			pb->cells[ startY][startX]->setItem(-1);
			startY--;
            pb->cells[startY][startX]->setItem(3);
        }
    }

    VisualForm->ext_pb->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TVisualForm::Button4Click(TObject *Sender)
{
	if(!itGen) return;
	if((startY+1<=4))
	{
	if((pb->cells[startY+1][startX]->getItem()!=4))
	{ pb->cells[startY][startX]->setItem(-1);	startY++;   pb->cells[startY][startX]->setItem(3);
	ext_pb->Repaint();
	}
	}

}

//---------------------------------------------------------------------------

void __fastcall TVisualForm::Button3Click(TObject *Sender)
{
	if(!itGen) return;
	if((startX-1>=0))
	{
	if((pb->cells[startY][startX-1]->getItem()!=4))
	{pb->cells[startY][startX]->setItem(-1); startX--; pb->cells[startY][startX]->setItem(3); }
	ext_pb->Repaint();
	}
	}

//---------------------------------------------------------------------------

void __fastcall TVisualForm::Button2Click(TObject *Sender)
{
	if(!itGen) return;
	if((startX+1<ROWS))
	{
	if((pb->cells[startY][startX+1]->getItem()!=4))
	{pb->cells[startY][startX]->setItem(-1);	startX++; pb->cells[startY][startX]->setItem(3);}
	ext_pb->Repaint();
	}
}

//---------------------------------------------------------------------------

