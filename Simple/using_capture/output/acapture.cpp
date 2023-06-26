#include "helper.h"
enum AutState
{
  S0,
  S1
};
struct TState_aCapture
{
  int  y;
  AutState  autState;

};
TState_aCapture  ts_aCapture;

int    e1(int  x)
{
	int  exec = 0;
	if(ts_aCapture.autState == S0)
	{
		ts_aCapture.y = x + ts_aCapture.y;ts_aCapture.autState = S1;
		exec = 1;
	
	}
	return exec;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_aCapture.autState = S0;
	ts_aCapture.y = 0;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("e1") == 0)
		{
			if(e1(Types::get_int(_evt.params[0])))
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
