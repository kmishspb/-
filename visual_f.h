//---------------------------------------------------------------------------
#define COLS 5
#define ROWS 5
#define CELLSIZE 50
#ifndef visual_fH
#define visual_fH
#define INF 100000
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "Main_f.h"
//---------------------------------------------------------------------------

class Cell;
class PantBox;
class StorageItem;
class Bochka;
class Poddon;
class Corob;

class Cell {
private:


public:
		int item;  // 0 - квадрат, 1 - круг, 2 - крестик, 3 - квадрат с крестиком 4 - треугольник

	Cell() : isOccupied(false), item(-1) {}
	bool isOccupied;

	void setItem(int newItem)
	{
		item = newItem;
		if(item!=-1)
		isOccupied=true;
		if(item==-1)
        isOccupied=false;
	}

	void draw(TCanvas* canvas, int x, int y, int cellSize, int labelOffset, int itemSize)   ;

    int getItem() {return item;}
};

const int numRows = COLS; //  оличество строк
const int numCols = ROWS; //  оличество столбцов
const int cellSize = CELLSIZE; // –азмер €чейки


class PantBox {

public:


  Cell* cells[COLS][COLS]; // ћассив указателей на €чейки

	TCanvas* canvas; // ”казатель на холст дл€ рисовани€

PantBox(TCanvas* cnv) : canvas(cnv)
{
    // ќсвобождаем предыдущие объекты €чеек, если они были созданы ранее
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (cells[i][j] != nullptr) {
                delete cells[i][j];
                cells[i][j] = nullptr;
            }
        }
    }

    // —оздаем новые объекты €чеек
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < COLS; j++) {
            cells[i][j] = new Cell();
        }
    }
}

void SetPantBox()
{
    // ќсвобождаем предыдущие объекты €чеек, если они были созданы ранее
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (cells[i][j] != nullptr) {
                delete cells[i][j];
                cells[i][j] = nullptr;
            }
        }
    }

    // —оздаем новые объекты €чеек
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < COLS; j++) {
            cells[i][j] = new Cell();
        }
    }
}





	void ClearPantBox() {
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				delete cells[i][j]; // ”дал€ем каждую €чейку
			}
		}
	}



};


class TVisualForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *paint_pn;
	TPageControl *paint_ctrl;
	TTabSheet *inv_z;
	TPanel *Inventory;
	TPanel *InventoryControl;
	TLabel *Label1;
	TLabel *Label2;
	TButton *StartBtn;
	TComboBox *ComboBox1;
	TListView *InventoryV;
	TTabSheet *ent_ext;
	TPanel *prim_pan;
	TPaintBox *legend_pb;
	  TPaintBox *ext_pb;
	TPanel *jap1;
	TLabel *Label3;
	TEdit *OkParty;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	void __fastcall DrawLegend(TObject *Sender);
	void __fastcall DrawField(TObject *Sender);
	void __fastcall Invent(TObject *Sender);
	void __fastcall Startin(TObject *Sender, System::WideChar &Key);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);



private:
public:


	int cellSize;
	int labelOffset;
	int itemSize;



	__fastcall TVisualForm(TComponent* Owner);
};

class PaPoint
{



	public:
	float x; float y;
	PaPoint(float X, float Y)
	{
		x=X;
		y=Y;
	}
};

template <typename T>
double calculateDistance(T& item1, T& item2);
template <typename T>
T findNearestNeighbor(T& currentBochka, T** remainingBochki, int numBochki, bool* visited);
template <typename T>
void processItems(StorageItem** STA, int NBEER);
	bool  isUnique(int randomItem, PantBox*pantBox) ;
   void fillField(PantBox*& pantBox, int numTriangles);


extern PACKAGE TVisualForm *VisualForm;

//---------------------------------------------------------------------------
#endif
