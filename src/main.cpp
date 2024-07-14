#include<iostream>
#include"AppWindow/AppWindow.h"

using namespace std;

static int x = 800;
static int y = 600;

int main(int argc, char* argv[]){
    AppWindow application(x,y);
    application.onCreate();

    
    return 0;
}
