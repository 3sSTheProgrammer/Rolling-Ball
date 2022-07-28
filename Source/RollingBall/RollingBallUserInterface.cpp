// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingBallUserInterface.h"

#include "RollingBallGameInstance.h"
#include "Components/TextBlock.h"

void URollingBallUserInterface::IncreasePlayerScore()
{
	PlayerScore += 1;
	UpdatePlayerInterface();

	//Save PlayerScore to GameInstance
	if (URollingBallGameInstance* GameInstance = Cast<URollingBallGameInstance>(GetGameInstance()))
	{
		GameInstance->SetPlayerScore(PlayerScore);
	}
}

void URollingBallUserInterface::NativeConstruct()
{
	Super::NativeConstruct();

	//Get PlayerScore from GameInstance
	if (URollingBallGameInstance* GameInstance = Cast<URollingBallGameInstance>(GetGameInstance()))
	{
		PlayerScore = GameInstance->GetPlayerScore();
	}
	UpdatePlayerInterface();
}

void URollingBallUserInterface::UpdatePlayerInterface()
{
	TextBlockPlayerScore->SetText(FText::AsNumber(PlayerScore));
}
