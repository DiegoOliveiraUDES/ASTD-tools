#include "helper.h"
enum KleeneState
{
  KLEENE_NOTSTARTED,
  KLEENE_STARTED
};
enum AutState
{
  S3,
  S4,
  S5,
  S6,
  S0,
  S1,
  S2
};
struct TState_B
{
  AutState  autState;

};
struct TState_S1
{
  int  y;
  int  qchoiceState;
  TState_B  ts_B;

};
struct TState_S0
{
  AutState  autState;

};
struct TState_A
{
  AutState  autState;
  TState_S0  ts_S0;
  TState_S1  ts_S1;

};
struct TState_MAIN
{
  KleeneState  kleeneState;
  TState_A  ts_A;

};
const std::vector<AutState>  shallow_final_A = {S2};
const std::vector<AutState>  shallow_final_S0 = {S4};
const std::vector<int>  T_S1 = {1, 10};
const std::vector<AutState>  shallow_final_B = {S6};
TState_MAIN  ts_MAIN;

int    e5()
{
	int  exec = 0;
	if(((std::find(shallow_final_A.begin(), shallow_final_A.end(), ts_MAIN.ts_A.autState) !=shallow_final_A.end() || KLEENE_NOTSTARTED == ts_MAIN.kleeneState) && S0 == S1))
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		ts_MAIN.ts_A.autState = S0;
		ts_MAIN.ts_A.ts_S0.autState = S3;
		if(ts_MAIN.ts_A.autState == S1)
		{
			ts_MAIN.ts_A.autState = S2;
			exec = 1;
		
		}
	
	}else if(ts_MAIN.ts_A.autState == S1)
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		if(ts_MAIN.ts_A.autState == S1)
		{
			ts_MAIN.ts_A.autState = S2;
			exec = 1;
		
		}
	
	}
	return exec;

}

int    e1(int  c1)
{
	int  exec = 0;
	if(((std::find(shallow_final_A.begin(), shallow_final_A.end(), ts_MAIN.ts_A.autState) !=shallow_final_A.end() || KLEENE_NOTSTARTED == ts_MAIN.kleeneState) && (S0 == S0 && S3 == S3)))
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		ts_MAIN.ts_A.autState = S0;
		ts_MAIN.ts_A.ts_S0.autState = S3;
		if((ts_MAIN.ts_A.autState == S0 && ts_MAIN.ts_A.ts_S0.autState == S3))
		{
			if(ts_MAIN.ts_A.ts_S0.autState == S3)
			{
				ts_MAIN.ts_A.ts_S0.autState = S4;
				exec = 1;
			
			}
		
		}
	
	}else if((ts_MAIN.ts_A.autState == S0 && ts_MAIN.ts_A.ts_S0.autState == S3))
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		if((ts_MAIN.ts_A.autState == S0 && ts_MAIN.ts_A.ts_S0.autState == S3))
		{
			if(ts_MAIN.ts_A.ts_S0.autState == S3)
			{
				ts_MAIN.ts_A.ts_S0.autState = S4;
				exec = 1;
			
			}
		
		}
	
	}
	return exec;

}

int    e2()
{
	int  exec = 0;
	if(((std::find(shallow_final_A.begin(), shallow_final_A.end(), ts_MAIN.ts_A.autState) !=shallow_final_A.end() || KLEENE_NOTSTARTED == ts_MAIN.kleeneState) && (S0 == S0 && S3 == S4)))
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		ts_MAIN.ts_A.autState = S0;
		ts_MAIN.ts_A.ts_S0.autState = S3;
		if((ts_MAIN.ts_A.autState == S0 && ts_MAIN.ts_A.ts_S0.autState == S4))
		{
			if(ts_MAIN.ts_A.ts_S0.autState == S4)
			{
				ts_MAIN.ts_A.ts_S0.autState = S3;
				exec = 1;
			
			}
		
		}
	
	}else if((ts_MAIN.ts_A.autState == S0 && ts_MAIN.ts_A.ts_S0.autState == S4))
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		if((ts_MAIN.ts_A.autState == S0 && ts_MAIN.ts_A.ts_S0.autState == S4))
		{
			if(ts_MAIN.ts_A.ts_S0.autState == S4)
			{
				ts_MAIN.ts_A.ts_S0.autState = S3;
				exec = 1;
			
			}
		
		}
	
	}
	return exec;

}

int  exists_S1e3_y(int&  y, int  _y, int&  c2)
{
	if(std::find(T_S1.begin(), T_S1.end(), _y) == T_S1.end())
	{
		return 0;
	
	}
	y = _y;
	if(std::find(T_S1.begin(), T_S1.end(), y) !=T_S1.end())
	{
		return 1;
	
	}
	return 0;

}

int    e3(int  _y, int  c2)
{
	int  exec = 0;
	if(((std::find(shallow_final_A.begin(), shallow_final_A.end(), ts_MAIN.ts_A.autState) !=shallow_final_A.end() || KLEENE_NOTSTARTED == ts_MAIN.kleeneState) && (S0 == S1 && ((ts_MAIN.ts_A.ts_S1.qchoiceState == 0 && exists_S1e3_y(ts_MAIN.ts_A.ts_S1.y, _y, c2)) || (!(ts_MAIN.ts_A.ts_S1.qchoiceState == 0) && (_y == ts_MAIN.ts_A.ts_S1.y || ts_MAIN.ts_A.ts_S1.ts_B.autState == S5))))))
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		ts_MAIN.ts_A.autState = S0;
		ts_MAIN.ts_A.ts_S0.autState = S3;
		if((ts_MAIN.ts_A.autState == S1 && ((ts_MAIN.ts_A.ts_S1.qchoiceState == 0 && exists_S1e3_y(ts_MAIN.ts_A.ts_S1.y, _y, c2)) || (!(ts_MAIN.ts_A.ts_S1.qchoiceState == 0) && (_y == ts_MAIN.ts_A.ts_S1.y || ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)))))
		{
			if((ts_MAIN.ts_A.ts_S1.qchoiceState == 0 && exists_S1e3_y(ts_MAIN.ts_A.ts_S1.y, _y, c2)))
			{
				ts_MAIN.ts_A.ts_S1.qchoiceState = 1;
				ts_MAIN.ts_A.ts_S1.ts_B.autState = S5;
				if(ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)
				{
					ts_MAIN.ts_A.ts_S1.ts_B.autState = S6;
					exec = 1;
				
				}
			
			}else if((!(ts_MAIN.ts_A.ts_S1.qchoiceState == 0) && (_y == ts_MAIN.ts_A.ts_S1.y || ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)))
			{
				if(ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)
				{
					ts_MAIN.ts_A.ts_S1.ts_B.autState = S6;
					exec = 1;
				
				}
			
			}
		
		}
	
	}else if((ts_MAIN.ts_A.autState == S1 && ((ts_MAIN.ts_A.ts_S1.qchoiceState == 0 && exists_S1e3_y(ts_MAIN.ts_A.ts_S1.y, _y, c2)) || (!(ts_MAIN.ts_A.ts_S1.qchoiceState == 0) && (_y == ts_MAIN.ts_A.ts_S1.y || ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)))))
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		if((ts_MAIN.ts_A.autState == S1 && ((ts_MAIN.ts_A.ts_S1.qchoiceState == 0 && exists_S1e3_y(ts_MAIN.ts_A.ts_S1.y, _y, c2)) || (!(ts_MAIN.ts_A.ts_S1.qchoiceState == 0) && (_y == ts_MAIN.ts_A.ts_S1.y || ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)))))
		{
			if((ts_MAIN.ts_A.ts_S1.qchoiceState == 0 && exists_S1e3_y(ts_MAIN.ts_A.ts_S1.y, _y, c2)))
			{
				ts_MAIN.ts_A.ts_S1.qchoiceState = 1;
				ts_MAIN.ts_A.ts_S1.ts_B.autState = S5;
				if(ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)
				{
					ts_MAIN.ts_A.ts_S1.ts_B.autState = S6;
					exec = 1;
				
				}
			
			}else if((!(ts_MAIN.ts_A.ts_S1.qchoiceState == 0) && (_y == ts_MAIN.ts_A.ts_S1.y || ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)))
			{
				if(ts_MAIN.ts_A.ts_S1.ts_B.autState == S5)
				{
					ts_MAIN.ts_A.ts_S1.ts_B.autState = S6;
					exec = 1;
				
				}
			
			}
		
		}
	
	}
	return exec;

}

int    e4()
{
	int  exec = 0;
	if(((std::find(shallow_final_A.begin(), shallow_final_A.end(), ts_MAIN.ts_A.autState) !=shallow_final_A.end() || KLEENE_NOTSTARTED == ts_MAIN.kleeneState) && S0 == S0))
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		ts_MAIN.ts_A.autState = S0;
		ts_MAIN.ts_A.ts_S0.autState = S3;
		if(ts_MAIN.ts_A.autState == S0)
		{
			ts_MAIN.ts_A.autState = S1;
			ts_MAIN.ts_A.ts_S1.qchoiceState = 0;
			exec = 1;
		
		}
	
	}else if(ts_MAIN.ts_A.autState == S0)
	{
		ts_MAIN.kleeneState = KLEENE_STARTED;
		if(ts_MAIN.ts_A.autState == S0)
		{
			ts_MAIN.ts_A.autState = S1;
			ts_MAIN.ts_A.ts_S1.qchoiceState = 0;
			exec = 1;
		
		}
	
	}
	return exec;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_MAIN.kleeneState = KLEENE_NOTSTARTED;
	ts_MAIN.ts_A.autState = S0;
	ts_MAIN.ts_A.ts_S0.autState = S3;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("e5") == 0)
		{
			if(e5())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("e1") == 0)
		{
			if(e1(Types::get_int(_evt.params[0])))
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("e2") == 0)
		{
			if(e2())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("e3") == 0)
		{
			if(e3(Types::get_int(_evt.params[0]), Types::get_int(_evt.params[1])))
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("e4") == 0)
		{
			if(e4())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else 
		{
			ERROR_1;
		
		}
	
	}
	return 0;

}
