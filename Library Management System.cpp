#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class Lib
{
   public:
       char bookname[100],auname[50],sc[20],sc1[50];
       int q,B,p;
       Lib()
       {
           strcpy(bookname,"Khong co ten Sach");
           strcpy(auname,"Khong co ten Tac Gia");
           strcpy(sc,"Khong co ID Sach");
           strcpy(sc1,"Khong co ID Sach");
           q=0;
           B=0;
           p=0;
       }
          void get();
          void student();
          void pass();
          void librarian();
          void password();
          void getdata();
          void show(int);
          void booklist(int);
          void modify();
          void see(int);
          int branch(int);
          void issue();
          void der(char[],int,int);
          void fine(int,int,int,int,int,int);
};
void Lib::getdata()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tNhap chi tiet :-\n";
                    cout<<"\n\t\tNhap ten Sach : ";
                    cin.getline(bookname,100);
                    for(i=0;bookname[i]!='\0';i++)
                    {
                    if(bookname[i]>='a'&&bookname[i]<='z')
                       bookname[i]-=32;
                    }
                    cout<<"\n\t\tNhap ten Tac Gia : ";
                    cin.getline(auname,50);
                    cout<<"\n\t\tNhap ten An pham : ";
                    cin.getline(sc1,50);
                    cout<<"\n\t\tNhap ID Sach : ";
                    cin.getline(sc,20);
                    cout<<"\n\t\tNhap Gia Sach : ";
                    cin>>p;
                    cout<<"\n\t\tNhap so luong Sach : ";
                    cin>>q;
}
void Lib::show(int i)
{
    cout<<"\n\t\tTen Sach : "<<bookname<<endl;
    cout<<"\n\t\tBTen Tac Gia : "<<auname<<endl;
    cout<<"\n\t\tMa so Sach : "<<sc<<endl;
    cout<<"\n\t\tSach xuat ban : "<<sc1<<endl;
    if(i==2)
    {
        cout<<"\n\t\tGia Sach : "<<p<<endl;
        cout<<"\n\t\tSo luong Sach : "<<q<<endl;
    }
}
  void Lib::booklist(int i)
  {
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tKhong tim thay File.";
                else
                {
                    cout<<"\n\t    ************ Danh sach Sach ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
                getch();
                system("cls");
                if(i==1)
                    student();
                else
                    librarian();
    }
  void Lib::modify()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Hay nhap 1 lua chon :-\n";
    cout<<"\n\t\t1.Sua doi Sach hien tai\n\n\t\t2.Them Sach moi\n\n\t\t3.Xoa Sach\n\n\t\t4.Tro lai\n";
    cout<<"\n\n\t\tNhap lua chon cua ban : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tKhong tim thay File\n";
                        cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
                        getch();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tHay nhap 1 lua chon :-\n";
                        cout<<"\n\t\t1.Tim kiem theo Ten Sach\n\n\t\t2.Tim kiem theo ID Sach\n";
                        cout<<"\n\t\tNhap lua chon cua ban : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tNhap ten Sach : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i++);
                                        if(bookname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tNhap ID Sach : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tNhap lua chon khong dung.....\n";
                            cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tKhong tim thay Sach.\n";
                            cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tCap nhat thanh cong.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);
                    system("cls");
                    getdata();
                    ofstream outf("Booksdata.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tThem Sach thanh cong.\n";
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("Booksdata.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tKhong tim thay File\n";
                        cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
                        getch();
                        intf1.close();
                        system("cls");
                        librarian();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tHay nhap 1 lua chon:-\n";
                        cout<<"\n\t\t1.Xoa theo ten Sach\n\n\t\t2.Xoa theo ID Sach\n";
                        cout<<"\n\t\tNhap lua chon cua ban : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tNhap ten Sach : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&bookname[i]!='\0'&&st1[i]!='\0'&&(st1[i]==bookname[i]||st1[i]==bookname[i]+32);i++);
                                        if(bookname[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tNhap ID Sach : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("Booksdata.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
                                        if(sc[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("Booksdata.txt");
                    rename("temp.txt","Booksdata.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tINhap lua chon khong dung.....\n";
                            cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tKhong tim thay Sach.\n";
                            cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tXoa Sach thanh cong.\n";

    }
    else if(i==4)
    {
    system("cls");
    librarian();
    }
    else
    {
    cout<<"\n\t\tLoi nhap.\n";
    cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
    getch();
    system("cls");
    librarian();

  }
  int Lib::branch(int x)
  {
      int i;
      cout<<"\n\t\t>>Hay nhap 1 lua chon :-\n";
      cout<<"\n\t\t1.Sach Kinh Te - Tai Chinh\n\n\t\t2.Sach Chinh Tri - Phap Luat\n\n\t\t3.Sach Ky Thuat - Cong Nghe\n\n\t\t4.Sach Van Hoa - Nghe Thuat\n\n\t\t5.Sach Tam Linh - Ton Giao\n\n\t\t6.Sach Giao Trinh\n\n\t\t7.Tro lai Menu\n";
      cout<<"\n\t\tNhap lua chon cua ban : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  student();
                  else
                    librarian();
          default : cout<<"\n\t\tVui long nhap tuy chon chinh xac";
                    getch();
                    system("cls");
                    branch(x);
        }
  }
  void Lib::see(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tKhong tim thay File.\n";
            cout<<"\n\t\t->Nhan phim bat ky de tiep tuc.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            librarian();
        }

      system("cls");
      cout<<"\n\t\tHay nhap 1 lua chon :-\n";
      cout<<"\n\t\t1.Tim kiem theo Ten Sach\n\n\t\t2.Tim kiem theo ID Sach\n";
      cout<<"\n\t\tNhap lua chon cua ban : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tNhap Ten Sach : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&bookname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bookname[i]||ch[i]==bookname[i]+32);i++);
            if(bookname[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tTim thay Sach :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tNhap ID Sach : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&sc[i]!='\0'&&ch[i]!='\0'&&ch[i]==sc[i];i++);
              if(sc[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tTim thay Sach :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tVui long nhap tuy chon chinh xac";
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tSach khong ton tai \n";

    cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    librarian();


  }
void Lib::issue()
{
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Hay nhap 1 lua chon :-\n";
    cout<<"\n\t\t1.Phat hanh Sach\n\n\t\t2.Xem danh sach Sach da phat hanh\n\n\t\t3.Tim kiem Sinh vien da duoc Phat hanh Sach\n\n\t\t4.Phat hanh lai Sach\n\n\t\t5.Tra Sach\n\n\t\t6.Tro lai Menu\n\n\t\tNhap lua chon cua ban : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Nhap vao chi tiet :-\n";
    cout<<"\n\t\tNhap Ten Sach : ";
    cin.getline(bookname,100);
    cout<<"\n\t\tNhap ID Sach : ";
    cin.getline(sc,20);
    //strcpy(st,sc);
    der(sc,b,1);
    cout<<"\n\t\tNhap Ten Hoc sinh/Sinh vien : ";
    cin.getline(auname,100);
    cout<<"\n\t\tNhap ID Hoc sinh/Sinh vien : ";
    cin.getline(sc1,20);
    cout<<"\n\t\tNhap ngay : ";
    cin>>q>>B>>p;
    ofstream outf("student.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tPhat hanh Sach thanh cong.\n";
    }
    else if(i==2)
    {
    ifstream intf("student.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->Chi tiet :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\tTen Hoc sinh/Sinh vien : "<<auname<<"\n\t\t"<<"ID Hoc sinh/Sinh vien : "<<sc1<<"\n\t\t"<<"Ten Sach : "<<bookname<<"\n\t\t"<<"ID Sach : "<<sc<<"\n\t\t"<<"Ngay : "<<q<<"/"<<B<<"/"<<p<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Vui long nhap Chi tiet :-\n";
        cout<<"\n\n\t\tNhap Ten Hoc sinh/Sinh vien : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tNhap ID Hoc sinh/Sinh vien : ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("student.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;sc1[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc1[i];i++);
              if(sc1[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->Chi tiet :-\n";
                      cout<<"\n\t\tTen Hoc sinh/Sinh vien : "<<auname;
                      cout<<"\n\t\tID Hoc sinh/Sinh vien : "<<sc1;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Chi tiet Sach *******\n";
                  cout<<"\n\t\tTen Sach : "<<bookname;
                  cout<<"\n\t\tID Sach : "<<sc;
                  cout<<"\n\t\tNgay : "<<q<<"/"<<B<<"/"<<p<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tKhong tim thay Ho so.";
    }
    else if(i==4)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Vui long nhap chi tiet :-\n";
    cout<<"\n\n\t\tNhap ID Hoc sinh/Sinh vien : ";
    cin.getline(st,50);
    cout<<"\n\t\tNhap ID Sach : ";
    cin.getline(st1,20);
    fstream intf("student.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
                {
                    d=q;
                    m=B;
                    y=p;
                    cout<<"\n\t\tNhap vao Ngay moi : ";
                    cin>>q>>B>>p;
                    fine(d,m,y,q,B,p); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\n\t\tPhat hanh lai thanh cong."; //fn3
                    break;
                }
                   intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==5)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Vui long nhap chi tiet :-\n";
    cout<<"\n\t\tNhap ID Sach : ";
    cin.getline(st1,20);
    der(st1,b,2);
    cout<<"\n\n\t\tNhap ID Hoc sinh/Sinh vien: ";
    cin.getline(st,20);
    cout<<"\n\t\tNhap vao ngay hien tai (Ngay tra Sach) : ";
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("student.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;sc[i]!='\0'&&st1[i]!='\0'&&st1[i]==sc[i];i++);
            for(j=0;sc1[j]!='\0'&&st[j]!='\0'&&st[j]==sc1[j];j++);
            if(sc[i]=='\0'&&sc1[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    fine(q,B,p,d,m,y);
                    cout<<"\n\t\tDa tra Sach thanh cong.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("student.txt");
    rename("temp.txt","student.txt");
    }
    else if(i==6)
    {
    system("cls");
    librarian();
    }
    else
        cout<<"\n\t\tNhap loi.\n";

    cout<<"\n\n\t\tNhan phim bat ky de tiep tuc.....";
    getch();
    system("cls");
    librarian();
}
void Lib::fine(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; //fn1353
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\n\t\tTong tien phat la : "<<n2;
    
}
void Lib::der(char st[],int b,int x)
{
    int i,cont=0;
    fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&sc[i]!='\0'&&st[i]!='\0'&&st[i]==sc[i];i++);
        if(sc[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tKhong tim thay Sach.\n";
        cout<<"\n\n\t\tNhan phim bat ky de tiep tuc.....";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}
void Lib::get()
{
   int i;
        cout<<"\n\t*********** HE THONG QUAN LY THU VIEN ***********\n"<<"\n\t\t\t    NHOM 1718 \n\t\t     Mai Xuan Duc 1720056\n\t\t     Nguyen Huynh Quyen 1720192\n\t\t     Nguyen Hoa My Nhi 18200192\n  ";
        cout<<"\n\t\t>>Hay nhap 1 lua chon \n";
        cout<<"\n\t\t1.Hoc sinh/Sinh vien\n\n\t\t2.Quan Ly\n\n\t\t3.Dong App\n";
        cout<<"\n\t\tNhap lua chon cua ban : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tVui long nhap lua chon chinh xac";
            getch();
            system("cls");
           get();
        }
}
void Lib::student()
{
    int i;
        cout<<"\n\t************ WELCOME HOC SINH/SINH VIEN ************\n";
        cout<<"\n\t\t>>Hay nhap 1 lua chon:\n";
        cout<<"\n\t\t1.Xem danh sach Sach\n\n\t\t2.Tim kiem Sach\n\n\t\t3.Tro ve Menu\n\n\t\t4.Dong App\n";
        cout<<"\n\t\tNhap lua chon cua ban : ";
        cin>>i;
            if(i==1)
                booklist(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tVui long nhap lua chon chinh xac";
                getch();
                system("cls");
                student();
            }
}
void Lib::pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"1718"};
    cout<<"\n\t\tNhap password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tSai Password.\n\n\t\tThu lai.....\n";
        getch();
        system("cls");
        get();
    }
}
void Lib::librarian()
{
    int i;
        cout<<"\n\t************ WELCOME QUAN LY ************\n";
        cout<<"\n\t\t>>Hay nhap 1 lua chon:\n";
        cout<<"\n\t\t1.Xem danh sach Sach\n\n\t\t2.Tim kiem Sach\n\n\t\t3.Chinh Sua/Them Sach/Xoa Sach\n\n\t\t4.Phat hanh Sach/Thong tin Phat hanh\n\n\t\t5.Thay doi Mat khau\n\n\t\t6.Tro lai Menu\n\n\t\t7.Dong App\n";
        cout<<"\n\t\tNhap lua chon cua ban : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modify();
                     break;
            case 4:issue();
                     break;
            case 5:password();
                    break;
            case 6:system("cls");
                     get();
                     break;
            case 7:exit(0);
            default:cout<<"\n\t\tVui long nhap lua chon chinh xac";
            getch();
            system("cls");
            librarian();
        }
}
void Lib::password()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"1718"};
    system("cls");
    cout<<"\n\n\t\tNhap mat khau cu : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**Password phai it hon 20 ky tu va khong co khoang trang**\n\n";
        cout<<"\n\t\tNhap mat khau moi : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tMat khau moi khong dung yeu cau \n\n\t\tNhan phim bat ky de thu lai.....";
                getch();
                system("cls");
                password();
                librarian();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*";
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tThay doi mat khau thanh cong.";
        cout<<"\n\t\tNhan phim bat ky de tiep tuc......";
        getch();
        system("cls");
        librarian();
    }
    else
    {
        cout<<"\n\n\t\tSai mat khau.....\n";
        cout<<"\n\t\tNhap phim 1 de thu lai hoac phim 2 de Tro lai Menu";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            librarian();
        }
    }
}
int main()
{
    Lib obj;
    obj.get();
    getch();
    return 0;
}
