// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingBallGameModeBase.h"

ARollingBallGameModeBase::ARollingBallGameModeBase()
{
	// set pawn and player controller
	ConstructorHelpers::FObjectFinder<UClass>
		PawnClass(TEXT("Class'/Game/Blueprints/BP_RollingBallPawn.BP_RollingBallPawn_C'"));
	if (PawnClass.Object != nullptr)
	{
		DefaultPawnClass = PawnClass.Object;
	}

	ConstructorHelpers::FObjectFinder<UClass>
		ControllerClass(TEXT("Class'/Game/Blueprints/BP_RollingBallPlayerController.BP_RollingBallPlayerController_C'"));
	if (ControllerClass.Object != nullptr)
	{
		PlayerControllerClass = ControllerClass.Object;
	}
}
