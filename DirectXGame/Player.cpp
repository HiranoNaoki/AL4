#include "Player.h"
#include <cassert>

void Player::Intialize(Model* model, uint32_t textureHandle){
	assert(model);
	textureHandle_ = textureHandle;

	model_ = model;

	worldTransform_.Initialize();

	input_ = Input::GetInstance();
}

void Player::Draw(ViewProjection& viewProjection){
	model_->Draw(worldTransform_,viewProjection,textureHandle_);
}

void Player::Update(){
	worldTransform_.TransferMatrix();

	Vector3 move = {0,0,0};

	const float kCharacterSpeed = 2.0f;

	if (input_->PushKey(DIK_LEFT)) {
		move.x -= kCharacterSpeed;
	}
	else if (input_->PushKey(DIK_RIGHT)){
		move.x += kCharacterSpeed;
    }

	if (input_->PushKey(DIK_UP)) {
		move.y += kCharacterSpeed;
	}
	else if (input_->PushKey(DIK_DOWN)) {
		move.y -= kCharacterSpeed;
	}

	worldTransform_.translation_ += move;
}