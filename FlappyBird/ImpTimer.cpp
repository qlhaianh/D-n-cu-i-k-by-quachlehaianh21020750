
#include "ImpTimer.h"
#include "CommonFunc.h"

ImpTimer::ImpTimer() {
	start_tick_ = 0;
	paused_ticks_ = 0;
	is_paused_ = false;
	is_started_ = false;
}

void ImpTimer::start() {
	is_started_ = true;
	is_paused_ = false;
	start_tick_ = SDL_GetTicks();
}
 
void ImpTimer::stop() {
	is_started_ = false;
	is_paused_ = false;
}

void ImpTimer::pause() {
	if ((is_started_ == true) && (is_paused_ == false)) {
		is_paused_ = true;
		paused_ticks_ = SDL_GetTicks() - start_tick_;
	}
}

void ImpTimer::unpause() {
	if (is_paused_ == true) {
		is_paused_ = false;
		start_tick_ = SDL_GetTicks() - paused_ticks_;
		paused_ticks_ = 0;
	}
}

int ImpTimer::get_ticks() {
	if (is_started_ == true) {
		if (is_paused_ == true) {
			return paused_ticks_;
		}
		else {
			return SDL_GetTicks() - start_tick_;
		}
	}
	return 0;
}

bool ImpTimer::is_started() {
	return is_started_;
}

bool ImpTimer::is_paused() {
	return is_paused_;
}