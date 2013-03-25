
	//My Personal Diary
	#include <iostream.h>
	#include <conio.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <time.h>
	#include <dos.h>
	#include <process.h>
	#include <fstream.h>

	void color()
	{
		unsigned t=time(NULL);
		srand(t);
		int a=rand()/100%15+1;
		textcolor(a);
	}

	void programmer()
	{
		textcolor(7);
		clrscr();
		gotoxy(1,25);
		_setcursortype(_NOCURSOR);
		textcolor(7);
		cout<<"CREATED BY ";
		color();
		cprintf("Reet Awwsum");
		delay(1000);
		gotoxy(67,25);
		cout<<"EDITED BY ";
		color();
		cprintf("SLX");

		delay(1500);
		exit(0);
	}

	void date()
	{
		int a;
		struct dosdate_t d;
		_dos_getdate(&d);
		printf("%d",d.day);
		int day2 = d.day;
		if(day2==1 || day2==21 || day2==31)
			printf("st");
		if(day2==2 || day2==22)
			printf("nd");
		if(day2==3 || day2==23)
			printf("rd");
		if(day2 > 3 && day2 <= 20)
			printf("th");
		if(day2 > 23 && day2 <=30)
			printf("th");
		cout<<" ";
		a=("%d",d.month);
		if (a==1)
			cout<<"January";
		if (a==2)
			cout<<"February";
		if (a==3)
			cout<<"March";
		if (a==4)
			cout<<"April";
		if (a==5)
			cout<<"May";
		if (a==6)
			cout<<"June";
		if (a==7)
			cout<<"July";
		if (a==8)
			cout<<"August";
		if (a==9)
			cout<<"September";
		if (a==10)
			cout<<"October";
		if (a==11)
			cout<<"November";
		if (a==12)
			cout<<"December";

		cout<<", ";
		printf("%d",d.year);

	}

	void entry()
	{
		void menu();
		char a[5000];
		textcolor(7);
		clrscr();
		_setcursortype(_NORMALCURSOR);
		gotoxy(1,2);
			cout<<"Dear Diary,";
		gotoxy(62,2);
			date();
		gotoxy(1,4);
			gets(a);


		struct dostime_t t;
		_dos_gettime(&t);
		int time1 = t.hour;
		int time2 = t.minute;
		int temp10=0;
		if(time1>12)
		{
			time1=time1-12;
			temp10=1;
		}

		struct dosdate_t d;
		_dos_getdate(&d);
		int day1=d.day;
		int month1=d.month;
		int year1=d.year;

		fstream obj;
		obj.open("entry",ios::out|ios::app);

			obj<<time1<<":";
			if(time2<10)
				obj<<"0";
			obj<<time2<<" ";
			if(temp10==0)
				obj<<"AM";
			if(temp10==1)
				obj<<"PM";
			obj<<"\t\t\t\t\t\t\t";
			obj<<day1;
			if(day1==1 || day1==21 || day1==31)
				obj<<"st";
			if(day1==2 || day1==22)
				obj<<"nd";
			if(day1==3 || day1==23)
				obj<<"rd";
			if(day1 > 3 && day1 <= 20)
				obj<<"th";
			if(day1 > 23 && day1 <=30)
				obj<<"th";
			obj<<" ";
			if (month1==1)
				obj<<"January";
			if (month1==2)
				obj<<"February";
			if (month1==3)
				obj<<"March";
			if (month1==4)
				obj<<"April";
			if (month1==5)
				obj<<"May";
			if (month1==6)
				obj<<"June";
			if (month1==7)
				obj<<"July";
			if (month1==8)
				obj<<"August";
			if (month1==9)
				obj<<"September";
			if (month1==10)
				obj<<"October";
			if (month1==11)
				obj<<"November";
			if (month1==12)
				obj<<"December";
			obj<<", "<<year1;
			obj<<endl;
			obj<<"Dear Diary, "

			<<endl<<"   \t"<<a;
			obj<<endl<<endl;
		obj.close();

		color();
		gotoxy(34,25);
			_setcursortype(_NOCURSOR);
			cprintf("Saving");
			delay(700);
			cout<<".";
			delay(700);
			cout<<".";
			delay(700);
			cout<<".";
			delay(1020);
		menu();
	}

	void view()
	{
		void menu();
		textcolor(7);
		clrscr();
		char m,n;
		_setcursortype(_NOCURSOR);
		int p=1,v=0;
		for (int i=5; i<=75; i++)
		{
			gotoxy(i,2);
				cout<<char(196);
			gotoxy(i,6);
				cout<<char(196);
		}

		gotoxy(39,4);
			color();
			cprintf("VIEW");
		gotoxy(10,8);
			textcolor(3);
			cprintf("DIARY");
		gotoxy(10,10);
			cout<<"CONTACTS";
		gotoxy(9,8);
			cout<<char(16);
		while(v!=13)
		{
			v=getch();
			if (v==0)
				v=getch();

			if (v==27)
				menu();

			if (v==80)
			{
				if (p==1)
				{
					gotoxy(9,8);
						cout<<char(255);
					gotoxy(10,8);
						textcolor(7);
						cprintf("DIARY");
					gotoxy(10,10);
						textcolor(3);
						cprintf("CONTACTS");
					gotoxy(9,10);
						cout<<char(16);
					p=2;
				}

				else if (p==2)
				{
					gotoxy(9,10);
						cout<<char(255);
					gotoxy(10,10);
						textcolor(7);
						cprintf("CONTACTS");
					gotoxy(10,8);
						textcolor(3);
						cprintf("DIARY");
					gotoxy(9,8);
						cout<<char(16);
					p=1;
				}
			}

			if (v==72)
			{
				if (p==1)
				{
					gotoxy(9,8);
						cout<<char(255);
					gotoxy(10,8);
						textcolor(7);
						cprintf("DIARY");
					gotoxy(10,10);
						textcolor(3);
						cprintf("CONTACTS");
					gotoxy(9,10);
						cout<<char(16);
					p=2;
				}

				else if (p==2)
				{
					gotoxy(9,10);
						cout<<char(255);
					gotoxy(10,10);
						textcolor(7);
						cprintf("CONTACTS");
					gotoxy(10,8);
						textcolor(3);
						cprintf("DIARY");
					gotoxy(9,8);
						cout<<char(16);
					p=1;
				}
			}
		}

		switch(p)
		{
			case 1: textcolor(7);
					clrscr();
					gotoxy(35,2);
						color();
						cprintf("My Diary");
						cout<<"\n\n";
					fstream print;
					print.open("entry",ios::in);
					if (!print)
					{
						cout<<"NO ENTRIES IN THE DIARY...";
						getch();
					}
					else
					{
						while(print)
						{
							print.get(m);
							cout<<m;
						}
					print.close();
					getch();
					}
					break;
			case 2: textcolor(7);
					clrscr();
					gotoxy(35,2);
						color();
						cprintf("My Contacts");
						cout<<"\n\n";
					fstream print1;
					print1.open("contact",ios::in);
					if (!print1)
					{
						cout<<"NO ENTRIES IN THE CONTACT...";
						getch();
					}
					else
					{
						while(print1)
						{
							print1.get(m);
							cout<<m;
						}
					print1.close();
					getch();
					}
					break;
		}
		menu();
	}

	void del()
	{
		void menu();
		textcolor(7);
		clrscr();
		char m,n;
		_setcursortype(_NOCURSOR);
		int p=1,v=0;
		for (int i=5; i<=75; i++)
		{
			gotoxy(i,2);
				cout<<char(196);
			gotoxy(i,6);
				cout<<char(196);
		}

		gotoxy(39,4);
			color();
			cprintf("DELETE");
		gotoxy(10,8);
			textcolor(3);
			cprintf("DIARY");
		gotoxy(10,10);
			cout<<"CONTACTS";
		gotoxy(9,8);
			cout<<char(16);
		while(v!=13)
		{
			v=getch();
			if (v==0)
				v=getch();

			if (v==27)
				menu();

			if (v==80)
			{
				if (p==1)
				{
					gotoxy(9,8);
						cout<<char(255);
					gotoxy(10,8);
						textcolor(7);
						cprintf("DIARY");
					gotoxy(10,10);
						textcolor(3);
						cprintf("CONTACTS");
					gotoxy(9,10);
						cout<<char(16);
					p=2;
				}

				else if (p==2)
				{
				gotoxy(9,10);
					cout<<char(255);
				gotoxy(10,10);
					textcolor(7);
					cprintf("CONTACTS");
				gotoxy(10,8);
					textcolor(3);
					cprintf("DIARY");
				gotoxy(9,8);
					cout<<char(16);
				p=1;
				}
			}

			if (v==72)
			{
				if (p==1)
				{
					gotoxy(9,8);
						cout<<char(255);
					gotoxy(10,8);
						textcolor(7);
						cprintf("DIARY");
					gotoxy(10,10);
						textcolor(3);
						cprintf("CONTACTS");
					gotoxy(9,10);
						cout<<char(16);
					p=2;
				}

				else if (p==2)
				{
					gotoxy(9,10);
						cout<<char(255);
					gotoxy(10,10);
						textcolor(7);
						cprintf("CONTACTS");
					gotoxy(10,8);
						textcolor(3);
						cprintf("DIARY");
					gotoxy(9,8);
						cout<<char(16);
					p=1;
				}
			}
		}

		switch(p)
		{
			case 1: fstream dia;
					dia.open("entry",ios::out);
					dia<<"";
					dia.close();
					clrscr();
					_setcursortype(_NOCURSOR);
					for (int r=1; r<3; r++)
					{
						textcolor(7);
						clrscr();
						textcolor(12);
						gotoxy(35,25);
							cprintf("DELETING DATA");
							delay(520);
							cprintf(".");
							delay(520);
							cprintf(".");
							delay(520);
							cprintf(".");
							delay(520);
						}
						break;
			case 2: fstream con;
					con.open("contact",ios::out);
					con<<"";
					con.close();
					clrscr();
					_setcursortype(_NOCURSOR);
					for (r=1; r<3; r++)
					{
						textcolor(7);
						clrscr();
						textcolor(12);
						gotoxy(35,25);
							cprintf("DELETING DATA");
							delay(440);
							cprintf(".");
							delay(440);
							cprintf(".");
							delay(440);
							cprintf(".");
							delay(720);
					}
					break;
	    }

		menu();
	}

	void contact()
	{
		void menu();
		loop:
		textcolor(7);
		clrscr();
		_setcursortype(_NORMALCURSOR);
		char a[25],b[15],c[300];
		gotoxy(35,3);
			color();
			cprintf("ADD CONTACTS");
			cout<<endl<<endl;
			cout<<"NAME :";
			gets(a);
			cout<<endl;
			cout<<"PHONE NO. :";
			gets(b);
			cout<<endl;
			fstream obj1;
			obj1.open("contact",ios::out|ios::app);
				obj1<<a<<"\t\t"<<b<<"\t\t"<<"\n";
			obj1.close();
			cout<<endl;
			cout<<"Do you want to add more contacts (Y/N) :";
			char y=getch();
		if (y=='Y'||y=='y')
			goto loop;

		else
		{
			gotoxy(35,25);
				color();
				_setcursortype(_NOCURSOR);
				cprintf("Saving");
				delay(400);
				cout<<".";
				delay(400);
				cout<<".";
				delay(400);
				cout<<".";
				delay(720);
		}


		menu();
	}

	void menu()
	{
		textcolor(7);
		clrscr();
		_setcursortype(_NOCURSOR);
		int p=1,v=0;
		for (int i=5; i<=75; i++)
		{
			gotoxy(i,2);
				cout<<char(196);
			gotoxy(i,6);
				cout<<char(196);
		}

		gotoxy(35,4);
			color();
			cprintf("MAIN MENU");
		gotoxy(10,8);
			textcolor(3);
			cprintf("ENTRY");
		gotoxy(10,10);
			cout<<"VIEW";
		gotoxy(10,12);
			cout<<"DELETE";
		gotoxy(10,14);
			cout<<"CONTACTS";
		gotoxy(10,16);
			cout<<"EXIT";
		gotoxy(9,8);
			cout<<char(16);

		while(v!=13)
		{
			v=getch();
			if (v==0)
				v=getch();

			if (v==27)
				programmer();

			if (v==80)
			{
				if (p==1)
				{
					gotoxy(9,8);
						cout<<char(255);
					gotoxy(10,8);
						textcolor(7);
						cprintf("ENTRY");
					gotoxy(10,10);
						textcolor(3);
						cprintf("VIEW");
					gotoxy(9,10);
						cout<<char(16);
					p=2;
				}

				else if (p==2)
				{
					gotoxy(9,10);
						cout<<char(255);
					gotoxy(10,10);
						textcolor(7);
						cprintf("VIEW");
					gotoxy(10,12);
						textcolor(3);
						cprintf("DELETE");
					gotoxy(9,12);
						cout<<char(16);
					p=3;
				}

				else if (p==3)
				{
					gotoxy(9,12);
						cout<<char(255);
					gotoxy(10,12);
						textcolor(7);
						cprintf("DELETE");
					gotoxy(10,14);
						textcolor(3);
						cprintf("CONTACTS");
					gotoxy(9,14);
						cout<<char(16);
					p=4;
				}

				else if (p==4)
				{
					gotoxy(9,14);
						cout<<char(255);
					gotoxy(10,14);
						textcolor(7);
						cprintf("CONTACTS");
					gotoxy(10,16);
						textcolor(3);
						cprintf("EXIT");
					gotoxy(9,16);
						cout<<char(16);
					p=5;
				}

				else if (p==5)
				{
					gotoxy(9,16);
						cout<<char(255);
					gotoxy(10,16);
						textcolor(7);
						cprintf("EXIT");
					gotoxy(10,8);
						textcolor(3);
						cprintf("ENTRY");
					gotoxy(9,8);
						cout<<char(16);
					p=1;
				}
			}

			if (v==72)
			{
				if (p==1)
				{
					gotoxy(9,8);
						cout<<char(255);
					gotoxy(10,8);
						textcolor(7);
						cprintf("ENTRY");
					gotoxy(10,16);
						textcolor(3);
						cprintf("EXIT");
					gotoxy(9,16);
						cout<<char(16);
					p=5;
				}

				else if (p==2)
				{
					gotoxy(9,10);
						cout<<char(255);
					gotoxy(10,10);
						textcolor(7);
						cprintf("VIEW");
					gotoxy(10,8);
						textcolor(3);
						cprintf("ENTRY");
					gotoxy(9,8);
						cout<<char(16);
					p=1;
				}

				else if (p==3)
				{
					gotoxy(9,12);
						cout<<char(255);
					gotoxy(10,12);
						textcolor(7);
						cprintf("DELETE");
					gotoxy(10,10);
						textcolor(3);
						cprintf("VIEW");
					gotoxy(9,10);
						cout<<char(16);
					p=2;
				}

				else if (p==4)
				{
					gotoxy(9,14);
						cout<<char(255);
					gotoxy(10,14);
						textcolor(7);
						cprintf("CONTACTS");
					gotoxy(10,12);
						textcolor(3);
						cprintf("DELETE");
					gotoxy(9,12);
						cout<<char(16);
					p=3;
				}

				else if (p==5)
				{
					gotoxy(9,16);
						cout<<char(255);
					gotoxy(10,16);
						textcolor(7);
						cprintf("EXIT");
					gotoxy(10,14);
						textcolor(3);
						cprintf("CONTACTS");
					gotoxy(9,14);
						cout<<char(16);
					p=4;
				}
			}
		}

		switch(p)
		{
			case 1: entry();
					break;
			case 2: view();
					break;
			case 3: del();
					break;
			case 4: contact();
					break;
			case 5: programmer();
					break;
		}

	}

	void password()
	{
			clrscr();
		gotoxy(35,11);
			textcolor(9);
			cprintf("My Diary");
			cout<<endl;
			cout<<"\t\t\t--*--*--*--*--*--*--*--*--*--";
		delay(60);
			clrscr();
		gotoxy(35,10);
			textcolor(2);
			cprintf("My Diary");
			cout<<endl;
			cout<<"\t\t\t--*--*--*--*--*--*--*--*--*--";
		delay(60);
			clrscr();
		gotoxy(35,9);
			textcolor(3);
			cprintf("My Diary");
			cout<<endl;
			cout<<"\t\t\t--*--*--*--*--*--*--*--*--*--";
		delay(60);
			clrscr();
		gotoxy(35,8);
			textcolor(4);
			cprintf("My Diary");
			cout<<endl;
			cout<<"\t\t\t--*--*--*--*--*--*--*--*--*--";
		delay(60);
			clrscr();
		gotoxy(35,7);
			textcolor(6);
			cprintf("My Diary");
			cout<<endl;
			cout<<"\t\t\t--*--*--*--*--*--*--*--*--*--";
		delay(60);
			clrscr();
		gotoxy(35,6);
			cprintf("My Diary");
			textcolor(7);
			cout<<endl;
			cout<<"\t\t\t--*--*--*--*--*--*--*--*--*--";

		for (int j=0; j<3; j++)
		{

			textcolor(7);
			clrscr();
			gotoxy(35,6);
			cprintf("My Diary");
			cout<<endl;
			textcolor(7);
			cout<<"\t\t\t--*--*--*--*--*--*--*--*--*--";
			char a[10];
			gotoxy(35,16);
				cout<<"PASSWORD";
			gotoxy(30,17);
				cout<<" _________________";
			gotoxy(30,18);
				cout<<"|_________________|";
			gotoxy(32,18);


			for (int i=0; i<15; i++)
			{
				a[i]=getch();

				if (a[i]==0)
					a[i]=getch();

				if (a[i]==27)
					programmer();


				cout<<"*";

				if (a[0]=='r'&&a[1]=='e'&&a[2]=='e'&&a[3]=='t'&&a[4]==13)
				{
					gotoxy(33,19);
						textcolor(GREEN);
						cprintf("Access Granted");
					gotoxy(34,25);
						cout<<"Please Wait";
						delay(400);
						cout<<".";
						delay(400);
						cout<<".";
						delay(400);
						cout<<".";
						delay(720);
					textcolor(7);
					menu();
				}
			}
			
			gotoxy(33,19);
				textcolor(RED);
				cprintf("Access Denied");
			getch();
		}

		programmer();
	}


	void main()
	{
		textcolor(7);
		clrscr();
		_setcursortype(_NOCURSOR);
		gotoxy(35,12);
			color();
			cprintf("My Diary");
			cout<<endl;
			cout<<"\t\t\t--*--*--*--*--*--*--*--*--*--";
			
			sleep(1);

		textcolor(7);
		password();
		getch();
	}


