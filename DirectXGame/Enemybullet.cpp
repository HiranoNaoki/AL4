#include "Enemybullet.h"
#include "MathUtilityForText.h"	
#include<assert.h>
#include "TextureManager.h"

void Enemybullet::Intialize(Model* model, const Vector3& posision,const Vector3& veloicity) {

	assert(model);

	model_ = model;
	textureHandle_ = TextureManager::Load("./Resources/Black.png");


	worldtransform_.Initialize();
	worldtransform_.translation_ = posision;

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