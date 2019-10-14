#include<iostream>
#include<string>

using namespace std;

int findShift(const string &str, const char &ch){
    int shift = 0;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ch){
            shift = i - 0;
            break;
        }
        ++i;
    }
    return shift;
}

bool checkIfRotated(const string &strOrig, const string &strRot, const int &shift){
    bool retVal = true;
    int i = 0;
    while(i != strOrig.length()){
        if(strOrig[i] != strRot[(i + shift)%strOrig.length()]){
            retVal = false;
        }
        ++i;
    }
    return retVal;
}

int main(int argc, char *argv[]){
    string strOrig("geeks");
    string strRot("ksgef");
    int shift = findShift(strRot,'g');
    int index,i = 0;
    bool retVal = true;
    while(i != strOrig.length()){
        index = (i + shift)%strOrig.length();
        if(strOrig[i] != strRot[index]){
            retVal = false;
        }
        ++i;
    }
    cout<<retVal<<endl;
    return 0;
}
