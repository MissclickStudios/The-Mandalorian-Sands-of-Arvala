#include "Application.h"
#include "M_Scene.h"
#include "MC_Time.h"
#include "Log.h"
#include "C_AudioSource.h"
#include "GameManager.h"
#include "GameObject.h"

#include "Gate.h"

Gate::Gate() : Script()
{
}

Gate::~Gate()
{
}

void Gate::Start()
{
	gameManager = App->scene->GetGameObjectByName(gameManagerName.c_str());

	quote = new C_AudioSource(gameObject);
	if(quote != nullptr)
		quote->SetEvent("door_closed");
}

void Gate::Update()
{
	quoteTimer += MC_Time::Game::GetDT();
}

void Gate::CleanUp()
{
	delete quote;
}

void Gate::OnCollisionEnter(GameObject* object)
{
	//TODO: GameManager
	if (gameManager != nullptr) 
	{
		if (!isLocked)
		{
			if(!triggeredNextRoom)
			{
				GameManager* gameManagerScript = (GameManager*)gameManager->GetScript("GameManager");

				gameManagerScript->GoNextRoom();

				triggeredNextRoom = true;
			}
		}
		else
		{
			if (quoteTimer >= quoteDelay)
			{
				if (quote != nullptr)
					quote->PlayFx(quote->GetEventId());
				quoteTimer = 0.f;
			}
		}
	}
}

void Gate::Unlock()
{
	isLocked = false;
}

Gate* CreateGate()
{
	Gate* script = new Gate();
	INSPECTOR_STRING(script->gameManagerName);
	INSPECTOR_DRAGABLE_FLOAT(script->quoteDelay);
	return script;
}
