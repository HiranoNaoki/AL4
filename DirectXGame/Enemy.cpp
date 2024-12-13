#include "Enemy.h"
#include <cassert>
#include <MathUtilityForText.h>
#include <imgui.h>
#include "Player.h"

void Enemy::Initialize(Model* model,uint32_t textureHandle){
	
	
	

	model_ = model;
	textureHandle_ = textureHandle;

	worldTransform_.Initialize();

}

void Enemy::Draw(ViewProjection& viewProjection){
	model_->Draw(worldTransform_,viewProjection,textureHandle_);

	for (Enemybullet* bullet : bullets_) {
		bullet->Draw(viewProjection);
	}
}

void Enemy::Update(){

	bullets_.remove_if([](Enemybullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;

	});



	worldTransform_.TransferMatrix();
	Vector3 move = {0,0,0};

	const float kCharacterSpeed = -0.05f;

	move.z-= kCharacterSpeed;

	worldTransform_.translation_ += move;

	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_,worldTransform_.rotation_,worldTransform_.translation_);

	worldTransform_.TransferMatrix();

	Approach();
	for (Enemybullet* bullet : bullets_) {
		bullet->Update();
	}

	Vector3 Amove = {0.2f,0.0f,0.0f};
	Vector3 Lmove = {0.2f,0.0f,0.0f};

	switch (phase_) {
		case Phase::Approach:
			default:
				worldTransform_.translation_ += Amove;
				if (worldTransform_.translation_.x >15.0f) {
					phase_ = Phase::Leave;
				}
				break;

		case Phase::Leave:

			worldTransform_.translation_ -= Lmove;
				if (worldTransform_.translation_.x <-15.0f) {
					phase_ = Phase::Approach;
				}
			break;
	}

	ImGui::Begin("Player");

	//ImGui::Text("Current Phase: %s" , phaseName);

	ImGui::End();

	/*const float kMoveLimitX = 34;
	const float kMoveLimitY = 18;

	
	worldTransform_.translation_.x = max(worldTransform_.translation_.x,-kMoveLimitX);
		worldTransform_.translation_.x = min(worldTransform_.translation_.x,-kMoveLimitX);
		worldTransform_.translation_.y = max(worldTransform_.translation_.y,-kMoveLimitY);
		worldTransform_.translation_.y = min(worldTransform_.translation_.y,-kMoveLimitY);*/

		//worldTransform_.TransferMatrix();
}

void Enemy::Fire() {
	const float kBulletSpeed = -1.0f;
	Vector3 velocity(0,0,kBulletSpeed);
	velocity = TransformNormal(velocity,worldTransform_.matWorld_);

	Vector3 playerPos = player_->GetWorldPosition();

	Vector3 enemyPos = Enemy::GetWorldPosition();

	Vector3 direction = enemyPos - playerPos;

	Vector3 normalizedDirection = Normalize(direction);
	
	velocity = normalizedDirection * kBulletSpeed;

	Enemybullet* newBullet = new Enemybullet();
	newBullet->Intialize(model_,worldTransform_.translation_,velocity);

	bullets_.push_back(newBullet);
}

Enemy::~Enemy() {
	for (Enemybullet* bullet : bullets_) {
		delete bullet;
	}
}

void Enemy::Approach() {
	fireTimer_++;

	if (fireTimer_ == kFiretime) {
		Fire();

		fireTimer_=0;
	}
}

Vector3 Enemy::GetWorldPosition() {
	Vector3 worldpos;

	worldpos.x = worldTransform_.translation_.x;
	worldpos.y = worldTransform_.translation_.y;
	worldpos.z = worldTransform_.translation_.z;

	return worldpos;
}

void Enemy::OnCollision(){};
