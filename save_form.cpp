#include <vcl.h>
#pragma hdrstop
#include "save_form.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TSaveForm *SaveForm;
extern int NBEER;   //счетчик обьектов в массиве на пока
extern StorageItem** storageArray;    //массив указателей на базовый класс
extern int typeofp;
extern bool isSorted;

__fastcall TSaveForm::TSaveForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TSaveForm::TupePaint(TObject *Sender)
{
	int centerX = type_pb->Width / 2;
	int centerY = type_pb->Height / 2;
	TCanvas* canvas = type_pb->Canvas;
 if(    type_grp->ItemIndex==0)
   {


	// Размер крестика
	int crossSize = type_pb->Width/8;

// Рисование первой наклонной линии
	canvas->MoveTo(centerX - crossSize, centerY - crossSize);
	canvas->LineTo(centerX + crossSize, centerY + crossSize);

	// Рисование второй наклонной линии
	canvas->MoveTo(centerX - crossSize, centerY + crossSize);
	canvas->LineTo(centerX + crossSize, centerY - crossSize);
	}
 if(type_grp->ItemIndex==1)
 {
	  int circleRadius = type_pb->Width/8;

	// Рисование круга в центре PaintBox
	canvas->Ellipse(centerX - circleRadius, centerY - circleRadius, centerX + circleRadius, centerY + circleRadius);
 }
 if( type_grp->ItemIndex==2)
			{
 int squareSize=   type_pb->Width/4;
	canvas->Rectangle(centerX - squareSize/2, centerY - squareSize/2, centerX + squareSize/2, centerY + squareSize/2);
	   }
}

void __fastcall TSaveForm::Reapint(TObject *Sender)
{
type_pb->Invalidate();
CleaningR();
switch (type_grp->ItemIndex) {

case 0:

Label3->Visible=true;  Label5->Visible=true;   Label4->Visible=true;    Label6->Visible=true;    Label7->Visible=true;
Label3->Caption="Количество брусков:";
Label5->Caption="Ширина бруса:";
Label4->Caption="Влажность:";
Label7->Caption="Длина бруса";
Label6->Caption="Погонная плотность";

Par1->Enabled=true;
Par2->Enabled=true;
Par3->Enabled=true;
Par4->Enabled=true;
Par5->Enabled=true;
ComboPar5->Visible=false;

break;
case 1:

Label3->Visible=true;  Label5->Visible=true;   Label4->Visible=true;    Label6->Visible=false;    Label7->Visible=true;
Label3->Caption="Высота:";
Label5->Caption="Радиус:";
Label4->Caption="Плотность:";
Label7->Caption="Температура хранения:";

Label6->Caption=" ";
ComboPar5->Visible=false;
Par1->Enabled=true;
Par2->Enabled=true;
Par3->Enabled=true;
Par5->Enabled=false;
Par4->Enabled=true;

break;
case 2:

Label3->Visible=true;  Label5->Visible=true;   Label4->Visible=true;    Label6->Visible=true;    Label7->Visible=true;
Label3->Caption="Высота:";
Label5->Caption="Ширина:";
Label4->Caption="Длина:";
Label6->Caption="Хрупкость:";
Label7->Caption="Число коробок";
ComboPar5->Visible=true;
Par1->Enabled=true;
Par2->Enabled=true;
Par3->Enabled=true;
ComboPar5->Enabled=true;
Par4->Enabled=true;

break;

default:
	;
}

}

void __fastcall TSaveForm::Filters_Ok(TObject *Sender, System::WideChar &Key)
{
TEdit* edit = dynamic_cast<TEdit*>(Sender);


	if (!isdigit(Key) && Key != '.' && Key != '-' && Key != 8) {
		Key = 0; // Отменить ввод символа, если он не является разрешенным
	}

	// Проверяем точку и минус
	if ((Key == '.' && edit->Text.Pos('.') > 0) || (Key == '-' && edit->Text != "")) {
		Key = 0; // Запрещаем ввод второй точки или минуса
	}
}

void __fastcall TSaveForm::Close_Re(TObject *Sender)
{
Close();
}

void __fastcall TSaveForm::Close_ReF(TObject *Sender, TCloseAction &Action)
{
type_grp->ItemIndex=-1;
 CleaningR();
  MainStorageForm->main_lv_tov->Clear();
 MainStorageForm->LetsShow(MainStorageForm);
 MainStorageForm->main_lv_tov->Invalidate();
	 TEdit* editControls[] = {Par1, Par2, Par3, Par4,Par5};
	 for(int i=0;i<5;i++)
	 editControls[i]->Enabled=false  ;
}

void TSaveForm:: CleaningR()
{
Par1->Text = "";
Par2->Text = "";
Par3->Text = "";
Par4->Text = "";
Par5->Text = "";
if(type_grp->ItemIndex==-1)
{zak_ed->Text="";
prod_ed->Text="";
spot_ed->Text="";}
ComboPar5->ItemIndex=-1;
}

void __fastcall TSaveForm::SaveBTN(TObject *Sender)
{
	 TEdit* editControls[] = {Par1, Par2, Par3, Par4,prod_ed,zak_ed,spot_ed};

// Проверка свойства Text каждого элемента на пустое значение
for (TEdit* editControl : editControls)
{
	if (editControl->Text == "") {
		ShowMessage("Не все поля заполнены");
		return; // Выход из цикла при первом пустом поле
	}
}
switch(type_grp->ItemIndex)
{
case 0:
if(Par5->Text=="")	{ShowMessage("Не все поля заполнены");	return;}
break;
case 2:
if(ComboPar5->ItemIndex==-1) {ShowMessage("Не все поля заполнены");	return;}
break;
}

if(!areBothNumbersWritten(spot_ed))  {ShowMessage("Неверный ввод позиции");	return;}
	// решение проблемы с тире
	AnsiString text = spot_ed->Text.Trim();
	int numbs[2];

	int dash_pos = text.Pos("-");

	AnsiString str_first_num = text.SubString(1, dash_pos - 1).Trim();
	numbs[0] = str_first_num.ToIntDef(0); // Преобразуем в целое число

	// Извлекаем второе число после тире
	AnsiString str_second_num = text.SubString(dash_pos + 1, text.Length()).Trim();
	numbs[1] = str_second_num.ToIntDef(0);
for(int i=0;i<NBEER;i++)
{ if(i==typeofp)continue;
  if(numbs[0]==storageArray[i]->placing[0]&& numbs[1]==storageArray[i]->placing[1])
   {ShowMessage("Такая позиция занята");	return;}
}


ObjSaving(type_grp->ItemIndex,storageArray,NBEER,typeofp);
Close();
}

//копировальня ряльна
void TSaveForm:: copyStorageItemsArray(StorageItem** &sourceArray, StorageItem** &destinationArray, int size,int exeption)
{
	for (int i = 0; i < size; i++) {
	if(i==exeption)continue;
		destinationArray[i] = sourceArray[i];
	}
}

//кхм...тире...
bool TSaveForm:: areBothNumbersWritten(TEdit* edit)
{
	AnsiString text = edit->Text.Trim();
	std::regex pattern("\\b\\d+-\\d+\\b"); // регулярное выражение

	return std::regex_search(text.c_str(), pattern);
}

void TSaveForm::ObjSaving(int flag, StorageItem** (&Ed), int (&n_),int positioning) {
	if (flag == -1) return;

	StorageItem** Bif = new StorageItem*[n_];
	copyStorageItemsArray(Ed, Bif, n_,positioning);

	delete[] Ed;

	Ed = new StorageItem*[n_+((positioning<0)?1:0)];

	copyStorageItemsArray(Bif, Ed, n_,positioning);

	// решение проблемы с тире
	AnsiString text = spot_ed->Text.Trim();
	int numbs[2];

	int dash_pos = text.Pos("-");

	AnsiString str_first_num = text.SubString(1, dash_pos - 1).Trim();
	numbs[0] = str_first_num.ToIntDef(0); // Преобразуем в целое число

	// Извлекаем второе число после тире
	AnsiString str_second_num = text.SubString(dash_pos + 1, text.Length()).Trim();
	numbs[1] = str_second_num.ToIntDef(0);

    switch (flag) {
		case 0:
		{ //	Poddon(int party, AnsiString productname, AnsiString zacaz, int placing[2],  int dlinna, int shir, int shtuk, double pogony, int osoby);
			if(positioning<0)
			Ed[n_]=new Poddon(NBEER, prod_ed->Text, zak_ed->Text, numbs, StrToInt(Par3->Text), StrToInt(Par2->Text), StrToInt(Par1->Text), StrToFloat(Par5->Text),StrToInt(Par4->Text));
			else
			Ed[positioning]=new Poddon(NBEER, prod_ed->Text, zak_ed->Text, numbs, StrToInt(Par3->Text), StrToInt(Par2->Text), StrToInt(Par1->Text), StrToFloat(Par5->Text),StrToInt(Par4->Text));

        }       break;

		case 1:
		{

		if(positioning<0)
		Ed[n_]=new Bochka(NBEER, prod_ed->Text, zak_ed->Text, numbs, StrToFloat(Par3->Text), StrToFloat(Par2->Text), StrToFloat(Par1->Text), StrToFloat(Par4->Text));
		else


		Ed[positioning]=new Bochka(NBEER, prod_ed->Text, zak_ed->Text, numbs, StrToFloat(Par3->Text), StrToFloat(Par2->Text), StrToFloat(Par1->Text), StrToFloat(Par4->Text));


		}
		break;

        case 2: {
       //	Corob(int party, AnsiString productname, AnsiString zacaz, int placing[2],  int width, int height, int depth, FragilityLevel osoby,  int numBoxes);
	   if(positioning<0)
	   Ed[n_]=new  Corob(NBEER, prod_ed->Text, zak_ed->Text, numbs, StrToInt(Par2->Text), StrToInt(Par1->Text), StrToInt(Par4->Text), IntToFrag(ComboPar5->ItemIndex),StrToInt(Par3->Text));
	   else
	   Ed[positioning]=new  Corob(NBEER, prod_ed->Text, zak_ed->Text, numbs, StrToInt(Par2->Text), StrToInt(Par1->Text), StrToInt(Par4->Text), IntToFrag(ComboPar5->ItemIndex),StrToInt(Par3->Text));

		}
		break;

		default: return;
	}

	delete[] Bif;

   if(positioning<0)	n_++;
   isSorted=false;
}

