#pragma once 
#include<iostream>
using namespace std;
#include "worker.h"

class PeopleManager
{
public:
    PeopleManager(){}
    ~PeopleManager(){}
    void Show_Menu();
    void addWorker();
    void showAllPerson();
    void save();
    void load();
    void deleteEm();
    int findWhereEm(int);
    void showEmInfo();
    void modifyEmInfo();

private:
    int m_EmpNum=0;
	//判断文件是否为空 标志
	bool m_FileIsEmpty=true;
    Worker ** workerArray = NULL;

};