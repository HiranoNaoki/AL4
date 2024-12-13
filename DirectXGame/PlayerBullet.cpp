#include <PlayerBullet.h>
#include <TextureManager.h>
#include "MathUtilityForText.h"

void PlayerBullet::Intialize(Model* model, const Vector3& position, const Vector3& velocity){
	assert(model);

	model_ = model;

	textureHandle_ = TextureManager::Load("./Resources/White1x1.png");
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

Vector3 PlayerBullet::GetWorldPosition() {
	Vector3 worldPos;

	worldPos.x = worldtransform_.translation_.x;
	worldPos.y = worldtransform_.translation_.y;
	worldPos.z = worldtransform_.translation_.z;
	return worldPos;
}



void PlayerBullet::OnCollision(){isDead_ = true;}
