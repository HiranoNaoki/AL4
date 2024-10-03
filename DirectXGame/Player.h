#include <Model.h>
#include <WorldTransform.h>

#pragma once
class Player {

	public:

		void Intialize(Model* model, uint32_t textureHandle);


		void Update();

		void Draw(ViewProjection& viewprojection);


	private:

		WorldTransform worldTransform_;

		Model* model_ = nullptr;

		uint32_t textureHandle_ = 0u;
		
};