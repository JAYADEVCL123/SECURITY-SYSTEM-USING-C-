#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a, i=0;
    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string creads[2],cp[2];

    cout <<"_______________SECURITY SYSTEM_______________"<<endl;
    cout <<"-----------------------------------------------------"<<endl;
    cout <<"***************1.REGISTER       ********************"<<endl;
    cout <<"***************2.LOGIN          ********************"<<endl;
    cout <<"***************3.CHANGE PASSWORD********************"<<endl;
    cout <<"***************4.END PROGRAM    ********************"<<endl;
    cout <<"-----------------------------------------------------"<<endl;

    do
    {
        cout<<"ENTER YOUR CHOICE : "<<endl;
        cin>>a;
        switch(a)
        {
            case 1:{
                      cout<<"------------------------------"<<endl;
                      cout<<"##########REGISTER############"<<endl;
                      cout<<"------------------------------"<<endl;
                      cout<<"PLEASE ENTER THE USER NAME"<<endl;
                      cin>>name;
                      cout<<"PLEASE ENTER THE PASSWORD"<<endl;
                      cin>>password0;
                      cout<<"PLEASE ENTER YOUR AGE"<<endl;
                      cin>>age;

                      ofstream of1;
                      of1.open("file.txt");

                      if(of1.is_open())
                      {
                          of1<<name<<"/n";
                          of1<<password0;
                          cout<<"REGISTRATION SUCESSFULL"<<endl;
                      }
                   }
                   break;

            case 2:{
                     i=0;
                     cout<<"------------------------------"<<endl;
                     cout<<"############LOGIN#############"<<endl;
                     cout<<"------------------------------"<<endl;

                     ifstream of2;
                     of2.open("file.txt");
                     cout<<"PLEASE ENTER THE USER NAME"<<endl;
                     cin>>user;
                     cout<<"PLEASE ENTER THE PASSWORD"<<endl;
                     cin>>pass;

                     if(of2.is_open())
                     {
                         while(of2.eof())
                         {
                             while(getline(of2,text))
                             {
                                 isstringstream iss(text);
                                 iss>>word;
                                 creads[i] = word;
                                 i++;
                             }
                             if(user == creads[0] && pass == creads[1])
                             {
                                 cout<<"LOGIN SUCESSFULL";
                                 cout<<"DETAILS ARE";
                                 cout<<"USER NAME " + name<<endl;
                                 cout<<"PASSWORD  " + pass<<endl;
                                 cout<<"AGE       " + age<<endl;
                             }
                             else
                             {
                                 cout<<"INCORRECT CREDENTIALS";
                                 cout<<"PRESS 2 TO LOGIN";
                                 cout<<"PRESS 3 TO CHANGE PASSWORD";
                             }
                         }
                     }


                   }
                   break;
            case 3 :
                {
                    i=0;
                    cout<<"-----------------CHANGE PASSWORD-----------------"<<endl;
                    ifstream of0;
                    of0.open("file.txt");
                    if(of0.is_open())
                    {
                        while(of0.eof())
                        {
                            while(getline(of0,text))
                            {
                                isstringstream iss(text);
                                iss>>word1;
                                cp[i] = word1;
                                i++;
                            }
                            if(old == cp[i])
                            {
                                of0.close();
                                ofstream of1;
                                if(of1.is_open())
                                {
                                    cout<<"ENTER YOUR NEW PASSWORD";
                                    cin>>password1;
                                    cout<<"ENTER YOUR NEW PASSWORD AGAIN";
                                    cin>>password2;

                                    if(password1 == password2)
                                    {
                                        of1<<cp[0]<<"/n";
                                        cout<<password1<<endl;
                                        cout<<"PASSWORD CHANGED SUCESSFULLY";
                                    }
                                    else
                                    {
                                        of1<<cp[0]<<"/n";
                                        cout<<password1<<endl;
                                        cout<<"PASSWORD DOESNOT MATCH";
                                    }
                                }
                            }
                            else
                            {
                                cout<<"PLEASE ENTER THE VALID PASSWORD"<<endl;
                                break;
                            }
                        }
                    }
                    break;
                }
            case 4 :
                     {
                       cout<<"--------------------THANKYOU-------------------"<<endl;
                       break;
                     }
            default :
                     {
                         cout<<"ENTER THE VALID CHOICE";
                     }
        }
    } while(a<=4);
    return 0;
}
