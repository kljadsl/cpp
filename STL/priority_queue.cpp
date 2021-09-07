#include<iostream>
#include<queue> 
using namespace std;

class complex{
	private:
		int real;
		int image;
	public:
		complex():real(0),image(0){};
		complex(int re,int im):real(re),image(im){};
		
		void show() const{
			cout << "(" << real << "," << image << ")";
		}
		
		bool operator<(const complex& a) const{
			if(real != a.real){
				return real < a.real;
			}else{
				return image < a.image;
			}
		}
};



int main(){
	complex a(2,3);
	complex b(3,2);
	complex c(3,3);
	complex d(2,2);
	priority_queue<complex> pq;
	pq.push(a);
	pq.push(b);
	pq.push(c);
	pq.push(d);
	while(!pq.empty()){
		pq.top().show();
		pq.pop();
	}
	return 0;
}
