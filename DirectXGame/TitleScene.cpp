#include "TitleScene.h"
#include <Input.h>
#include <DirectXCommon.h>
#include "Sprite.h"
#include <TextureManager.h>

void TitleScene::Initialize(){
	textureHandle_ = TextureManager::Load("./Resources/title.png");
	sprite_ = Sprite::Create(textureHandle_,{0,0});
}


void TitleScene::Update(){
	if (Input::GetInstance()->PushKey(DIK_RETURN)) {
		finished_ = true;
	}
}

void TitleScene::Draw(){
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();


	Sprite::PreDraw(commandList);

	sprite_->Draw();

	
	Sprite::PostDraw();

}
