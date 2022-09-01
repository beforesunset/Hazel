#pragma once
#include "Event.h"
#include "Hazel/Core/KeyCodes.h"
#include <sstream>

namespace Hazel
{
	class KeyEvent : public Event
	{
	public:
		
		KeyCode GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

	protected:
		KeyEvent(KeyCode keycode)
			: m_KeyCode(keycode) {}
		KeyCode m_KeyCode;
	};
	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keycode, bool isRepeat = false)
			: KeyEvent(keycode), m_IsRepeat(isRepeat) {}

		std::string ToString()
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		bool m_IsRepeat;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode keycode)
			: KeyEvent(keycode) {}

		std::string ToString()
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
	
		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(KeyCode keycode)
			: KeyEvent(keycode) {}

		std::string ToString()
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

}