//---------------------------------------------------------------------------
#ifndef Main_fH
#define Main_fH
#define MY_PI 3.14
#define MINPAY 100
#define PARTYSIZE 5
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "visual_f.h"
#include "save_form.h"
#include <Vcl.Dialogs.hpp>
#include <Vcl.ActnPopup.hpp>
#include <Vcl.Menus.hpp>
#include <string.h>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
#include <fstream>
#include <cstdio>
enum FragilityLevel
{
	NOT_FRAGILE,
	FRAGILE,
	HIGHLY_FRAGILE

};

FragilityLevel IntToFrag(int a)
{
    switch(a)
    {
        case 0: return NOT_FRAGILE;
        case 1: return FRAGILE;
        case 2: return HIGHLY_FRAGILE;
        default: return NOT_FRAGILE; // Обработка некорректного значения a
    }
}
//---------------------------------------------------------------------------

struct DateM
{
	unsigned short day;
	unsigned short month;
    unsigned short year;
};

class  StorageItem
{
	protected:
	int party;
	double ves;
	double zena;

	public:
	int vremya;
	AnsiString  productname;
	AnsiString  zacaz;
	int placing[2];
	virtual ~StorageItem() {} // Виртуальный деструктор
	virtual void CostSaving()=0;
	 AnsiString getProductName(){return productname;}
	virtual void FindCol() =0;
	int getparty(){return (party);}
	 void SetParty(int a){party=a/5;}
	 int* getPlacing() {
        return placing;
    }


virtual void WritingInFile( FILE* file)
{
	fprintf(file, "%s\n", productname.c_str());
	fprintf(file, "%s\n", zacaz.c_str());
	fprintf(file, "%d %d\n", placing[0], placing[1]);
}


virtual void ReadingFromFile(FILE* file) ;

	int getParty()			{return party;}

	AnsiString getProductname()	{return productname;}

	AnsiString getZacaz()	{return zacaz;}

	int getPlacing(int index)
	{
		if (index >= 0 && index < 2)
		{
			return placing[index];
		}
		return -1; // Возвращаем ошибку или значение по умолчанию
	}

	double getVes()			{return ves;}

	double getZena()		{return zena;}

	virtual void setVremya () {}

};


class Bochka : public StorageItem
{
	private :

	public:

	double osoby;
	double colvo;
	double Brad;
	double Bheight;
	double plotn;
    Bochka()  {}
    Bochka(int x, int y) {
    placing[0] = x;
    placing[1] = y;
}
	~Bochka() = default;
	Bochka(int party, AnsiString productname, AnsiString zacaz, int placing[2],double osoby, double Brad, double Bheight, double plotn);
	Bochka(FILE* file);
	void FindCol()    override
	{
	  colvo=Brad*Brad*MY_PI*Bheight;
	  ves=colvo*plotn;
	}

	void CostSaving() override    ;

	void WritingInFile(FILE* file) override    ;

	double getOsoby()	{return osoby;}

	double getColvo()	{return colvo;}

	double getBrad()	{return Brad;}

	double getBheight()	{return Bheight;}

	double getPlotn()	{return plotn;}

	void setVremya () override
	 {vremya=Brad*Brad*MY_PI/24+1;}
};

class Poddon :  public StorageItem
{
	private:

	public:

	int dlinna;
	int shir;
	int shtuk;
	double pogony;
	int osoby;
	double colvo;

	Poddon(){}
	~Poddon() = default;
	Poddon(int party, AnsiString productname, AnsiString zacaz, int placing[2],  int dlinna, int shir, int shtuk, double pogony, int osoby);
	Poddon(FILE* file);

	int getDlinna()	{return dlinna;}

	int getShir()		{return shir;}

	int getShtuk()		{return shtuk;}

	double getPogony()	{return pogony;}

	int getOsoby()		{return osoby;}

	double getColvo()	{return colvo;}

	void FindCol()   override
	{
		colvo=(shir+shtuk+dlinna)/3;
		ves=pogony*colvo;
	}

	void CostSaving() override    ;

	void WritingInFile(FILE* file) override    ;

	void setVremya () override
	 {vremya=(shir+shtuk+dlinna)/(3*24)+1;}

};

class Corob : public StorageItem
{
	private:

	public:
	int width;
	int height;
	int depth;
	FragilityLevel osoby;
	int colvo;
	int numBoxes;

	Corob(){}
	~Corob() = default;
	Corob(FILE* file);
	Corob(int party, AnsiString productname, AnsiString zacaz, int placing[2],  int width, int height, int depth, FragilityLevel osoby,  int numBoxes);


	int getWidth()				{return width;}

	int getHeight()				{return height;}

	int getDepth()				{return depth;}

	FragilityLevel getOsoby()	{return osoby;}

	int getColvo()				{return colvo;}

	int getNumBoxes()			{return numBoxes;}


	void FindCol()    override
	{
		colvo = width * height * depth * numBoxes;

		ves=colvo;
	}

		void CostSaving() override    ;

	void WritingInFile(FILE* file) override    ;

    	void setVremya () override
	 {vremya=width * height * depth * numBoxes/24+1;}

};

class TMainStorageForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *main_panel_c;
	TPanel *main_panel_top;
	TPanel *main_panel_bot;
	TButton *vis_b;
	TButton *reed_b;
	TButton *save_b;
	TPageControl *pg_ctr_main;
	TTabSheet *tovar_sh;
	TTabSheet *player;
	TListView *main_lv_tov;
	TPanel *main_pan_tov;
	TEdit *main_tov_fn;
	TLabel *main_tov_fnd_lb;
	TSplitter *Splitter1;
	TButton *main_tov_sort_btn;
	TPanel *Personal_panel;
	TListView *chat_lv;
	TEdit *name_fl;
	TEdit *text_fl;
	TButton *Button1;
	TLabel *Label2;
	TLabel *Сообщение;
	TLabel *Label3;
	TEdit *log_ed;
	TTimer *load_chat_t;
	TButton *close_btn;
	TButton *sort_flag;
	TComboBox *sort_combo;
	TPopupActionBar *popup_menu;
	TButton *Button2;
	TEdit *log_edO;
	TLabel *Label1;
	TOpenDialog *OpenDialog1;
	TButton *Button3;
	TTabSheet *alcoritm;
	TListView *ListView1;
	TButton *Button4;
	TEdit *Edit1;
	TButton *Button5;
	void __fastcall ClFindS(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ClFindUNSHIFT(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall VisualFormActive(TObject *Sender);
	void __fastcall SaveActive(TObject *Sender);
	void __fastcall AddChat(TObject *Sender);
	void __fastcall ChatLoad(TObject *Sender);
	void __fastcall Closing(TObject *Sender);
	void __fastcall FindActive(TObject *Sender);
	void __fastcall FindExit(TObject *Sender);
	void __fastcall SortType(TObject *Sender);
	void __fastcall MainPanResize(TObject *Sender);

    //подменю
	void __fastcall NewItem(TObject *Sender);
	void __fastcall Redacted(TObject *Sender);
	void __fastcall PopDel(TObject *Sender) ;
	void __fastcall ReChat(TObject *Sender);
	void __fastcall LetsShow(TObject *Sender);
	void __fastcall reed_bClick(TObject *Sender);
	void __fastcall Sortyrovka(TObject *Sender);
	void __fastcall Fresh(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button5Click(TObject *Sender);

private:

	void ArrayClear(); 	// User declarations

public:

	String log;	// User declarations
	__fastcall TMainStorageForm(TComponent* Owner);
   __fastcall ~TMainStorageForm();
};



void WriteStorageItemsToFile(const char* filename, StorageItem* items, int numItems) {
	FILE* file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < numItems; i++) {
            items[i].WritingInFile(file);
        }
        fclose(file);
    } else {
        return;
    }
}

bool compareByZena( StorageItem* a,  StorageItem* b, bool ascending) {
    if (ascending) {
        return a->getZena() < b->getZena();
    } else {
        return a->getZena() > b->getZena();
    }
}

bool compareByProductName( StorageItem* a,  StorageItem* b, bool ascending) {
    if (ascending) {
        return a->getProductName() < b->getProductName();
    } else {
        return a->getProductName() > b->getProductName();
    }
}
void shellSortByZena(StorageItem** arr, int size, bool ascending) ;
void shellSortByProductName(StorageItem** arr, int size, bool ascending);
void moveItemToStart(StorageItem* arr[], int size, StorageItem* item) ;
StorageItem* binarySearch(StorageItem* arr[], int size, AnsiString key, bool ascending);
StorageItem* linearSearch(StorageItem* arr[], int size, AnsiString key);
void GetUniqueZacazValues(StorageItem* storageItems[], int zize,AnsiString uniqueZacazValues,int& uniqueCount);
void findPtime(StorageItem** storageItems, int size, int* partyset);
//---------------------------------------------------------------------------
 extern PACKAGE TMainStorageForm *MainStorageForm;
//---------------------------------------------------------------------------
#endif


