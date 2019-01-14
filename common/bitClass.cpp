#include"bitClass.hpp"
bitclass* bitClass::m_ptr = NULL;

bool bitClass::setMask(const int &mask){
	bool ret = false;
	if(flushAll()){
		maskDataInit();
		ret = true;
	}
	return ret;
}

bool bitClass::maskDataInit(){
	calcDigits();	// calculates digits of the mask
	calcReqBits();	// calculates required number of bits
	for(int i = 0;i<size;i++){
        *(m_Array + i) = isBitSet(i+1);
    }
}

void bitClass::calcReqBits(){
    int m_bitsReq = (m_digits*3.321) + 1;
    return;
}

// following method populates m_digits
void bitClass::calcDigits(){
    int temp = m_mask/10;
    while(temp > 0){
        temp /= 10;
        ++m_digits;
    }
    return;
}

bool bitClass::isBitSet(const int &index){
    int calc = pow(2,index-1);
    return (mask&calc)?true:false;
}
