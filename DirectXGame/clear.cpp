#include "clear.h"
#include <Input.h>
#include "TextureManager.h"
#include <Sprite.h>
#include "DirectXCommon.h"
#include <numbers>

void clear::Initialize(){
	textureHandle_ = TextureManager::Load("./Resources/clear.png");
	sprite_ = Sprite::Create(textureHandle_,{0,0});
}

void clear::Update(){
	if (Input::GetInstance()->PushKey(DIK_Z)) {
		finished_ = true;
	}
}

void clear::Draw(){

	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();


	Sprite::PreDraw(commandList);

	sprite_->Draw();

	
	Sprite::PostDraw();
}