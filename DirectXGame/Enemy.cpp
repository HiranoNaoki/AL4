#include "Enemy.h"
#include <cassert>
#include <MathUtilityForText.h>
#include <imgui.h>

void Enemy::Initialize(Model* model,uint32_t textureHandle){
	
	
	

	model_ = model;
	textureHandle_ = textureHandle;

	worldTransform_.Initialize();

}

void Enemy::Draw(ViewProjection& viewProjection){
	model_->Draw(worldTransform_,viewProjection,textureHandle_);
}

void Enemy::Update(){
	worldTransform_.TransferMatrix();
	Vector3 move = {0,0,0};

	const float kCharacterSpeed = 0.02f;

	move.z-= kCharacterSpeed;

	worldTransform_.translation_ += move;

	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_,worldTransform_.rotation_,worldTransform_.translation_);

	worldTransform_.TransferMatrix();

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


