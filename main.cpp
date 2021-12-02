#include<iostream>
#include <unistd.h>
#include "Peoplemanager.h"


using namespace std;
int main(){


    PeopleManager *manger = new PeopleManager();
    manger->load();

    while(true){

        system("clear");
        manger->Show_Menu();
        cout<<"请输入选项:"<<endl;
        int selection;
        cin>>selection;
        cin.get();

        switch(selection){
            
            case 0:exit(0);break;
            case 1:manger->addWorker();break;
            case 2:manger->deleteEm();break;
            case 3:manger->showAllPerson();break;
            case 4:manger->modifyEmInfo();break;
            case 5:manger->showEmInfo();break;
            default: 
            {
                cout<<"错误的选项，请重新输入"<<endl;
            }

        }

        manger->save();
        sleep(1);

    }

    delete manger;
    return 0;

}