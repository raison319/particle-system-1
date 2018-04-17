#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "Strategy.h"
using namespace sf;
using namespace std;

struct Particle
{
	Vector2f velocity, startVelocity;
	float size, startSize;
	Time currentLifetime, lifetime;
	RectangleShape rect;
};

class ParticleSystem
{
public:
	std::vector<Particle> m_particles;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
	Texture t;

	ParticleSystem(unsigned int count);
	void resetParticle(std::size_t index);
	void setEmitter(sf::Vector2f position);
	void update(sf::Time elapsed);

	StrategyPattern *velocityXStrategy = nullptr;
	StrategyPattern *velocityYStrategy = nullptr;
	StrategyPattern *sizeStrategy = nullptr;

};
