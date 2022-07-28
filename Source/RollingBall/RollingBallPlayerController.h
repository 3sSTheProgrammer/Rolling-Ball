// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RollingBallPlayerController.generated.h"

class ARollingBallPawn;
/**
 * 
 */
UCLASS()
class ROLLINGBALL_API ARollingBallPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// A player interface widget blueprint
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> PlayerInterfaceClass;
	
protected:
	// A reference to player pawn
	UPROPERTY()
	ARollingBallPawn* RollingBallPawn;

protected:

	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;

	// Used to process rotation input
	void RotatePawn(float Input);

	// Used to process increasing velocity input
	void IncreaseVelocity();

	// Used to process add impulse input
	void AddVelocityImpulse();

	// Used to process use ability input
	void UseAbility();
};
