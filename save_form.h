//---------------------------------------------------------------------------
#include <regex>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#ifndef save_formH
#define save_formH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
 #include "Main_f.h"

class StorageItem;
class Bochka;
class Poddon;
class Corob;

class TSaveForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *DataPan;
	TRadioGroup *type_grp;
	TEdit *zak_ed;
	TEdit *prod_ed;
	TLabel *prdlbl;
	TLabel *Label2;
	TPaintBox *type_pb;
	TEdit *spot_ed;
	TLabel *llbl;
	TLabel *Label1;
	TLabel *okey;
	TEdit *Par1;
	TEdit *Par2;
	TEdit *Par3;
	TEdit *Par4;
	TEdit *Par5;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TComboBox *ComboPar5;
	TButton *GoBTN;

	void __fastcall TupePaint(TObject *Sender);
	void __fastcall Reapint(TObject *Sender);
	void __fastcall Filters_Ok(TObject *Sender, System::WideChar &Key);
	void __fastcall Close_Re(TObject *Sender);
	void __fastcall Close_ReF(TObject *Sender, TCloseAction &Action);
	void __fastcall SaveBTN(TObject *Sender);

private: void CleaningR();	// User declarations
		 void SetItems(StorageItem* STI);
		 bool areBothNumbersWritten(TEdit* edit);

public:		// User declarations
	__fastcall TSaveForm(TComponent* Owner);
	void ObjSaving(int flag, StorageItem ** (&Ed), int (&n_),int positioning=-1);
	void copyStorageItemsArray(StorageItem** &sourceArray, StorageItem** &destinationArray, int size,int exeption=-1);
};


//---------------------------------------------------------------------------
extern PACKAGE TSaveForm *SaveForm;
//---------------------------------------------------------------------------
#endif
