// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingBallEnemyActor.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "RollingBallUserInterface.h"

// Sets default values
ARollingBallEnemyActor::ARollingBallEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ARollingBallEnemyActor::Die()
{
	// Increase player score
	if (!PlayerInterface)
	{
		InitPlayerInterface();
	}
	PlayerInterface->IncreasePlayerScore();

	// Spawn bridge if needed
	if (SpawnBridgeAfterDeath)
	{
		if (BridgeActor)
		{
			GetWorld()->SpawnActor<AActor>(BridgeActor, SpawnBridgeLocation, SpawnBridgeRotation);
		}
	}

	
	Destroy();
}

// Called when the game starts or when spawned
void ARollingBallEnemyActor::BeginPlay()
{
	Super::BeginPlay();

	InitPlayerInterface();
}

void ARollingBallEnemyActor::InitPlayerInterface()
{
	TArray<UUserWidget*> FoundWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, URollingBallUserInterface::StaticClass());
	if (FoundWidgets.Num() > 0)
	{
		PlayerInterface = Cast<URollingBallUserInterface>(FoundWidgets[0]);
	}
}

