#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdio>
#include<cstdlib>

using namespace std;
static int p = 0;
class RoomAllocation{
    char RoomNo[5] , Host[10], Start[5] , End[5],
    From[10],to[10],  Chair[8][4][10];

    public :
        void ReserveRoom();

        void allotment();

        void empty();

        void show();

        void avail();
        
        void position(int i);


} room[10];

void vline(char ch)
{
    for (int i = 80; i>0; i--)
    {
        cout<<ch;
    }
}

void RoomAllocation:: ReserveRoom()
{
    cout<< "Book a Room by entering its Room number : ";

    cin>>room[p].RoomNo;

    cout<<"\nRoom is Booked by (Host's Name)  : ";

    cin>>room[p].Host;

    cout<<"\nCheck-in Time(am/pm) : ";

    cin>> room[p].Start;

    cout<<"\nCheck-out Time(am/pm) : ";

    cin>> room[p].End;

  /**/  cout<<"\nFrom : \t";

    cin>> room[p].From;

    cout<<"\nTo : \t";

    cin>> room[p].to;

    room[p].empty();

    p++;
}

void RoomAllocation :: allotment()
{
    int chair ;

    char num[5] ;

    top : cout<<"Room no. : ";
    cin >> num;

    int n;
     
     for (n = 0; n <= p ; n++)
     {
        if(strcmp(room[n].RoomNo , num)== 0 )
        break;

     }

     while(n <= p)
     {
        cout <<"\n Chair Number : ";

        cin>> chair ;
        
        if(chair >32)
        {
            cout<<"\nThere are  only 32 chairs available in the room ";


        }else
        { 
            if(strcmp(room[n].Chair[chair/4][(chair % 4) - 1], "Empty") == 0)////////////
             {
               cout<<"\nSeat is reserved for (name) : ";
         
         cin>>room[n].Chair[chair/4][(chair % 4) -1] ;         
      
       cout<<"\nYour Seat is reserved." ;

               break;
            } 
            else
           {
             cout<<"\nThe Chair number is already reserved .\n" ;
           }      
        }
     }
    if( n > p)
    {
        cout<<"Enter different Room number : \n";
        goto top; 
    }
 }
     

     void RoomAllocation :: empty()
     {
        for(int i = 0; i<8 ; i++)
        {
          for(int j = 0; j<4 ; j++)
          {
            strcpy(room[p].Chair[i][j] , "Empty") ;
            }
        }
     }

     void RoomAllocation :: show()
     {
        int n;
        char number[5] ;
        
        cout<<"Enter Room number you want to book for your seat : " ;
        cin>>number ;

        for(n = 0; n <= p ; n++)
        {
            if(strcmp(room[n].RoomNo , number ) == 0)
             break;
        }

        while (n <= p){
            vline('*');
            cout<<"\nRoom Number :\t"<<room[n].RoomNo <<"\nHost : \t"<<room[n].Host
            <<"\t\tStart Time : " <<room[n].Start<<"\t End time : "<<room[n].End
            <<"\nFrom : \t\t"<<room[n].From<< "\t\tTo : \t\t" <<room[n].to <<"\n" ;
         vline('*') ;

         room[0].position(n);
         int a = 1;

         for(int i = 0; i < 8 ; i++)
         {
            for(int j = 0; j< 4; j++)
            {
                a++ ;
                if(strcmp(room[n].Chair[i][j] , "Empty") != 0)
                cout<<"\nThe Chair number "<<(a -1 )<<" is reversed for "<<room[n].Chair[i][j]<<".";
            }
         }
       break;
        }
        if (n>p)
        cout<<"Status not available . Please select a Room Booked before";
     }

     void RoomAllocation :: position(int l)
     {
        int s=0 ; p= 0;

        for(int i = 0; i < 8 ; i++){
            cout<<"\n";

            for(int j = 0; j < 4 ; j++) {
                s++;
                if(strcmp(room[l].Chair[i][j], "Empty") == 0)
                {
                    cout.width(5);
                    cout.fill(' ');
                    
                    cout<<s<<".";

                    cout.width(10);

                    cout.fill(' ');

                    cout<<room[l].Chair[i][j];
                    p++;

                }
                else {
                   cout.width(5);
                    cout.fill(' ');
                    
                    cout<<s<<".";

                    cout.width(10);

                    cout.fill(' ');

                    cout<<room[l].Chair[i][j];
 
                }
            }
        }

        cout<<"\n\nThere are "<<p<<" seats unreserved in the Room number : "<<room[l].RoomNo;
        
     }


     void RoomAllocation :: avail()
     {
        for( int n =0; n<p ; n++)
        {
            vline('*') ;

            cout<<"\nRoom number : \t"<<room[n].RoomNo<<"\nHost : \t"<<room[n].Host
            <<"\t\tStart Time : \t" <<room[n].Start<<"\tEnd time : \t"<<room[n].End
            <<"\nFrom : \t\t"<<room[n].From<< "\t\tTo : \t\t\t" <<room[n].to <<"\n" ;
         vline('*') ;cout<<"\n";
         vline('_') ;
        }
     }
    int main()
{   system("cls") ;
    int w;
     cout<<"\t\t\tWELCOME";
    while(1)
    {          cout<<"\n\n\n" ;
        cout<<"\t\t\t1.Book a Room \n\t\t\t"<< "2.Make Reservation for a chair\n\t\t\t"
        <<"3.Check status for a Room\n\t\t\t"<<"4.Show Rooms status. \n\t\t\t"
        <<"5.Exit" ;
        cout<<"\n\t\t\tEnter Your Choice Here :- " ;
                cin>>w;
         switch(w)
        {       case 1: room[p].ReserveRoom();
            break;
                case 2: room[p].allotment();
            break;
                case 3: room[0].show();
            break;
                case 4: room[0].avail();
            break;
                case 5: cout<<"Thank you ";
                exit(0);
            break;  } }
    return 0;}