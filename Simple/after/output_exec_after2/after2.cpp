#include "helper.h"
#include "blockingconcurrentqueue.h"
#include <pthread.h>
#include <mutex>
#include <chrono>
#include <ctime>
#include <atomic>
enum AutState
{
  S0,
  S1
};
struct TState_B
{
  int  x;
  AutState  autState;

};
struct TState_after2
{
  TState_B  ts_B;

};
TState_after2  ts_after2;
moodycamel::BlockingConcurrentQueue<Event>  queue;
std::time_t  step_time = 10000000;
Timer  last_event_time;
Timer  last_step_time;
Timer  exec_start;
bool  continue_signal = 1;

int    Step()
{
	int  exec = 0;
	exec_start.reset_clock();
	if((last_event_time.expired(1.0E9)  && (ts_after2.ts_B.autState == S0 || ts_after2.ts_B.autState == S1)))
	{
		if(ts_after2.ts_B.autState == S0)
		{
			ts_after2.ts_B.x++;
			std::cout<<"\nThe value of x is: "<<ts_after2.ts_B.x;ts_after2.ts_B.autState = S1;
			exec = 1;
		
		}else if(ts_after2.ts_B.autState == S1)
		{
			ts_after2.ts_B.x++;
			std::cout<<"\nThe value of x is: "<<ts_after2.ts_B.x;ts_after2.ts_B.autState = S0;
			exec = 1;
		
		}
	
	}
	if(exec == 1)
	{
		last_event_time = exec_start;
	
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
		queue.enqueue(_evt);
	
	}
	return NULL;

}
void* producers_Step_func(void* arg)
{
	while (continue_signal)
	{
		if(last_step_time.expired(step_time))
		{
			Event  Step;
			Step.label = "Step";
			queue.enqueue(Step);
			last_step_time.reset_clock();
		
		}
		std::this_thread::sleep_for(std::chrono::nanoseconds(step_time/1000));
	
	}
	return NULL;

}
void* consumer_func(void* arg)
{
	Event  _evt;
	while (continue_signal)
	{
		queue.wait_dequeue(_evt);
		if(_evt.label.compare("Step") == 0)
		{
			if(Step())
			{
				continue;
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
	ts_after2.ts_B.autState = S0;
	ts_after2.ts_B.x = 0;
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
