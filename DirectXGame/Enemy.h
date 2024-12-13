#pragma once
#include <WorldTransform.h>
#include <Model.h>
#include "Enemybullet.h"

class Player;

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

	void SetPlayer(Player* player){player_ = player;}

	Vector3 GetWorldPosition();

	void OnCollision();

	const std::list<Enemybullet*>& GetBullets() const {return bullets_;}
	private:
		WorldTransform worldTransform_;

		Model* model_ = nullptr;

		uint32_t textureHandle_ = 0u;

		Phase phase_ = Phase::Approach;

		std::list<Enemybullet*> bullets_;

		int32_t fireTimer_ = 0;

		Player* player_ = nullptr;
};