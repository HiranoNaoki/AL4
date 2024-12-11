#include <Model.h>
#include <WorldTransform.h>
#include <Input.h>
#include "Affine.h"
#include "MathUtilityForText.h"
#include "PlayerBullet.h"
#include <list>

#pragma once
class Player {

	public:

		void Intialize(Model* model, uint32_t textureHandle);


		void Update();

		void Draw(ViewProjection& viewprojection);

		void Attack();

		~Player();

	private:

		WorldTransform worldTransform_;

		Model* model_ = nullptr;

		uint32_t textureHandle_ = 0u;

		Input* input_ =  nullptr;

		WorldTransform* worldTransformBlock = nullptr;
		
		

		std::list<PlayerBullet*> bullets_;
};