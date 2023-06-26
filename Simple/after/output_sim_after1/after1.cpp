#include "helper.h"
#include <chrono>
#include <ctime>
#include "inttypes.h"
std::time_t  current_time = 0;
enum AutState
{
  S0,
  S1
};
struct TState_After1
{
  int  x;
  Timer t = current_time;
  AutState  autState;

};
const std::vector<AutState>  shallow_final_After1 = {S1};
TState_After1  ts_After1;
std::time_t  step_time = 10000000;
Timer  last_event_time = 0;

int    Step()
{
	int  exec = 0;
	current_time = step_time+current_time;
	if((ts_After1.autState == S1 && ts_After1.t.expired(1E9, current_time) ))
	{
		ts_After1.x++; 
		std::cout<<"\nThe value of x is :"<<ts_After1.x;
		ts_After1.t.reset_clock(current_time);ts_After1.autState = S0;
		exec = 1;
	
	}else if((ts_After1.autState == S0 && ts_After1.t.expired(1E9, current_time) ))
	{
		ts_After1.x++; 
		std::cout<<"\nThe value of x is :"<<ts_After1.x;
		ts_After1.t.reset_clock(current_time);ts_After1.autState = S1;
		exec = 1;
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_After1.autState = S0;
	ts_After1.x = 0;
	ts_After1.t.reset_clock(current_time);
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("Step") == 0)
		{
			if(Step())
			{
				continue;
			}
		}else if(_evt.label.compare("advanceTo") == 0){
			if(Types::get_str(_evt.params[0]).find(":") != std::string::npos){
				long int numberOfSteps = advanceToV1(current_time, step_time, Types::get_str(_evt.params[0]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
			else{
				long int numberOfSteps = advanceToV2(current_time, step_time, Types::get_str(_evt.params[0]), (std::time_t) Types::get_double(_evt.params[1]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
		}else if(_evt.label.compare("advanceOf") == 0){
			if(Types::get_str(_evt.params[0]).find(":") != std::string::npos){
				long int numberOfSteps = advanceOfV1(step_time, Types::get_str(_evt.params[0]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}
			else{
				long int numberOfSteps = advanceOfV2(step_time, Types::get_str(_evt.params[0]), (std::time_t) Types::get_double(_evt.params[1]));
				while (numberOfSteps > 0)
				{
					Step();
					numberOfSteps--;
				}
			}	
		}
		else 
		{
			ERROR_1;
		
		}
	
	}
	return 0;

}
