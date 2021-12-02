#include <iostream>
#include "Peoplemanager.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
using namespace std;
#include<vector>
#include<fstream>
#define DataFile "data.txt"

void PeopleManager::addWorker(){
    cout<<"此次添加数量："<<endl;
    int num=0;
    cin>>num;
    if(num<0){
        cout<<"添加的数量必须大于0"<<endl;
        return;
    }

    Worker ** workerArray = new Worker*[this->m_EmpNum + num];

    if (this->workerArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            workerArray[i] = this->workerArray[i];
        }
    }

    for (int i = 0; i < num; i++)
	{
        int id;
        string name;
        int dSelect;

        bool idexist =false;
        do{
            cout << "请输入第 " << i + 1 << "个新职工编号：" << endl;
            cin >> id;
            cin.get();
            idexist = this->findWhereEm(id)!=-1;
            if(idexist)cout<<"编号已经存在，请重新输入"<<endl;
        }while(idexist);


        cout << "请输入第 " << i + 1 << "个新职工姓名：" << endl;
        cin >> name;
        cin.get();

        cout << "请选择该职工的岗位：" << endl;
        cout << "1、普通职工" << endl;
        cout << "2、经理" << endl;
        cout << "3、老板" << endl;
        cin >> dSelect;
        cin.get();

        Worker * worker = NULL;
        switch (dSelect)
        {
        case 1: //普通员工
            worker = new Employee(id, name, 1);
            break;
        case 2: //经理
            worker = new Manager(id, name, 2);
            break;
        case 3:  //老板
            worker = new Boss(id, name, 3);
            break;
        default:
            break;
        }

        workerArray[this->m_EmpNum + i] = worker;
	}

    if(this->workerArray != NULL) delete [] this->workerArray;
    this->workerArray = workerArray;
    this->m_EmpNum = num + this->m_EmpNum;
    cout<<"添加完成！";
    cout<<"按任意键继续"<<endl;
    cin.get();
}

void PeopleManager::Show_Menu()
{
	cout << "欢迎来到职工管理系统！" << endl;
	cout << "0.退出程序" << endl;
	cout << "1.增加职工" << endl;
	cout << "2.删除职工" << endl;
	cout << "3.显示所有职工信息" << endl;
	cout << "4.修改职工信息" << endl;
	cout << "5.查找职工信息" << endl;
}

void PeopleManager::showAllPerson()
{
    if(this->m_EmpNum==0){
        cout<<"没有人员信息！"<<endl;
        return;
    }else{

        cout<<"以下是现有所有人员信息："<<endl;
        for(int i=0;i<this->m_EmpNum;i++){
            Worker * work = this->workerArray[i];
            work->showInfo();
        }
    }
    cout<<"显示完成，按任意键继续"<<endl;
    cin.get();
}

void PeopleManager::save(){

    ofstream ofs;
    ofs.open(DataFile, ios::out);

    if(this->m_EmpNum<=0){
        // cout<<"没有员工数据可保存"<<endl;
        ofs.close();
        return;
    }else{

        for(int i=0;i<this->m_EmpNum;i++){
            ofs<<this->workerArray[i]->m_Name<<" "
            <<this->workerArray[i]->m_Id<<" "
            <<this->workerArray[i]->m_DeptId<<" "
            <<this->workerArray[i]->gettype()<<endl;
        }
        ofs.close();
        // cout<<"数据已经保存"<<endl;
        return;


    }

}


void PeopleManager::load(){

    ifstream ifs;

    ifs.open(DataFile, ios::in);
    if(!ifs.is_open()){
        cout<<"打开文件失败，请检查文件"<<endl;
        ifs.close();
        return;
    }

    ifs.get();
    if(ifs.eof()){
        cout<<"文件内容为空，请检查文件"<<endl;
        ifs.close();
        return;
    }

    string name;
    int id, did, type;
    vector<Worker*>work_vector; 
    while(ifs>>name && ifs>>id && ifs>>did && ifs>>type){

        Worker * worker;
        if(type==1) worker = new Employee(id, name, did);
        if(type==2) worker = new Manager(id, name, did);
        if(type==3) worker = new Boss(id, name, did);
        work_vector.push_back(worker);
    }

    unsigned int number_in_file = work_vector.size();
    Worker ** array = new Worker*[number_in_file + this->m_EmpNum];

    for(int i=0;i<this->m_EmpNum;i++){
        array[i] = this->workerArray[i];
    }

    for(int i=0;i<number_in_file;i++){
        array[i+this->m_EmpNum] = work_vector[i];
    }

    if(this->workerArray != NULL){
        delete [] this->workerArray;
    }
    this->workerArray = array;
    this->m_EmpNum = number_in_file + this->m_EmpNum;
    cout<<this->m_EmpNum<<endl;
}


int PeopleManager::findWhereEm(int id){

    for(int i=0;i<this->m_EmpNum;i++){

        if(this->workerArray[i]->m_Id==id){
            return i;
        }
    }

    return -1;
}

void PeopleManager::deleteEm(){
    int id;
    cout<<"请输入需要删除的人的ID：";
    cin>>id;
    cin.get();

    unsigned int  w =  this->findWhereEm(id);

    if(w!=-1){

        for(int j=w;j<this->m_EmpNum-1;j++){
            this->workerArray[j] = this->workerArray[j+1];
        }
        this->m_EmpNum-=1;
        cout<<"已经删除"<<endl;
        return;

    }


    cout<<"没有找到需要删除的人"<<endl;
}

void PeopleManager::showEmInfo(){

    int id;
    cout<<"请输入需要查询的人的ID：";
    cin>>id;
    cin.get();
    if(this->findWhereEm(id)!=-1){
        this->workerArray[this->findWhereEm(id)]->showInfo();
    }else{
        cout<<"没有该ID"<<endl;
    }
    cout<<"按任意键继续"<<endl;
    cin.get();
}

void PeopleManager::modifyEmInfo(){

    int id;
    cout<<"请输入需要修改的人的ID：";
    cin>>id;
    cin.get();
    int w = this->findWhereEm(id);
    if(w==-1){
        cout<<"没有该ID"<<endl;
        return;
    }else{

        string name;
        int dSelect; 
        cout << "请输入姓名：" << endl;
        cin >> name;
        cin.get();

        cout << "请选择该职工的岗位：" << endl;
        cout << "1、普通职工" << endl;
        cout << "2、经理" << endl;
        cout << "3、老板" << endl;
        cin >> dSelect;
        cin.get();

        Worker * worker = NULL;
        switch (dSelect)
        {
        case 1: //普通员工
            worker = new Employee(id, name, 1);
            break;
        case 2: //经理
            worker = new Manager(id, name, 2);
            break;
        case 3:  //老板
            worker = new Boss(id, name, 3);
            break;
        default:
            {   
                cout<<"错误的岗位类型"<<endl;
                break;
            }
            
        }

        if(worker != NULL){
            delete this->workerArray[w];
            this->workerArray[w] = worker;
            cout<<"已经修改"<<endl;
        }else{
            delete worker;
        }




    }

}