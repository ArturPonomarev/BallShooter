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

    // ������������ ����� GameState
    virtual void Init() override;
    virtual void Leave() override;
    virtual void Pause() override;
    virtual void Resume() override;
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
    virtual void HandleEvent() override;


    std::shared_ptr<GameObject>& CreateObject(ObjectTypes type); //������� ������ ���� type
    void DeleteObjects(); //������� ��� ������� � ������ delete = true;
    

private:

    std::shared_ptr<Content> m_content; 

    std::weak_ptr<PlayerObject> m_player;               //�����
    std::vector<std::shared_ptr<GameObject>> m_objects; //������ ��������
    std::shared_ptr<GameObject> m_bufObject;            //��������� ������ ��� ���������� �������, � ������� CreateObject
                                                        

    sf::Sprite m_mark;  //������, ���������� ����������� ������

    sf::View m_view;    //������                       
};

