#include<iostream>

using namespace std;



template<class alpha>

class interval{
public:
	interval(){};
	~interval(){};


  	interval( const alpha& start,
            const alpha& end,
            const bool lc,
            const bool rc ):start(start),end(end),lc(lc),rc(rc){
  	
  	};



 	alpha getstart(){
 		return start;
 	}
private:
	
	  alpha start;
	
	  alpha end;
	
	  bool lc;
	
	  bool rc;
};


template<class theta>
class point{
public:
	point(){};
	~point(){};
	point(const theta pt):value(pt);

	theta getpoint(){
		return theta;
	}

private:
	theta value;

}



template< class S, class T>

class MP{

public : 

	MP(interval<S> interv){inter = interv;};
	
	interval<S> getinterval(){
		return inter;
	}

private:

	interval<S> inter;



};



int main(){

	interval<float> first(5,10,0,0);


	cout<<first.getstart()<<endl;

	MP<float,int> nuevo(first);
	cout<<nuevo.getinterval().getstart();
	return 0;
}