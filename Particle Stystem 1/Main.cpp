#include "ParticleSystemManager.h"

int main()
{
	Texture tex;
	tex.loadFromFile("tex.png");


	// create the window
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Particles");

	// create the particle system
	ParticleSystemManager psm(tex);
	// create a clock to track the elapsed time
	sf::Clock clock;

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Add || event.key.code == sf::Keyboard::Equal))
			{
				vector<Particle> new_particles(100);
				for (ParticleSystem *ps : psm.particleSystems)
				{
					ps->m_particles.insert(ps->m_particles.end(), new_particles.begin(), new_particles.end());
				}
			}
			else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Subtract || event.key.code == sf::Keyboard::Dash))
			{
				for (ParticleSystem *ps : psm.particleSystems)
				{
					if (ps->m_particles.size() > 100)
					{
						ps->m_particles.erase(ps->m_particles.end() - 100, ps->m_particles.end());
					}
				}

			}
		}

		// make the particle system emitter follow the mouse
		//sf::Vector2i mouse = sf::Mouse::getPosition(window);
		//particles.setEmitter(window.mapPixelToCoords(mouse));
		// update it
		sf::Time elapsed = clock.restart();
		
		// draw it
		window.clear();
		for (ParticleSystem *ps : psm.particleSystems)
		{

			ps->update(elapsed);
			for (Particle p : ps->m_particles)
			{
				window.draw(p.rect);
			}
		}
		window.display();
	}

	return 0;
}