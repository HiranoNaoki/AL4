#include "Player.h"

#include <cassert>

#include <Vector3.h>

void Player::Intialize(Model* model, uint32_t textureHandle){
	assert(model);
	textureHandle_ = textureHandle;

	model_ = model;

	worldTransform_.Initialize();

	input_ = Input::GetInstance();
}

void Player::Draw(ViewProjection& viewProjection){
	model_->Draw(worldTransform_,viewProjection,textureHandle_);

	for (PlayerBullet* bullet : bullets_){
		bullet->Draw(viewProjection);
	}
}

void Player::Update(){

	bullets_.remove_if([](PlayerBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});

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

	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();


	const float kMoveLimitx = 30;
	const float kMoveLimity = 15;

	worldTransform_.translation_.x  = max(worldTransform_.translation_.x, -kMoveLimitx);
	worldTransform_.translation_.x  = min(worldTransform_.translation_.x, +kMoveLimitx);
	worldTransform_.translation_.y  = max(worldTransform_.translation_.y, -kMoveLimity);
	worldTransform_.translation_.y= min(worldTransform_.translation_.y, +kMoveLimity);

	const float kRotSpeed = 0.02f;
	if (input_->PushKey(DIK_A)) {
		worldTransform_.rotation_.y -= kRotSpeed;
	}
	else if(input_->PushKey(DIK_D)){
		worldTransform_.rotation_.y -= kRotSpeed;
	}

	Attack();

	for (PlayerBullet* bullet : bullets_) {
		bullet->Update();
	}
}

void Player::Attack(){
	if (input_->PushKey(DIK_RETURN)) {

		const float kBulletSpeed = 1.0f;
		Vector3 velocity(0,0,kBulletSpeed);
		
		velocity = TransformNormal(velocity,worldTransform_.matWorld_);

		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Intialize(model_,worldTransform_.translation_,velocity);

		

		bullets_.push_back(newBullet);
	}
};

Player::~Player() {
	for (PlayerBullet* bullet : bullets_) {
		delete bullet;
	}
}