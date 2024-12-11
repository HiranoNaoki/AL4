#include <PlayerBullet.h>
#include <TextureManager.h>
#include "MathUtilityForText.h"

void PlayerBullet::Intialize(Model* model, const Vector3& position, const Vector3& velocity){
	assert(model);

	model_ = model;

	textureHandle_ = TextureManager::Load("./Resources/black.png");
	worldtransform_.Initialize();

	worldtransform_.translation_ = position;

	velocity_ = velocity;
};

void PlayerBullet::Update(){
	worldtransform_.UpdateMatrix();

	worldtransform_.translation_ += velocity_;

	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
};

void PlayerBullet::Draw(const ViewProjection& viewProjection){
	model_->Draw(worldtransform_, viewProjection, textureHandle_);

};
