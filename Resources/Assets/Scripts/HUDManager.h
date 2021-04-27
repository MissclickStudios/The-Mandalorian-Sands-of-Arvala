#pragma once
#include <string>
#include "Script.h"
#include "ScriptMacros.h"


class GameObject;
class C_2DAnimator;
class C_UI_Text;
class C_Material;
class Player;
class R_Texture;

class SCRIPTS_API HUDManager : public Script {
public:
	HUDManager();
	~HUDManager();

	void Start() override;
	void Update() override;
	void CleanUp() override;

	std::string mandoImageName = "Mando";
	std::string secondaryWeaponImageName = "SecodaryWeapon";
	std::string primaryWeaponImageName = "PrimaryWeapon";
	std::string dashImageName = "Dash";
	std::string creditsImageName = "Credits";
	std::string playerName = "Mandalorian";

	std::string debugMenuCanvasName = "DebugMenuCanvas";
	std::string hubShopCanvasName = "hubShopCanvas";
	std::string hudCanvasName = "hubShopCanvas";
	std::string pauseMenuCanvasName = "pauseMenuCanvas";

	std::string creditsTextName = "CreditsText";
	std::string beskarTextName = "BeskarText";
	std::string ammoTextName = "AmmoText";


	std::string heart1Name = "Heart1";
	std::string heart2Name = "Heart2";
	std::string heart3Name = "Heart3";
private:
	C_2DAnimator* mandoImage;
	C_2DAnimator* secondaryWeaponImage;
	C_2DAnimator* primaryWeaponImage;
	C_2DAnimator* dashImage;
	C_2DAnimator* creditsImage;

	GameObject* playerObject;
	Player* player;

	C_Canvas* debugMenuCanvas = nullptr;
	C_Canvas* hubShopCanvas = nullptr;
	C_Canvas* hudCanvas = nullptr;
	C_Canvas* pauseMenuCanvas = nullptr;

	C_UI_Text* creditsText = nullptr;
	C_UI_Text* beskarText = nullptr;
	C_UI_Text* ammoText = nullptr;

	C_Material* heart1;
	C_Material* heart2;
	C_Material* heart3;

	R_Texture* halfHeart;
	R_Texture* fullHeart;
	R_Texture* emptyHeart;

	bool hitAlready;

	void ManageHeartImage(int hp);
};

SCRIPTS_FUNCTION HUDManager* CreateHUDManager() {
	HUDManager* script = new HUDManager();
	INSPECTOR_STRING(script->mandoImageName);
	INSPECTOR_STRING(script->secondaryWeaponImageName);
	INSPECTOR_STRING(script->primaryWeaponImageName);
	INSPECTOR_STRING(script->dashImageName);
	INSPECTOR_STRING(script->creditsImageName);
	INSPECTOR_STRING(script->playerName);
	INSPECTOR_STRING(script->debugMenuCanvasName);
	INSPECTOR_STRING(script->hubShopCanvasName);
	INSPECTOR_STRING(script->hudCanvasName);
	INSPECTOR_STRING(script->pauseMenuCanvasName);

	INSPECTOR_STRING(script->creditsTextName);
	INSPECTOR_STRING(script->beskarTextName);
	INSPECTOR_STRING(script->ammoTextName);
	return script;
}