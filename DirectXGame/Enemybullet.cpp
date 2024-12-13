#include "Enemybullet.h"
#include "MathUtilityForText.h"	
#include<assert.h>
#include "TextureManager.h"

void Enemybullet::Intialize(Model* model, const Vector3& position,const Vector3& veloicity) {

	assert(model);

	model_ = model;
	textureHandle_ = TextureManager::Load("./Resources/Black.png");


	worldtransform_.Initialize();
	worldtransform_.translation_ = position;

	velocity_ = veloicity;

}
void Enemybullet::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldtransform_,viewProjection,textureHandle_);
}
void Enemybullet::Update(){
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}



	worldtransform_.translation_ += velocity_;
	worldtransform_.UpdateMatrix();
}

Vector3 Enemybullet::GetWorldPosition() {
	Vector3 worldPos;

	worldPos.x = worldtransform_.translation_.x;
	worldPos.y = worldtransform_.translation_.y;
	worldPos.z = worldtransform_.translation_.z;
	return worldPos;
}



void Enemybullet::OnCollision(){isDead_ = true;}