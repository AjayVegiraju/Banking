#include <iostream>
#include "jolly_banker.h"
#include <fstream>
using namespace std;

int main(int argc, char **argv){

    //variable to be changed if file name is different
    string file_name = argv[1];;
    // readin from a file into banks transaction queue
    Bank B1;
    
    
    B1.ReadIn(file_name);
  //  ofstream file4("bank_trans_out.txt",ios_base::app);
    
    B1.Execute();
    B1.Output();
    
    return 0;

}   