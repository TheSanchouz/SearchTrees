#pragma once

template<typename Key, typename Value>
class AssociativePair
{
private:
	Key key;
	Value value;

public:
	AssociativePair(Key key = Key(NULL), Value value = Value(NULL))
		: key(key), value(value) {}
	AssociativePair(const AssociativePair &src)
	{
		key = src.key;
		value = src.value;
	}
	AssociativePair operator=(const AssociativePair &src)
	{
		key = src.key;
		value = src.value;

		return *this;
	}
	~AssociativePair()
	{

	}

	void SetValue(Value _value)
	{
		value = _value;
	}

	Key GetKey()
	{
		return key;
	}
	Value GetValue()
	{
		return value;
	}
};