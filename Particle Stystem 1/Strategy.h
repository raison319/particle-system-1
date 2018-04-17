#pragma once

class StrategyPattern
{
public:
	virtual float update(float ratio) = 0;
};

class LinearStrategy : public StrategyPattern
{
public:
	virtual float update(float ratio)
	{
		return 1;
	}
};

class ExponentialStrategy : public StrategyPattern
{
public:
	virtual float update(float ratio)
	{
		return 3*ratio*ratio*ratio*ratio;
	}
};

class SinStrategy : public StrategyPattern
{
public:
	virtual float update(float ratio)
	{
		return sinf(ratio*2*3.14);
	}
};