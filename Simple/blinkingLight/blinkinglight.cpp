#include "helper.h"
#include "blockingconcurrentqueue.h"
#include <pthread.h>
#include <mutex>
#include <chrono>
#include <ctime>
#include <atomic>
#include "inttypes.h"
enum AutState
{
  red,
  blue,
  Pdelay,
  yellow,
  off
};
struct TState_on
{
  AutState  autState;

};
struct TState_Pdelay
{
  TState_on  ts_on;

};
struct TState_BlinkingLight
{
  AutState  autState;
  TState_Pdelay  ts_Pdelay;

};
TState_BlinkingLight  ts_BlinkingLight;
moodycamel::BlockingConcurrentQueue<std::string>  queue;
std::time_t  step_time = 2000000;
std::time_t  last_event_time = std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count();
std::time_t  last_step_time = std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count();
bool  continue_signal = 1;

int    Step()
{
	int  exec = 0;
	if((ts_BlinkingLight.autState == Pdelay && (std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count() >= 1.0E9 + last_event_time && (ts_BlinkingLight.ts_Pdelay.ts_on.autState == red || ts_BlinkingLight.ts_Pdelay.ts_on.autState == blue || ts_BlinkingLight.ts_Pdelay.ts_on.autState == yellow))))
	{
		if((std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count() >= 1.0E9 + last_event_time && (ts_BlinkingLight.ts_Pdelay.ts_on.autState == red || ts_BlinkingLight.ts_Pdelay.ts_on.autState == blue || ts_BlinkingLight.ts_Pdelay.ts_on.autState == yellow)))
		{
			if(ts_BlinkingLight.ts_Pdelay.ts_on.autState == red)
			{
				std::cout<<"going blue\n";
				ts_BlinkingLight.ts_Pdelay.ts_on.autState = blue;
				exec = 1;
			
			}else if(ts_BlinkingLight.ts_Pdelay.ts_on.autState == blue)
			{
				std::cout<<"going yellow\n";
				ts_BlinkingLight.ts_Pdelay.ts_on.autState = yellow;
				exec = 1;
			
			}else if(ts_BlinkingLight.ts_Pdelay.ts_on.autState == yellow)
			{
				std::cout<<"going red\n";
				ts_BlinkingLight.ts_Pdelay.ts_on.autState = red;
				exec = 1;
			
			}
		
		}
	
	}
	return exec;

}

int    press()
{
	int  exec = 0;
	if(ts_BlinkingLight.autState == off)
	{
		ts_BlinkingLight.autState = Pdelay;
		ts_BlinkingLight.ts_Pdelay.ts_on.autState = red;
		exec = 1;
	
	}else if(ts_BlinkingLight.autState == Pdelay)
	{
		ts_BlinkingLight.autState = off;
		exec = 1;
	
	}
	return exec;

}
void* producers_event_func(void* arg)
{
	while (continue_signal)
	{
		int*  argc = (int*) arg;
		Event  _evt = IO::read_event(*argc);
		if(_evt.label.empty())
		{
			continue_signal = 0;
			break;
		
		}
		queue.enqueue(_evt.label);
	
	}
	return NULL;

}
void* producers_Step_func(void* arg)
{
	while (continue_signal)
	{
		if(std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count() >= last_step_time + step_time)
		{
			queue.enqueue("Step");
			Clock::reset_clock(last_step_time);
		
		}
		std::this_thread::sleep_for(std::chrono::nanoseconds(step_time/1000));
	
	}
	return NULL;

}
void* consumer_func(void* arg)
{
	std::string  consumed_event;
	while (continue_signal)
	{
		queue.wait_dequeue(consumed_event);
		if(consumed_event.compare("Step") == 0)
		{
			if(Step())
			{
			last_event_time = std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count();
				continue;
			}
		}else if(consumed_event.compare("press") == 0)
		{
			if(press())
			{
			last_event_time = std::chrono::duration_cast<std::chrono::nanoseconds>((std::chrono::system_clock::now().time_since_epoch())).count();
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
	return NULL;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_BlinkingLight.autState = off;
	pthread_t  consumer;
	pthread_t  producers[2];
	pthread_create(& consumer, NULL, consumer_func, NULL);
	pthread_create(& producers[0], NULL, producers_event_func, (void*) &argc);
	pthread_create(& producers[1], NULL, producers_Step_func, NULL);
	pthread_join(consumer, NULL);
	pthread_join(producers[0], NULL);
	pthread_join(producers[1], NULL);
	return 0;

}
