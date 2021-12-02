#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager:public Worker{

public:
    Manager(int m_ID, string m_name, int m_DeptId){
        this->m_Id = m_ID;
        this->m_Name = m_name;
        this->m_DeptId = m_DeptId;
    }
    
    ~Manager(){}

    virtual int gettype(){
        return 2;
    }

    virtual void showInfo(){

        cout << "职工编号： " << this->m_Id
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责： 完成老板交给的任务，并下发任务给员工" << endl;

    }

    virtual string getDeptName(){
        return  string("经理");
    }
};