#pragma once
#include <WorldTransform.h>
#include <Model.h>
#include "Enemybullet.h"

enum class Phase {
	Approach,
	Leave,
};

class Enemy {
public:
	void Initialize(Model* model,uint32_t textureHandle);

	void Update();
	void Draw(ViewProjection& viewProjection);

	void Fire();

	~Enemy();

	static const int kFiretime = 60;

	void Approach();

	private:
		WorldTransform worldTransform_;

		Model* model_ = nullptr;

		uint32_t textureHandle_ = 0u;

		Phase phase_ = Phase::Approach;

		std::list<Enemybullet*> bullets_;

		int32_t fireTimer_ = 0;
};