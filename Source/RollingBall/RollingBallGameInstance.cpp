// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingBallGameInstance.h"

void URollingBallGameInstance::SetPlayerScore(int32 Score)
{
	PlayerScore = Score;

}

int32 URollingBallGameInstance::GetPlayerScore()
{
	return PlayerScore;
}

