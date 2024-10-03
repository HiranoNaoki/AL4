#include "Player.h"
#include <cassert>

void Player::Intialize(Model* model, uint32_t textureHandle){
	assert(model);
	textureHandle_ = textureHandle;

	model_ = model;

	worldTransform_.Initialize();
}

void Player::Draw(ViewProjection& viewProjection){
	model_->Draw(worldTransform_,viewProjection,textureHandle_);
}

void Player::Update(){
	worldTransform_.TransferMatrix();
}