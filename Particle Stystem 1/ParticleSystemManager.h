#pragma once
#include "ParticleSystem.h"
#include "Strategy.h"

class ParticleSystemManager
{
public:
	vector<ParticleSystem*> particleSystems;

	ParticleSystemManager(Texture &t);
};