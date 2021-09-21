#include"message.h"

int main() {
	MessagerImp* pc = new PCMessagerImp();
	MessagerImp* mb = new MobileMessagerImp();
	
	Messager* mp = new MessagerPerfect(pc);
	Messager* ml = new MessagerLite(mb);
	
	mp->Login("cjs");
	mp->SendMsg("nihao");
	
	ml->Login("cjs");
	ml->SendMsg("nihao");
	
	delete pc;
	delete mb;
	delete mp;
	delete ml;
} 
