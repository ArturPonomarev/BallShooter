#include "MainMenuState.h"
#include "PlayState.h"



#include "Game.h"
#include "Assets.h"

MainMenuState::MainMenuState(std::shared_ptr<Content>& content)
{
	m_content = content;
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Init()
{
	m_content->assetMan->AddFont(Fonts::MAIN_FONT, "Fonts/PFAgoraSlabProBold.ttf");
	
	m_exitTextLabel.setFont(m_content->assetMan->GetFont(MAIN_FONT));
	m_startTextLabel.setFont(m_content->assetMan->GetFont(MAIN_FONT));
	m_titleLabel.setFont(m_content->assetMan->GetFont(MAIN_FONT));

	//Заголовок-----------------------------------------------
	m_titleLabel.setString("Ball Shooter");
	m_titleLabel.setCharacterSize(50);
	m_titleLabel.setPosition(475, 100);
	m_titleLabel.setFillColor(sf::Color::Black);
	//--------------------------------------------------------


	//Кнопка старта-------------------------------------------
	m_startButtonFrame.setPosition(475, 300);
	m_startButtonFrame.setSize(sf::Vector2f(300.f, 50.f));
	m_startButtonFrame.setFillColor(sf::Color(sf::Color::White));
	m_startButtonFrame.setOutlineThickness(5);
	m_startButtonFrame.setOutlineColor(sf::Color::Black);

	m_startTextLabel.setString("Start");
	m_startTextLabel.setCharacterSize(30);
	m_startTextLabel.setPosition(580, 305);
	m_startTextLabel.setFillColor(sf::Color::Black);
	//--------------------------------------------------------


	//Кнопка выхода-------------------------------------------
	m_exitButtonFrame.setPosition(475, 500);
	m_exitButtonFrame.setSize(sf::Vector2f(300.f, 50.f));
	m_exitButtonFrame.setFillColor(sf::Color(sf::Color::White));
	m_exitButtonFrame.setOutlineThickness(5);
	m_exitButtonFrame.setOutlineColor(sf::Color::Black);

	m_exitTextLabel.setString("Exit");
	m_exitTextLabel.setCharacterSize(30);
	m_exitTextLabel.setPosition(590, 505);
	m_exitTextLabel.setFillColor(sf::Color::Black);
	//--------------------------------------------------------


	m_isStartButtonPressed = false;
	m_isExitButtonPressed = false;
	m_isStartButtonSelected = false;
	m_isExitButtonSelected = false;


	
}

void MainMenuState::Leave()
{
}

void MainMenuState::Pause()
{
}

void MainMenuState::Resume()
{
}

void MainMenuState::Render()
{
	m_content->renderWindow->clear(sf::Color::White);

	m_content->renderWindow->draw(m_titleLabel);
	m_content->renderWindow->draw(m_startButtonFrame);
	m_content->renderWindow->draw(m_startTextLabel);
	m_content->renderWindow->draw(m_exitButtonFrame);
	m_content->renderWindow->draw(m_exitTextLabel);
	
	m_content->renderWindow->display();
}

void MainMenuState::Update(float deltaTime)
{
	this->HandleEvent();

	sf::Vector2i cursorPos = sf::Mouse::getPosition(*(m_content->renderWindow.get()));
	
	//Выделение кнопки старта---------------------------------
	if (m_startButtonFrame.getGlobalBounds().contains(m_content->renderWindow->mapPixelToCoords(cursorPos)))
	{
		m_startButtonFrame.setFillColor(sf::Color::Green);
		m_isStartButtonSelected = true;
	}
	else
	{
		m_startButtonFrame.setFillColor(sf::Color::White);
		m_isStartButtonSelected = false;
	}
	//--------------------------------------------------------


	//Выделение кнопки выхода---------------------------------
	if (m_exitButtonFrame.getGlobalBounds().contains(m_content->renderWindow->mapPixelToCoords(cursorPos)))
	{
		m_exitButtonFrame.setFillColor(sf::Color::Green);
		m_isExitButtonSelected = true;
	}
	else
	{
		m_exitButtonFrame.setFillColor(sf::Color::White);
		m_isExitButtonSelected = false;
	}
	//--------------------------------------------------------


	//Нажатие кнопки старта-----------------------------------
	if (m_isStartButtonPressed)
		m_content->stateMan->Add(std::make_unique<PlayState>(m_content));
	m_isStartButtonPressed = false;
	//--------------------------------------------------------


	//Нажатие кнопки выхода-----------------------------------
	if (m_isExitButtonPressed)
		m_content->renderWindow->close();
	m_isExitButtonPressed = false;
	//--------------------------------------------------------
}


void MainMenuState::HandleEvent()
{
	sf::Event ev;

	while (m_content->renderWindow->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			m_content->renderWindow->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (m_isStartButtonSelected)
				m_isStartButtonPressed = true;

			if (m_isExitButtonSelected)
				m_isExitButtonPressed = true;
			break;

		default:
			break;
		}
	}
}
