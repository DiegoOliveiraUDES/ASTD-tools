#include "helper.h"
enum KleeneState
{
  KLEENE_NOTSTARTED,
  KLEENE_STARTED
};
enum AutState
{
  S0,
  S1
};
enum SequenceState
{
  FST,
  SND
};
struct TState_D
{
  int  x4;
  AutState  autState;

};
struct TState_C
{
  int  x3;
  AutState  autState;

};
struct TState_B
{
  int  x2;
  KleeneState  kleeneState;
  TState_C  ts_C;

};
struct TState_A1
{
  int  x1;
  SequenceState  sequenceState;
  TState_B  ts_B;
  TState_D  ts_D;

};
struct TState_A
{
  int  x0;
  KleeneState  kleeneState;
  TState_A1  ts_A1;

};
const std::vector<AutState>  shallow_final_C = {S1};
const std::vector<AutState>  shallow_final_D = {S1};
TState_A  ts_A;

int    e1()
{
	int  exec = 0;
	if(((((ts_A.ts_A1.sequenceState == FST && ((ts_A.ts_A1.ts_B.kleeneState == KLEENE_NOTSTARTED || std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end()) && std::find(shallow_final_D.begin(), shallow_final_D.end(), S0) !=shallow_final_D.end())) || (ts_A.ts_A1.sequenceState == SND && std::find(shallow_final_D.begin(), shallow_final_D.end(), ts_A.ts_A1.ts_D.autState) !=shallow_final_D.end())) || KLEENE_NOTSTARTED == ts_A.kleeneState) && (FST == FST && (((std::find(shallow_final_C.begin(), shallow_final_C.end(), S0) !=shallow_final_C.end() || KLEENE_NOTSTARTED == ts_A.ts_A1.ts_B.kleeneState) && S0 == S0) || S0 == S0))))
	{
		ts_A.kleeneState = KLEENE_STARTED;
		ts_A.ts_A1.sequenceState = FST;
		ts_A.ts_A1.x1 = ts_A.x0+1;
		ts_A.ts_A1.ts_B.kleeneState = KLEENE_NOTSTARTED;
		ts_A.ts_A1.ts_B.x2 = ts_A.ts_A1.x1+1;
		ts_A.ts_A1.ts_B.ts_C.autState = S0;
		ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.x2+1;
		if((ts_A.ts_A1.sequenceState == FST && (((std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end() || KLEENE_NOTSTARTED == ts_A.ts_A1.ts_B.kleeneState) && S0 == S0) || ts_A.ts_A1.ts_B.ts_C.autState == S0)))
		{
			if(((std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end() || KLEENE_NOTSTARTED == ts_A.ts_A1.ts_B.kleeneState) && S0 == S0))
			{
				ts_A.ts_A1.ts_B.kleeneState = KLEENE_STARTED;
				ts_A.ts_A1.ts_B.ts_C.autState = S0;
				ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.x2+1;
				if(ts_A.ts_A1.ts_B.ts_C.autState == S0)
				{
					ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.ts_C.x3 + 1;
					ts_A.ts_A1.ts_B.x2 = ts_A.ts_A1.ts_B.x2 + 1;
					ts_A.ts_A1.x1 = ts_A.ts_A1.x1 + 1;
					std::cout <<
					"x1 = " << ts_A.ts_A1.x1 <<
					"x2 = " << ts_A.ts_A1.ts_B.x2 <<
					"x3 = " << ts_A.ts_A1.ts_B.ts_C.x3 <<
					"\n";ts_A.ts_A1.ts_B.ts_C.autState = S1;
					exec = 1;
				
				}
			
			}else if(ts_A.ts_A1.ts_B.ts_C.autState == S0)
			{
				ts_A.ts_A1.ts_B.kleeneState = KLEENE_STARTED;
				if(ts_A.ts_A1.ts_B.ts_C.autState == S0)
				{
					ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.ts_C.x3 + 1;
					ts_A.ts_A1.ts_B.x2 = ts_A.ts_A1.ts_B.x2 + 1;
					ts_A.ts_A1.x1 = ts_A.ts_A1.x1 + 1;
					std::cout <<
					"x1 = " << ts_A.ts_A1.x1 <<
					"x2 = " << ts_A.ts_A1.ts_B.x2 <<
					"x3 = " << ts_A.ts_A1.ts_B.ts_C.x3 <<
					"\n";ts_A.ts_A1.ts_B.ts_C.autState = S1;
					exec = 1;
				
				}
			
			}
		
		}
	
	}else if((ts_A.ts_A1.sequenceState == FST && (((std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end() || KLEENE_NOTSTARTED == ts_A.ts_A1.ts_B.kleeneState) && S0 == S0) || ts_A.ts_A1.ts_B.ts_C.autState == S0)))
	{
		ts_A.kleeneState = KLEENE_STARTED;
		if((ts_A.ts_A1.sequenceState == FST && (((std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end() || KLEENE_NOTSTARTED == ts_A.ts_A1.ts_B.kleeneState) && S0 == S0) || ts_A.ts_A1.ts_B.ts_C.autState == S0)))
		{
			if(((std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end() || KLEENE_NOTSTARTED == ts_A.ts_A1.ts_B.kleeneState) && S0 == S0))
			{
				ts_A.ts_A1.ts_B.kleeneState = KLEENE_STARTED;
				ts_A.ts_A1.ts_B.ts_C.autState = S0;
				ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.x2+1;
				if(ts_A.ts_A1.ts_B.ts_C.autState == S0)
				{
					ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.ts_C.x3 + 1;
					ts_A.ts_A1.ts_B.x2 = ts_A.ts_A1.ts_B.x2 + 1;
					ts_A.ts_A1.x1 = ts_A.ts_A1.x1 + 1;
					std::cout <<
					"x1 = " << ts_A.ts_A1.x1 <<
					"x2 = " << ts_A.ts_A1.ts_B.x2 <<
					"x3 = " << ts_A.ts_A1.ts_B.ts_C.x3 <<
					"\n";ts_A.ts_A1.ts_B.ts_C.autState = S1;
					exec = 1;
				
				}
			
			}else if(ts_A.ts_A1.ts_B.ts_C.autState == S0)
			{
				ts_A.ts_A1.ts_B.kleeneState = KLEENE_STARTED;
				if(ts_A.ts_A1.ts_B.ts_C.autState == S0)
				{
					ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.ts_C.x3 + 1;
					ts_A.ts_A1.ts_B.x2 = ts_A.ts_A1.ts_B.x2 + 1;
					ts_A.ts_A1.x1 = ts_A.ts_A1.x1 + 1;
					std::cout <<
					"x1 = " << ts_A.ts_A1.x1 <<
					"x2 = " << ts_A.ts_A1.ts_B.x2 <<
					"x3 = " << ts_A.ts_A1.ts_B.ts_C.x3 <<
					"\n";ts_A.ts_A1.ts_B.ts_C.autState = S1;
					exec = 1;
				
				}
			
			}
		
		}
	
	}
	return exec;

}

int    e2()
{
	int  exec = 0;
	if(((((ts_A.ts_A1.sequenceState == FST && ((ts_A.ts_A1.ts_B.kleeneState == KLEENE_NOTSTARTED || std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end()) && std::find(shallow_final_D.begin(), shallow_final_D.end(), S0) !=shallow_final_D.end())) || (ts_A.ts_A1.sequenceState == SND && std::find(shallow_final_D.begin(), shallow_final_D.end(), ts_A.ts_A1.ts_D.autState) !=shallow_final_D.end())) || KLEENE_NOTSTARTED == ts_A.kleeneState) && ((FST == FST && ((KLEENE_NOTSTARTED == KLEENE_NOTSTARTED || std::find(shallow_final_C.begin(), shallow_final_C.end(), S0) !=shallow_final_C.end()) && S0 == S0)) || (FST == SND && ts_A.ts_A1.ts_D.autState == S0))))
	{
		ts_A.kleeneState = KLEENE_STARTED;
		ts_A.ts_A1.sequenceState = FST;
		ts_A.ts_A1.x1 = ts_A.x0+1;
		ts_A.ts_A1.ts_B.kleeneState = KLEENE_NOTSTARTED;
		ts_A.ts_A1.ts_B.x2 = ts_A.ts_A1.x1+1;
		ts_A.ts_A1.ts_B.ts_C.autState = S0;
		ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.x2+1;
		if((ts_A.ts_A1.sequenceState == FST && ((ts_A.ts_A1.ts_B.kleeneState == KLEENE_NOTSTARTED || std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end()) && S0 == S0)))
		{
			ts_A.ts_A1.sequenceState = SND;
			ts_A.ts_A1.ts_D.autState = S0;
			ts_A.ts_A1.ts_D.x4 = ts_A.ts_A1.x1+2;
			if(ts_A.ts_A1.ts_D.autState == S0)
			{
				ts_A.ts_A1.x1 = ts_A.ts_A1.x1 + 1;
				std::cout <<
				"x1 = " << ts_A.ts_A1.x1 <<
				"x4 = " << ts_A.ts_A1.ts_D.x4 <<
				"\n";ts_A.ts_A1.ts_D.autState = S1;
				exec = 1;
			
			}
		
		}else if((ts_A.ts_A1.sequenceState == SND && ts_A.ts_A1.ts_D.autState == S0))
		{
			if(ts_A.ts_A1.ts_D.autState == S0)
			{
				ts_A.ts_A1.x1 = ts_A.ts_A1.x1 + 1;
				std::cout <<
				"x1 = " << ts_A.ts_A1.x1 <<
				"x4 = " << ts_A.ts_A1.ts_D.x4 <<
				"\n";ts_A.ts_A1.ts_D.autState = S1;
				exec = 1;
			
			}
		
		}
	
	}else if(((ts_A.ts_A1.sequenceState == FST && ((ts_A.ts_A1.ts_B.kleeneState == KLEENE_NOTSTARTED || std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end()) && S0 == S0)) || (ts_A.ts_A1.sequenceState == SND && ts_A.ts_A1.ts_D.autState == S0)))
	{
		ts_A.kleeneState = KLEENE_STARTED;
		if((ts_A.ts_A1.sequenceState == FST && ((ts_A.ts_A1.ts_B.kleeneState == KLEENE_NOTSTARTED || std::find(shallow_final_C.begin(), shallow_final_C.end(), ts_A.ts_A1.ts_B.ts_C.autState) !=shallow_final_C.end()) && S0 == S0)))
		{
			ts_A.ts_A1.sequenceState = SND;
			ts_A.ts_A1.ts_D.autState = S0;
			ts_A.ts_A1.ts_D.x4 = ts_A.ts_A1.x1+2;
			if(ts_A.ts_A1.ts_D.autState == S0)
			{
				ts_A.ts_A1.x1 = ts_A.ts_A1.x1 + 1;
				std::cout <<
				"x1 = " << ts_A.ts_A1.x1 <<
				"x4 = " << ts_A.ts_A1.ts_D.x4 <<
				"\n";ts_A.ts_A1.ts_D.autState = S1;
				exec = 1;
			
			}
		
		}else if((ts_A.ts_A1.sequenceState == SND && ts_A.ts_A1.ts_D.autState == S0))
		{
			if(ts_A.ts_A1.ts_D.autState == S0)
			{
				ts_A.ts_A1.x1 = ts_A.ts_A1.x1 + 1;
				std::cout <<
				"x1 = " << ts_A.ts_A1.x1 <<
				"x4 = " << ts_A.ts_A1.ts_D.x4 <<
				"\n";ts_A.ts_A1.ts_D.autState = S1;
				exec = 1;
			
			}
		
		}
	
	}
	return exec;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_A.kleeneState = KLEENE_NOTSTARTED;
	ts_A.x0 = 0;
	ts_A.ts_A1.sequenceState = FST;
	ts_A.ts_A1.x1 = ts_A.x0+1;
	ts_A.ts_A1.ts_B.kleeneState = KLEENE_NOTSTARTED;
	ts_A.ts_A1.ts_B.x2 = ts_A.ts_A1.x1+1;
	ts_A.ts_A1.ts_B.ts_C.autState = S0;
	ts_A.ts_A1.ts_B.ts_C.x3 = ts_A.ts_A1.ts_B.x2+1;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("e1") == 0)
		{
			if(e1())
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
		
		}else 
		{
			ERROR_1;
		
		}
	
	}
	return 0;

}
