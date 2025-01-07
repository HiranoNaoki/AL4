#pragma once
#include "Sprite.h"

class TitleScene {
public:
	void Initialize();

	void Update();

	void Draw();

bool finished_ = false;

bool IsFinished() const {return finished_;}

private:
uint32_t textureHandle_ = 0;

Sprite* sprite_ = nullptr;
};
