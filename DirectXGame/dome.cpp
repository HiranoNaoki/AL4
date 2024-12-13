#include "dome.h"

void dome::Initialize(Model* model,ViewProjection* viewProjection) {
	worldTransform_.Initialize();
	model_ = model;
	viewProjection_ = viewProjection;
}

void dome::Update(){
	worldTransform_.UpdateMatrix();
}

void dome::Draw() {
	model_->Draw(worldTransform_,*viewProjection_);
}