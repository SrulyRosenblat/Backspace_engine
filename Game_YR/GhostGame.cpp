#include "GhostGame.h"

void GhostGame::OnUpdate()
{
	Draw(0, 0, bg);

	player.MoveTime();
	placePLayer();

	baby.Follow(player.GetUnit());
	baby.MoveTime();
	placeBaby();

}
void  GhostGame::placePLayer() {
	be::Unit& unit = player.GetUnit();
	if (player.FacingRight)
		Draw(unit);
	else
		DrawAlt(unit);
}
void GhostGame::placeBaby() {
	be::Unit& unit = baby.GetUnit();
	if (baby.FacingRight)
		Draw(unit);
	else
		DrawAlt(unit);
}
GhostGame::GhostGame() {
	SetKeyPressedCallback([this](const be::KeyPressed& e) {player.OnKeyPressed(e); });
	SetKeyReleasedCallback([this](const be::KeyReleased& e) {player.OnKeyReleased(e); });
}