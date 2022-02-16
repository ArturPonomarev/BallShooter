#pragma once
#include "GameState.h"

#include "PlayerObject.h"
#include "BulletObject.h"

class PlayState :
    public GameState
{
public:
    PlayState(std::shared_ptr<Content>& content);
    ~PlayState();

    // Унаследовано через GameState
    virtual void Init() override;
    virtual void Leave() override;
    virtual void Pause() override;
    virtual void Resume() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void HandleEvent() override;


    std::shared_ptr<GameObject>& CreateObject(ObjectTypes type); //Создает объект типа type
    void DeleteObjects(); //Удаляет все объекты с меткой delete = true;
    

private:

    std::shared_ptr<Content> m_content; 

    std::weak_ptr<PlayerObject> m_player;               //Игрок
    std::vector<std::shared_ptr<GameObject>> m_objects; //Массив объектов
    std::shared_ptr<GameObject> m_bufObject;            //Временный объект для заполнения массива, в функции CreateObject
                                                        

    sf::Sprite m_mark;  //Прицел, заменяющий стандартный курсор

    sf::View m_view;    //Камера                       
};

