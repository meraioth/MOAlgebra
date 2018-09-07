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

 	alpha getend(){
 		return end;
 	}

 	alpha getlc(){
 		return lc;
 	}

 	alpha getrc(){
 		return rc;
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
	point(const theta pt):value(pt){};

	theta getpoint(){
		return value;
	};

	bool is_free_space(){
		if(value.get_domain().compare("fs")==0){
			return true;
		}else
		return false;
	}

	bool is_network(){
		if(value.get_domain().compare("network")==0){
			return true;
		}else
		return false;
	}


private:
	theta value;

};



template< class S, class T>

class Unit{

public : 

	Unit(S begin, S end,interval<T> interv):inter(interv),begin(begin),end(end){};	
	interval<S> getinterval(){
		return inter;
	}

private:

	interval<T> inter;
	S begin, end;



};


class fspoint{
public:
	fspoint(float x, float y):x(x),y(y){};

	string to_coordinate(){
		return " "+to_string(x)+to_string(y);
	}

	string get_domain(){
		return domain;
	}
	private:
		float x,y;
		string domain = "fs";


};

class netpoint{
public:
	fspoint(int x, float y):x(x),y(y){};

	string to_coordinate(){
		return " "+to_string(x)+to_string(y);
	}

	string get_domain(){
		return domain;
	}
	private:
		int x;
		float y;
		string domain = "network";


};



int main(){

	interval<float> first(5,10,0,0);
	fspoint fs(-73.65,-63.27);
	cout<<"original"<<endl;
	cout<<fs.to_coordinate()<<endl;

	point<fspoint> pt(fs);

	cout<<"passed to template"<<endl;
	cout<<pt.getpoint().to_coordinate()<<endl;

	cout<<pt.is_free_space()<<endl;


	return 0;
}