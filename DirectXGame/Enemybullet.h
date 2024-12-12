#pragma once
#include "WorldTransform.h"
#include "Model.h"

class Enemybullet {
public:
	void Intialize(Model* model, const Vector3& posision, const Vector3& velocity);

	void Update();

	void Draw(const ViewProjection& viewProjection);

	bool IsDead()const {return isDead_;}

	static const int32_t kLifeTime = 60*5;
private:


	WorldTransform worldtransform_;

		Model* model_  = nullptr;

		uint32_t textureHandle_ = 0u;

		Vector3 velocity_;

		int32_t deathTimer_ = kLifeTime;

		bool isDead_ = false;
};