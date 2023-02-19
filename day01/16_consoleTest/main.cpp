#include <QCoreApplication>
#include <iostream>
#include <vector>
using namespace std;

bool testVector(vector<int> *num1,vector<int>* num2){
    num2=num1;
    for(size_t i=0;i<num1->size();i++){
        num2->at(i)=100;
    }
    return true;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"hello world";
    vector<int> num1,num2;
    num1.push_back(12);
    num1.push_back(5);
    num1.push_back(77);

    testVector(&num1,&num2);
    for(size_t i=0;i<num1.size();i++){
        cout<<num1.at(i)<<endl;
    }
    bool t = (&num1==&num2);
    cout<<t<<endl;


    return a.exec();
}
