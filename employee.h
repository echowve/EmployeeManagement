#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Employee:public Worker{

    
public:
    Employee(int m_ID, string m_name, int m_DeptId){
        this->m_Id = m_ID;
        this->m_Name = m_name;
        this->m_DeptId = m_DeptId;
    }
    

    ~Employee(){}

    int type=1;

    virtual int gettype(){
        return 1;
    }

    virtual void showInfo(){

        cout << "职工编号： " << this->m_Id
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责： 完成经理交给的任务" << endl;

    }

    virtual string getDeptName(){
        return  string("员工");
    }
};


