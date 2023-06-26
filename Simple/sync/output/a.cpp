#include "helper.h"
enum KleeneState
{
  KLEENE_NOTSTARTED,
  KLEENE_STARTED
};
enum AutState
{
  S0,
  S1,
  S2
};
struct TState_B1
{
  int  z;
  AutState  autState;

};
struct TState_B
{
  int  y;
  KleeneState  kleeneState;
  TState_B1  ts_B1;

};
struct TState_C1
{
  int  z;
  AutState  autState;

};
struct TState_C
{
  int  y;
  KleeneState  kleeneState;
  TState_C1  ts_C1;

};
struct TState_A
{
  int  x;
  TState_C  ts_C;
  TState_B  ts_B;

};
const std::vector<AutState>  shallow_final_C1 = {S2};
const std::vector<AutState>  shallow_final_B1 = {S2};
TState_A  ts_A;

int    e()
{
	int  exec = 0;
	if(((((std::find(shallow_final_C1.begin(), shallow_final_C1.end(), ts_A.ts_C.ts_C1.autState) !=shallow_final_C1.end() || KLEENE_NOTSTARTED == ts_A.ts_C.kleeneState) && S0 == S0) || ts_A.ts_C.ts_C1.autState == S0) && (((std::find(shallow_final_B1.begin(), shallow_final_B1.end(), ts_A.ts_B.ts_B1.autState) !=shallow_final_B1.end() || KLEENE_NOTSTARTED == ts_A.ts_B.kleeneState) && S0 == S0) || ts_A.ts_B.ts_B1.autState == S0)))
	{
		if(((std::find(shallow_final_C1.begin(), shallow_final_C1.end(), ts_A.ts_C.ts_C1.autState) !=shallow_final_C1.end() || KLEENE_NOTSTARTED == ts_A.ts_C.kleeneState) && S0 == S0))
		{
			ts_A.ts_C.kleeneState = KLEENE_STARTED;
			ts_A.ts_C.ts_C1.autState = S0;
			ts_A.ts_C.ts_C1.z = 0;
			if(ts_A.ts_C.ts_C1.autState == S0)
			{
				ts_A.ts_C.ts_C1.z++;
				std::cout<<"\nThe number of executions of this cycle in C is: "<<ts_A.ts_C.ts_C1.z;ts_A.ts_C.ts_C1.autState = S1;
				exec = 1;
			
			}
			ts_A.ts_C.y++;
			std::cout<<"\nThe number of executions of C is : "<<ts_A.ts_C.y;
		}else if(ts_A.ts_C.ts_C1.autState == S0)
		{
			ts_A.ts_C.kleeneState = KLEENE_STARTED;
			if(ts_A.ts_C.ts_C1.autState == S0)
			{
				ts_A.ts_C.ts_C1.z++;
				std::cout<<"\nThe number of executions of this cycle in C is: "<<ts_A.ts_C.ts_C1.z;ts_A.ts_C.ts_C1.autState = S1;
				exec = 1;
			
			}
			ts_A.ts_C.y++;
			std::cout<<"\nThe number of executions of C is : "<<ts_A.ts_C.y;
		}
		if(((std::find(shallow_final_B1.begin(), shallow_final_B1.end(), ts_A.ts_B.ts_B1.autState) !=shallow_final_B1.end() || KLEENE_NOTSTARTED == ts_A.ts_B.kleeneState) && S0 == S0))
		{
			ts_A.ts_B.kleeneState = KLEENE_STARTED;
			ts_A.ts_B.ts_B1.autState = S0;
			ts_A.ts_B.ts_B1.z = 0;
			if(ts_A.ts_B.ts_B1.autState == S0)
			{
				ts_A.ts_B.ts_B1.z++;
				std::cout<<"\nThe number of executions of this cycle in B is: "<<ts_A.ts_B.ts_B1.z;ts_A.ts_B.ts_B1.autState = S1;
				exec = 1;
			
			}
			ts_A.ts_B.y++;
			std::cout<<"\nThe number of executions of B is : "<<ts_A.ts_B.y;
		}else if(ts_A.ts_B.ts_B1.autState == S0)
		{
			ts_A.ts_B.kleeneState = KLEENE_STARTED;
			if(ts_A.ts_B.ts_B1.autState == S0)
			{
				ts_A.ts_B.ts_B1.z++;
				std::cout<<"\nThe number of executions of this cycle in B is: "<<ts_A.ts_B.ts_B1.z;ts_A.ts_B.ts_B1.autState = S1;
				exec = 1;
			
			}
			ts_A.ts_B.y++;
			std::cout<<"\nThe number of executions of B is : "<<ts_A.ts_B.y;
		}
		ts_A.x++;
		std::cout<<"\nThe number of total executions is x : "<<ts_A.x<<"\n";
	}
	return exec;

}

int    f()
{
	int  exec = 0;
	if((((std::find(shallow_final_B1.begin(), shallow_final_B1.end(), ts_A.ts_B.ts_B1.autState) !=shallow_final_B1.end() || KLEENE_NOTSTARTED == ts_A.ts_B.kleeneState) && (S0 == S1 || S0 == S2)) || (ts_A.ts_B.ts_B1.autState == S1 || ts_A.ts_B.ts_B1.autState == S2)))
	{
		if(((std::find(shallow_final_B1.begin(), shallow_final_B1.end(), ts_A.ts_B.ts_B1.autState) !=shallow_final_B1.end() || KLEENE_NOTSTARTED == ts_A.ts_B.kleeneState) && (S0 == S1 || S0 == S2)))
		{
			ts_A.ts_B.kleeneState = KLEENE_STARTED;
			ts_A.ts_B.ts_B1.autState = S0;
			ts_A.ts_B.ts_B1.z = 0;
			if(ts_A.ts_B.ts_B1.autState == S1)
			{
				ts_A.ts_B.ts_B1.z++;
				std::cout<<"\nThe number of executions of this cycle in B is: "<<ts_A.ts_B.ts_B1.z;ts_A.ts_B.ts_B1.autState = S2;
				exec = 1;
			
			}else if(ts_A.ts_B.ts_B1.autState == S2)
			{
				ts_A.ts_B.ts_B1.z++;
				std::cout<<"\nThe number of executions of this cycle in B is: "<<ts_A.ts_B.ts_B1.z;ts_A.ts_B.ts_B1.autState = S0;
				exec = 1;
			
			}
			ts_A.ts_B.y++;
			std::cout<<"\nThe number of executions of B is : "<<ts_A.ts_B.y;
		}else if((ts_A.ts_B.ts_B1.autState == S1 || ts_A.ts_B.ts_B1.autState == S2))
		{
			ts_A.ts_B.kleeneState = KLEENE_STARTED;
			if(ts_A.ts_B.ts_B1.autState == S1)
			{
				ts_A.ts_B.ts_B1.z++;
				std::cout<<"\nThe number of executions of this cycle in B is: "<<ts_A.ts_B.ts_B1.z;ts_A.ts_B.ts_B1.autState = S2;
				exec = 1;
			
			}else if(ts_A.ts_B.ts_B1.autState == S2)
			{
				ts_A.ts_B.ts_B1.z++;
				std::cout<<"\nThe number of executions of this cycle in B is: "<<ts_A.ts_B.ts_B1.z;ts_A.ts_B.ts_B1.autState = S0;
				exec = 1;
			
			}
			ts_A.ts_B.y++;
			std::cout<<"\nThe number of executions of B is : "<<ts_A.ts_B.y;
		}
		ts_A.x++;
		std::cout<<"\nThe number of total executions is x : "<<ts_A.x<<"\n";
	}
	return exec;

}

int    g()
{
	int  exec = 0;
	if((((std::find(shallow_final_C1.begin(), shallow_final_C1.end(), ts_A.ts_C.ts_C1.autState) !=shallow_final_C1.end() || KLEENE_NOTSTARTED == ts_A.ts_C.kleeneState) && (S0 == S1 || S0 == S2)) || (ts_A.ts_C.ts_C1.autState == S1 || ts_A.ts_C.ts_C1.autState == S2)))
	{
		if(((std::find(shallow_final_C1.begin(), shallow_final_C1.end(), ts_A.ts_C.ts_C1.autState) !=shallow_final_C1.end() || KLEENE_NOTSTARTED == ts_A.ts_C.kleeneState) && (S0 == S1 || S0 == S2)))
		{
			ts_A.ts_C.kleeneState = KLEENE_STARTED;
			ts_A.ts_C.ts_C1.autState = S0;
			ts_A.ts_C.ts_C1.z = 0;
			if(ts_A.ts_C.ts_C1.autState == S1)
			{
				ts_A.ts_C.ts_C1.z++;
				std::cout<<"\nThe number of executions of this cycle in C is: "<<ts_A.ts_C.ts_C1.z;ts_A.ts_C.ts_C1.autState = S2;
				exec = 1;
			
			}else if(ts_A.ts_C.ts_C1.autState == S2)
			{
				ts_A.ts_C.ts_C1.z++;
				std::cout<<"\nThe number of executions of this cycle in C is: "<<ts_A.ts_C.ts_C1.z;ts_A.ts_C.ts_C1.autState = S0;
				exec = 1;
			
			}
			ts_A.ts_C.y++;
			std::cout<<"\nThe number of executions of C is : "<<ts_A.ts_C.y;
		}else if((ts_A.ts_C.ts_C1.autState == S1 || ts_A.ts_C.ts_C1.autState == S2))
		{
			ts_A.ts_C.kleeneState = KLEENE_STARTED;
			if(ts_A.ts_C.ts_C1.autState == S1)
			{
				ts_A.ts_C.ts_C1.z++;
				std::cout<<"\nThe number of executions of this cycle in C is: "<<ts_A.ts_C.ts_C1.z;ts_A.ts_C.ts_C1.autState = S2;
				exec = 1;
			
			}else if(ts_A.ts_C.ts_C1.autState == S2)
			{
				ts_A.ts_C.ts_C1.z++;
				std::cout<<"\nThe number of executions of this cycle in C is: "<<ts_A.ts_C.ts_C1.z;ts_A.ts_C.ts_C1.autState = S0;
				exec = 1;
			
			}
			ts_A.ts_C.y++;
			std::cout<<"\nThe number of executions of C is : "<<ts_A.ts_C.y;
		}
		ts_A.x++;
		std::cout<<"\nThe number of total executions is x : "<<ts_A.x<<"\n";
	}
	return exec;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_A.x = 0;
	ts_A.ts_C.kleeneState = KLEENE_NOTSTARTED;
	ts_A.ts_C.y = 0;
	ts_A.ts_C.ts_C1.autState = S0;
	ts_A.ts_C.ts_C1.z = 0;
	ts_A.ts_B.kleeneState = KLEENE_NOTSTARTED;
	ts_A.ts_B.y = 0;
	ts_A.ts_B.ts_B1.autState = S0;
	ts_A.ts_B.ts_B1.z = 0;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("e") == 0)
		{
			if(e())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("f") == 0)
		{
			if(f())
			{
				continue;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("g") == 0)
		{
			if(g())
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
