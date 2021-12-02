#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Boss:public Worker{
public:
    Boss(int m_ID, string m_name, int m_DeptId){
        this->m_Id = m_ID;
        this->m_Name = m_name;
        this->m_DeptId = m_DeptId;
    }
    
    ~Boss(){}

    int type=3;
    virtual int gettype(){
        return 3;
    }
    virtual void showInfo(){

	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名： " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责： 管理公司所有事务" << endl;

    }

    virtual string getDeptName(){
        return  string("老板");
    }
};