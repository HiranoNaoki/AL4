#include <PlayerBullet.h>
#include <TextureManager.h>

void PlayerBullet::Intialize(Model* model, const Vector3& position){
	assert(model);

	model_ = model;

	textureHandle_ = TextureManager::Load("./Resources/black.png");
	worldtransform_.Initialize();

	worldtransform_.translation_ = position;
};

void PlayerBullet::Update(){
	worldtransform_.UpdateMatrix();
};

void PlayerBullet::Draw(const ViewProjection& viewProjection){
	model_->Draw(worldtransform_, viewProjection, textureHandle_);

};
