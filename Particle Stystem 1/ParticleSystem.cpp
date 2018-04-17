#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(unsigned int count)
{
	m_particles = vector<Particle>(count);
	m_lifetime = sf::seconds(3);
}

void ParticleSystem::resetParticle(std::size_t index)
{
	// give a random velocity and lifetime to the particle
	float angle = (std::rand() % 360) * 3.14f / 180.f;
	float speed = (std::rand() % 50) + 50.f;
	m_particles[index].startVelocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	m_particles[index].velocity = m_particles[index].startVelocity;
	m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);
	m_particles[index].currentLifetime = m_particles[index].lifetime;
	m_particles[index].startSize = (rand() % 30) + 40;
	m_particles[index].size = m_particles[index].startSize;
	m_particles[index].rect.setSize(Vector2f(m_particles[index].size, m_particles[index].size));
	m_particles[index].rect.setOrigin(Vector2f(25, 25));
	m_particles[index].rect.setPosition(m_emitter);
	m_particles[index].rect.setTexture(&t);
}


void ParticleSystem::setEmitter(sf::Vector2f position)
{
	m_emitter = position;
}


void ParticleSystem::update(sf::Time elapsed)
{
	for (std::size_t i = 0; i < m_particles.size(); ++i)
	{
		// update the particle lifetime
		Particle& p = m_particles[i];
		p.currentLifetime -= elapsed;

		// if the particle is dead, respawn it
		if (p.currentLifetime <= sf::Time::Zero)
			resetParticle(i);

		float ratio = p.currentLifetime.asSeconds() / p.lifetime.asSeconds();

		if (velocityXStrategy != nullptr)
			p.velocity = Vector2f(velocityXStrategy->update(ratio)*p.startVelocity.x, p.velocity.y);
		if (velocityYStrategy != nullptr)
			p.velocity = Vector2f(p.velocity.x, velocityYStrategy->update(ratio)*p.startVelocity.y);

		if (sizeStrategy != nullptr)
			p.size = sizeStrategy->update(ratio) * p.startSize;
		// update the position of the corresponding vertex

		p.rect.move(elapsed.asSeconds()*p.velocity.x, elapsed.asSeconds()*p.velocity.y);
		p.rect.setSize(Vector2f(p.size, p.size));

		// update the alpha (transparency) of the particle according to its lifetime
		Color c = p.rect.getFillColor();
		c.a = static_cast<sf::Uint8>(ratio * 255);
		p.rect.setFillColor(c);
	}
}