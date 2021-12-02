#include<iostream>
using namespace std;
#include "employee.h"

int main1(){

    Employee * worker = new Employee(32, string("dsa"),1);
    delete worker;
    return 0;
}