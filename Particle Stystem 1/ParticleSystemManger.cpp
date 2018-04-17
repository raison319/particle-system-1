#include "ParticleSystemManager.h"

ParticleSystemManager::ParticleSystemManager(Texture &t)
{
	ParticleSystem *particles1 = new ParticleSystem(200);
	particles1->t = t;
	particles1->velocityXStrategy = new LinearStrategy();
	particles1->velocityYStrategy = new LinearStrategy();
	particles1->sizeStrategy = new LinearStrategy();
	particles1->m_emitter = Vector2f(350,500);
	ParticleSystem *particles2 = new ParticleSystem(200);
	particles2->t = t;
	particles2->velocityXStrategy = new LinearStrategy();
	particles2->velocityYStrategy = new ExponentialStrategy();
	particles2->sizeStrategy = new ExponentialStrategy();
	particles2->m_emitter = Vector2f(700, 500);
	ParticleSystem *particles3 = new ParticleSystem(200);
	particles3->t = t;
	particles3->velocityXStrategy = new LinearStrategy();
	particles3->velocityYStrategy = new SinStrategy();
	particles3->sizeStrategy = new SinStrategy();
	particles3->m_emitter = Vector2f(1050, 500);

	particleSystems.push_back(particles1);
	particleSystems.push_back(particles2);
	particleSystems.push_back(particles3);
}