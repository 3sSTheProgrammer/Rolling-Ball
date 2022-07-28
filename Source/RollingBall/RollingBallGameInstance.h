// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RollingBallGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ROLLINGBALL_API URollingBallGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	int32 PlayerScore;

public:
	void SetPlayerScore(int32 Score);

	int32 GetPlayerScore();
};
