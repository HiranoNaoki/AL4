#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "Affine.h"
#include <Vector3.h>
#include "WorldTransform.h"

class PlayerBullet {
	public:

		void Intialize(Model* model,const Vector3& position);

		void Update();

		void Draw(const ViewProjection&  viewProjection);



	private:
		WorldTransform worldtransform_;

		Model* model_  = nullptr;

		uint32_t textureHandle_ = 0u;
};