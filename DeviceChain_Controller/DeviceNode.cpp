#include "DeviceNode.h"
#include "../MIDI_DeviceController/Device.h"
#include "DeviceChain_Base.h"

SerialDebug DeviceNode::_debug;

DeviceNode::DeviceNode(Device *d, DeviceChain_Base *dc)
{
	device = d;
	parent = dc;
}

bool DeviceNode::tryAssign(uint8_t note)
{
	if(device->isAvailable())
	{
		//DEBUG2(device->getID(), F(" - Available"))
		device->assignNote(note);
		return true;
	}
	
	//DEBUG2(device->getID(), F(" - Not available"))
	return false;
}

bool DeviceNode::tryClear(uint8_t note)
{
	if(device->getCurrentNote() == note)
	{
		//DEBUG2(device->getID(), F(" - Matches"))
		device->clearNote();
		return true;
	}
	
	//DEBUG3(device->getID(), F(" - Doesn't match: "), device->getCurrentNote())
	return false;
}

void DeviceNode::assignNote(uint8_t note)
{
	device->assignNote(note);	
	// lastAssignStamp = millis();
}

void DeviceNode::clearNote()
{
	device->clearNote();	
	// lastAssignStamp = 0;
}