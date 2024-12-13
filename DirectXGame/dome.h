#pragma once
#include "WorldTransform.h"
#include "Model.h"


class dome {
public:
	void Initialize(Model*model, ViewProjection* viewProjection);

	void Update();

	void Draw();


	private:

		WorldTransform worldTransform_;

		ViewProjection* viewProjection_ =nullptr;

		Model* model_ = nullptr;
};