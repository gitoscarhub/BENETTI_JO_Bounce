#include "Game.h"

Game::Game()
{
    // Se crea una ventana de renderización con las dimensiones y título especificados
    _pWnd = new RenderWindow(VideoMode(800, 600, 32), "MAVI - Bounce");

    // Se crea un objeto BaseObject (_pBall) y se ajusta su escala y posición
    _pBall = new BaseObject("rcircle.png");
    _pBall->SetScale(0.50f);
    _pBall->SetPosition(Vector2f(300.0f, 100.0f));

}

Game::~Game()
{
    // Se liberan las memorias asignadas dinámicamente para el objeto BaseObject y la ventana RenderWindow
    delete _pBall;
    delete _pWnd;
}

void Game::Loop()
{
    Clock clock;
    clock.restart();
    float dt = 0.0f;

    while (_pWnd->isOpen())
    {
        // Calcula el tiempo transcurrido desde la última iteración del bucle
        float dt = clock.restart().asSeconds();

        // Procesa eventos, actualiza y dibuja en cada iteración
        _ProcessEvents();
        _Update(dt);
        _Draw();
    }
}

void Game::_Draw()
{
    // Limpia la ventana con un color de fondo negro
    _pWnd->clear(Color::Black);

   
    // Dibuja el objeto BaseObject (_pBall)
    _pBall->Draw(_pWnd);

    // Muestra en pantalla lo que se ha dibujado
    _pWnd->display();

}

void Game::_Update(float dt)
{
                 
             // Aplicar velocidad al objeto
                   _pBall->AddAcceleration(Vector2f(0.0f, 9.8f));
                   
                   //porcentaje gravedad 
                   float aux = _pBall->GetVelocity().y;
                         aux = aux*(80.0f /100.0f);
            
            // Chequea si el objeto ha salido de la ventana
            if (_pBall->GetPosition().y >500.0f)
            {
             
                _pBall->SetVelocity(Vector2f(0.0f, -aux));
        
            }
           
    // Actualiza el objeto BaseObject (_pBall)
    _pBall->Update(dt);
    
}

void Game::_ProcessEvents()
{
    Event evt;
    while (_pWnd->pollEvent(evt))
    {
        // Si se cierra la ventana, termina el bucle
        if (evt.type == Event::Closed)
        {
            _pWnd->close();
        }
    }
}
