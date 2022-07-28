// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingBallPlayerController.h"

#include "RollingBallPawn.h"
#include "RollingBallUserInterface.h"
#include "Blueprint/UserWidget.h"

void ARollingBallPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Find and save player pawn
	if (ARollingBallPawn* TaskPawn = Cast<ARollingBallPawn>(GetPawn()))
	{
		RollingBallPawn = TaskPawn;
	}

	// Create player interface
	URollingBallUserInterface* PlayerInterface = CreateWidget<URollingBallUserInterface>(this, PlayerInterfaceClass);
	if (PlayerInterface)
	{
		PlayerInterface->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget is null"));
	}
}

void ARollingBallPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	check(InputComponent != nullptr);

	InputComponent->BindAction("ChangeVelocity", EInputEvent::IE_Pressed, 
		this, &ARollingBallPlayerController::IncreaseVelocity);
	InputComponent->BindAction("ChangeVelocity", EInputEvent::IE_Released,
		this, &ARollingBallPlayerController::AddVelocityImpulse);

	InputComponent->BindAction("UseAbility", EInputEvent::IE_Pressed,
		this, &ARollingBallPlayerController::UseAbility);

	InputComponent->BindAxis("ChangeDirection", this, &ARollingBallPlayerController::RotatePawn);
}

// Used to process rotation input
void ARollingBallPlayerController::RotatePawn(float Input)
{
	if (Input != 0)
	{
		if (RollingBallPawn)
		{
			RollingBallPawn->ChangeDirection(Input);
		}
	}
}

// Used to process increasing velocity input
void ARollingBallPlayerController::IncreaseVelocity()
{
	if (RollingBallPawn)
	{
		RollingBallPawn->IncreaseVelocity();
	}
}

// Used to process add impulse input
void ARollingBallPlayerController::AddVelocityImpulse()
{
	if (RollingBallPawn)
	{
		RollingBallPawn->AddVelocityImpulse();
	}
}

// Used to process use ability input
void ARollingBallPlayerController::UseAbility()
{
	if (RollingBallPawn)
	{
		RollingBallPawn->UseAbility();
	}
}
