#include <vcl.h>
#pragma hdrstop
#include<stdio.h>
#include "Main_f.h"
#pragma package(smart_init)
#include <regex>

#pragma resource "*.dfm"
//���������� ����������
TMainStorageForm *MainStorageForm;
int NBEER=0;   //������� �������� � ������� �� ����
StorageItem** storageArray = new StorageItem*[NBEER];
bool sortirivkaFlag;
bool srtType;
int typeofp;
int zize= 100;
bool isSorted=false;
AnsiString uniqueZacazValues[100];
int uniqueCount = 0;                                                                    //����� �������
DateM dateArray[100];                                         //������ ��������� �������
int counting=0;
DateM TodayD;

TDateTime currentDate = Date();
unsigned short day, month, year;                 //���� ������
int partyTime[100]; // ����� �������� ������
int partyArray[100];  //������ ��� ����� 1 ������
int n;
int itogParty[100]; //�������� ������������������ ������
int goyda=0;

void findPtime(StorageItem** storageItems, int size, int* partyset)
{
	int batchSize = 5;
	int currentBatchNumber = -1;
	int currentBatchSize = 0;
	int totalPreparationTime = 0;

	for (int i = 0; i < size; ++i) {
		if (storageItems[i]->getparty() != currentBatchNumber) {

			if (currentBatchNumber != -1) {
				// ���������� �����
				partyset[currentBatchNumber] = totalPreparationTime;
			}

			currentBatchNumber = storageItems[i]->getparty();
			currentBatchSize = 1;
			totalPreparationTime = storageItems[i]->vremya;
		} else {
			// ��������� ������ � ������� ������
			currentBatchSize++;
			totalPreparationTime += storageItems[i]->vremya;
		}

		if (currentBatchSize == batchSize || i == size - 1) {
			// ������ ��������� ��� ��������� ����� �������
			// ���������� ����� ���������� ������� ������
			partyset[currentBatchNumber] = totalPreparationTime;

			// �����
            currentBatchNumber = -1;
			currentBatchSize = 0;
			totalPreparationTime = 0;
		}
	}
}

void FindZacaz(StorageItem** storageItems, int size, int* partyset, AnsiString customer, int &n)
{
    n = 0;
    for (int i = 0; i < size; i++)
    {
        if (storageItems[i]->getZacaz() == customer)
		{
            bool isFind = false;
            for (int j = 0; j < n; j++)
            {
                if (partyset[j] == storageItems[i]->getparty())
                {
                    isFind = true;
                    break;
                }
			}
            if (!isFind)
            {
                partyset[n] = storageItems[i]->getparty();
                n++;
            }
        }
    }
}

void GetUniqueZacazValues(StorageItem* storageItems[], int zize, AnsiString uniqueZacazValues[], int& uniqueCount)
{
	uniqueCount = 0;

	for (int i = 0; i < zize; ++i) {
		AnsiString currentZacaz = storageItems[i]->zacaz;


		bool isUnique = true;
		for (int j = 0; j < uniqueCount; ++j) {
			if (uniqueZacazValues[j] == currentZacaz) {
				isUnique = false;
				break;
			}
		}


		if (isUnique) {
			uniqueZacazValues[uniqueCount] = currentZacaz;
            uniqueCount++;
		}
	}
}
void sortOrders(AnsiString* uniqueZacazValues, DateM* dateArray, int size)
{

	AnsiString* tempZacazValues = new AnsiString[size];
	DateM* tempDateArray = new DateM[size];


	for (int i = 0; i < size; ++i) {
		tempZacazValues[i] = uniqueZacazValues[i];
		tempDateArray[i] = dateArray[i];
	}


	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (tempDateArray[j].year > tempDateArray[j + 1].year ||
				(tempDateArray[j].year == tempDateArray[j + 1].year && tempDateArray[j].month > tempDateArray[j + 1].month) ||
				(tempDateArray[j].year == tempDateArray[j + 1].year && tempDateArray[j].month == tempDateArray[j + 1].month && tempDateArray[j].day > tempDateArray[j + 1].day)) {

				DateM tempDate = tempDateArray[j];
				tempDateArray[j] = tempDateArray[j + 1];
				tempDateArray[j + 1] = tempDate;


				AnsiString tempZacaz = tempZacazValues[j];
				tempZacazValues[j] = tempZacazValues[j + 1];
				tempZacazValues[j + 1] = tempZacaz;
			}
		}
	}


	for (int i = 0; i < size; ++i) {
		uniqueZacazValues[i] = tempZacazValues[i];
		dateArray[i] = tempDateArray[i];
	}


	delete[] tempZacazValues;
	delete[] tempDateArray;
}

void AddDaysToDate(DateM& date, int daysToAdd)
{
	date.day += daysToAdd;
	// ��������� �������� ������ � ����
	while (date.day > 30) {
		date.day -= 30;
		date.month++;
		if (date.month > 12) {
			date.month = 1;
			date.year++;
		}
	}
}

bool compareDates(DateM date1, DateM date2)
{
	if (date1.year != date2.year)
	{
		return date1.year < date2.year;
	}
	else if (date1.month != date2.month)
	{
		return date1.month < date2.month;
	}
	else
	{
		return date1.day < date2.day;
	}
}


void sborZ (DateM TodayD,	DateM* DateArr,	int uniqueCount,	AnsiString* uniqueZacazValues, int &n ,
 int * partytimes, int *partys, StorageItem** storageItems, int size , int * itog	,int & goyda	)
{               goyda=0;
                findPtime(storageItems,size,partytimes);
		/**/   DateM  TodayC;
				TodayC.day=TodayD.day;
				TodayC.month=TodayD.month;
				TodayC.year=TodayD.year;

		  sortOrders(    uniqueZacazValues,   DateArr   ,uniqueCount);
		  for(int i = 0 ;i<uniqueCount;i++)
		  {
			FindZacaz(   storageItems,size, partys , uniqueZacazValues[i],n);

			for(int j=0;j<n;j++)
			{

		  AddDaysToDate(TodayC,partytimes[partys[j]]);	      // aka;      TodayC+=partytimes[partys[j]];

			 if(! compareDates(TodayC,DateArr[i])  )
			 {	TodayC.day=TodayD.day;
				TodayC.month=TodayD.month;
				TodayC.year=TodayD.year;
				ShowMessage("���������� ���������:" +    uniqueZacazValues[i]);

			 }

			 else

			 for(int k=0;k<n;k++)
				{


			 if (partytimes[partys[k]] != 0) {
        itog[goyda] = partys[k];
        goyda++;
        partytimes[partys[k]] = 0;
    }           //��� �� ��� �������� ��������� ������ � ��������� ������
				}

			 }
		  }
	   /*	*/
}


// ����������� �����
__fastcall TMainStorageForm::TMainStorageForm(TComponent* Owner)
	: TForm(Owner)
{
	ChatLoad(NULL);

	//������� ����������
	TMenuItem *popup_new = new TMenuItem(popup_menu);
	popup_new->Caption = "�������� �����";
	popup_new->OnClick = NewItem;
	popup_menu->Items->Add(popup_new);

	//������� ���������
	TMenuItem *popup_red = new TMenuItem(popup_menu);
	popup_red->Caption = "��������";

	popup_red->OnClick = Redacted;
	popup_menu->Items->Add(popup_red);

	//������� ��������
	TMenuItem *popup_del = new TMenuItem(popup_menu);
	popup_del->Caption = "�������";

	popup_del->OnClick = PopDel;
	popup_menu->Items->Add(popup_del);

 
   DecodeDate(currentDate, year, month, day);
	TodayD.day=day;
 TodayD.month=month;
   TodayD.year=year;
}

//������ ����������
 __fastcall TMainStorageForm::~TMainStorageForm()
{
	delete[] storageArray;
}

void __fastcall TMainStorageForm::NewItem(TObject *Sender)
{
	typeofp=-1;
	SaveForm->Visible=true;
}

void __fastcall TMainStorageForm::PopDel(TObject *Sender)
{

	 int selectedIndex = main_lv_tov->ItemIndex;
	  if (selectedIndex < 0 || selectedIndex >= NBEER)
	{
	   ShowMessage("��� ������ ��������");
		return;
	}

delete storageArray[selectedIndex];

StorageItem** tempArray = new StorageItem*[NBEER - 1];
for (int i = 0; i < selectedIndex; ++i)
{
	tempArray[i] = storageArray[i];
}

for (int i = selectedIndex; i < NBEER - 1; ++i)
{
	tempArray[i] = storageArray[i + 1];
}

--NBEER;

delete[] storageArray;


storageArray = tempArray;
	storageArray = tempArray;
   ShowMessage("������");
	   MainStorageForm->main_lv_tov->Clear();
	   MainStorageForm->LetsShow(MainStorageForm);
	   MainStorageForm->main_lv_tov->Invalidate();
	   isSorted=false;
}

void __fastcall TMainStorageForm::Redacted(TObject *Sender)
{
	int selectedIndex = main_lv_tov->ItemIndex  ;
	if (selectedIndex < 0 || selectedIndex >= NBEER)
	{
	   ShowMessage("��� ������ ��������");
		return;
	}
	int zagl=-2;


   typeofp = main_lv_tov->ItemIndex;
   SaveForm->Visible=true;


}

void __fastcall TMainStorageForm::ClFindS(TObject *Sender, WORD &Key, TShiftState Shift)
{
	//���� ������ �������� ��� �����
	((TEdit*)Sender)->Color = clYellow;

}

void __fastcall TMainStorageForm::ClFindUNSHIFT(TObject *Sender, WORD &Key, TShiftState Shift)

{
	//���� ������ �������� ��� �����
	((TEdit*)Sender)->Color = clActiveCaption;
}

void __fastcall TMainStorageForm::VisualFormActive(TObject *Sender)
{
	//������� ����� ���������
	VisualForm->Visible=true;
}

void __fastcall TMainStorageForm::Closing(TObject *Sender)
{
Close();
}

void __fastcall TMainStorageForm::FindActive(TObject *Sender)
{
		((TEdit*)Sender)->Color=clActiveCaption;
}

void __fastcall TMainStorageForm::FindExit(TObject *Sender)
{
	((TEdit*)Sender)->Color=clWindow;
}

void __fastcall TMainStorageForm::SortType(TObject *Sender)
{
	if(sort_flag->Caption=="^")
{ sort_flag->Caption="v"  ;  sortirivkaFlag=true; return;}

	if(sort_flag->Caption=="v")
	{sort_flag->Caption="^";
	sortirivkaFlag=false; return;}

}

void __fastcall TMainStorageForm::MainPanResize(TObject *Sender)
{
	if(main_pan_tov->Width!=0)
{
	main_tov_fn->Width=main_pan_tov->Width-5;
	sort_flag->Left=main_tov_fn->Width-sort_flag->Width+2;
	main_tov_sort_btn->Width=main_tov_fn->Width-sort_flag->Width-5;
	sort_combo->Width= main_tov_fn->Width;
}
}


void __fastcall TMainStorageForm::SaveActive(TObject *Sender)
{
	AnsiString filename = log_edO->Text;
	FILE* file= fopen(AnsiString(log_edO->Text.c_str()).c_str(),"at");
	if(!file)return;
	for(int i=0;i<NBEER;i++) storageArray[i]->WritingInFile(file);
	fclose (file);
	ShowMessage("������ ������� �������� � ����: " + filename);
}
// ��� ���  true`
void __fastcall TMainStorageForm::AddChat(TObject *Sender)
{
//zapis v file

	FILE*out = fopen(AnsiString(log_ed->Text.c_str()).c_str(),"at");
	if(!out)return(ShowMessage("File Error!"));

	char name[13];
	char text[61];

	AnsiString n = name_fl->Text;
	AnsiString t = text_fl->Text;
	strcpy (name,n.c_str());
	strcpy(text,t.c_str());
	fprintf(out,"%-12.12s:%-60.60s\r\n",name,text);

	fclose(out);
	text_fl->Clear();

	ChatLoad(NULL);
}

void __fastcall TMainStorageForm::ChatLoad(TObject *Sender)
{
  FILE *inp=fopen(AnsiString(log_ed->Text.c_str()).c_str(),"rt");
  if(!inp)return;

  chat_lv->Items->Clear();

  while(!feof(inp))
  {
	char name[13];
	char text[61];

	memset(name,0,sizeof(name));
	memset(text,0,sizeof(text));

	fscanf(inp, "%12c:%60c\r\n" ,name,text);

	TListItem *item = chat_lv->Items->Add();
	item->Caption=name;
	item->SubItems->Add(text);
  }

  fclose(inp);
}

void __fastcall TMainStorageForm::ReChat(TObject *Sender)
{
	ChatLoad(NULL);
}

// ����� �������
void __fastcall TMainStorageForm::LetsShow(TObject *Sender)
	{

		for (int i = 0; i < NBEER; i++)
	 {
		TListItem* item = main_lv_tov->Items->Add();

		item->Caption = IntToStr(i + 1);
		item->SubItems->Add(IntToStr(storageArray[i]->getParty()));
		item->SubItems->Add(storageArray[i]->getProductname());
		item->SubItems->Add(storageArray[i]->getZacaz());
		item->SubItems->Add(IntToStr(storageArray[i]->getPlacing(0)) + "-" + IntToStr(storageArray[i]->getPlacing(1)));


		Poddon* poddonItem = dynamic_cast<Poddon*>(storageArray[i]);
		Corob* corobItem = dynamic_cast<Corob*>(storageArray[i]);
		Bochka* bochkaItem = dynamic_cast<Bochka*>(storageArray[i]) ;
		/*
		  dynamic_cast<Bochka*> - ��� �������� ���������� ���� � C++, ������� �������� ��������� ���������� ���������� ��������� ��� ������ �� ������� ����� � ��������� ��� ������ �� ����������� �����.   � ������ �������� �� ������ ������� ����  ������ ��� null
		*/

			if (bochkaItem!=nullptr)
			{
			item->SubItems->Add("�����. ������: " + FloatToStr(bochkaItem->getBheight()) + " ������: " + FloatToStr(bochkaItem->getBrad()));
			item->SubItems->Add("�����: " + FloatToStr(bochkaItem->getColvo()) + " ������");
			item->SubItems->Add("���������: " + FloatToStr(bochkaItem->getPlotn()) + ", �����������: " + FloatToStr(bochkaItem->getOsoby()));
			}


			if (poddonItem != nullptr) {
			item->SubItems->Add("������. �����: " + IntToStr(poddonItem->getDlinna()) + ", ������: " + IntToStr(poddonItem->getShir()) + ", ���������� �������: " + IntToStr(poddonItem->getShtuk()));
			item->SubItems->Add("�������: " + FloatToStr(poddonItem->getColvo()) + " �^2");
			item->SubItems->Add("�������� ���������: " + FloatToStr(poddonItem->getPogony()) + ", ���������: " + FloatToStr(poddonItem->getOsoby())+" %");
			}

			if (corobItem != nullptr)
				{
		item->SubItems->Add("�������. ������: " + IntToStr(corobItem->getWidth()) + ", ������: " + IntToStr(corobItem->getHeight()) + ", �������: " + IntToStr(corobItem->getDepth()) + ", ���������� �������: " + IntToStr(corobItem->getNumBoxes()));
item->SubItems->Add("�����: " + IntToStr(corobItem->getColvo()) + " �^3");

switch (corobItem->getOsoby())
{
	case NOT_FRAGILE:
		item->SubItems->Add("����� �� �������, ���: " + FloatToStr(corobItem->getVes()));
		break;
	case FRAGILE:
		item->SubItems->Add("����� �������, ���: " + FloatToStr(corobItem->getVes()));
		break;
	case HIGHLY_FRAGILE:
		item->SubItems->Add("����� ����� �������, ���: " + FloatToStr(corobItem->getVes()));
		break;
	default:
		item->SubItems->Add("����������� ������� ���������, ���: " + FloatToStr(corobItem->getVes()));
}
				}


		item->SubItems->Add(FloatToStr(storageArray[i]->getZena()));
}
	}


void StorageItem:: ReadingFromFile(FILE* file) {
		// ����� ������ ������ �� �����
		char buffer[255];
		fscanf(file, "%s", buffer); // ��������� productname
		productname = AnsiString(buffer);

		fscanf(file, "%s", buffer); // ��������� zacaz
		zacaz = AnsiString(buffer);

		fscanf(file, "%d %d", &placing[0], &placing[1]);
	}

//��� ��������
	Poddon::Poddon(int party, AnsiString productname, AnsiString zacaz, int placing[2], int dlinna, int shir, int shtuk, double pogony, int osoby) //: StorageItem(party, productname, zacaz, placing)
{
	this->party = party/5+1;
	this->productname = productname;
	this->zacaz = zacaz;
	this->placing[0] = placing[0];
	this->placing[1] = placing[1];

  this->dlinna = dlinna;
  this->shir = shir;
  this->shtuk = shtuk;
  this->pogony = pogony;
  this->osoby = osoby;
  FindCol();
  CostSaving();
}

	void	Poddon::  CostSaving()
	{   zena =MINPAY;
		if (ves<100)
		{
			zena*=(ves/100);
		}
		if(osoby>30)
		{
			zena*=abs(osoby-30)*0.5;
		}

	}

	void Poddon:: WritingInFile(FILE* file)
	{
		fprintf(file,"#Poddon\n");
		StorageItem::WritingInFile(file);
		fprintf(file, "%d\n", dlinna);
		fprintf(file, "%d\n", shir);
		fprintf(file, "%d\n", shtuk);
		fprintf(file, "%.2lf\n", pogony);
		fprintf(file, "%d\n", osoby);
	}

	 Poddon::Poddon(FILE* file) {

			StorageItem::ReadingFromFile(file);
			fscanf(file, "%d", &dlinna);
			fscanf(file, "%d", &shir);
			fscanf(file, "%d", &shtuk);
			fscanf(file, "%lf", &pogony);
			fscanf(file, "%d", &osoby);
	FindCol();   	CostSaving();
			SetParty(NBEER);
	}

//��� �����
	Bochka::Bochka(int party, AnsiString productname, AnsiString zacaz, int placing[2], double osoby, double Brad, double Bheight, double plotn) //: StorageItem(party, productname, zacaz, placing)
{
	this->osoby = osoby;
	this->Brad = Brad;
	this->Bheight = Bheight;
	this->plotn = plotn;
	this->party = party/5+1;
	this->productname = productname;
	this->zacaz = zacaz;
	this->placing[0] = placing[0];
	this->placing[1] = placing[1];
	FindCol();
	CostSaving();
}

	void Bochka:: WritingInFile(FILE* file)
	{
	fprintf(file,"#Bochka\n");
	StorageItem::WritingInFile(file);
	fprintf(file, "%.2f\n", osoby);
	fprintf(file, "%.2f\n", Brad);
	fprintf(file, "%.2f\n", Bheight);
	fprintf(file, "%.2f\n", plotn);
	}

	void Bochka:: CostSaving()
	{   zena =MINPAY;
		if (ves<10)
		{
			zena*=(ves/10);
		}
		if(abs(osoby)>26)
		{
			zena+=(26-abs(osoby))*1.4;
		}
        setVremya () ;
	}

Bochka::Bochka(FILE* file) {


			StorageItem::ReadingFromFile(file);
			fscanf(file, "%lf", &osoby);
			fscanf(file, "%lf", &Brad);
			fscanf(file, "%lf", &Bheight);
			fscanf(file, "%lf", &plotn);
	FindCol();   	CostSaving();
			SetParty(NBEER);
			setVremya () ;
	}

//��� �������

Corob::Corob(int party, AnsiString productname, AnsiString zacaz, int placing[2], int width, int height, int depth, FragilityLevel osoby, int numBoxes)	// : StorageItem(party, productname, zacaz, placing)
{
  this->width = width;
  this->height = height;
  this->depth = depth;
  this->osoby = osoby;
  this->numBoxes = numBoxes;
	this->party = party/5+1;
	this->productname = productname;
	this->zacaz = zacaz;
	this->placing[0] = placing[0];
	this->placing[1] = placing[1];
	FindCol();
	CostSaving();
	setVremya () ;
}

	void Corob:: CostSaving()
	{
		zena = MINPAY;

		if (osoby == HIGHLY_FRAGILE)
		{
			zena += width * height * depth * 0.1;
		}
		else if (osoby == FRAGILE)
		{
			zena += width * height * depth * 0.05;
		}

		zena += ves * 0.2;

		zena *= numBoxes;


	}

void Corob:: WritingInFile(FILE* file)
{

	fprintf(file,"#Corob\n");
	StorageItem::WritingInFile(file);
	fprintf(file, "%d\n", width);
	fprintf(file, "%d\n", height);
	fprintf(file, "%d\n", depth);
	fprintf(file, "%d\n", numBoxes);
	fprintf(file, "%d\n", osoby);
}

Corob::Corob(FILE* file) {



			StorageItem::ReadingFromFile(file);
			fscanf(file, "%d", &width);
			fscanf(file, "%d", &height);
			fscanf(file, "%d", &depth);
			fscanf(file, "%d", &numBoxes);
			fscanf(file, "%d", &osoby);

			FindCol();   	CostSaving();
			SetParty(NBEER);
	}

// �������
	void  TMainStorageForm::ArrayClear()
	{
	delete[] storageArray;

	storageArray = nullptr;
	NBEER = 0;
	}

	//chtenye
void __fastcall TMainStorageForm::reed_bClick(TObject *Sender)
{
 OpenDialog1->Execute();
   if (OpenDialog1->FileName == "")
  {
	return;
  }

	 String FileName = OpenDialog1->FileName;
	FILE* file = fopen(AnsiString(FileName).c_str(), "rt");
	if (file == NULL) {
		ShowMessage("������ �������� �����");
		return;
	}
	char str[255]; // ����� ��� ������
while(fgets(str, sizeof(str), file) != NULL)
	{

	str[strcspn(str, "\n")] = 0;

	// �������� � �������� ������� ������� ����
	StorageItem* newItem = nullptr;
	if(strcmp(str, "#Bochka") == 0)
	{
		newItem = new Bochka(file);
	}
	else if(strcmp(str, "#Poddon") == 0)
	{
		newItem = new Poddon(file);
	}
	else if(strcmp(str, "#Corob") == 0)
	{
		newItem = new Corob(file);
	}

		// ���������� ������� � ������ ���������� � ���������� ������� �������
		if(newItem != nullptr)
		{
			StorageItem** tempArray = new StorageItem*[NBEER + 1];
			for(int i = 0; i < NBEER; i++)
			{
				tempArray[i] = storageArray[i];
			}
			tempArray[NBEER] = newItem;

			delete[] storageArray;
			storageArray = tempArray;

			NBEER++;
		}
	}
	 fclose(file);
	  ShowMessage("������");
	   MainStorageForm->main_lv_tov->Clear();
	   MainStorageForm->LetsShow(MainStorageForm);
	   MainStorageForm->main_lv_tov->Invalidate();
	   isSorted=false;
}
// vremya sortirovky

void shellSortByZena(StorageItem** arr, int size, bool ascending)
{
	// ����� ���� ��� ����������
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; ++i)
		{
			StorageItem* temp = arr[i];
			int j;
			for (j = i; j >= gap && compareByZena(arr[j - gap], temp,ascending); j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}



void shellSortByProductName(StorageItem** arr, int size, bool ascending)
{
	// ����� ���� ��� ����������
	 srtType=ascending;
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; ++i)
		{
			StorageItem* temp = arr[i];
			int j;
			for (j = i; j >= gap && compareByProductName(arr[j - gap], temp,ascending); j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

void __fastcall TMainStorageForm::Sortyrovka(TObject *Sender)
{
switch (sort_combo->ItemIndex) {
case 0:
shellSortByProductName(storageArray,NBEER,sortirivkaFlag);     isSorted=true;
break;

case 1:
		shellSortByZena(storageArray,NBEER,sortirivkaFlag);

break;


default: ShowMessage("������ ��� ����������"); return;

}
		MainStorageForm->main_lv_tov->Clear();
		MainStorageForm->LetsShow(MainStorageForm);
		MainStorageForm->main_lv_tov->Invalidate();
}

void __fastcall TMainStorageForm::Fresh(TObject *Sender)
{


StorageItem* result;
AnsiString key = main_tov_fn->Text;
 if(!isSorted)
 result =  linearSearch(storageArray, NBEER , key);
 else
 {
 result =  binarySearch(storageArray, NBEER , key,!srtType);
 }

if (result) {

	ShowMessage(result->getProductName() + " � ������:" + IntToStr(result->getparty()));
	moveItemToStart(storageArray, NBEER, result); // ���������� ��������� ������� � ������ �������
	isSorted=false;
}
		MainStorageForm->main_lv_tov->Clear();
		MainStorageForm->LetsShow(MainStorageForm);
		MainStorageForm->main_lv_tov->Invalidate();

}


StorageItem* linearSearch(StorageItem* arr[], int size, AnsiString key) {
	for (int i = 0; i < size; ++i) {
		if (key == arr[i]->getProductName()) {
			return arr[i];
		}
	}

	return nullptr;
}

StorageItem* binarySearch(StorageItem* arr[], int size, AnsiString key, bool ascending) {
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (key == arr[mid]->getProductName()) {
			return arr[mid];
		}

		if (ascending) {
			if (key > arr[mid]->getProductName()) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		} else {
			if (key < arr[mid]->getProductName()) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
	}

	return nullptr;
}


void moveItemToStart(StorageItem* arr[], int size, StorageItem* item) {
	int pos = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == item) {
			pos = i;
			break;
		}
	}

	if (pos != -1) {
		for (int i = pos; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = item;
	}
}


void __fastcall TMainStorageForm::Button4Click(TObject *Sender)
{
GetUniqueZacazValues(storageArray, NBEER, uniqueZacazValues, uniqueCount)      ;

ListView1->Items->Clear();
	for (int i = 0; i < uniqueCount; i++)
	 {
TListItem* item = ListView1->Items->Add();

		item->Caption = uniqueZacazValues[i];
		}
	  for(int i = 0; i < uniqueCount; ++i) {
    AnsiString subItem = IntToStr(dateArray[i].day) + "." + IntToStr(dateArray[i].month) + "." + IntToStr(dateArray[i].year);
    ListView1->Items->Item[i]->SubItems->Add(subItem);
}

}
//---------------------------------------------------------------------------

void __fastcall TMainStorageForm::Edit1KeyPress(TObject *Sender, System::WideChar &Key)

{
	if(Key==13)
	{
 AnsiString inputText = Edit1->Text;

    std::regex numberRegex("\\d+\\.\\d+\\.\\d+"); // ���������� ��������� ��� ���������� ���� ����� ����������� �������

	if (std::regex_search(inputText.c_str(), numberRegex)) {
         if(ListView1->Selected == NULL) {ShowMessage("�� ������ ��������") ;	return;    }
		int selectedIndex = ListView1->ItemIndex;


dateArray[selectedIndex].day = StrToInt(inputText.SubString(1, inputText.Pos(".") - 1));
inputText.Delete(1, inputText.Pos("."));
dateArray[selectedIndex].month = StrToInt(inputText.SubString(1, inputText.Pos(".") - 1));
inputText.Delete(1, inputText.Pos("."));
dateArray[selectedIndex].year = StrToInt(inputText);
counting++;

		}

    else {
        ShowMessage("������������ ������ �����. ������� � ������� �����.�����.�����");
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TMainStorageForm::Button5Click(TObject *Sender)
{
//
//   findPtime( storageArray, NBEER,  partyTime);
   GetUniqueZacazValues(storageArray,NBEER,	uniqueZacazValues ,	uniqueCount);
   sborZ(   TodayD,	 dateArray,	 uniqueCount,    uniqueZacazValues, n ,
 partyTime, partyArray, storageArray, NBEER , itogParty ,goyda )  ;
 AnsiString result = "������� ������ :";

	for (int i = 0; i < goyda; i++) {
		result += " " + IntToStr(itogParty[i]);
	}

	ShowMessage(result);

}


//---------------------------------------------------------------------------

