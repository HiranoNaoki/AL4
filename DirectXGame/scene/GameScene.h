#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"Player.h"
#include "DebugCamera.h"
#include "MathUtilityForText.h"
#include <Enemy.h>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

		Model* model_ = nullptr;

		Model* modelEnemy_ = nullptr;

		WorldTransform worldTransform_;
		
	ViewProjection viewProjection_;

	void CheckAllColisions();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	uint32_t textureHandle_ = 0;

	uint32_t textureHandleEne_ = 0;




	Player* player_ = nullptr;

	Enemy* enemy_ = nullptr;

	bool isDebugCameraActive_ = false;

	DebugCamera* debugCamera_ = nullptr;
	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
