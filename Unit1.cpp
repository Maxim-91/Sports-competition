//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
#include "fstream.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
 int d=0, b=0;
 typedef struct
 {
  AnsiString kr, ko, pip;
  float n, vi, r, va;
 } Tstud;
 Tstud st[100];
 Tstud stmin[100];
 FILE *ff;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
 int i;

 st[d].kr=Edit2->Text;
 st[d].ko=Edit3->Text;
 st[d].pip=Edit4->Text;
 st[d].n=StrToFloat(Edit1->Text);
 st[d].vi=StrToFloat(Edit7->Text);
 st[d].r=StrToFloat(Edit8->Text);
 st[d].va=StrToFloat(Edit9->Text);

 Memo1->Lines->Add(st[d].kr+" "+st[d].ko+" "+st[d].pip+" "+st[d].n+" "+st[d].vi+" "+st[d].r+" "+st[d].va);
 d++;
}
//---------------------------------------------------------------------------







void __fastcall TForm1::Button1Click(TObject *Sender)
{
 int i;
 ofstream ff("Sportyvni_zmagannya.text");
 for (i=0; i<=d;i++)
 {
  char* kr=st[i].kr.c_str();
  char* ko=st[i].ko.c_str();
  char* pip=st[i].pip.c_str();
  float n=st[i].n;
  float vi=st[i].vi;
  float r=st[i].r;
  float va=st[i].va;

  ff<<kr<<" "<<ko<<" "<<pip<<" "<<n<<" "<<vi<<" "<<r<<" "<<va<<endl;
 }
 ff.close();
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button3Click(TObject *Sender)
{
 int i,j,a,l;
 AnsiString p;
 for (i=0;i<d;i++)
 {
  if (st[i].kr==""||st[i].ko=="") goto s;
  stmin[b].kr=st[i].kr;
  stmin[b].ko=st[i].ko;
  stmin[b].vi=st[i].vi;
  stmin[b].r=st[i].r;
  stmin[b].va=st[i].va;
  for (j=i+1;j<d;j++)
  {if (st[i].kr==st[j].kr &&
      st[i].ko==st[j].ko)
  {
   stmin[b].vi+=st[j].vi;
   stmin[b].r+=st[j].r;
   stmin[b].va+=st[j].va;
   a++;

   st[j].kr="";
   st[j].ko="";
  }}
  stmin[b].vi=stmin[b].vi/a;
  stmin[b].r=stmin[b].r/a;
  stmin[b].va=stmin[b].va/a;
  b++;
  a=1;
  s:
 }

 p=stmin[0].vi;
 for (i=1;i<b;i++)
 {
  if (p>stmin[i].vi)
  {
   p=stmin[i].vi;
   l=i;
  }
 }
 Memo2->Lines->Add("Наймолодша команда: "+stmin[l].ko+" - "+stmin[l].kr);
 Memo2->Lines->Add("");

 p=stmin[0].r;
 for (i=1;i<b;i++)
 {
  if (p>stmin[i].r)
  {
   p=stmin[i].r;
   l=i;
  }
 }
 Memo2->Lines->Add("Короткоросла команда: "+stmin[l].ko+" - "+stmin[l].kr);
 Memo2->Lines->Add("");

 p=stmin[0].va;
 for (i=1;i<b;i++)
 {
  if (p>stmin[i].va)
  {
   p=stmin[i].va;
   l=i;
  }
 }
 Memo2->Lines->Add("Легша команда: "+stmin[l].ko+" - "+stmin[l].kr);
 Memo2->Lines->Add("");
}
//---------------------------------------------------------------------------

