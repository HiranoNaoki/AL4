#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include "AxisIndicator.h"

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete model_;
	delete player_;
	delete debugCamera_;
	delete enemy_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	textureHandle_ = TextureManager::Load("./Resources/mario.png");
	textureHandleEne_ = TextureManager::Load("./Resources/black.png");


	model_ = Model::Create();
	modelEnemy_ = Model::Create();

	viewProjection_.Initialize();

	player_ = new Player();
	player_->Intialize(model_,textureHandle_);

	enemy_ = new Enemy();
	enemy_->Initialize(modelEnemy_,textureHandleEne_);

	debugCamera_ = new DebugCamera(1280,720);

	AxisIndicator::GetInstance()->SetVisible(true);
	AxisIndicator::GetInstance()->SetTargetViewProjection(&viewProjection_);

	enemy_->SetPlayer(player_);

}

void GameScene::Update() {
	player_->Update();

	enemy_->Update();

	debugCamera_->Update();

	CheckAllColisions();

#ifdef _DEBUG
	if (input_->TriggerKey(DIK_SPACE)) {

	}isDebugCameraActive_ =true;
#endif
	if (isDebugCameraActive_) {

		debugCamera_->Update();
		viewProjection_.matView = debugCamera_->GetViewProjection().matView;
		viewProjection_.matProjection = debugCamera_->GetViewProjection().matProjection;
		
		viewProjection_.TransferMatrix();

	}else {
		
		viewProjection_.TransferMatrix();
	

	}
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	/// 
	player_->Draw(viewProjection_);

	enemy_->Draw(viewProjection_); 
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion


	
}

void GameScene::CheckAllColisions() {
	Vector3 posA,posB;

	const std::list<PlayerBullet*>& playerBullets = player_->GetBullets();

	const std::list<Enemybullet*>& enemyBullets = enemy_->GetBullets();
	#pragma region 自キャラと敵弾の当たり判定

	posA = player_->GetWorldPosition();
	for (Enemybullet* bullet : enemyBullets) {
		
		posB = bullet->GetWorldPosition();
		
		if (((posB.x - posA.x) * (posB.x - posA.x) + (posB.y - posA.y) * (posB.y - posA.y) + (posB.z - posA.z) * (posB.z - posA.z) <= (1.0f + 1.0f) * (1.0f + 1.0f))) {
			
			player_->OnCollision();
			
			bullet->OnCollision();
		}
	}
#pragma endregion
#pragma region 自弾と敵キャラの当たり判定
	
	posB = enemy_->GetWorldPosition();
	for (PlayerBullet* bullet : playerBullets) {
		
		posA = bullet->GetWorldPosition();
		
		if (((posB.x - posA.x) * (posB.x - posA.x) + (posB.y - posA.y) * (posB.y - posA.y) + (posB.z - posA.z) * (posB.z - posA.z) <= (1.0f + 1.0f) * (1.0f + 1.0f))) {
			
			enemy_->OnCollision();
			
			bullet->OnCollision();
		}
	}
#pragma endregion
#pragma region 自弾と敵弾の当たり判定
	for (PlayerBullet* bulletP : playerBullets) {
		
		posA = bulletP->GetWorldPosition();
		for (Enemybullet* bulletE : enemyBullets) {
			
			posB = bulletE->GetWorldPosition();
			
			if (((posB.x - posA.x) * (posB.x - posA.x) + (posB.y - posA.y) * (posB.y - posA.y) + (posB.z - posA.z) * (posB.z - posA.z) <= (1.0f + 1.0f) * (1.0f + 1.0f))) {
				
				bulletP->OnCollision();
				
				bulletE->OnCollision();
			}
		}
	}
#pragma endregion
}
