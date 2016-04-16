#include<constream.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
void mainmenu();
class CD
{
	int cno;
	char muscd[50];
	char movcd[50];
	char sellcd[50];
	float mus_price;
	float mov_price;
	public:
	void mus_entry()
	{
		clrscr();
		cout<<"---*PLEASE ENTER THE DETAILS OF THE MUSIC CD*--- ";
		cout<<"\n\nCD NUMBER : ";
		cin>>cno;
		cout<<"\n\nNAME OF THE CD : ";
		gets(muscd);
		cout<<"\n\nPRICE OF THE CD : ";
		cin>>mus_price;
	}
	void mus_display()
	{
		cout<<"\nMUSIC CD NUMBER : "<<cno;
		cout<<"\nMUSIC CD NAME : "<<muscd;
		cout<<"\nMUSIC CD PRICE : "<<mus_price;
	}
	void mov_entry()
	{
		clrscr();
		cout<<"--*PLEASE ENTER THE DETAILS OF THE MOVIE CD*-- ";
		cout<<"\n\nCD NUMBER : ";
		cin>>cno;
		cout<<"\n\nNAME : ";
		gets(movcd);
		cout<<"\n\nPRICE : ";
		cin>>mov_price;
	}
	void mov_display()
	{
		cout<<"\nMOVIE CD NUMBER : "<<cno;
		cout<<"\nMOVIE CD NAME : "<<movcd;
		cout<<"\nMOVIE CD PRICE : "<<mov_price;
		}
	int rsn()
	{
		return cno;
	}
	float  musprc()
	{
		return mus_price;
	}
	float  movprc()
	{
		return mov_price;
	}
};
void reg()
{
	char name[30];
	char add[30];
	char phno[12];
	cout<<"***SELL CD MENU***";
	cout<<"\n\nKINDLY REGISTER YOURSELF FIRST!!!!";
	cout<<"\n\nENTER YOUR NAME : ";
	gets(name);
	cout<<"\n\nENTER YOUR ADDRESS : ";
	gets(add);
	cout<<"\n\nENTER YOUR PHONE NUMBER : ";
	cin>>phno;
	cout<<"\n\n***PRESS ENTER KEY TO REGISTER...***";
	getchar();
	ofstream out;
	out.open("REG.TXT",ios::app);
	out<<"\n\nNAME : "<<name;
	out<<"\n\nADDRESS : "<<add;
	out<<"\n\nPHONE NO : "<<phno;
	out.close();
	clrscr();
}
void sell()
{
	clrscr();
	char sname[30];
	char stype[30];
	char sprice[30];
	cout<<"\n\n\t\t***THANK YOU FOR REGISTERING***";
	cout<<"\n\nENTER YOUR CD NAME : ";
	gets(sname);
	cout<<"\n\nENTER YOUR CD TYPE : ";
	gets(stype);
	cout<<"\n\nENTER YOUR CD PRICE : ";
	gets(sprice);
	ofstream out;
	out.open("REG.TXT",ios::app);
	out<<"\n\nCD NAME : "<<sname;
	out<<"\n\nCD TYPE : "<<stype;
	out<<"\n\nCD PRICE : "<<sprice;
	cout<<"\n___________________________________________________";
	out.close();
	clrscr();
}
void sell_display()
{
	cout<<"\n\n\n\n\tYOUR CD IS NOW LISTED IN OUR RECORS.THANKS FOR USING OUR SERVICE.";
	getch();
}
CD obj;
void begin()
{
	clrscr();
	textcolor(MAGENTA);
	textbackground(WHITE);
	gotoxy(25,7);
	cprintf("\n\n*<<<<WELCOME TO THE C++ PROJECT>>>>*");
	getch();
	clrscr();
	textcolor(CYAN+BLINK);
	textbackground(WHITE);
	cout<<"\n\n\n\t\tCD CAFE smile emoticon";
	cout<<"\n\n\tTHIS PROJECT ENABLES YOU TO BUY AS WELL AS SELL TWO KINDS OF CDS";
	cout<<"\n\t\tMUSIC CDS\n\t\tMOVIE CDS";
	cout<<"\n\n\n\t\tMADE BY:\n\t\tRUPALI WADHWANI\n\t\t12TH - 'C' \n\t\tSAGAR PUBLIC SCHOOL,2012-2013";
	cout<<"\n\n\t\t****PRESS ENTER TO CONTINUE****";
	getchar();
	mainmenu();
}
void muswrite()
{
	clrscr();
	char ch='y';
	CD c;
	fstream inout;
	inout.open("MUSCD.DAT",ios::out|ios::binary|ios::app);
	while(ch=='y'||ch=='Y')
	{
		c.mus_entry();
		inout.write((char*)&c,sizeof(c));
		cout<<"\n Do you want to add another record ? ";
		cin>>ch;
	}
	inout.close();
	mainmenu();
}
void musread()
{
	clrscr();
	CD c;
	int size;
	fstream in;
	in.open("MUSCD.DAT",ios::in|ios::binary);
	cout<<"***LIST OF AVAILABLE CDS*** ";
	while(!in.eof())
		{
		in.read((char*)&c,sizeof(c));
		c.mus_display();
		}
	in.close();
}
void movwrite()
{
    clrscr();
    CD mov;
    char ch='y';
    fstream out;
    out.open("MOVCD.DAT",ios::out|ios::binary|ios::app);
    while(ch=='y'||ch=='Y')
	  {
	  mov.mov_entry();
	  out.write((char*)&mov,sizeof(mov));
	  cout<<"\n Do you want to add another record ? ";
	  cin>>ch;
	  }
	  out.close();
	  mainmenu();
}
void movread()
{
    clrscr();
    CD mov;
    fstream in;
    in.open("MOVCD.DAT",ios::in|ios::binary);
    cout<<"****List of Available CDS****";
    while(!in.eof())
    {
	in.read((char*)&mov,sizeof(mov));
	mov.mov_display();
    }
    in.close();
}
void buymus()
{
    int qty,cn,amt;
    cout<<"\nMUSIC CD\n\n";
    musread();
    cout<<"\nENTER CD NUMBER OF THE CD YOU WISH TO BUY :";
    cin>>cn;
    cout<<"\nENTER THE NUMBER OF CDS YOU WISH TO BUY : ";
    cin>>qty;
    fstream in;
    in.open("MUSCD.DAT",ios::in|ios::binary);
    while(in)
    {
	in.read((char*)&obj,sizeof(obj));
	if(obj.rsn()==cn)
	{
		   amt=obj.musprc()*qty;
		   cout<<"\nAMOUNT TO BE PAID IS : "<<amt;
		   getchar();
		   break;
	}
	 in.close();
    }
}
void buymov()
{
    int qty,cn;
    float amt;
    cout<<"\nMOVIE CD\n\n";
    movread();
    cout<<"\nENTER CD NUMBER OF THE CD YOU WISH TO BUY : ";
    cin>>cn;
    cout<<"\nENTER THE NUMBER OF CDS YOU WISH TO BUY : ";
    cin>>qty;
    fstream in;
    in.open("MOVCD.DAT",ios::in|ios::binary);
    while(in)
     {
	  in.read((char*)&obj,sizeof(obj));
	  if(obj.rsn()==cn)
	  {
		    amt=obj.movprc()*qty;
		    cout<<"\nAMOUNT TO BE PAID IS : "<<amt;
		    getchar();
		    break;
	  }
    }
    in.close();
}
void sellcd()
{
	reg();
	sell();
	sell_display();
	mainmenu();
}
void mainmenu()
{
	clrscr();
	cout<<"\n\nMAIN MENU ";
	cout<<"\n\n(1) BUY/ADD CD ";
	cout<<"\n\n(2) SELL CD ";
	cout<<"\n\n(3) EXIT ";
	int ch;
	cout<<"\n\n\nENTER YOUR CHOICE :";
	cin>>ch;
	switch (ch)
	{
		 case 1:
		 {
			  fflush(stdin);
			  clrscr();
			  int ch2;
			  cout<<"\n\t\t**** Buy / Add CD Menu ****   ";
			  cout<<"\n\nEnter your choice from below : ";
			  cout<<"\n\n1>MUSIC CD: Press 1";
			  cout<<"\n\n2>MOVIE CD: Press 2";
			  cout<<"\n\n3>EXIT:Press 3";
			  cout<<"\n\n4>Add MUSIC CD In MUSCD.DAT";
			  cout<<"\n\n5>Add MOVIE CD In MOVCD.DAT";
			  cout<<"\n\n\nENTER your choice::>>";
			  cin>>ch2;
			  switch (ch2)
			  {
			  case 1:
			  {
				  clrscr();
				  buymus();
				  mainmenu();
				  getchar();
				  break;
			  }
			  case 2:
			  {
				  clrscr();
				  buymov();
				  mainmenu();
				  getchar();
				  break;
			  }
			  case 3:
			  exit(0);
			  break;
			  case 4:
			  muswrite();
			  break;
			  case 5:
			  movwrite();
			  break;
			  default:
			  cout<<"\nInvalid Option";
			  break;
		 }
		 break;
	  }
	  case 2:
	  {
		 clrscr();
		 fflush(stdin);
		 sellcd();
		 getchar();
		 break;
	  }
	  case 3:
	  exit(0);
	  break;
	  default:
	  cout<<"\nInvalid Option";
	  break;
	}
}
int main ()
{
    clrscr();
    begin();
    return 0;
}
