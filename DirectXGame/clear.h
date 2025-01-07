#pragma once

#include <Input.h>
#include "Model.h"
#include"ViewProjection.h"
#include"WorldTransform.h"
#include "GameScene.h"

class clear {
	public:
		void Initialize();

		void Draw();

		void Update();

		bool finished_ = false;

bool IsFinished() const {return finished_;}

private:
uint32_t textureHandle_ = 0;

Sprite* sprite_ = nullptr;

};