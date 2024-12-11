#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "Affine.h"
#include <Vector3.h>
#include "WorldTransform.h"

class PlayerBullet {
	public:

		void Intialize(Model* model,const Vector3& position, const Vector3& velocity);

		void Update();

		void Draw(const ViewProjection&  viewProjection);

		static const int32_t kLiferTime = 60*5;

		bool IsDead() const {return isDead_;}

	private:
		WorldTransform worldtransform_;

		Model* model_  = nullptr;

		uint32_t textureHandle_ = 0u;

		Vector3 velocity_;

		

		int32_t deathTimer_ = kLiferTime;

		bool isDead_ = false;

		
};