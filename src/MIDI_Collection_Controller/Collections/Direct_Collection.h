#ifndef Direct_Collection_h
	#define Direct_Collection_h

	#include "../../MIDI_Device_Controller/MIDI_Device.h"
	#include "../Base_MIDI_Device_Collection.h"

	struct MIDI_Device_Node;

	//Directly assigns the given note to all devices in the chain
	class Direct_Collection : public Base_MIDI_Device_Collection
	{	
		private:
		
		public:		
			//Abstract implementations		
			bool playNote(uint8_t note);
			void stopNote(uint8_t note);
	};
	
#endif