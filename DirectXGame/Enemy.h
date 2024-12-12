#pragma once
#include <WorldTransform.h>
#include <Model.h>

enum class Phase {
	Approach,
	Leave,
};

class Enemy {
public:
	void Initialize(Model* model,uint32_t textureHandle);

	void Update();
	void Draw(ViewProjection& viewProjection);


	private:
		WorldTransform worldTransform_;

		Model* model_ = nullptr;

		uint32_t textureHandle_ = 0u;

		Phase phase_ = Phase::Approach;
};