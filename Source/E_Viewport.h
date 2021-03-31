#ifndef __E_VIEWPORT_H__
#define __E_VIEWPORT_H__

#include "MathGeoLib/include/Math/float2.h"
#include "ImGuizmo/include/ImGuizmo.h"
#include "EditorPanel.h"

class E_Viewport : public EditorPanel
{
public:
	E_Viewport();
	~E_Viewport();

	bool Draw			(ImGuiIO& io) override;
	bool CleanUp		() override;

public:
	float2	GetWorldMousePosition				();
	float2	GetScreenMousePosition				();
	float2	GetWorldMouseMotion					();
	float2	GetSceneTextureSize					();

	bool	UsingGuizmo							();
	bool	HoveringGuizmo						();

private:
	void	DrawScene							();
	void	DrawGame							();
	
	void	AdaptTextureToWindowSize			();
	void	AdaptTextureToGameWindowSize		();
	void	DrawSceneTexture					();

	void	ResourceDragAndDropTargetListener	();

	void	HandleGuizmos						();

private:
	ImVec2					texSize;
	ImVec2					texOrigin;
	ImVec2					cursorPos;

	ImGuizmo::OPERATION		guizmoOperation;
	ImGuizmo::MODE			guizmoMode;

	bool					usingGuizmo;

	bool					sceneFocused;
	bool					gameFocused;

private:
	bool					wantTextInput;
};

#endif // !__E_VIEWPORT_H__